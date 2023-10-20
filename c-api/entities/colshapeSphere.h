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

EXPORT_SHARED uint32_t ColShapeSphere_GetID(alt::IColShapeSphere* colShapeSphere);

EXPORT_SHARED alt::IColShape* ColShapeSphere_GetColShape(alt::IColShapeSphere* colShapeSphere);

EXPORT_SHARED float ColShapeSphere_GetRadius(alt::IColShapeSphere* colShapeSphere);