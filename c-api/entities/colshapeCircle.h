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

EXPORT_SHARED uint32_t ColShapeCircle_GetID(alt::IColShapeCircle* colShapeCircle);

EXPORT_SHARED alt::IColShape* ColShapeCircle_GetColShape(alt::IColShapeCircle* colShapeCircle);

EXPORT_SHARED float ColShapeCircle_GetRadius(alt::IColShapeCircle* colShapeCircle);