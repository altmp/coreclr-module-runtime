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

EXPORT_SHARED alt::IWorldObject* VirtualEntity_GetWorldObject(alt::IVirtualEntity* virtualEntity);

EXPORT_SHARED uint32_t VirtualEntity_GetID(alt::IVirtualEntity* virtualEntity);
EXPORT_SHARED alt::IVirtualEntityGroup* VirtualEntity_GetGroup(alt::IVirtualEntity* virtualEntity);
EXPORT_SHARED uint8_t VirtualEntity_HasStreamSyncedMetaData(alt::IVirtualEntity* virtualEntity, const char* key);
EXPORT_SHARED alt::MValueConst* VirtualEntity_GetStreamSyncedMetaData(alt::IVirtualEntity* virtualEntity, const char* key);

EXPORT_CLIENT uint8_t VirtualEntity_IsStreamedIn(alt::IVirtualEntity* virtualEntity);

EXPORT_SHARED uint32_t VirtualEntity_GetStreamingDistance(alt::IVirtualEntity* virtualEntity);
EXPORT_SERVER void VirtualEntity_SetStreamSyncedMetaData(alt::IVirtualEntity* virtualEntity, const char* key, alt::MValueConst* val);
EXPORT_SERVER void VirtualEntity_SetMultipleStreamSyncedMetaData(alt::IVirtualEntity* virtualEntity, const char* keys[], alt::MValueConst* values[], uint64_t size);
EXPORT_SERVER void VirtualEntity_DeleteStreamSyncedMetaData(alt::IVirtualEntity* virtualEntity, const char* key);

EXPORT_SHARED void VirtualEntity_SetVisible(alt::IVirtualEntity* virtualEntity, uint8_t toggle);
EXPORT_SHARED uint8_t VirtualEntity_IsVisible(alt::IVirtualEntity* virtualEntity);