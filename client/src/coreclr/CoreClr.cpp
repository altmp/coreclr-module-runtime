// ReSharper disable CppClangTidyClangDiagnosticCastFunctionType
#include "CoreClr.h"
#include <future>
#include "cpp-sdk/SDK.h"
#include <string>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <Log.h>
#include <zip_file.hpp>

#include "utils.h"
#include "../../c-api/client.h"
#include "../../c-api/func_table.h"

using namespace alt;
using namespace std;

CoreClrDelegate_t load_resource_delegate = nullptr;
CoreClrDelegate_t stop_resource_delegate = nullptr;
CoreClrDelegate_t stop_runtime_delegate = nullptr;

#if ALTV_CSHARP_SHARED
#define DLL_NAME "coreclr-client-module"
#else
#define DLL_NAME "altv-client"
#endif

std::filesystem::path CoreClr::GetMainDirectoryPath() {
#ifdef DEBUG_CLIENT
    const auto debugDllPath = filesystem::path(utils::wstring_to_string(utils::get_current_dll_path()));
    return debugDllPath.parent_path().parent_path().parent_path().append("csharp-cache");
#else
    auto rootPath = filesystem::path(alt::ICore::Instance().GetClientPath());
    return rootPath.append("csharp-cache");
#endif
}

std::filesystem::path CoreClr::GetLibrariesDirectoryPath() {
    return GetMainDirectoryPath().append("libraries");
}

std::filesystem::path CoreClr::GetDataDirectoryPath() {
    return GetMainDirectoryPath().append("data");
}

std::filesystem::path CoreClr::GetRuntimeDirectoryPath() {
    return GetDataDirectoryPath().append("runtime");
}

std::filesystem::path CoreClr::GetCoreClrDllPath() {
    return GetRuntimeDirectoryPath().append("coreclr.dll");
}

void CoreClr::InitializeCoreclr() {
    const auto runtimePath = GetRuntimeDirectoryPath().string();
    const auto clrDirectoryPath = GetDataDirectoryPath().string();
    
    const auto tpaList = BuildTpaList(runtimePath);
    
    const char *propertyKeys[] = {
        "TRUSTED_PLATFORM_ASSEMBLIES",
        "APP_PATHS",
        "APP_NI_PATHS",
        "NATIVE_DLL_SEARCH_DIRECTORIES",
        "System.GC.Server",
        "System.Globalization.Invariant",
    };
    
    const char *propertyValues[] = {
        tpaList.c_str(),
        clrDirectoryPath.c_str(),
        clrDirectoryPath.c_str(),
        runtimePath.c_str(),
        "true",
        "true",
    };

    cs::Log::Info << "Initializing CLR" << cs::Log::Endl;
    const int rc = _initializeCoreClr(clrDirectoryPath.c_str(), "AltV Host", std::size(propertyKeys), propertyKeys, propertyValues, &_runtimeHost, &_domainId);
    
    if (rc != 0) {
        std::stringstream error;
        error << "Init failed: " << std::hex << std::showbase << rc << std::endl;
        throw std::runtime_error(error.str());
    }

    cs::Log::Info << "CLR initialized successfully" << cs::Log::Endl;
}

CoreClr::CoreClr(alt::ICore* core) {
    cs::Log::Info << "Constructing CoreCLR" << cs::Log::Endl;
    _core = core;
}

void CoreClr::Initialize(progressfn_t progress) {
    if (initialized) return;
    cs::Log::Info << "Initializing CoreCLR" << cs::Log::Endl;

    try
    {
        Update(progress, 0);
    } catch(std::exception& e)
    {
        cs::Log::Error << e.what() << cs::Log::Endl;
        throw CoreClrInitError("FAILED_TO_DOWNLOAD_CSHARP");
    }

    const auto coreclrPath = GetCoreClrDllPath();
    // cs::Log::Info << "CoreCLR dll found: " << coreclrPath.string() << cs::Log::Endl;

    _coreClrLib = LoadLibraryEx(coreclrPath.c_str(), nullptr, 0);
    // cs::Log::Info << "Loaded lib nice" << cs::Log::Endl;

    _initializeCoreClr = (coreclr_initialize_ptr)GetProcAddress(_coreClrLib, "coreclr_initialize");
    _shutdownCoreClr = (coreclr_shutdown_2_ptr)GetProcAddress(_coreClrLib, "coreclr_shutdown_2");
    _createDelegate = (coreclr_create_delegate_ptr)GetProcAddress(_coreClrLib, "coreclr_create_delegate");
    _executeAssembly = (coreclr_execute_assembly_ptr)GetProcAddress(_coreClrLib, "coreclr_execute_assembly");
    // cs::Log::Info << "Loaded delegates nice" << cs::Log::Endl;

    if (!_initializeCoreClr || !_shutdownCoreClr || !_createDelegate || !_executeAssembly)
    {
        cs::Log::Error << "Unable to find CoreCLR dll methods" << cs::Log::Endl;
        throw CoreClrInitError("FAILED_TO_INITIALIZE_CSHARP");
    }

    InitializeCoreclr();

    typedef uint8_t (* initialize_method)(alt::ICore* ptr, const char* dllName, uint8_t sandbox, const function_table_t* cApiFuncTable);
    initialize_method hostInitDelegate = nullptr;

    const int rc = _createDelegate(_runtimeHost, _domainId, "AltV.Net.Client.Host", "Entrypoint", "Initialize", (void **) &hostInitDelegate);
    if (rc != 0 || hostInitDelegate == nullptr) {
        cs::Log::Error << "Cannot load Host dll. Return code: " << std::hex << std::showbase << rc << cs::Log::Endl;
        throw CoreClrInitError("FAILED_TO_INITIALIZE_CSHARP");
    }

    cs::Log::Info << "Executing method from Host dll" << cs::Log::Endl;

    const auto hostInitRc = hostInitDelegate(_core, DLL_NAME, sandbox, get_func_table());
    if (hostInitRc != 0) {
        cs::Log::Error << "Host dll initialization failed. Code: " << std::to_string(hostInitRc) << cs::Log::Endl;
        throw CoreClrInitError("FAILED_TO_INITIALIZE_CSHARP");
    }
    initialized = true;
}

bool CoreClr::StartResource(alt::IResource* resource, alt::ICore* core) {
    const auto path = utils::string_to_wstring(resource->GetMain());

    struct start_args {
        const wchar_t *mainFilePath;
        const alt::IResource *resourcePtr;
        const alt::ICore *corePtr;
    };
    start_args startArgs{path.c_str(), resource, core};

    return load_resource_delegate(&startArgs, sizeof(startArgs)) == 0;
}

bool CoreClr::StopResource(alt::IResource* resource) {
    struct stop_args {
        const alt::IResource *resourcePtr;
    };
    stop_args stopArgs{resource};

    return stop_resource_delegate(&stopArgs, sizeof(stopArgs)) == 0;
}

// ReSharper disable once CppInconsistentNaming
void SetResourceLoadDelegates(const CoreClrDelegate_t resourceExecute, const CoreClrDelegate_t resourceExecuteUnload,
                                     const CoreClrDelegate_t stopRuntime) {
    if (load_resource_delegate || stop_resource_delegate || stop_runtime_delegate) {
        cs::Log::Error << "Resource delegates cannot be replaced" << cs::Log::Endl;
        abort(); // developer tried to call that method from resource XD
    }

    load_resource_delegate = resourceExecute;
    stop_resource_delegate = resourceExecuteUnload;
    stop_runtime_delegate = stopRuntime;
}

// ReSharper disable once CppInconsistentNaming
bool GetCachedAssembly(const char* name, int* bufferSize, void** buffer) {
    auto strName = std::string(name);
    const auto path = CoreClr::GetLibrariesDirectoryPath().append(utils::to_lower(strName) + ".nupkg");
    if (!exists(path)) return false;
    auto stream = std::ifstream(path, std::ios::binary);
    miniz_cpp::zip_file zip(stream);
    std::stringstream contentStream;
    auto fileName = std::string("lib/net6.0/") + name + ".dll";
    if (!zip.has_file(fileName)) {
        cs::Log::Warning << "Nupkg was found, but no dll was found in it" << cs::Log::Endl;
        zip.printdir();
        return false;
    }
    contentStream << zip.open(fileName).rdbuf();
    auto content = contentStream.str();
    
    *bufferSize = static_cast<int>(content.size());
    *buffer = utils::get_clr_value(content.data(), content.size());
    return true;
}
