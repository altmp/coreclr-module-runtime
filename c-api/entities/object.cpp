//
// Created by Till Schreiber on 2022-08-02.
//

#include "object.h"

uint16_t Object_GetID(alt::IObject* object) {
    return object->GetID();
}

alt::IEntity* Object_GetEntity(alt::IObject* object) {
    return dynamic_cast<alt::IEntity*>(object);
}

uint8_t Object_GetAlpha(alt::IObject* object) {
    return object->GetAlpha();
}

void Object_SetAlpha(alt::IObject* object, uint8_t alpha) {
    object->SetAlpha(alpha);
}

void Object_ResetAlpha(alt::IObject* object) {
    object->ResetAlpha();
}

uint8_t Object_IsDynamic(alt::IObject* object) {
    return object->IsDynamic();
}

uint16_t Object_GetLodDistance(alt::IObject* object) {
    return object->GetLodDistance();
}

void Object_SetLodDistance(alt::IObject* object, uint16_t distance) {
    object->SetLodDistance(distance);
}

uint8_t Object_HasGravity(alt::IObject* object) {
    return object->HasGravity();
}

void Object_ToggleGravity(alt::IObject* object, uint8_t toggle) {
    object->ToggleGravity(toggle);
}

void Object_AttachToEntity(alt::IObject* object, alt::IEntity* entity, int16_t bone, position_t pos, rotation_t rot, uint8_t useSoftPinning, uint8_t collision, uint8_t fixedRot) {
    alt::Position position{pos.x, pos.y, pos.z};
    alt::Rotation rotation{rot.roll, rot.pitch, rot.yaw};
    object->AttachToEntity(entity, bone, position, rotation, useSoftPinning, collision, fixedRot);
}

void Object_Detach(alt::IObject* object, uint8_t dynamic) {
    object->Detach(dynamic);
}

uint8_t Object_IsCollisionEnabled(alt::IObject* object) {
    return object->IsCollisionEnabled();
}

void Object_ToggleCollision(alt::IObject* object, uint8_t toggle, uint8_t keepPhysics) {
    object->ToggleCollision(toggle, keepPhysics);
}

void Object_PlaceOnGroundProperly(alt::IObject* object) {
    object->PlaceOnGroundProperly();
}

void Object_SetPositionFrozen(alt::IObject* object, uint8_t toggle) {
    object->SetPositionFrozen(toggle);
}

void Object_ActivatePhysics(alt::IObject* object) {
    object->ActivatePhysics();
}

uint8_t Object_GetTextureVariation(alt::IObject* object) {
    return object->GetTextureVariation();
}

void Object_SetTextureVariation(alt::IObject* object, uint8_t variation) {
    object->SetTextureVariation(variation);
}

uint8_t Object_IsWorldObject(alt::IObject* object) {
    return object->IsWorldObject();
}

#ifdef ALT_CLIENT_API

uint8_t Object_IsRemote(alt::IObject* object) {
    return object->IsRemote();
}

#endif