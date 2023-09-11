#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "../utils/export.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_SHARED uint32_t ColShapeCuboid_GetID(alt::IColShapeCuboid* colShapeCuboid);

EXPORT_SHARED alt::IColShape* ColShapeCuboid_GetColShape(alt::IColShapeCuboid* colShapeCuboid);

EXPORT_SHARED alt::Position ColShapeCuboid_GetMin(alt::IColShapeCuboid* colShapeCuboid);
EXPORT_SHARED alt::Position ColShapeCuboid_GetMax(alt::IColShapeCuboid* colShapeCuboid);
