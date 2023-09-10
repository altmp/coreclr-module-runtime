#include "colshapePoly.h"

#include "../utils/macros.h"

CAPI_START()

uint32_t ColShapePoly_GetID(alt::IColShapePoly* colShapePoly)
{
    return colShapePoly->GetID();
}

alt::IColShape* ColShapePoly_GetColShape(alt::IColShapePoly* colShapePoly)
{
    return dynamic_cast<alt::IColShape*>(colShapePoly);
}

float ColShapePoly_GetMinZ(alt::IColShapePoly* colShapePoly)
{
    return colShapePoly->GetMinZ();
}

float ColShapePoly_GetMaxZ(alt::IColShapePoly* colShapePoly)
{
    return colShapePoly->GetMaxZ();
}

vector2_t* ColShapePoly_GetPoints(alt::IColShapePoly* colShapePoly, uint64_t& size)
{
    auto points = colShapePoly->GetPoints();
    size = points.size();
    auto out = new vector2_t[size];
    for (auto i = 0; i < size; i++) {
        out[i].x = points[i][0];
        out[i].y = points[i][1];
    }

    return out;
}

CAPI_END()
