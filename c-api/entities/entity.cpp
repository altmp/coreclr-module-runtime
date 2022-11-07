#include "entity.h"

uint16_t Entity_GetID(alt::IEntity* entity) {
    return entity->GetID();
}

alt::IWorldObject* Entity_GetWorldObject(alt::IEntity* entity) {
    return dynamic_cast<alt::IWorldObject*>(entity);
}

uint8_t Entity_GetTypeByID(alt::ICore* core, uint16_t id, uint8_t& type) {
    auto entity = core->GetEntityByID(id);
    if (entity == nullptr) return false;
    type = static_cast<uint8_t>(entity->GetType());
    return true;
}


uint32_t Entity_GetModel(alt::IEntity* entity) {
    return entity->GetModel();
}

uint8_t Entity_GetNetOwnerID(alt::IEntity* entity, uint16_t& id) {
    auto owner = entity->GetNetworkOwner();
    if (owner == nullptr) {
        return false;
    }

    id = owner->GetID();
    return true;
}


alt::IPlayer* Entity_GetNetOwner(alt::IEntity* entity) {
    return entity->GetNetworkOwner();
}

void Entity_GetRotation(alt::IEntity* entity, rotation_t& rot) {
    auto vector = entity->GetRotation();
    rot.roll = vector.roll;
    rot.pitch = vector.pitch;
    rot.yaw = vector.yaw;
}


uint8_t Entity_HasStreamSyncedMetaData(alt::IEntity* Entity, const char* key) {
    return Entity->HasStreamSyncedMetaData(key);
}

alt::MValueConst* Entity_GetStreamSyncedMetaData(alt::IEntity* Entity, const char* key) {
    return new alt::MValueConst(Entity->GetStreamSyncedMetaData(key));
}


uint8_t Entity_HasSyncedMetaData(alt::IEntity* Entity, const char* key) {
    return Entity->HasSyncedMetaData(key);
}

alt::MValueConst* Entity_GetSyncedMetaData(alt::IEntity* Entity, const char* key) {
    return new alt::MValueConst(Entity->GetSyncedMetaData(key));
}

#ifdef ALT_SERVER_API
void Entity_SetNetOwner(alt::IEntity* entity, alt::IPlayer* networkOwnerPlayer, uint8_t disableMigration) {
    entity->SetNetworkOwner(networkOwnerPlayer, disableMigration);
}

void Entity_SetRotation(alt::IEntity* entity, rotation_t rot) {
    alt::Rotation rotation;
    rotation.roll = rot.roll;
    rotation.pitch = rot.pitch;
    rotation.yaw = rot.yaw;
    entity->SetRotation(rotation);
}

void Entity_SetStreamSyncedMetaData(alt::IEntity* entity, const char* key, alt::MValueConst* val) {
    if (val == nullptr) return;
    entity->SetStreamSyncedMetaData(key, val->Get()->Clone());
}

void Entity_DeleteStreamSyncedMetaData(alt::IEntity* entity, const char* key) {
    entity->DeleteStreamSyncedMetaData(key);
}

void Entity_SetSyncedMetaData(alt::IEntity* entity, const char* key, alt::MValueConst* val) {
    if (val == nullptr) return;
    entity->SetSyncedMetaData(key, val->Get()->Clone());
}

void Entity_DeleteSyncedMetaData(alt::IEntity* entity, const char* key) {
    entity->DeleteSyncedMetaData(key);
}

uint8_t Entity_GetVisible(alt::IEntity* entity) {
    return entity->GetVisible();
}

void Entity_SetVisible(alt::IEntity* entity, uint8_t state) {
    entity->SetVisible(state);
}

uint8_t Entity_GetStreamed(alt::IEntity* entity) {
    return entity->GetStreamed();
}

void Entity_SetStreamed(alt::IEntity* entity, uint8_t state) {
    entity->SetStreamed(state);
}

uint8_t Entity_IsFrozen(alt::IEntity* entity) {
    return entity->IsFrozen();
}

void Entity_SetFrozen(alt::IEntity* entity, uint8_t state) {
    entity->SetFrozen(state);
}

uint8_t Entity_HasCollision(alt::IEntity* entity) {
    return entity->HasCollision();
}

void Entity_SetCollision(alt::IEntity* entity, uint8_t state) {
    entity->SetCollision(state);
}
#endif

#ifdef ALT_CLIENT_API
int32_t Entity_GetScriptID(alt::IEntity* entity) {
    return entity->GetScriptGuid();
}
#endif
