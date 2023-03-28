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

EXPORT_SHARED uint32_t ColShape_GetID(alt::IColShape* colShape);

EXPORT_SHARED alt::IWorldObject* ColShape_GetWorldObject(alt::IColShape* colShape);

EXPORT_SHARED uint8_t ColShape_IsEntityIn(alt::IColShape* colShape, alt::IEntity* entity);
EXPORT_SHARED uint8_t ColShape_IsEntityIdIn(alt::IColShape* colShape, uint16_t id);
EXPORT_SHARED uint8_t ColShape_IsPointIn(alt::IColShape* colShape, vector3_t point);

EXPORT_SERVER uint8_t ColShape_GetColShapeType(alt::IColShape* colShape);
EXPORT_SERVER void ColShape_SetPlayersOnly(alt::IColShape* colShape, uint8_t state);
EXPORT_SERVER uint8_t ColShape_IsPlayersOnly(alt::IColShape* colShape);