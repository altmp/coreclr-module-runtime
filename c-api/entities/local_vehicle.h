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

EXPORT_CLIENT alt::IVehicle* LocalVehicle_GetVehicle(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT uint32_t LocalVehicle_GetID(alt::ILocalVehicle* localVehicle);

EXPORT_CLIENT void LocalVehicle_SetModel(alt::ILocalVehicle* localVehicle, uint32_t model);
EXPORT_CLIENT uint32_t LocalVehicle_GetStreamingDistance(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_SetVisible(alt::ILocalVehicle* localVehicle, uint8_t toggle);
EXPORT_CLIENT uint8_t LocalVehicle_IsVisible(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT uint32_t LocalVehicle_GetScriptID(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT uint32_t LocalVehicle_GetRemoteID(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT uint8_t LocalVehicle_IsRemote(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT uint8_t LocalVehicle_IsStreamedIn(alt::ILocalVehicle* localVehicle);
