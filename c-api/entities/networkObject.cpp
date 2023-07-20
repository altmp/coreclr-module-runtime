#include "networkObject.h"

uint16_t NetworkObject_GetID(alt::IObject* networkObject)
{
    return networkObject->GetID();
}

alt::IEntity* NetworkObject_GetEntity(alt::IObject* networkObject)
{
    return dynamic_cast<alt::IEntity*>(networkObject);
}

uint8_t NetworkObject_GetAlpha(alt::IObject* networkObject)
{
    return networkObject->GetAlpha();
}

uint8_t NetworkObject_GetTextureVariation(alt::IObject* networkObject)
{
    return networkObject->GetTextureVariation();
}

uint16_t NetworkObject_GetLodDistance(alt::IObject* networkObject)
{
    return networkObject->GetLodDistance();
}

#ifdef ALT_SERVER_API
void NetworkObject_ActivatePhysics(alt::INetworkObject* networkObject)
{
    networkObject->ActivatePhysics();
}

void NetworkObject_PlaceOnGroundProperly(alt::INetworkObject* networkObject)
{
    networkObject->PlaceOnGroundProperly();
}

void NetworkObject_SetAlpha(alt::INetworkObject* networkObject, uint8_t alpha)
{
    networkObject->SetAlpha(alpha);
}

void NetworkObject_SetTextureVariation(alt::INetworkObject* networkObject, uint8_t textureVariation)
{
    networkObject->SetTextureVariation(textureVariation);
}

void NetworkObject_SetLodDistance(alt::INetworkObject* networkObject, uint16_t lodDistance)
{
    networkObject->SetLodDistance(lodDistance);
}
#endif
