#include <json.hpp>
#include <Log.h>
#include <sha1.hpp>
#include <sha512.hpp>
#include <iomanip>
#include <zip_file.hpp>

#include "CoreClr.h"
#include "cpp-sdk/SDK.h"

using namespace alt;
namespace fs = std::filesystem;

std::string CoreClr::GetBaseCdnUrl() const {
    static auto branch = _core->GetBranch();
    return "https://cdn.alt-mp.com/coreclr-client-module/" + branch + "/x64_win32/";
}

inline const std::string host_dll_name = "AltV.Net.Client.Host.dll";


std::string CoreClr::GetLatestNugetVersion(alt::IHttpClient* httpClient, const std::string& packageName) {
    if (!_nuget) _nuget.emplace(httpClient);
    auto branch = _core->GetBranch();
    if (branch == "internal") branch = "dev";
    const auto versions = _nuget->GetPackageVersions(packageName);
    for (auto it = versions.rbegin(); it != versions.rend(); ++it) {
        if (branch == "release") {
            if (it->find("-") == std::string::npos) return *it;
        } else {
            if (it->find("-" + branch + ".") != std::string::npos) return *it;
        }
    }

    throw std::runtime_error("Failed to find latest version of " + packageName + " for branch " + branch);
}


void CoreClr::GetRequiredNugets(alt::IHttpClient* httpClient, const std::string& nuget, std::map<std::string, nlohmann::json>& vec)
{
    if (!_nuget) _nuget.emplace(httpClient);
    cs::Log::Info << "Fetching NuGet " << nuget << cs::Log::Endl;
    const auto version = GetLatestNugetVersion(httpClient, nuget);
    const auto json = _nuget->GetCatalog(nuget, version);
    vec[nuget] = json;

    const auto dependencyGroup = json["dependencyGroups"][0];
    if (!dependencyGroup.contains("dependencies")) return;

    const auto& dependencies = dependencyGroup["dependencies"];
    for (auto it = dependencies.begin(); it != dependencies.end(); ++it) {
        auto id = it.value()["id"].get<std::string>();
        utils::to_lower(id);

        if (!utils::has_prefix(id, "altv.")) continue;
        if (vec.count(id) > 0) continue;

        GetRequiredNugets(httpClient, id, vec);
    }
}

bool CoreClr::ValidateRuntime(nlohmann::json updateJson, Progress& progress) const {
    const auto hashList = updateJson["hashList"];
    const auto sizeList = updateJson["sizeList"];

    auto const runtimeDirectoryPath = GetRuntimeDirectoryPath();
    if (!fs::exists(runtimeDirectoryPath)) return false;

    for (auto it = hashList.begin(); it != hashList.end(); ++it) {
        if (!utils::has_prefix(it.key(), "runtime/")) continue;
        auto path = GetDataDirectoryPath();
        path.append(it.key());
        if (!fs::exists(path)) {
            cs::Log::Warning << "File " << path.string() << " does not exist" << cs::Log::Endl;
            return false;
        }
        SHA1 checksum;
        auto stream = std::ifstream(path, std::ios::binary);
        checksum.update(stream);
        const std::string hash = checksum.final();
        if (hash != it.value()) {
            cs::Log::Warning << "File " << path << " has invalid hash" << cs::Log::Endl;
            cs::Log::Warning << "Current " << hash << " Needed " << it.value() << cs::Log::Endl;
            return false;
        }

        progress.Advance(sizeList[it.key()].get<float>());
    }

    for (auto& entry : fs::recursive_directory_iterator(runtimeDirectoryPath)) {
        if (entry.is_directory() || !entry.is_regular_file()) continue;
        auto relativePath = "runtime/" + fs::relative( entry.path(), runtimeDirectoryPath ).generic_string();
        if (!hashList.contains(relativePath)) {
            cs::Log::Warning << "File " << entry.path() << " is not in update.json" << cs::Log::Endl;
            if (!fs::remove(entry.path())) {
                throw std::runtime_error("Failed to remove file " + entry.path().string());
            }
        }
    }

    return true;
}

void CoreClr::DownloadRuntime(alt::IHttpClient* httpClient, Progress& progress) const {
    auto attempt = 0;

    while (true) {
        if (attempt++ >= 6) throw std::runtime_error("Failed to download CoreCLR after " + std::to_string(attempt) + " attempts");

        cs::Log::Info << "Downloading CoreCLR (attempt " << attempt << ")" << cs::Log::Endl;

        static auto url = GetBaseCdnUrl() + "runtime.zip";
        // todo pass progress
        const auto response = utils::download_file_sync(httpClient, url);
        cs::Log::Info << "Download finished" << cs::Log::Endl;

        static auto runtimeDirectoryPath = GetRuntimeDirectoryPath();
        if (!fs::exists(runtimeDirectoryPath)) fs::create_directories(runtimeDirectoryPath);

        std::istringstream is(response.body, std::ios::binary);
        cs::Log::Info << "Extracting zip" << cs::Log::Endl;

        try {
            miniz_cpp::zip_file zip(is);
            zip.extractall(runtimeDirectoryPath.string());
            cs::Log::Info << "Extract finished" << cs::Log::Endl;
            return;
        } catch (std::runtime_error& e) {
            cs::Log::Error << "Failed to extract zip: " << e.what() << cs::Log::Endl;

            auto path = GetDataDirectoryPath() / "runtime.zip";
            try
            {
                cs::Log::Info << "Writing debug ZIP to: " << path.string() << cs::Log::Endl;
                std::ofstream os(path);
                os << response.body;
                os.close();
                cs::Log::Info << "Writing debug ZIP finished" << cs::Log::Endl;
            } catch(std::runtime_error& e)
            {
                cs::Log::Info << "Writing debug ZIP failed: " << e.what() << cs::Log::Endl;
            }
        }
    }
}

bool CoreClr::ValidateHost(nlohmann::json updateJson) const {
    cs::Log::Info << "Validating Host" << cs::Log::Endl;

    static auto hostPath = GetDataDirectoryPath().append(host_dll_name);

    if (!fs::exists(hostPath)) {
        cs::Log::Warning << "Host file does not exist" << cs::Log::Endl;
        return false;
    }

    if (alt::ICore::Instance().GetBranch() == "internal")
    {
        return true;
    }

    SHA1 checksum;
    auto stream = std::ifstream(hostPath, std::ios::binary);
    checksum.update(stream);
    const std::string hash = checksum.final();

    const auto hashList = updateJson["hashList"];

    if (hashList[host_dll_name] != hash) {
        cs::Log::Warning << "Host has invalid hash." << cs::Log::Endl;
        cs::Log::Warning << "CDN hash: " << hashList[host_dll_name] << cs::Log::Endl;
        cs::Log::Warning << "Local hash: " << hash << cs::Log::Endl;
        return false;
    }

    return true;
}

void CoreClr::DownloadHost(alt::IHttpClient* httpClient, Progress& progress) const {
    static auto url = GetBaseCdnUrl() + host_dll_name;
    auto attempt = 0;

    while (true) {
        if (attempt++ >= 6) throw std::runtime_error("Failed to download Host after " + std::to_string(attempt) + " attempts");

        cs::Log::Info << "Downloading Host (attempt " << attempt << ")" << cs::Log::Endl;

        const auto response = utils::download_file_sync(httpClient, url);
        if (response.statusCode != 200) {
            cs::Log::Error << "Failed to download Host: " << response.statusCode << cs::Log::Endl;
            continue;
        }


        static auto path = GetDataDirectoryPath().append(host_dll_name);
        std::ofstream file(path, std::ios::binary);
        file.write(response.body.data(), response.body.size());
        file.close();
        return;
    }
}

bool CoreClr::ValidateNuGet(alt::IHttpClient* httpClient, nlohmann::json json) {
    if (!_nuget) _nuget.emplace(httpClient);
    const auto package = json["id"].get<std::string>();
    const auto version = json["version"].get<std::string>() ;
    cs::Log::Info << "Validating NuGet package " << package << " " << version << cs::Log::Endl;

    auto librariesDirectoryPath = GetLibrariesDirectoryPath();
    auto nupkgPath = librariesDirectoryPath.append(package + ".nupkg");
    if (!fs::exists(nupkgPath)) {
        cs::Log::Info << "Nuget file does not exist" << cs::Log::Endl;
        return false;
    }
    auto stream = std::ifstream(nupkgPath, std::ios::binary);
    const auto hashAlgorithm = json["packageHashAlgorithm"].get<std::string>();

    std::string fileHash;
    if (hashAlgorithm == "SHA512") {
        fileHash = sw::sha512::calculate(stream);
    } else if (hashAlgorithm == "SHA256") {
        std::string content((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
        fileHash = _core->StringToSHA256(content);
    } else {
        throw std::runtime_error("Unsupported hash algorithm " + json["packageHashAlgorithm"].get<std::string>());
    }

    const auto neededHashBase64 = json["packageHash"].get<std::string>();
    std::stringstream neededHash;
    for (const auto &item : utils::base64_decode(neededHashBase64)) {
        neededHash << std::hex << std::setw(2) << std::setfill('0') << (int) item;
    }

    cs::Log::Info << "Needed hash was " << neededHash.str() << " actual hash was " << fileHash << cs::Log::Endl;

    if (neededHash.str() != fileHash) {
        cs::Log::Error << "Failed to validate NuGet " << package << " " << version << cs::Log::Endl;
        return false;
    }
    return true;
}

void CoreClr::DownloadNuGet(alt::IHttpClient* httpClient, nlohmann::json json, Progress& progress)
{
    if (!_nuget) _nuget.emplace(httpClient);
    const auto packageName = json["id"].get<std::string>();
    const auto version = json["version"].get<std::string>() ;
    cs::Log::Info << "Downloading NuGet package " << packageName << " " << version << cs::Log::Endl;

    auto librariesDirectoryPath = GetLibrariesDirectoryPath();
    if (!fs::exists(librariesDirectoryPath)) fs::create_directories(librariesDirectoryPath);
    const auto nupkgPath = librariesDirectoryPath.append(packageName + ".nupkg");
    // todo pass progress
    const auto content = _nuget->DownloadPackage(packageName, version);
    std::ofstream file(nupkgPath, std::ios::binary);
    file.write(content.data(), content.size());
    file.close();
}

void CoreClr::Update(progressfn_t progressFn, int attempt) {
    const auto httpClient = _core->CreateHttpClient(nullptr);

    static auto url = GetBaseCdnUrl() + "update.json";
    const auto updateFile = utils::download_file_sync(httpClient, url);
    const auto updateJson = nlohmann::json::parse(updateFile.body);
    const auto sizeList = updateJson["sizeList"];

    std::map<std::string, nlohmann::json> nugets;
    GetRequiredNugets(httpClient, "altv.net.client", nugets);

    float runtimeSize = 0;
    for (const auto& item : sizeList.items())
        if (utils::has_prefix(item.key(), "runtime/"))
            runtimeSize += item.value().get<float>();
    float hostSize = sizeList[host_dll_name].get<float>();
    float totalSize = runtimeSize + hostSize;
    for (auto& [key, value] : nugets)
        totalSize += value["packageSize"].get<float>();

    float validated = 0;
    Progress validationProgress { ValidatingRuntime, totalSize, 0, progressFn };

    auto runtimeValid = ValidateRuntime(updateJson, validationProgress);
    validationProgress.current = validated += runtimeSize;
    validationProgress.Update();

    bool hostValid = ValidateHost(updateJson);
    validationProgress.current = validated += hostSize;
    validationProgress.Update();

    std::vector<nlohmann::json> invalidNugets{};

    for (auto& [key, value] : nugets)
    {
        if (!ValidateNuGet(httpClient, value)) invalidNugets.push_back(value);
        validationProgress.current = validated += value["packageSize"].get<float>();
        validationProgress.Update();
    }

    if (runtimeValid && hostValid && invalidNugets.empty()) return;
    if (attempt >= 3) throw std::runtime_error("Failed to confirm CoreCLR update after " + std::to_string(attempt) + " attempts");


    float downloadSize = 0;
    if (!runtimeValid) downloadSize += sizeList["runtime.zip"].get<float>();
    if (!hostValid) downloadSize += hostSize;
    for (auto nuget : invalidNugets)
        downloadSize += nuget["packageSize"].get<float>();
    float downloaded = 0;

    Progress downloadProgress { DownloadingRuntime, downloadSize, 0, progressFn };

    if (!runtimeValid)
    {
        DownloadRuntime(httpClient, downloadProgress);
        downloadProgress.current = downloaded += sizeList["runtime.zip"].get<float>();
        downloadProgress.Update();
    }

    if (!hostValid)
    {
        DownloadHost(httpClient, downloadProgress);
        downloadProgress.current = downloaded += hostSize;
        downloadProgress.Update();
    }

    for (auto nuget : invalidNugets)
    {
        DownloadNuGet(httpClient, nuget, downloadProgress);
        downloadProgress.current = downloaded += nuget["packageSize"].get<float>();
        downloadProgress.Update();
    }

    Update(progressFn, attempt + 1);
}
