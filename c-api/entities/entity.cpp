#include "entity.h"

#include "../mvalue.h"
#include "../utils/macros.h"

CAPI_START()

uint32_t Entity_GetID(alt::IEntity* entity) {
    return entity->GetID();
}

alt::IWorldObject* Entity_GetWorldObject(alt::IEntity* entity) {
    return dynamic_cast<alt::IWorldObject*>(entity);
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
    return AllocMValue(Entity->GetStreamSyncedMetaData(key));
}

void Entity_SetRotation(alt::IEntity* entity, rotation_t rot) {
    alt::Rotation rotation;
    rotation.roll = rot.roll;
    rotation.pitch = rot.pitch;
    rotation.yaw = rot.yaw;
    entity->SetRotation(rotation);
}

uint8_t Entity_IsFrozen(alt::IEntity* entity) {
    return entity->IsFrozen();
}

void Entity_SetFrozen(alt::IEntity* entity, uint8_t state) {
    entity->SetFrozen(state);
}

#ifdef ALT_SERVER_API
void Entity_SetNetOwner(alt::IEntity* entity, alt::IPlayer* networkOwnerPlayer, uint8_t disableMigration) {
    entity->SetNetworkOwner(networkOwnerPlayer, disableMigration);
}

void Entity_SetStreamSyncedMetaData(alt::IEntity* entity, const char* key, alt::MValueConst* val) {
    if (val == nullptr) return;
    entity->SetStreamSyncedMetaData(key, val->get()->Clone());
}

void Entity_DeleteStreamSyncedMetaData(alt::IEntity* entity, const char* key) {
    entity->DeleteStreamSyncedMetaData(key);
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

uint8_t Entity_HasCollision(alt::IEntity* entity) {
    return entity->HasCollision();
}

void Entity_SetCollision(alt::IEntity* entity, uint8_t state) {
    entity->SetCollision(state);
}

void Entity_AttachToEntity(alt::IEntity* entity, alt::IEntity* secondEntity, uint16_t otherBoneId, uint16_t ownBoneId,
    position_t pos, rotation_t rot, uint8_t collision, uint8_t noFixedRot)
{
    alt::Position position{pos.x, pos.y, pos.z};
    alt::Rotation rotation{rot.roll, rot.pitch, rot.yaw};
    entity->AttachToEntity(secondEntity, otherBoneId, ownBoneId, position, rotation, collision, noFixedRot);
}

void Entity_AttachToEntity_BoneString(alt::IEntity* entity, alt::IEntity* secondEntity, const char* otherBone,
    const char* ownBone, position_t pos, rotation_t rot, uint8_t collision, uint8_t noFixedRot)
{
    alt::Position position{pos.x, pos.y, pos.z};
    alt::Rotation rotation{rot.roll, rot.pitch, rot.yaw};
    entity->AttachToEntity(secondEntity, otherBone, ownBone, position, rotation, collision, noFixedRot);
}

void Entity_Detach(alt::IEntity* entity)
{
    entity->Detach();
}

uint32_t Entity_GetTimestamp(alt::IEntity* entity)
{
    return entity->GetTimestamp();
}

void Entity_SetMultipleStreamSyncedMetaData(alt::IEntity* entity, const char* keys[], alt::MValueConst* values[],
    uint64_t size)
{
    std::unordered_map<std::string, alt::MValue> data = {};

    for (uint64_t i = 0; i < size; i++) {
        if (values[i]->get() == nullptr) continue;
        data[keys[i]] = values[i]->get()->Clone();
    }

    entity->SetMultipleStreamSyncedMetaData(data);
}

uint32_t Entity_GetStreamingDistance(alt::IEntity* entity)
{
    return entity->GetStreamingDistance();
}

void Entity_SetStreamingDistance(alt::IEntity* entity, uint32_t streamingDistance)
{
    entity->SetStreamingDistance(streamingDistance);
}
#endif

#ifdef ALT_CLIENT_API
uint32_t Entity_GetScriptID(alt::IEntity* entity) {
    return entity->GetScriptID();
}

void Entity_GetSyncInfo(alt::IEntity* entity, sync_info_t& syncInfo)
{
    auto entitySyncInfo = entity->GetSyncInfo();

    sync_info_t outSyncInfo;

    outSyncInfo.active = entitySyncInfo.active;
    outSyncInfo.receivedTick = entitySyncInfo.receivedTick;
    outSyncInfo.fullyReceivedTick = entitySyncInfo.fullyReceivedTick;
    outSyncInfo.sendTick = entitySyncInfo.sendTick;
    outSyncInfo.ackedSendTick = entitySyncInfo.ackedSendTick;
    outSyncInfo.propertyCount = entitySyncInfo.propertyCount;
    outSyncInfo.componentCount = entitySyncInfo.componentCount;

    const auto componentPropertyIndex = new uint32_t*[entitySyncInfo.componentCount];
    const auto propertyUpdateCount = new uint32_t[entitySyncInfo.componentCount];
    uint32_t lastPropertyIdx = 0;
    for (uint32_t i = 0; i < entitySyncInfo.componentCount; i++)
    {
        const uint32_t endIdx = i == entitySyncInfo.componentCount - 1
        ? entitySyncInfo.propertyCount
        : entitySyncInfo.componentPropertyIndex[i];

        uint32_t* propertiesUpdateTick = new uint32_t[endIdx - lastPropertyIdx];
        for (uint32_t j = lastPropertyIdx; j < endIdx; j++)
        {
            propertiesUpdateTick[j-lastPropertyIdx] = entitySyncInfo.propertiesUpdateTick[j];
        }
        propertyUpdateCount[i] = endIdx - lastPropertyIdx;
        componentPropertyIndex[i] = propertiesUpdateTick;
        lastPropertyIdx = endIdx;
    }

    outSyncInfo.propertyUpdateCount = propertyUpdateCount;
    outSyncInfo.propertyUpdateTicks = componentPropertyIndex;

    syncInfo = outSyncInfo;
}
#endif

CAPI_END()
