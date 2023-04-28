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


EXPORT_SHARED alt::IWorldObject* LocalPed_GetWorldObject(alt::ILocalPed* localPed);

EXPORT_SHARED uint32_t LocalPed_GetID(alt::ILocalPed* localPed);
EXPORT_SHARED uint32_t LocalPed_GetModel(alt::ILocalPed* localPed);
EXPORT_SHARED void LocalPed_GetRotation(alt::ILocalPed* localPed, rotation_t& rot);
EXPORT_SHARED void LocalPed_SetRotation(alt::ILocalPed* localPed, rotation_t rot);

EXPORT_SHARED uint32_t LocalPed_GetStreamingDistance(alt::ILocalPed* localPed);

EXPORT_SHARED void LocalPed_SetVisible(alt::ILocalPed* localPed, uint8_t toggle);
EXPORT_SHARED uint8_t LocalPed_IsVisible(alt::ILocalPed* localPed);

EXPORT_CLIENT uint32_t LocalPed_GetScriptID(alt::ILocalPed* localPed);

EXPORT_CLIENT uint32_t LocalPed_GetRemoteID(alt::ILocalPed* localPed);
EXPORT_CLIENT uint8_t LocalPed_IsRemote(alt::ILocalPed* localPed);
EXPORT_CLIENT uint8_t LocalPed_IsStreamedIn(alt::ILocalPed* localPed);
