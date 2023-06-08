#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "../data/types.h"
#include "../data/invoker.h"
#include "../utils/export.h"

#ifdef ALT_SERVER_API
#include <CSharpResourceImpl.h>
#elif ALT_CLIENT_API
#include "../../client/src/runtime/CSharpResourceImpl.h"
#endif

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_CLIENT uint16_t Object_GetID(alt::IObject* object);
EXPORT_CLIENT alt::IEntity* Object_GetEntity(alt::IObject* object);
EXPORT_CLIENT void Object_ResetAlpha(alt::IObject* object);

EXPORT_CLIENT uint8_t Object_GetAlpha(alt::IObject* object);
EXPORT_CLIENT void Object_SetAlpha(alt::IObject* object, uint8_t alpha);

EXPORT_CLIENT void Object_SetModel(alt::IObject* object, uint32_t model);

EXPORT_CLIENT uint8_t Object_IsDynamic(alt::IObject* object);

EXPORT_CLIENT uint16_t Object_GetLodDistance(alt::IObject* object);
EXPORT_CLIENT void Object_SetLodDistance(alt::IObject* object, uint16_t distance);

EXPORT_CLIENT uint8_t Object_HasGravity(alt::IObject* object);
EXPORT_CLIENT void Object_ToggleGravity(alt::IObject* object, uint8_t toggle);

EXPORT_CLIENT void Object_AttachToEntity(alt::IObject* object, alt::IEntity* entity, int16_t bone, position_t pos, rotation_t rot, uint8_t useSoftPinning, uint8_t collision, uint8_t fixedRot);
EXPORT_CLIENT void Object_AttachToEntity_ScriptId(alt::IObject* object, uint32_t scriptId, int16_t bone, position_t pos, rotation_t rot, uint8_t useSoftPinning, uint8_t collision, uint8_t fixedRot);
EXPORT_CLIENT void Object_Detach(alt::IObject* object, uint8_t dynamic);

EXPORT_CLIENT uint8_t Object_IsCollisionEnabled(alt::IObject* object);
EXPORT_CLIENT void Object_ToggleCollision(alt::IObject* object, uint8_t toggle, uint8_t keepPhysics);

EXPORT_CLIENT void Object_PlaceOnGroundProperly(alt::IObject* object);

EXPORT_CLIENT void Object_SetPositionFrozen(alt::IObject* object, uint8_t toggle);

EXPORT_CLIENT void Object_ActivatePhysics(alt::IObject* object);

EXPORT_CLIENT uint8_t Object_GetTextureVariation(alt::IObject* object);
EXPORT_CLIENT void Object_SetTextureVariation(alt::IObject* object, uint8_t variation);

EXPORT_CLIENT uint8_t Object_IsWorldObject(alt::IObject* object);

EXPORT_CLIENT uint8_t Object_IsStreamedIn(alt::IObject* object);
EXPORT_CLIENT uint8_t Object_UsesStreaming(alt::IObject* object);
EXPORT_CLIENT uint32_t Object_GetStreamingDistance(alt::IObject* object);

EXPORT_CLIENT void Object_SetVisible(alt::IObject* object, uint8_t toggle);
EXPORT_CLIENT uint8_t Object_IsVisible(alt::IObject* object);

EXPORT_CLIENT uint8_t Object_IsWeaponObject(alt::IObject* object);

EXPORT_CLIENT void Object_SetTintIndex(alt::IObject* object, int32_t tintIndex);
EXPORT_CLIENT int32_t Object_GetTintIndex(alt::IObject* object);

EXPORT_CLIENT void Object_GiveComponent(alt::IObject* object, int32_t componentType);
EXPORT_CLIENT void Object_RemoveComponent(alt::IObject* object, int32_t componentType);

EXPORT_CLIENT void Object_SetComponentTintIndex(alt::IObject* object, int32_t componentType, int32_t tintIndex);
EXPORT_CLIENT int32_t Object_GetComponentTintIndex(alt::IObject* object, int32_t componentType);
