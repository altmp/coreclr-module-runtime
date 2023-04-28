#include "local_ped.h"

alt::IWorldObject* LocalPed_GetWorldObject(alt::ILocalPed* localPed)
{
    return dynamic_cast<alt::IWorldObject*>(localPed);
}

uint32_t LocalPed_GetID(alt::ILocalPed* localPed)
{
    return localPed->GetID();
}

uint32_t LocalPed_GetModel(alt::ILocalPed* localPed)
{
    return localPed->GetModel();
}

void LocalPed_GetRotation(alt::ILocalPed* localPed, rotation_t& rot)
{
    auto localPedRotation = localPed->GetRotation();
    rot.roll = localPedRotation.roll;
    rot.pitch = localPedRotation.pitch;
    rot.yaw = localPedRotation.yaw;
}

void LocalPed_SetRotation(alt::ILocalPed* localPed, rotation_t rot)
{
    alt::Rotation localPedRot;
    localPedRot.roll = rot.roll;
    localPedRot.pitch = rot.pitch;
    localPedRot.yaw = rot.yaw;
    localPed->SetRotation(localPedRot);
}

uint32_t LocalPed_GetStreamingDistance(alt::ILocalPed* localPed)
{
    return localPed->GetStreamingDistance();
}

void LocalPed_SetVisible(alt::ILocalPed* localPed, uint8_t toggle)
{
    localPed->SetVisible(toggle);
}

uint8_t LocalPed_IsVisible(alt::ILocalPed* localPed)
{
    return localPed->IsVisible();
}

#ifdef ALT_CLIENT_API
uint32_t LocalPed_GetScriptID(alt::ILocalPed* localPed)
{
    return localPed->GetScriptID();
}

uint32_t LocalPed_GetRemoteID(alt::ILocalPed* localPed)
{
    return localPed->GetRemoteID();
}

uint8_t LocalPed_IsRemote(alt::ILocalPed* localPed)
{
    return localPed->IsRemote();
}

uint8_t LocalPed_IsStreamedIn(alt::ILocalPed* localPed)
{
    return localPed->IsStreamedIn();
}
#endif
