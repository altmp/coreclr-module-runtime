#include <Log.h>
#include "CSharpScriptRuntime.h"
#include "CSharpResourceImpl.h"
#include "natives.h"

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

CSharpScriptRuntime::CSharpScriptRuntime(alt::ICore* core) : clr(core), core(core) {
    cs::Log::Info << "CSharp runtime initialized" << cs::Log::Endl;
    auto config = core->GetClientConfig();
    try {
        if (!config["disableRestrictedSandbox"]->AsBool(false)) return;

        const int result = MessageBox(nullptr, L"You've enabled disableRestrictedSandbox in altv.toml\r\n"
            "ONLY JOIN TRUSTED SERVERS, AS WITHOUT SANDBOXING THEY CAN ACCESS YOUR PERSONAL DATA.\r\n"
            "Are you sure you want to disable sandboxing?", L"Do you want to disable restricted sandbox?",  MB_YESNO | MB_ICONWARNING);
        if (result != IDYES) return;

        cs::Log::Warning << "C# sandbox disabled" << cs::Log::Endl;
        clr.sandbox = false;
    } catch(std::exception& e) {
        cs::Log::Error << "Failed to parse disableRestrictedSandbox value: " << e.what() << cs::Log::Endl;
    }
}

alt::IResource::Impl* CSharpScriptRuntime::CreateImpl(alt::IResource* resource)
{
    InitNatives();
    return new CSharpResourceImpl(this, resource, core);
}

void CSharpScriptRuntime::DestroyImpl(alt::IResource::Impl* impl) {}

void CSharpScriptRuntime::Init(std::function<void(bool success, std::string error)> next, progressfn_t setProgress)
{
    std::thread thread([=]{
        try {
            clr.Initialize(setProgress);
            next(true, "");
        } catch(CoreClrInitError& e)
        {
            next(false, e.what());
        } catch(std::exception& e) {
            cs::Log::Error << e.what() << cs::Log::Endl;
            std::stringstream ss{};
            ss << "Failed to initialize CLR: " << e.what();
            next(false, ss.str());
        } catch(...)
        {
            cs::Log::Error << "Critical CoreCLR initialization failure" << cs::Log::Endl;
        }
    });
    thread.detach();
}
