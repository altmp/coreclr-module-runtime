#include "colshapeRect.h"

#include "../utils/macros.h"
#include "../data/types.h"

CAPI_START()

uint32_t ColShapeRect_GetID(alt::IColShapeRect* colShapeRect)
{
    return colShapeRect->GetID();
}

alt::IColShape* ColShapeRect_GetColShape(alt::IColShapeRect* colShapeRect){
    return dynamic_cast<alt::IColShape*>(colShapeRect);
}

void ColShapeRect_GetMin(alt::IColShapeRect* colShapeRect, vector2_t& pos) {
    auto min = colShapeRect->GetMin();
    pos.x = min[0];
    pos.y = min[1];
}

void ColShapeRect_GetMax(alt::IColShapeRect* colShapeRect, vector2_t& pos) {
    auto max = colShapeRect->GetMax();
    pos.x = max[0];
    pos.y = max[1];
}

CAPI_END()
