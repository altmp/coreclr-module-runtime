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

EXPORT_SHARED uint32_t Checkpoint_GetID(alt::ICheckpoint* checkpoint);

EXPORT_SHARED alt::IColShape* Checkpoint_GetColShape(alt::ICheckpoint* checkpoint);

EXPORT_SHARED uint8_t Checkpoint_GetCheckpointType(alt::ICheckpoint* checkpoint);
EXPORT_SHARED void Checkpoint_SetCheckpointType(alt::ICheckpoint* checkpoint, uint8_t type);
EXPORT_SHARED float Checkpoint_GetHeight(alt::ICheckpoint* checkpoint);
EXPORT_SHARED void Checkpoint_SetHeight(alt::ICheckpoint* checkpoint, float height);
EXPORT_SHARED float Checkpoint_GetRadius(alt::ICheckpoint* checkpoint);
EXPORT_SHARED void Checkpoint_SetRadius(alt::ICheckpoint* checkpoint, float radius);
EXPORT_SHARED void Checkpoint_GetColor(alt::ICheckpoint* checkpoint, rgba_t &color);
EXPORT_SHARED void Checkpoint_SetColor(alt::ICheckpoint* checkpoint, rgba_t color);
EXPORT_SHARED void Checkpoint_GetIconColor(alt::ICheckpoint* checkpoint, rgba_t &color);
EXPORT_SHARED void Checkpoint_SetIconColor(alt::ICheckpoint* checkpoint, rgba_t color);
EXPORT_SHARED void Checkpoint_GetNextPosition(alt::ICheckpoint* checkpoint, vector3_t &pos);
EXPORT_SHARED void Checkpoint_SetNextPosition(alt::ICheckpoint* checkpoint, vector3_t pos);
EXPORT_SHARED uint32_t Checkpoint_GetStreamingDistance(alt::ICheckpoint* checkpoint);

EXPORT_SHARED void Checkpoint_SetVisible(alt::ICheckpoint* checkpoint, uint8_t toggle);
EXPORT_SHARED uint8_t Checkpoint_IsVisible(alt::ICheckpoint* checkpoint);

EXPORT_CLIENT uint8_t Checkpoint_IsStreamedIn(alt::ICheckpoint* checkpoint);
EXPORT_CLIENT uint32_t Checkpoint_GetGameID(alt::ICheckpoint* checkpoint);

EXPORT_SERVER uint8_t Checkpoint_HasStreamSyncedMetaData(alt::ICheckpoint* checkpoint, const char* key);
EXPORT_SERVER alt::MValueConst* Checkpoint_GetStreamSyncedMetaData(alt::ICheckpoint* checkpoint, const char* key);

EXPORT_SERVER void Checkpoint_SetStreamSyncedMetaData(alt::ICheckpoint* checkpoint, const char* key, alt::MValueConst* val);
EXPORT_SERVER void Checkpoint_SetMultipleStreamSyncedMetaData(alt::ICheckpoint* checkpoint, const char* keys[], alt::MValueConst* values[], uint64_t size);
EXPORT_SERVER void Checkpoint_DeleteStreamSyncedMetaData(alt::ICheckpoint* checkpoint, const char* key);

