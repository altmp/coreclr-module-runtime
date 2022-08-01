//
// Created by Till Schreiber on 2022-08-02.
//

#include "object.h"

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

void Object_SetDynamic(alt::IObject* object, uint8_t dynamic) {
    object->SetDynamic(dynamic);
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

uint8_t Object_IsOnFire(alt::IObject* object) {
    return object->IsOnFire();
}

uint32_t Object_StartFire(alt::IObject* object) {
    return object->StartFire();
}

void Object_StopFire(alt::IObject* object) {
    object->StopFire();
}

#ifdef ALT_CLIENT_API

uint8_t Object_IsRemote(alt::IObject* object) {
    return object->IsRemote();
}

#endif