#include "colshapeCylinder.h"

#include "../utils/macros.h"

CAPI_START()

uint32_t ColShapeCylinder_GetID(alt::IColShapeCylinder* colShapeCylinder)
{
    return colShapeCylinder->GetID();
}

alt::IColShape* ColShapeCylinder_GetColShape(alt::IColShapeCylinder* colShapeCylinder)
{
    return dynamic_cast<alt::IColShape*>(colShapeCylinder);
}

float ColShapeCylinder_GetRadius(alt::IColShapeCylinder* colShapeCylinder)
{
    return colShapeCylinder->GetRadius();
}

float ColShapeCylinder_GetHeight(alt::IColShapeCylinder* colShapeCylinder)
{
    return colShapeCylinder->GetHeight();
}

CAPI_END()
