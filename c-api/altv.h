#pragma once

#include "utils/export.h"
#include "utils/strings.h"
#include "cpp-sdk/SDK.h"
#include "data/sync_info.h"
#include "data/types.h"

EXPORT_SHARED void FreeUIntArray(std::vector<uint32_t> *array);
//EXPORT void FreePlayerPointerArray(alt::Array<alt::IPlayer*> *array);
//EXPORT void FreeStringViewArray(alt::Array<std::stringView> *array);
//EXPORT void FreeStringArray(alt::Array<std::string>* array);
/*EXPORT void FreeMValueArray(alt::Array<alt::MValue> *array);*/
EXPORT_SHARED void FreeCharArray(char charArray[]);
EXPORT_SHARED void FreeUInt32Array(/** nint */ uint32_t* uInt32Array);
EXPORT_SHARED void FreeUInt8Array(/** nint */ uint8_t* uInt8Array);
EXPORT_SHARED void FreeVector2Array(/** nint */ vector2_t* vector2Array);
EXPORT_SHARED void FreeVoidPointerArray(/** nint */void** voidPointerArray);
EXPORT_SHARED void FreeWeaponTArray(/** nint */ weapon_t* weaponArray, uint32_t size);
EXPORT_SHARED void FreeSyncInfo(/** nint */ sync_info_t syncInfo);
EXPORT_SHARED void FreeString(const char* string);
EXPORT_SHARED void FreeStringArray(const char** stringArray, uint32_t size);
EXPORT_SHARED void FreeResourceArray(alt::IResource** resourceArray);
EXPORT_SHARED void FreePlayerArray(alt::IPlayer** playerArray);
EXPORT_SHARED void FreeBlipArray(alt::IBlip** blipArray);
EXPORT_SHARED void FreeVehicleArray(alt::IVehicle** vehicleArray);
EXPORT_SHARED void FreePedArray(alt::IPed** pedArray);
EXPORT_SHARED void FreeNetworkObjectArray(alt::IObject** networkObjectArray);
EXPORT_SHARED void FreeColShapeArray(alt::IColShape** colShapeArray);
EXPORT_SHARED void FreeMarkerArray(alt::IMarker** markerArray);
EXPORT_SHARED void FreeTextLabelArray(alt::ITextLabel** textLabelArray);
EXPORT_SHARED void FreeCheckpointArray(alt::ICheckpoint** checkpointArray);
EXPORT_SHARED void FreeVirtualEntityArray(alt::IVirtualEntity** virtualEntityArray);
EXPORT_SHARED void FreeVirtualEntityGroupArray(alt::IVirtualEntityGroup** virtualEntityGroupArray);
EXPORT_SHARED void FreeConnectionInfoArray(alt::IConnectionInfo** connectionInfoArray);
EXPORT_SHARED void FreeLocalObjectArray(alt::ILocalObject** objectArray);
EXPORT_SHARED void FreeAudioArray(alt::IAudio** audioArray);
EXPORT_SHARED void FreeAudioOutputArray(alt::IAudioOutput** audioOutputArray);
EXPORT_SHARED void FreeMValueConstArray(alt::MValueConst** mvalueConstArray);
EXPORT_SHARED const char* GetVersionStatic(int32_t &size);
EXPORT_SHARED const char* GetBranchStatic(int32_t &size);
EXPORT_SHARED uint8_t IsDebugStatic();
EXPORT_SHARED const char* GetCApiVersion(int32_t &size);
EXPORT_SHARED const char* GetSDKVersion(int32_t &size);

EXPORT_CLIENT void FreeRmlElementArray(alt::IRmlElement** rmlElementArray);
EXPORT_CLIENT void FreeLocalVehicleArray(alt::ILocalVehicle** localVehicleArray);
EXPORT_CLIENT void FreeLocalPedArray(alt::ILocalPed** localPedArray);
EXPORT_CLIENT void* Win_GetTaskDialog();
