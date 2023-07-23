#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "../data/types.h"
#include "../utils/export.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_CLIENT alt::IPed* LocalPed_GetPed(alt::ILocalPed* localPed);

EXPORT_CLIENT uint32_t LocalPed_GetID(alt::ILocalPed* localPed);
EXPORT_CLIENT void LocalPed_SetModel(alt::ILocalPed* localPed, uint32_t model);

EXPORT_CLIENT uint32_t LocalPed_GetStreamingDistance(alt::ILocalPed* localPed);

EXPORT_CLIENT void LocalPed_SetVisible(alt::ILocalPed* localPed, uint8_t toggle);
EXPORT_CLIENT uint8_t LocalPed_IsVisible(alt::ILocalPed* localPed);

EXPORT_CLIENT uint32_t LocalPed_GetScriptID(alt::ILocalPed* localPed);

EXPORT_CLIENT uint8_t LocalPed_IsStreamedIn(alt::ILocalPed* localPed);
