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


EXPORT_SHARED alt::IBaseObject* WorldObject_GetBaseObject(alt::IWorldObject* worldObject);
EXPORT_SHARED void WorldObject_GetPosition(alt::IWorldObject* worldObject, vector3_t& position);
EXPORT_SHARED void WorldObject_GetPositionCoords(alt::IWorldObject* worldObject, float* position_x, float* position_y, float* position_z, int* dimension);

EXPORT_SERVER int32_t WorldObject_GetDimension(alt::IWorldObject* worldObject);
EXPORT_SERVER void WorldObject_SetDimension(alt::IWorldObject* worldObject, int32_t dimension);
EXPORT_SERVER void WorldObject_SetPosition(alt::IWorldObject* worldObject, position_t pos);
