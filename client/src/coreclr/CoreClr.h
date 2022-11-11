#pragma once
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include "utils.h"
#include "cpp-sdk/ICore.h"
#include <coreclr.h>
#include <filesystem>
#include <optional>

#include "nuget/NuGet.h"

typedef int (* CoreClrDelegate_t)(void* args, int argsLength);

class CoreClr {
public:
    explicit CoreClr(alt::ICore* core);

    bool initialized = false;
    bool sandbox = true;
    void Initialize();
    static bool StartResource(alt::IResource* resource, alt::ICore* core);
    static bool StopResource(alt::IResource* resource);
    static std::string BuildTpaList(const std::string& runtimeDir);
    static std::filesystem::path GetMainDirectoryPath();
    static std::filesystem::path GetDataDirectoryPath();
    static std::filesystem::path GetLibrariesDirectoryPath();
    static std::filesystem::path GetRuntimeDirectoryPath();
    static std::filesystem::path GetCoreClrDllPath();

private:
    alt::ICore* _core;
    HMODULE _coreClrLib = nullptr;
    coreclr_initialize_ptr _initializeCoreClr = nullptr;
    coreclr_shutdown_2_ptr _shutdownCoreClr = nullptr;
    coreclr_create_delegate_ptr _createDelegate = nullptr;
    coreclr_execute_assembly_ptr _executeAssembly = nullptr;
    
    void* _runtimeHost = nullptr;
    unsigned int _domainId = 0;
    std::optional<NuGet> _nuget;

    [[nodiscard]] bool ValidateRuntime(nlohmann::json updateJson, alt::IHttpClient* httpClient) const;
    [[nodiscard]] bool ValidateHost(nlohmann::json updateJson) const;
    [[nodiscard]] bool ValidateNuGet(alt::IHttpClient* httpClient, const std::string& package, const std::string& version, nlohmann::json json = nullptr);
    [[nodiscard]] bool ValidateNuGets(alt::IHttpClient* httpClient);
    std::string GetLatestNugetVersion(alt::IHttpClient* httpClient, const std::string& packageName);
    void DownloadRuntime(alt::IHttpClient* httpClient) const;
    void DownloadHost(alt::IHttpClient* httpClient) const;
    void DownloadNuGet(alt::IHttpClient* httpClient, const std::string& packageName, const std::string& version, nlohmann::json json = nullptr);
    void DownloadNuGets(alt::IHttpClient* httpClient);
    
    void InitializeCoreclr();
    void Update();
    
    std::string GetBaseCdnUrl() const;
};
