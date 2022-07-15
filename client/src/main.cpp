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
        Log::Info << "Main thread is " << std::this_thread::get_id() << Log::Endl;
        Log::Info << "Starting initialization" << Log::Endl;
        auto* runtime = new CSharpScriptRuntime(core);
        core->RegisterScriptRuntime("csharp", runtime);
        Log::Info << "Initialized successfully" << Log::Endl;
        return runtime;
    } catch(std::exception& e) {
        Log::Error << "Initialization failed:" << Log::Endl;
        Log::Error << e.what() << Log::Endl;
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
        Log::Error << "Initialization failed: " << Log::Endl;
        Log::Error << e.what() << Log::Endl;
    }
}
#endif
