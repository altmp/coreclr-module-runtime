#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "../../cpp-sdk/SDK.h"
#include "../../c-api/altv.h"
#include "CSharpScriptRuntime.h"
#include "../../cpp-sdk/version/version.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT bool altMain(alt::ICore* core)
{
    alt::ICore::SetInstance(core);
    auto* cSharpScriptRuntime = new CSharpScriptRuntime(core);
    core->RegisterScriptRuntime("csharp", cSharpScriptRuntime);
    return true;
}

EXPORT const char* GetSDKHash()
{
    return ALT_SDK_VERSION;
}
