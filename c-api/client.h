#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "data/types.h"
#include "utils/export.h"

#ifdef ALT_CLIENT_API
#include "../client/src/runtime/CSharpResourceImpl.h"
#include "../client/src/runtime/eventDelegates.h"
#endif

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_CLIENT ONLY_MANUAL void SetResourceLoadDelegates(/** delegate **/ const CoreClrDelegate_t resourceExecute, /** delegate **/ const CoreClrDelegate_t resourceExecuteUnload, /** delegate **/ const CoreClrDelegate_t stopRuntime);
EXPORT_CLIENT ONLY_MANUAL bool GetCachedAssembly(const char* name, int* bufferSize, void** buffer);
EXPORT_CLIENT void* GetNativeFuncTable();