#include "colshapeCircle.h"

#include "../utils/macros.h"

CAPI_START()

uint32_t ColShapeCircle_GetID(alt::IColShapeCircle* colShapeCircle)
{
    return colShapeCircle->GetID();
}

alt::IColShape* ColShapeCircle_GetColShape(alt::IColShapeCircle* colShapeCircle)
{
    return dynamic_cast<alt::IColShape*>(colShapeCircle);
}

float ColShapeCircle_GetRadius(alt::IColShapeCircle* colShapeCircle)
{
    return colShapeCircle->GetRadius();
}

CAPI_END()
