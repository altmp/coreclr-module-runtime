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

EXPORT_CLIENT uint16_t LocalObject_GetID(alt::ILocalObject* localObject);
EXPORT_CLIENT alt::IObject* LocalObject_GetObject(alt::ILocalObject* localObject);
EXPORT_CLIENT void LocalObject_ResetAlpha(alt::ILocalObject* localObject);

EXPORT_CLIENT void LocalObject_SetAlpha(alt::ILocalObject* localObject, uint8_t alpha);

EXPORT_CLIENT void LocalObject_SetModel(alt::ILocalObject* localObject, uint32_t model);

EXPORT_CLIENT uint8_t LocalObject_IsDynamic(alt::ILocalObject* localObject);

EXPORT_CLIENT void LocalObject_SetLodDistance(alt::ILocalObject* localObject, uint16_t distance);

EXPORT_CLIENT uint8_t LocalObject_HasGravity(alt::ILocalObject* localObject);
EXPORT_CLIENT void LocalObject_ToggleGravity(alt::ILocalObject* localObject, uint8_t toggle);

EXPORT_CLIENT void LocalObject_AttachToEntity(alt::ILocalObject* localObject, alt::IEntity* entity, int16_t boneIndex, position_t pos, rotation_t rot, uint8_t useSoftPinning, uint8_t collision, uint8_t fixedRot);
EXPORT_CLIENT void LocalObject_AttachToEntity_ScriptId(alt::ILocalObject* localObject, uint32_t scriptId, int16_t boneIndex, position_t pos, rotation_t rot, uint8_t useSoftPinning, uint8_t collision, uint8_t fixedRot);
EXPORT_CLIENT void LocalObject_Detach(alt::ILocalObject* localObject, uint8_t dynamic);

EXPORT_CLIENT uint8_t LocalObject_IsCollisionEnabled(alt::ILocalObject* localObject);
EXPORT_CLIENT void LocalObject_ToggleCollision(alt::ILocalObject* localObject, uint8_t toggle, uint8_t keepPhysics);

EXPORT_CLIENT void LocalObject_PlaceOnGroundProperly(alt::ILocalObject* localObject);

EXPORT_CLIENT void LocalObject_SetPositionFrozen(alt::ILocalObject* localObject, uint8_t toggle);

EXPORT_CLIENT void LocalObject_ActivatePhysics(alt::ILocalObject* localObject);

EXPORT_CLIENT void LocalObject_SetTextureVariation(alt::ILocalObject* localObject, uint8_t variation);

EXPORT_CLIENT uint8_t LocalObject_IsWorldObject(alt::ILocalObject* localObject);

EXPORT_CLIENT uint8_t LocalObject_IsStreamedIn(alt::ILocalObject* localObject);
EXPORT_CLIENT uint8_t LocalObject_UsesStreaming(alt::ILocalObject* localObject);
EXPORT_CLIENT uint32_t LocalObject_GetStreamingDistance(alt::ILocalObject* localObject);

EXPORT_CLIENT void LocalObject_SetVisible(alt::ILocalObject* localObject, uint8_t toggle);
EXPORT_CLIENT uint8_t LocalObject_IsVisible(alt::ILocalObject* localObject);

EXPORT_CLIENT uint8_t LocalObject_IsWeaponObject(alt::ILocalObject* localObject);

EXPORT_CLIENT void LocalObject_SetTintIndex(alt::ILocalObject* localObject, int32_t tintIndex);
EXPORT_CLIENT int32_t LocalObject_GetTintIndex(alt::ILocalObject* localObject);

EXPORT_CLIENT void LocalObject_GiveComponent(alt::ILocalObject* localObject, int32_t componentType);
EXPORT_CLIENT void LocalObject_RemoveComponent(alt::ILocalObject* localObject, int32_t componentType);

EXPORT_CLIENT void LocalObject_SetComponentTintIndex(alt::ILocalObject* localObject, int32_t componentType, int32_t tintIndex);
EXPORT_CLIENT int32_t LocalObject_GetComponentTintIndex(alt::ILocalObject* localObject, int32_t componentType);
