#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "../utils/export.h"
#include "../data/types.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_SHARED uint32_t ColShapeRect_GetID(alt::IColShapeRect* colShapeRect);

EXPORT_SHARED alt::IColShape* ColShapeRect_GetColShape(alt::IColShapeRect* colShapeRect);

EXPORT_SHARED void ColShapeRect_GetMin(alt::IColShapeRect* colShapeRect, vector2_t& pos);
EXPORT_SHARED void ColShapeRect_GetMax(alt::IColShapeRect* colShapeRect, vector2_t& pos);
