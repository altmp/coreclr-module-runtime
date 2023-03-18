#pragma once
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include "utils.h"
#include "cpp-sdk/ICore.h"
#include <coreclr.h>
#include <filesystem>
#include <Log.h>
#include <optional>

#include "nuget/NuGet.h"

typedef int (* CoreClrDelegate_t)(void* args, int argsLength);

typedef std::function<void(alt::InitState state, float progress, float total)> progressfn_t;

struct Progress
{
    alt::InitState state;
    float total;
    float current;
    progressfn_t& updateFn;
    
    void Update() const
    {
        updateFn(state, current, total);
    }
    
    void Advance(float value)
    {
        current += value;
        if (current > total) current = total;
        Update();
    }
};

class CoreClrInitError final : public std::runtime_error {
public:
    explicit CoreClrInitError(const std::string& _Message)
        : runtime_error(_Message) {}
};

class CoreClr {
public:
    explicit CoreClr(alt::ICore* core);

    bool initialized = false;
    bool sandbox = true;
    void Initialize(progressfn_t progress);
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

    void GetRequiredNugets(alt::IHttpClient* httpClient, const std::string& nuget, std::map<std::string, nlohmann::json>& vec);
    [[nodiscard]] bool ValidateRuntime(nlohmann::json updateJson, Progress& progress) const;
    [[nodiscard]] bool ValidateHost(nlohmann::json updateJson) const;
    [[nodiscard]] bool ValidateNuGet(alt::IHttpClient* httpClient, nlohmann::json json);
    // [[nodiscard]] bool ValidateNuGets(alt::IHttpClient* httpClient);
    std::string GetLatestNugetVersion(alt::IHttpClient* httpClient, const std::string& packageName);
    void DownloadRuntime(alt::IHttpClient* httpClient, Progress& progress) const;
    void DownloadHost(alt::IHttpClient* httpClient, Progress& progress) const;
    void DownloadNuGet(alt::IHttpClient* httpClient, nlohmann::json json, Progress& progress);
    void DownloadNuGets(alt::IHttpClient* httpClient, progressfn_t& progress);
    
    void InitializeCoreclr();
    void Update(progressfn_t progressFn, int attempt);
    
    std::string GetBaseCdnUrl() const;
};
