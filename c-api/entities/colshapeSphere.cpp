#include "colshapeSphere.h"

#include "../utils/macros.h"

CAPI_START()

uint32_t ColShapeSphere_GetID(alt::IColShapeSphere* colShapeSphere)
{
    return colShapeSphere->GetID();
}

alt::IColShape* ColShapeSphere_GetColShape(alt::IColShapeSphere* colShapeSphere)
{
    return dynamic_cast<alt::IColShape*>(colShapeSphere);
}

float ColShapeSphere_GetRadius(alt::IColShapeSphere* colShapeSphere)
{
    return colShapeSphere->GetRadius();
}

CAPI_END()
