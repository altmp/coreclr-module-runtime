#pragma once
#include <coreclr/CoreClr.h>
#include "cpp-sdk/SDK.h"

class CSharpScriptRuntime : public alt::IScriptRuntime {
public:
    explicit CSharpScriptRuntime(alt::ICore* core);

    alt::IResource::Impl * CreateImpl(alt::IResource *resource) override;
    void DestroyImpl(alt::IResource::Impl *impl) override;
    void Init(std::function<void(bool success, std::string error)> next, std::function<void(alt::InitState state, float progress, float total)> setProgress) override;

    CoreClr clr;

private:
    alt::ICore* core;
};
