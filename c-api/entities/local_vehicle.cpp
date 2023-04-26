#include "local_vehicle.h"

alt::IWorldObject* LocalVehicle_GetWorldObject(alt::ILocalVehicle* localVehicle)
{
    return dynamic_cast<alt::IWorldObject*>(localVehicle);
}

uint32_t LocalVehicle_GetID(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetID();
}

uint32_t LocalVehicle_GetModel(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetModel();
}

void LocalVehicle_GetRotation(alt::ILocalVehicle* localVehicle, rotation_t& rot)
{
    auto localVehicleRotation = localVehicle->GetRotation();
    rot.roll = localVehicleRotation.roll;
    rot.pitch = localVehicleRotation.pitch;
    rot.yaw = localVehicleRotation.yaw;
}

void LocalVehicle_SetRotation(alt::ILocalVehicle* localVehicle, rotation_t rot)
{
    alt::Rotation localVehicleRot;
    localVehicleRot.roll = rot.roll;
    localVehicleRot.pitch = rot.pitch;
    localVehicleRot.yaw = rot.yaw;
    localVehicle->SetRotation(localVehicleRot);
}

uint32_t LocalVehicle_GetStreamingDistance(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetStreamingDistance();
}

void LocalVehicle_SetVisible(alt::ILocalVehicle* localVehicle, uint8_t toggle)
{
    localVehicle->SetVisible(toggle);
}

uint8_t LocalVehicle_IsVisible(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->IsVisible();
}

#ifdef ALT_CLIENT_API
uint32_t LocalVehicle_GetScriptID(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetScriptID();
}

uint32_t LocalVehicle_GetRemoteID(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetRemoteID();
}

uint8_t LocalVehicle_IsRemote(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->IsRemote();
}

uint8_t LocalVehicle_IsStreamedIn(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->IsStreamedIn();
}
#endif
