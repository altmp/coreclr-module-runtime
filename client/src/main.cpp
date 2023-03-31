#define ALT_CLIENT_API
#include <exceptions/LoadException.h>
#include "cpp-sdk/SDK.h"
#include "runtime/CSharpScriptRuntime.h"
#ifdef ALTV_CSHARP_SHARED
#include "cpp-sdk/version/version.h"
#endif
#include <Log.h>

using namespace alt;

#ifdef ALTV_CSHARP_SHARED
EXPORT alt::IScriptRuntime* CreateScriptRuntime(ICore* core)
#else
EXPORT alt::IScriptRuntime* CreateScriptRuntimeCSharp(ICore* core)
#endif
{
    ICore::SetInstance(core);
    try
    {
        cs::Log::Info << "Main thread is " << std::this_thread::get_id() << cs::Log::Endl;
        cs::Log::Info << "Starting initialization" << cs::Log::Endl;
        auto* runtime = new CSharpScriptRuntime(core);
        core->RegisterScriptRuntime("csharp", runtime);
        cs::Log::Info << "Initialized successfully" << cs::Log::Endl;
        return runtime;
    } catch(std::exception& e) {
        cs::Log::Error << "Initialization failed:" << cs::Log::Endl;
        cs::Log::Error << e.what() << cs::Log::Endl;
        throw;
    }
}

#ifdef ALTV_CSHARP_SHARED
EXPORT const char* GetType()
{
    return "csharp";
}

EXPORT char* GetSDKHash()
{
    return ALT_SDK_VERSION;
}
#endif

#ifdef DEBUG_CLIENT
int main() {
    try {
        CoreCLR clr(nullptr);
        clr.Initialize();
//        Test test;
//        clr.start_resource(&test);
    } catch(std::exception& e) {
        cs::Log::Error << "Initialization failed: " << cs::Log::Endl;
        cs::Log::Error << e.what() << cs::Log::Endl;
    }
}
#endif
