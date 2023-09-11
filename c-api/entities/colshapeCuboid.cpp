#include "colshapeCuboid.h"

#include "../utils/macros.h"

CAPI_START()

uint32_t ColShapeCuboid_GetID(alt::IColShapeCuboid* colShapeCuboid)
{
    return colShapeCuboid->GetID();
}

alt::IColShape* ColShapeCuboid_GetColShape(alt::IColShapeCuboid* colShapeCuboid)
{
    return dynamic_cast<alt::IColShape*>(colShapeCuboid);
}

alt::Position ColShapeCuboid_GetMin(alt::IColShapeCuboid* colShapeCuboid)
{
    return colShapeCuboid->GetMin();
}

alt::Position ColShapeCuboid_GetMax(alt::IColShapeCuboid* colShapeCuboid)
{
    return colShapeCuboid->GetMax();
}

CAPI_END()
