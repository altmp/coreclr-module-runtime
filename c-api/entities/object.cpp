#include "object.h"

#include "../utils/macros.h"

CAPI_START()

uint16_t Object_GetID(alt::IObject* object)
{
    return object->GetID();
}

alt::IEntity* Object_GetEntity(alt::IObject* object)
{
    return dynamic_cast<alt::IEntity*>(object);
}

uint8_t Object_GetAlpha(alt::IObject* object)
{
    return object->GetAlpha();
}

uint8_t Object_GetTextureVariation(alt::IObject* object)
{
    return object->GetTextureVariation();
}

uint16_t Object_GetLodDistance(alt::IObject* object)
{
    return object->GetLodDistance();
}

#ifdef ALT_SERVER_API
void Object_ActivatePhysics(alt::IObject* object)
{
    object->ActivatePhysics();
}

void Object_PlaceOnGroundProperly(alt::IObject* object)
{
    object->PlaceOnGroundProperly();
}

void Object_SetAlpha(alt::IObject* object, uint8_t alpha)
{
    object->SetAlpha(alpha);
}

void Object_SetTextureVariation(alt::IObject* object, uint8_t textureVariation)
{
    object->SetTextureVariation(textureVariation);
}

void Object_SetLodDistance(alt::IObject* object, uint16_t lodDistance)
{
    object->SetLodDistance(lodDistance);
}
#endif


CAPI_END()