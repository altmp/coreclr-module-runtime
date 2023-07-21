#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "../data/types.h"
#include "../utils/export.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_SHARED uint16_t Object_GetID(alt::IObject* object);
EXPORT_SHARED alt::IEntity* Object_GetEntity(alt::IObject* object);

EXPORT_SHARED uint8_t Object_GetAlpha(alt::IObject* object);
EXPORT_SHARED uint8_t Object_GetTextureVariation(alt::IObject* object);
EXPORT_SHARED uint16_t Object_GetLodDistance(alt::IObject* object);

EXPORT_SERVER void Object_ActivatePhysics(alt::IObject* object);
EXPORT_SERVER void Object_PlaceOnGroundProperly(alt::IObject* object);
EXPORT_SERVER void Object_SetAlpha(alt::IObject* object, uint8_t alpha);
EXPORT_SERVER void Object_SetTextureVariation(alt::IObject* object, uint8_t textureVariation);
EXPORT_SERVER void Object_SetLodDistance(alt::IObject* object, uint16_t lodDistance);
