//
// Created by Till Schreiber on 2022-08-02.
//

#include "local_object.h"

#include "../utils/macros.h"

CAPI_START()

#ifdef ALT_CLIENT_API

uint16_t LocalObject_GetID(alt::ILocalObject* localObject) {
    return localObject->GetID();
}

alt::IObject* LocalObject_GetObject(alt::ILocalObject* localObject) {
    return dynamic_cast<alt::IObject*>(localObject);
}

void LocalObject_SetAlpha(alt::ILocalObject* localObject, uint8_t alpha) {
    localObject->SetAlpha(alpha);
}

void LocalObject_SetModel(alt::ILocalObject* localObject, uint32_t model) {
    localObject->SetModel(model);
}

void LocalObject_ResetAlpha(alt::ILocalObject* localObject) {
    localObject->ResetAlpha();
}

uint8_t LocalObject_IsDynamic(alt::ILocalObject* localObject) {
    return localObject->IsDynamic();
}

void LocalObject_SetLodDistance(alt::ILocalObject* localObject, uint16_t distance) {
    localObject->SetLodDistance(distance);
}

uint8_t LocalObject_HasGravity(alt::ILocalObject* localObject) {
    return localObject->HasGravity();
}

void LocalObject_ToggleGravity(alt::ILocalObject* localObject, uint8_t toggle) {
    localObject->ToggleGravity(toggle);
}

void LocalObject_AttachToEntity(alt::ILocalObject* localObject, alt::IEntity* entity, int16_t boneIndex, position_t pos, rotation_t rot, uint8_t useSoftPinning, uint8_t collision, uint8_t fixedRot) {
    alt::Position position{pos.x, pos.y, pos.z};
    alt::Rotation rotation{rot.roll, rot.pitch, rot.yaw};
    localObject->AttachToEntity(entity, boneIndex, position, rotation, useSoftPinning, collision, fixedRot);
}

void LocalObject_AttachToEntity_ScriptId(alt::ILocalObject* localObject, uint32_t scriptId, int16_t boneIndex, position_t pos, rotation_t rot, uint8_t useSoftPinning, uint8_t collision, uint8_t fixedRot) {
    alt::Position position{pos.x, pos.y, pos.z};
    alt::Rotation rotation{rot.roll, rot.pitch, rot.yaw};
    localObject->AttachToEntity(scriptId, boneIndex, position, rotation, useSoftPinning, collision, fixedRot);
}

void LocalObject_Detach(alt::ILocalObject* localObject, uint8_t dynamic) {
    localObject->Detach(dynamic);
}

uint8_t LocalObject_IsCollisionEnabled(alt::ILocalObject* localObject) {
    return localObject->IsCollisionEnabled();
}

void LocalObject_ToggleCollision(alt::ILocalObject* localObject, uint8_t toggle, uint8_t keepPhysics) {
    localObject->ToggleCollision(toggle, keepPhysics);
}

void LocalObject_PlaceOnGroundProperly(alt::ILocalObject* localObject) {
    localObject->PlaceOnGroundProperly();
}

void LocalObject_SetPositionFrozen(alt::ILocalObject* localObject, uint8_t toggle) {
    localObject->SetPositionFrozen(toggle);
}

void LocalObject_ActivatePhysics(alt::ILocalObject* localObject) {
    localObject->ActivatePhysics();
}

void LocalObject_SetTextureVariation(alt::ILocalObject* localObject, uint8_t variation) {
    localObject->SetTextureVariation(variation);
}

uint8_t LocalObject_IsWorldObject(alt::ILocalObject* localObject) {
    return localObject->IsWorldObject();
}

uint32_t LocalObject_GetStreamingDistance(alt::ILocalObject* localObject)
{
    return localObject->GetStreamingDistance();
}

void LocalObject_SetVisible(alt::ILocalObject* localObject, uint8_t toggle)
{
    localObject->SetVisible(toggle);
}

uint8_t LocalObject_IsVisible(alt::ILocalObject* localObject)
{
    return localObject->IsVisible();
}

uint8_t LocalObject_IsStreamedIn(alt::ILocalObject* localObject)
{
    return localObject->IsStreamedIn();
}

uint8_t LocalObject_UsesStreaming(alt::ILocalObject* localObject)
{
    return localObject->UsesStreaming();
}

uint8_t LocalObject_IsWeaponObject(alt::ILocalObject* localObject)
{
    return localObject->IsWeaponObject();
}

void LocalObject_SetTintIndex(alt::ILocalObject* localObject, int32_t tintIndex)
{
    localObject->SetTintIndex(tintIndex);
}

int32_t LocalObject_GetTintIndex(alt::ILocalObject* localObject)
{
    return localObject->GetTintIndex();
}

void LocalObject_GiveComponent(alt::ILocalObject* localObject, int32_t componentType)
{
    localObject->GiveComponent(componentType);
}

void LocalObject_RemoveComponent(alt::ILocalObject* localObject, int32_t componentType)
{
    localObject->RemoveComponent(componentType);
}

void LocalObject_SetComponentTintIndex(alt::ILocalObject* localObject, int32_t componentType, int32_t tintIndex)
{
    localObject->SetComponentTintIndex(componentType, tintIndex);
}

int32_t LocalObject_GetComponentTintIndex(alt::ILocalObject* localObject, int32_t componentType)
{
    return localObject->GetComponentTintIndex(componentType);
}

#endif

CAPI_END()