#include "worldObject.h"

#include "../utils/macros.h"

CAPI_START()

using namespace alt;

alt::IBaseObject* WorldObject_GetBaseObject(alt::IWorldObject* worldObject) {
    return dynamic_cast<alt::IBaseObject*>(worldObject);
}

void WorldObject_GetPosition(alt::IWorldObject* worldObject, vector3_t& position) {
    auto pos = worldObject->GetPosition();
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;
}

int32_t WorldObject_GetDimension(alt::IWorldObject* worldObject) {
    return worldObject->GetDimension();
}

void WorldObject_SetPosition(alt::IWorldObject* worldObject, position_t pos) {
    alt::Position position;
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;
    worldObject->SetPosition(position);
}

void WorldObject_SetDimension(alt::IWorldObject* worldObject, int32_t dimension) {
    worldObject->SetDimension(dimension);
}

#ifdef ALT_SERVER_API
void WorldObject_GetPositionCoords(alt::IWorldObject* worldObject, float *position_x, float *position_y, float *position_z, int *dimension) {
    auto playerPosition = worldObject->GetPosition();
    *position_x = playerPosition.x;
    *position_y = playerPosition.y;
    *position_z = playerPosition.z;
    *dimension = worldObject->GetDimension();
}

#endif

CAPI_END()