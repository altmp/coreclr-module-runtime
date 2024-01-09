#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "../utils/export.h"
#include "../data/types.h"
#include "../data/sync_info.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_SHARED uint32_t Entity_GetID(alt::IEntity* entity);
EXPORT_SHARED alt::IWorldObject* Entity_GetWorldObject(alt::IEntity* entity);

EXPORT_SHARED uint32_t Entity_GetModel(alt::IEntity* entity);
EXPORT_SHARED uint8_t Entity_GetNetOwnerID(alt::IEntity* entity, uint16_t& id);
EXPORT_SHARED alt::IPlayer* Entity_GetNetOwner(alt::IEntity* entity);
EXPORT_SHARED void Entity_GetRotation(alt::IEntity* entity, rotation_t& rot);

EXPORT_SHARED uint8_t Entity_HasStreamSyncedMetaData(alt::IEntity* Entity, const char* key);
EXPORT_SHARED alt::MValueConst* Entity_GetStreamSyncedMetaData(alt::IEntity* Entity, const char* key);

EXPORT_SERVER void Entity_SetNetOwner(alt::IEntity* entity, alt::IPlayer* networkOwnerPlayer, uint8_t disableMigration);
EXPORT_SHARED void Entity_SetRotation(alt::IEntity* entity, rotation_t rot);

EXPORT_SERVER void Entity_SetStreamSyncedMetaData(alt::IEntity* entity, const char* key, alt::MValueConst* val);
EXPORT_SERVER void Entity_DeleteStreamSyncedMetaData(alt::IEntity* entity, const char* key);

EXPORT_SERVER uint8_t Entity_GetVisible(alt::IEntity* entity);
EXPORT_SERVER void Entity_SetVisible(alt::IEntity* entity, uint8_t state);

EXPORT_SERVER uint8_t Entity_GetStreamed(alt::IEntity* entity);
EXPORT_SERVER void Entity_SetStreamed(alt::IEntity* entity, uint8_t state);

EXPORT_CLIENT uint32_t Entity_GetScriptID(alt::IEntity* entity);
EXPORT_CLIENT void Entity_GetSyncInfo(alt::IEntity* entity, /** nint* */  sync_info_t& syncInfo);

EXPORT_SHARED uint8_t Entity_IsFrozen(alt::IEntity* entity);
EXPORT_SHARED void Entity_SetFrozen(alt::IEntity* entity, uint8_t state);

EXPORT_SERVER uint8_t Entity_HasCollision(alt::IEntity* entity);
EXPORT_SERVER void Entity_SetCollision(alt::IEntity* entity, uint8_t state);

EXPORT_SERVER void Entity_AttachToEntity(alt::IEntity* entity, alt::IEntity* secondEntity, uint16_t otherBoneId, uint16_t ownBoneId, position_t pos, rotation_t rot, uint8_t collision, uint8_t noFixedRot);
EXPORT_SERVER void Entity_AttachToEntity_BoneString(alt::IEntity* entity, alt::IEntity* secondEntity, const char* otherBone, const char* ownBone, position_t pos, rotation_t rot, uint8_t collision, uint8_t noFixedRot);
EXPORT_SERVER void Entity_Detach(alt::IEntity* entity);

EXPORT_SERVER void Entity_SetMultipleStreamSyncedMetaData(alt::IEntity* entity, const char* keys[], alt::MValueConst* values[], uint64_t size);

EXPORT_SERVER uint32_t Entity_GetTimestamp(alt::IEntity* entity);

EXPORT_SERVER uint32_t Entity_GetStreamingDistance(alt::IEntity* entity);
EXPORT_SERVER void Entity_SetStreamingDistance(alt::IEntity* entity, uint32_t streamingDistance);
