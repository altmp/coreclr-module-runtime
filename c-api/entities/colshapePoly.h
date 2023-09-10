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

EXPORT_SHARED uint32_t ColShapePoly_GetID(alt::IColShapePoly* colShapePoly);

EXPORT_SHARED alt::IColShape* ColShapePoly_GetColShape(alt::IColShapePoly* colShapePoly);

EXPORT_SHARED float ColShapePoly_GetMinZ(alt::IColShapePoly* colShapePoly);
EXPORT_SHARED float ColShapePoly_GetMaxZ(alt::IColShapePoly* colShapePoly);
EXPORT_SHARED vector2_t* ColShapePoly_GetPoints(alt::IColShapePoly* colShapePoly, uint64_t& size);
