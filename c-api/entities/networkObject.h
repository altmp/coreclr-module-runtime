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

EXPORT_SHARED uint16_t NetworkObject_GetID(alt::INetworkObject* networkObject);
EXPORT_SHARED alt::IEntity* NetworkObject_GetEntity(alt::INetworkObject* networkObject);

EXPORT_SHARED uint8_t NetworkObject_GetAlpha(alt::INetworkObject* networkObject);
EXPORT_SHARED uint8_t NetworkObject_GetTextureVariation(alt::INetworkObject* networkObject);
EXPORT_SHARED uint16_t NetworkObject_GetLodDistance(alt::INetworkObject* networkObject);

EXPORT_SERVER void NetworkObject_ActivatePhysics(alt::INetworkObject* networkObject);
EXPORT_SERVER void NetworkObject_PlaceOnGroundProperly(alt::INetworkObject* networkObject);
EXPORT_SERVER void NetworkObject_SetAlpha(alt::INetworkObject* networkObject, uint8_t alpha);
EXPORT_SERVER void NetworkObject_SetTextureVariation(alt::INetworkObject* networkObject, uint8_t textureVariation);
EXPORT_SERVER void NetworkObject_SetLodDistance(alt::INetworkObject* networkObject, uint16_t lodDistance);
