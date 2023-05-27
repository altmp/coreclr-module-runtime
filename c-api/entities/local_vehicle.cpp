#include "local_vehicle.h"


#ifdef ALT_CLIENT_API
alt::IVehicle* LocalVehicle_GetVehicle(alt::ILocalVehicle* localVehicle)
{
    return dynamic_cast<alt::IVehicle*>(localVehicle);
}

uint32_t LocalVehicle_GetID(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetID();
}

void LocalVehicle_SetModel(alt::ILocalVehicle* localVehicle, uint32_t model)
{
    localVehicle->SetModel(model);
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
