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

EXPORT_SHARED uint32_t ColShapeCylinder_GetID(alt::IColShapeCylinder* colShapeCylinder);

EXPORT_SHARED alt::IColShape* ColShapeCylinder_GetColShape(alt::IColShapeCylinder* colShapeCylinder);

EXPORT_SHARED float ColShapeCylinder_GetRadius(alt::IColShapeCylinder* colShapeCylinder);
EXPORT_SHARED float ColShapeCylinder_GetHeight(alt::IColShapeCylinder* colShapeCylinder);
