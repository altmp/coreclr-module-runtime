#include "core.h"
#include "mvalue.h"
#include "utils/strings.h"
#include "data/config_node_data.h"
#include <vector>

#include "data/weapon_model_info.h"
#include "utils/entity.h"
#include "utils/macros.h"
#include "utils/uint.h"

CAPI_START()

void Core_LogInfo(alt::ICore* core, const char* str) {
    core->LogInfo(str);
}

void Core_LogDebug(alt::ICore* core, const char* str) {
    core->LogDebug(str);
}

void Core_LogWarning(alt::ICore* core, const char* str) {
    core->LogWarning(str);
}

void Core_LogError(alt::ICore* core, const char* str) {
    core->LogError(str);
}

void Core_LogColored(alt::ICore* core, const char* str) {
    core->LogColored(str);
}

alt::MValueConst* Core_CreateMValueNil(alt::ICore* core) {
    auto mValue = core->CreateMValueNil();
    return AllocMValue(mValue);
}

alt::MValueConst* Core_CreateMValueBool(alt::ICore* core, uint8_t value) {
    auto mValue = core->CreateMValueBool(value);
    return AllocMValue(mValue);
}

alt::MValueConst* Core_CreateMValueInt(alt::ICore* core, int64_t value) {
    auto mValue = core->CreateMValueInt(value);
    return AllocMValue(mValue);
}

alt::MValueConst* Core_CreateMValueUInt(alt::ICore* core, uint64_t value) {
    auto mValue = core->CreateMValueUInt(value);
    return AllocMValue(mValue);
}

alt::MValueConst* Core_CreateMValueDouble(alt::ICore* core, double value) {
    auto mValue = core->CreateMValueDouble(value);
    return AllocMValue(mValue);
}

alt::MValueConst* Core_CreateMValueString(alt::ICore* core, const char* value) {
    auto mValue = core->CreateMValueString(value);

    return AllocMValue(mValue);
}

alt::MValueConst* Core_CreateMValueList(alt::ICore* core, alt::MValueConst* val[], uint64_t size) {
    auto mValueConst = core->CreateMValueList(size);
    auto mValue = mValueConst;
    for (uint64_t i = 0; i < size; i++) {
        auto mValueElement = val[i];
        if (mValueElement == nullptr || mValueElement->get() == nullptr) {
            mValue->Set(i, core->CreateMValueNil());
        } else {
            mValue->Set(i, mValueElement->get()->Clone());
        }
    }
    return AllocMValue(std::move(mValue));
}

alt::MValueConst* Core_CreateMValueDict(alt::ICore* core, const char* keys[], alt::MValueConst* val[], uint64_t size) {
    auto mValueConst = core->CreateMValueDict();
    auto mValue = mValueConst;
    for (uint64_t i = 0; i < size; i++) {
        auto mValueElement = val[i];
        if (mValueElement == nullptr || mValueElement->get() == nullptr) {
            mValue->Set(keys[i], core->CreateMValueNil());
        } else {
            auto element = mValueElement->get()->Clone();
            mValue->Set(keys[i], element);
        }
    }
    return AllocMValue(std::move(mValue));
}

alt::MValueConst* Core_CreateMValueBaseObject(alt::ICore* core, alt::IBaseObject* value) {
    auto mValue = core->CreateMValueBaseObject(value);
    return AllocMValue(mValue);
}

alt::MValueConst* Core_CreateMValueVector3(alt::ICore* core, position_t value) {
    alt::Vector3f vector3F;
    vector3F[0] = value.x;
    vector3F[1] = value.y;
    vector3F[2] = value.z;
    alt::MValueConst mValue = core->CreateMValueVector3(vector3F);
    return AllocMValue(std::move(mValue));
}

alt::MValueConst* Core_CreateMValueVector2(alt::ICore* core, vector2_t value) {
    alt::Vector2f vector2F;
    vector2F[0] = value.x;
    vector2F[1] = value.y;
    alt::MValueConst mValue = core->CreateMValueVector2(vector2F);
    return AllocMValue(std::move(mValue));
}

alt::MValueConst* Core_CreateMValueByteArray(alt::ICore* core, uint64_t size, const void* data) {
    auto byteArray = (const uint8_t*) data;
    alt::MValueConst mValue = core->CreateMValueByteArray(byteArray, size);
    return AllocMValue(std::move(mValue));
}

alt::MValueConst* Core_CreateMValueRgba(alt::ICore* core, rgba_t value) {
    alt::RGBA rgba;
    rgba.r = value.r;
    rgba.g = value.g;
    rgba.b = value.b;
    rgba.a = value.a;
    alt::MValueConst mValue = core->CreateMValueRGBA(rgba);
    return AllocMValue(std::move(mValue));
}

alt::MValueConst* Core_CreateMValueFunction(alt::ICore* core, CustomInvoker* value) {
    alt::MValueConst mValue = core->CreateMValueFunction(value);
    return AllocMValue(std::move(mValue));
}

uint64_t Core_GetMValueSize(alt::ICore* core, alt::MValueConst* args)
{
    return core->GetMValueSize(args->get()->Clone());
}

uint64_t Core_GetMValueArgsSize(alt::ICore* core, alt::MValueConst* args[], int size)
{
    alt::MValueArgs mValues = alt::MValueArgs(size);
    for (int i = 0; i < size; i++) {
        ToMValueArg(mValues, core, args[i], i);
    }
    return core->GetMValueArgsSize(mValues);
}

alt::IPlayer** Core_GetPlayers(alt::ICore* core, uint64_t& size) {
    auto players = core->GetBaseObjects(alt::IBaseObject::Type::PLAYER);
    size = players.size();
    auto out = new alt::IPlayer*[size];
    for (auto i = 0; i < size; i++) {
        out[i] = dynamic_cast<alt::IPlayer*>(players[i]);
    }

    return out;
}

alt::IVehicle** Core_GetVehicles(alt::ICore* core, uint64_t& size) {
    auto vehiclesArray = core->GetBaseObjects(alt::IBaseObject::Type::VEHICLE);
    size = vehiclesArray.size();
    auto out = new alt::IVehicle*[size];
    for (uint64_t i = 0; i < size; i++) {
        out[i] = dynamic_cast<alt::IVehicle*>(vehiclesArray[i]);
    }
    return out;
}
alt::IPed** Core_GetPeds(alt::ICore* core, uint64_t& size) {
    auto pedsArray = core->GetBaseObjects(alt::IBaseObject::Type::PED);
    size = pedsArray.size();
    auto out = new alt::IPed*[size];
    for (uint64_t i = 0; i < size; i++) {
        out[i] = dynamic_cast<alt::IPed*>(pedsArray[i]);
    }

    return out;
}

alt::IVirtualEntity** Core_GetVirtualEntities(alt::ICore* core, uint64_t& size)
{
    auto virtualEntitiyArray = core->GetBaseObjects(alt::IBaseObject::Type::VIRTUAL_ENTITY);
    size = virtualEntitiyArray.size();
    auto out = new alt::IVirtualEntity*[size];
    for (uint64_t i = 0; i < size; i++) {
        out[i] = dynamic_cast<alt::IVirtualEntity*>(virtualEntitiyArray[i]);
    }

    return out;
}

alt::IVirtualEntityGroup** Core_GetVirtualEntityGroups(alt::ICore* core, uint64_t& size)
{
    auto virtualEntitiyGroupArray = core->GetBaseObjects(alt::IBaseObject::Type::VIRTUAL_ENTITY_GROUP);
    size = virtualEntitiyGroupArray.size();
    auto out = new alt::IVirtualEntityGroup*[size];
    for (uint64_t i = 0; i < size; i++) {
        out[i] = dynamic_cast<alt::IVirtualEntityGroup*>(virtualEntitiyGroupArray[i]);
    }

    return out;
}

alt::IBlip** Core_GetBlips(alt::ICore* core, uint64_t& size) {
    auto blipsArray = core->GetBaseObjects(alt::IBaseObject::Type::BLIP);
    size = blipsArray.size();
    auto out = new alt::IBlip*[size];
    for (uint64_t i = 0; i < size; i++) {
        out[i] = dynamic_cast<alt::IBlip*>(blipsArray[i]);
    }

    return out;
}

void* Core_GetBaseObjectByID(alt::ICore* core, uint8_t type, uint32_t id) {
    auto entity = core->GetBaseObjectByID((alt::IBaseObject::Type)type, id);

    return Util_GetBaseObjectPointer(entity);
}

alt::IResource* Core_GetResource(alt::ICore* core, const char* resourceName) {
    return core->GetResource(resourceName);
}

alt::IResource** Core_GetAllResources(alt::ICore* core, uint32_t& size) {
    auto vector = core->GetAllResources();
    size = vector.size();
    auto out = new alt::IResource*[size];
    for (auto i = 0; i < size; i++) {
        out[i] = vector[i];
    }

    return out;
}

uint8_t Core_IsDebug(alt::ICore* core) {
    return core->IsDebug();
}

const char* Core_GetVersion(alt::ICore* core, int32_t &size) {
    return AllocateString(core->GetVersion(), size);
}

const char* Core_GetBranch(alt::ICore* core, int32_t &size) {
    return AllocateString(core->GetBranch(), size);
}


void Core_DestroyBaseObject(alt::ICore* core, alt::IBaseObject* baseObject) {
    return core->DestroyBaseObject(baseObject);
}

alt::MValueConst* Core_GetMetaData(alt::ICore* core, const char* key) {
    return AllocMValue(core->GetMetaData(key));
}

void Core_SetMetaData(alt::ICore* core, const char* key, alt::MValueConst* val) {
    if (val == nullptr) return;
    core->SetMetaData(key, val->get()->Clone());
}

uint8_t Core_HasMetaData(alt::ICore* core, const char* key) {
    return core->HasMetaData(key);
}

void Core_DeleteMetaData(alt::ICore* core, const char* key) {
    core->DeleteMetaData(key);
}

alt::MValueConst* Core_GetSyncedMetaData(alt::ICore* core, const char* key) {
    return AllocMValue(core->GetSyncedMetaData(key));
}

uint8_t Core_HasSyncedMetaData(alt::ICore* core, const char* key) {
    return core->HasSyncedMetaData(key);
}

void Core_TriggerLocalEvent(alt::ICore* core, const char* event, alt::MValueConst* args[], int size) {
    alt::MValueArgs mValues = alt::MValueArgs(size);
    for (int i = 0; i < size; i++) {
        ToMValueArg(mValues, core, args[i], i);
    }
    core->TriggerLocalEvent(event, mValues);
}

uint8_t Core_FileExists(alt::ICore* core, const char* path) {
    return core->FileExists(path);
}

const char* Core_FileRead(alt::ICore* core, const char* path, int32_t& size) {
    return AllocateString(core->FileRead(path), size);
}

alt::ICore* Core_GetCoreInstance() {
    return &alt::ICore::Instance();
}

void Core_ToggleEvent(alt::ICore* core, uint8_t event, uint8_t state) {
    return core->ToggleEvent((alt::CEvent::Type) event, state);
}

uint8_t Core_GetEventTypeSize() {
    return static_cast<uint8_t>(alt::CEvent::Type::SIZE);
}

uint8_t Core_GetBaseObjectTypeSize() {
    return static_cast<uint8_t>(alt::IBaseObject::Type::SIZE);
}

uint8_t Core_GetVoiceConnectionState(alt::ICore* core)
{
    return static_cast<uint8_t>(core->GetVoiceConnectionState());
}

alt::IObject** Core_GetNetworkObjects(alt::ICore* core, uint64_t& size)
{
    auto networkObjectsArray = core->GetBaseObjects(alt::IBaseObject::Type::OBJECT);
    size = networkObjectsArray.size();
    auto out = new alt::IObject*[size];
    for (uint64_t i = 0; i < size; i++) {
        out[i] = dynamic_cast<alt::IObject*>(networkObjectsArray[i]);
    }

    return out;
}

alt::ICheckpoint** Core_GetCheckpoints(alt::ICore* core, uint64_t& size)
{
    auto checkpointsArray = core->GetBaseObjects(alt::IBaseObject::Type::CHECKPOINT);
    size = checkpointsArray.size();
    auto out = new alt::ICheckpoint*[size];
    for (uint64_t i = 0; i < size; i++) {
        out[i] = dynamic_cast<alt::ICheckpoint*>(checkpointsArray[i]);
    }

    return out;
}

alt::IMarker** Core_GetMarkers(alt::ICore* core, uint64_t& size)
{
    auto markersArray = core->GetBaseObjects(alt::IBaseObject::Type::MARKER);
    size = markersArray.size();
    auto out = new alt::IMarker*[size];
    for (uint64_t i = 0; i < size; i++) {
        out[i] = dynamic_cast<alt::IMarker*>(markersArray[i]);
    }

    return out;
}

alt::IColShape** Core_GetColShapes(alt::ICore* core, uint64_t& size)
{
    auto colShapesArray = core->GetBaseObjects(alt::IBaseObject::Type::COLSHAPE);
    size = colShapesArray.size();
    auto out = new alt::IColShape*[size];
    for (uint64_t i = 0; i < size; i++) {
        out[i] = dynamic_cast<alt::IColShape*>(colShapesArray[i]);
    }

    return out;
}

alt::ITextLabel** Core_GetTextLabels(alt::ICore* core, uint64_t& size)
{
    auto textLabelsArray = core->GetBaseObjects(alt::IBaseObject::Type::TEXT_LABEL);
    size = textLabelsArray.size();
    auto out = new alt::ITextLabel*[size];
    for (uint64_t i = 0; i < size; i++) {
        out[i] = dynamic_cast<alt::ITextLabel*>(textLabelsArray[i]);
    }

    return out;
}

alt::IVirtualEntity* Core_CreateVirtualEntity(alt::ICore* core, alt::IVirtualEntityGroup* group, vector3_t position,
                                              uint32_t streamingDistance, const char* keys[], alt::MValueConst* values[], uint64_t size, uint32_t &id)
{
    alt::Position pos;
    pos.x = position.x;
    pos.y = position.y;
    pos.z = position.z;

    std::unordered_map<std::string, alt::MValue> data = {};

    for (uint64_t i = 0; i < size; i++) {
        if (values[i] == nullptr || values[i]->get() == nullptr) {
            data[keys[i]] = core->CreateMValueNil();
        } else {
            data[keys[i]] = values[i]->get()->Clone();
        }
    }

    auto virtualEntity = core->CreateVirtualEntity(group, pos, streamingDistance, data);
    if (virtualEntity != nullptr) {
        id = virtualEntity->GetID();
    }
    return virtualEntity;
}

alt::IVirtualEntityGroup* Core_CreateVirtualEntityGroup(alt::ICore* core, uint32_t maxEntitiesInStream, uint32_t &id)
{
    auto virtualEntityGroup = core->CreateVirtualEntityGroup(maxEntitiesInStream);
    if (virtualEntityGroup != nullptr) {
        id = virtualEntityGroup->GetID();
    }
    return virtualEntityGroup;
}

alt::IColShape* Core_CreateColShapeCylinder(alt::ICore* core, position_t pos, float radius, float height, uint32_t &id) {
    alt::Position position;
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;

    auto colShape = core->CreateColShapeCylinder(position, radius, height);
    if (colShape != nullptr) {
        id = colShape->GetID();
    }
    return colShape;
}

alt::IColShape* Core_CreateColShapeSphere(alt::ICore* core, position_t pos, float radius, uint32_t &id) {
    alt::Position position;
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;
    auto colShape = core->CreateColShapeSphere(position, radius);
    if (colShape != nullptr) {
        id = colShape->GetID();
    }
    return colShape;
}

alt::IColShape* Core_CreateColShapeCircle(alt::ICore* core, position_t pos, float radius, uint32_t &id) {
    alt::Position position;
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;
    auto colShape = core->CreateColShapeCircle(position, radius);
    if (colShape != nullptr) {
        id = colShape->GetID();
    }
    return colShape;
}

alt::IColShape* Core_CreateColShapeCube(alt::ICore* core, position_t pos, position_t pos2, uint32_t &id) {
    alt::Position position;
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;

    alt::Position position2;
    position2.x = pos2.x;
    position2.y = pos2.y;
    position2.z = pos2.z;
    auto colShape = core->CreateColShapeCube(position, position2);
    if (colShape != nullptr) {
        id = colShape->GetID();
    }
    return colShape;
}

alt::IColShape* Core_CreateColShapeRectangle(alt::ICore* core, float x1, float y1, float x2, float y2, float z, uint32_t &id) {
    auto colShape = core->CreateColShapeRectangle(x1, y1, x2, y2, z);
    if (colShape != nullptr) {
        id = colShape->GetID();
    }
    return colShape;
}

alt::IColShape* Core_CreateColShapePolygon(alt::ICore* core, float minZ, float maxZ, vector2_t points[], int pointSize, uint32_t &id) {
    std::vector<alt::Vector2f> convertedPoints(pointSize);
    for (int i = 0; i < pointSize; i++)
    {
       alt::Vector2f point;
       point[0] = points[i].x;
       point[1] = points[i].y;
       convertedPoints[i] = point;
    }

    auto colShape = core->CreateColShapePolygon(minZ, maxZ, convertedPoints);
    if (colShape != nullptr) {
        id = colShape->GetID();
    }
    return colShape;
}

int32_t Core_GetNetTime(alt::ICore* core) {
    return core->GetNetTime();
}

#ifdef ALT_SERVER_API
uint8_t Core_SubscribeCommand(alt::ICore* core, const char* cmd, alt::CommandCallback cb) {
    return core->SubscribeCommand(cmd, cb);
}

void Core_TriggerServerEvent(alt::ICore* core, const char* ev, alt::MValueConst* args[], int size) {
    alt::MValueArgs mValues = alt::MValueArgs(size);
    for (int i = 0; i < size; i++) {
        ToMValueArg(mValues, core, args[i], i);
    }
    core->TriggerLocalEvent(ev, mValues);
}

void Core_TriggerClientEvent(alt::ICore* core, alt::IPlayer* target, const char* ev, alt::MValueConst* args[],
                          int size) {
    alt::MValueArgs mValues = alt::MValueArgs(size);
    for (int i = 0; i < size; i++) {
        ToMValueArg(mValues, core, args[i], i);
    }
    core->TriggerClientEvent(target, ev, mValues);
}

void Core_TriggerClientEventForSome(alt::ICore* core, alt::IPlayer* targets[], int targetsSize, const char* ev, alt::MValueConst* args[],
    int argsSize) {
    std::vector<alt::IPlayer*> clients(targetsSize);
    for (int i = 0; i < targetsSize; i++)
    {
        clients[i] = targets[i];
    }
    alt::MValueArgs mValues = alt::MValueArgs(argsSize);
    for (int i = 0; i < argsSize; i++) {
        ToMValueArg(mValues, core, args[i], i);
    }
    core->TriggerClientEvent(clients, ev, mValues);
}

void Core_TriggerClientEventForAll(alt::ICore* core, const char* ev, alt::MValueConst* args[],
    int size) {
    alt::MValueArgs mValues = alt::MValueArgs(size);
    for (int i = 0; i < size; i++) {
        ToMValueArg(mValues, core, args[i], i);
    }
    core->TriggerClientEventForAll(ev, mValues);
}

void Core_TriggerClientEventUnreliable(alt::ICore* core, alt::IPlayer* target, const char* ev, alt::MValueConst* args[],
                          int size) {
    alt::MValueArgs mValues = alt::MValueArgs(size);
    for (int i = 0; i < size; i++) {
        ToMValueArg(mValues, core, args[i], i);
    }
    core->TriggerClientEventUnreliable(target, ev, mValues);
}

void Core_TriggerClientEventUnreliableForSome(alt::ICore* core, alt::IPlayer* targets[], int targetsSize, const char* ev, alt::MValueConst* args[],
    int argsSize) {
    std::vector<alt::IPlayer*> clients(targetsSize);
    for (int i = 0; i < targetsSize; i++)
    {
        clients[i] = targets[i];
    }
    alt::MValueArgs mValues = alt::MValueArgs(argsSize);
    for (int i = 0; i < argsSize; i++) {
        ToMValueArg(mValues, core, args[i], i);
    }
    core->TriggerClientEventUnreliable(clients, ev, mValues);
}

void Core_TriggerClientEventUnreliableForAll(alt::ICore* core, const char* ev, alt::MValueConst* args[],
    int size) {
    alt::MValueArgs mValues = alt::MValueArgs(size);
    for (int i = 0; i < size; i++) {
        ToMValueArg(mValues, core, args[i], i);
    }
    core->TriggerClientEventUnreliableForAll(ev, mValues);
}

alt::IVehicle* Core_CreateVehicle(alt::ICore* core, uint32_t model, position_t pos, rotation_t rot, uint32_t streamingDistance, uint32_t &id) {
    alt::Position position;
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;
    alt::Rotation rotation;
    rotation.roll = rot.roll;
    rotation.pitch = rot.pitch;
    rotation.yaw = rot.yaw;
    auto vehicle = core->CreateVehicle(model, position, rotation, streamingDistance);
    if (vehicle != nullptr) {
        id = vehicle->GetID();
    }
    return vehicle;
}

alt::IPed* Core_CreatePed(alt::ICore* core, uint32_t model, position_t pos, rotation_t rot, uint32_t streamingDistance, uint32_t &id)
{
    alt::Position position;
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;

    alt::Rotation rotation;
    rotation.roll = rot.roll;
    rotation.pitch = rot.pitch;
    rotation.yaw = rot.yaw;

    auto ped = core->CreatePed(model, position, rotation, streamingDistance);
    if (ped != nullptr) {
        id = ped->GetID();
    }
    return ped;
}

alt::ICheckpoint* Core_CreateCheckpoint(alt::ICore* core, uint8_t type, position_t pos, float radius,
                        float height, rgba_t color, uint32_t streamingDistance, uint32_t &id) {
    alt::Position position;
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;
    alt::RGBA rgba;
    rgba.r = color.r;
    rgba.g = color.g;
    rgba.b = color.b;
    rgba.a = color.a;

    auto checkPoint = core->CreateCheckpoint(type, position, radius, height, rgba, streamingDistance);
    if (checkPoint != nullptr) {
        id = checkPoint->GetID();
    }
    return checkPoint;
}

alt::IBlip* Core_CreateBlip(alt::ICore* core, uint8_t global, uint8_t type, position_t pos, alt::IPlayer* targets[], int targetsSize, uint32_t &id) {
    std::vector<alt::IPlayer*> vectorTargets(targetsSize);

    for (auto i = 0; i < targetsSize; i++) {
        vectorTargets[i] = targets[i];
    }

    alt::Position position;
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;

    auto blip = core->CreateBlip(global, (alt::IBlip::BlipType) type, position, vectorTargets);
    if (blip != nullptr) {
        id = blip->GetID();
    }
    return blip;
}

alt::IBlip* Core_CreateBlipAttached(alt::ICore* core, uint8_t global, uint8_t type, alt::IEntity* attachTo, alt::IPlayer* targets[], int targetsSize, uint32_t &id) {
    std::vector<alt::IPlayer*> vectorTargets(targetsSize);

    for (auto i = 0; i < targetsSize; i++) {
        vectorTargets[i] = targets[i];
    }

    auto blip = core->CreateBlip(global, (alt::IBlip::BlipType) type, attachTo, vectorTargets);
    if (blip != nullptr) {
        id = blip->GetID();
    }
    return blip;
}

ClrVehicleModelInfo* Core_GetVehicleModelInfo(alt::ICore* core, uint32_t hash) {
    return new ClrVehicleModelInfo(core->GetVehicleModelByHash(hash));
}

void Core_GetLoadedVehicleModels(alt::ICore* core, uint32_t*& loadedVehicleModelsOut, uint64_t& size) {
    auto loadedVehicleModels = core->GetLoadedVehicleModels();
    size = loadedVehicleModels.size();
    auto valuesArr = new uint32_t[size];
    for (auto i = 0; i < size; i++) {
        valuesArr[i] = loadedVehicleModels[i];
    }
    loadedVehicleModelsOut = valuesArr;
}

ClrPedModelInfo* Core_GetPedModelInfo(alt::ICore* core, uint32_t hash) {
    return new ClrPedModelInfo(core->GetPedModelByHash(hash));
}

ClrWeaponModelInfo* Core_GetWeaponModelByHash(alt::ICore* core, uint32_t hash)
{
    return new ClrWeaponModelInfo(core->GetWeaponModelByHash(hash));
}

void Core_DeallocVehicleModelInfo(ClrVehicleModelInfo* modelInfo) {
    delete modelInfo;
}

void Core_DeallocPedModelInfo(ClrPedModelInfo* modelInfo) {
    delete modelInfo;
}

void Core_DeallocWeaponModelInfo(ClrWeaponModelInfo* modelInfo) {
    delete modelInfo;
}

alt::IVoiceChannel* Core_CreateVoiceChannel(alt::ICore* core, uint8_t spatial, float maxDistance, uint32_t &id) {
    auto voiceChannel = core->CreateVoiceChannel(spatial, maxDistance);
    if (voiceChannel != nullptr) {
        id = voiceChannel->GetID();
    }
    return voiceChannel;
}

/*void Core_DestroyBaseObject(alt::ICore* core, alt::IBaseObject* baseObject) {
    return core->DestroyBaseObject(baseObject);
}*/

void Core_DestroyVehicle(alt::ICore* core, alt::IVehicle* baseObject) {
    return core->DestroyBaseObject(baseObject);
}

void Core_DestroyCheckpoint(alt::ICore* core, alt::ICheckpoint* baseObject) {
    return core->DestroyBaseObject(baseObject);
}

void Core_DestroyVoiceChannel(alt::ICore* core, alt::IVoiceChannel* baseObject) {
    return core->DestroyBaseObject(baseObject);
}

void Core_DestroyColShape(alt::ICore* core, alt::IColShape* baseObject) {
    return core->DestroyBaseObject(baseObject);
}

const char* Core_GetRootDirectory(alt::ICore* core, int32_t& size) {
    return AllocateString(core->GetRootDirectory(), size);
}

void Core_StartResource(alt::ICore* core, const char* text) {
    core->StartResource(text);
}

void Core_StopResource(alt::ICore* core, const char* text) {
    core->StopResource(text);
}

void Core_RestartResource(alt::ICore* core, const char* text) {
    core->RestartResource(text);
}

void Core_SetSyncedMetaData(alt::ICore* core, const char* key, alt::MValueConst* val) {
    if (val == nullptr) return;
    core->SetSyncedMetaData(key, val->get()->Clone());
}

void Core_DeleteSyncedMetaData(alt::ICore* core, const char* key) {
    core->DeleteSyncedMetaData(key);
}

uint64_t Core_HashPassword(alt::ICore* core, const char* password) {
    return core->HashServerPassword(password);
}

void Core_SetPassword(alt::ICore* core, const char* value) {
    core->SetPassword(value);
}

void Core_StopServer(alt::ICore* core) {
    core->StopServer();
}

ClrConfigNodeData* Core_GetServerConfig(alt::ICore* core) {
    return new ClrConfigNodeData(core->GetServerConfig());
}

void Core_SetWorldProfiler(alt::ICore* core, uint8_t state) {
    core->SetWorldProfiler(state);
}

uint64_t Core_GetEntitiesInDimensionCount(alt::ICore* core, int32_t dimension, uint64_t allowedTypes) {
    return core->GetEntitiesInDimension(dimension, allowedTypes).size();
}

uint64_t Core_GetEntitiesInRangeCount(alt::ICore* core, vector3_t position, int32_t range, int32_t dimension, uint64_t allowedTypes) {
    alt::Position pos;
    pos.x = position.x;
    pos.y = position.y;
    pos.z = position.z;

    return core->GetEntitiesInRange(pos, range, dimension, allowedTypes).size();
}

uint64_t Core_GetClosestEntitiesCount(alt::ICore* core, vector3_t position, int32_t range, int32_t dimension, int32_t limit, uint64_t allowedTypes) {
    alt::Position pos;
    pos.x = position.x;
    pos.y = position.y;
    pos.z = position.z;

    return core->GetClosestEntities(pos, range, dimension, limit, allowedTypes).size();
}

void Core_GetEntitiesInDimension(alt::ICore* core, int32_t dimension, uint64_t allowedTypes, void**& entities, uint8_t types[], uint64_t size) {
    auto entitiesArray = core->GetEntitiesInDimension(dimension, allowedTypes);
    if (entitiesArray.size() < size) {
        size = entitiesArray.size();
    }

    auto entityArr = new void*[size];
    for (uint64_t i = 0; i < size; i++) {
        entityArr[i] = Util_GetBaseObjectPointer(entitiesArray[i]);
        types[i] = (uint8_t) entitiesArray[i]->GetType();
    }
    entities = entityArr;
}

void Core_GetEntitiesInRange(alt::ICore* core, vector3_t position, int32_t range, int32_t dimension, uint64_t allowedTypes, void**& entities, uint8_t types[], uint64_t size) {
    alt::Position pos;
    pos.x = position.x;
    pos.y = position.y;
    pos.z = position.z;

    auto entitiesArray = core->GetEntitiesInRange(pos, range, dimension, allowedTypes);
    if (entitiesArray.size() < size) {
        size = entitiesArray.size();
    }

    auto entityArr = new void*[size];
    for (uint64_t i = 0; i < size; i++) {
        entityArr[i] = Util_GetBaseObjectPointer(entitiesArray[i]);
        types[i] = (uint8_t) entitiesArray[i]->GetType();
    }
    entities = entityArr;
}

void Core_GetClosestEntities(alt::ICore* core, vector3_t position, int32_t range, int32_t dimension, int32_t limit, uint64_t allowedTypes, void**& entities, uint8_t types[], uint64_t size) {
    alt::Position pos;
    pos.x = position.x;
    pos.y = position.y;
    pos.z = position.z;

    auto entitiesArray = core->GetClosestEntities(pos, range, dimension, limit, allowedTypes);
    if (entitiesArray.size() < size) {
        size = entitiesArray.size();
    }

    auto entityArr = new void*[size];
    for (uint64_t i = 0; i < size; i++) {
        entityArr[i] = Util_GetBaseObjectPointer(entitiesArray[i]);
        types[i] = (uint8_t) entitiesArray[i]->GetType();
    }
    entities = entityArr;
}

alt::IMarker* Core_CreateMarker(alt::ICore* core, alt::IPlayer* target, uint8_t type, position_t position, rgba_t color,
    alt::IResource* resource, uint32_t& id)
{
    alt::Position pos;
    pos.x = position.x;
    pos.y = position.y;
    pos.z = position.z;

    alt::RGBA rgbaColor;
    rgbaColor.r = color.r;
    rgbaColor.g = color.g;
    rgbaColor.b = color.b;
    rgbaColor.a = color.a;

    auto marker = core->CreateMarker(target, (alt::IMarker::MarkerType)type, pos, rgbaColor, resource);
    if (marker != nullptr) {
        id = marker->GetID();
    }
    return marker;
}

alt::IObject* Core_CreateObject(alt::ICore* core, uint32_t model, position_t position, rotation_t rotation,
    uint8_t alpha, uint8_t textureVariation, uint16_t lodDistance, uint32_t streamingDistance, uint32_t& id)
{
    alt::Position pos;
    pos.x = position.x;
    pos.y = position.y;
    pos.z = position.z;

    alt::Rotation rot;
    rot.roll = rotation.roll;
    rot.pitch = rotation.pitch;
    rot.yaw = rotation.yaw;

    auto networkObject = core->CreateObject(model, pos, rot, alpha, textureVariation, lodDistance, streamingDistance);
    if (networkObject != nullptr) {
        id = networkObject->GetID();
    }
    return networkObject;
}

alt::IConnectionInfo** Core_GetConnectionInfos(alt::ICore* core, uint64_t& size)
{
    auto connectionInfoArray = core->GetBaseObjects(alt::IBaseObject::Type::CONNECTION_INFO);
    size = connectionInfoArray.size();
    auto out = new alt::IConnectionInfo*[size];
    for (uint64_t i = 0; i < size; i++) {
        out[i] = dynamic_cast<alt::IConnectionInfo*>(connectionInfoArray[i]);
    }

    return out;
}

alt::Metric* Core_RegisterMetric(alt::ICore* core, const char* metricName, uint8_t type, const char* keys[],
    const char* values[], uint64_t size)
{

    std::unordered_map<std::string, std::string> data = {};

    for (uint64_t i = 0; i < size; i++) {
        data[keys[i]] = values[i];
    }

    return core->RegisterMetric(metricName, static_cast<alt::Metric::Type>(type), data);
}

void Core_UnregisterMetric(alt::ICore* core, alt::Metric* metric)
{
    core->UnregisterMetric(metric);
}

void Core_SetVoiceExternalPublic(alt::ICore* core, const char* host, uint16_t port)
{
    core->SetVoiceExternalPublic(host, port);
}

void Core_SetVoiceExternal(alt::ICore* core, const char* host, uint16_t port)
{
    core->SetVoiceExternal(host, port);
}

uint16_t Core_GetMaxStreamingPeds(alt::ICore* core)
{
    return core->GetMaxStreamingPeds();
}

void Core_SetMaxStreamingPeds(alt::ICore* core, uint16_t limit)
{
    core->SetMaxStreamingPeds(limit);
}

uint16_t Core_GetMaxStreamingObjects(alt::ICore* core)
{
    return core->GetMaxStreamingObjects();
}

void Core_SetMaxStreamingObjects(alt::ICore* core, uint16_t limit)
{
    core->SetMaxStreamingObjects(limit);
}

uint16_t Core_GetMaxStreamingVehicles(alt::ICore* core)
{
    return core->GetMaxStreamingVehicles();
}

void Core_SetMaxStreamingVehicles(alt::ICore* core, uint16_t limit)
{
    core->SetMaxStreamingVehicles(limit);
}

uint8_t Core_GetStreamerThreadCount(alt::ICore* core)
{
    return core->GetStreamerThreadCount();
}

void Core_SetStreamerThreadCount(alt::ICore* core, uint8_t limit)
{
    core->SetStreamerThreadCount(limit);
}

uint32_t Core_GetStreamingTickRate(alt::ICore* core)
{
    return core->GetStreamingTickRate();
}

void Core_SetStreamingTickRate(alt::ICore* core, uint32_t limit)
{
    core->SetStreamingTickRate(limit);
}

uint32_t Core_GetStreamingDistance(alt::ICore* core)
{
    return core->GetStreamingDistance();
}

void Core_SetStreamingDistance(alt::ICore* core, uint32_t limit)
{
    core->SetStreamingDistance(limit);
}

uint8_t Core_GetMigrationThreadCount(alt::ICore* core)
{
    return core->GetMigrationThreadCount();
}

void Core_SetMigrationThreadCount(alt::ICore* core, uint8_t limit)
{
    core->SetMigrationThreadCount(limit);
}

uint8_t Core_GetSyncSendThreadCount(alt::ICore* core)
{
    return core->GetSyncSendThreadCount();
}

void Core_SetSyncSendThreadCount(alt::ICore* core, uint8_t limit)
{
    core->SetSyncSendThreadCount(limit);
}

uint8_t Core_GetSyncReceiveThreadCount(alt::ICore* core)
{
    return core->GetSyncReceiveThreadCount();
}

void Core_SetSyncReceiveThreadCount(alt::ICore* core, uint8_t limit)
{
    core->SetSyncReceiveThreadCount(limit);
}

uint32_t Core_GetMigrationTickRate(alt::ICore* core)
{
    return core->GetMigrationTickRate();
}

void Core_SetMigrationTickRate(alt::ICore* core, uint32_t limit)
{
    core->SetMigrationTickRate(limit);
}

uint32_t Core_GetColShapeTickRate(alt::ICore* core)
{
    return core->GetColShapeTickRate();
}

void Core_SetColShapeTickRate(alt::ICore* core, uint32_t limit)
{
    core->SetColShapeTickRate(limit);
}

uint32_t Core_GetMigrationDistance(alt::ICore* core)
{
    return core->GetMigrationDistance();
}

void Core_SetMigrationDistance(alt::ICore* core, uint32_t limit)
{
    core->SetMigrationDistance(limit);
}

void Core_TriggerClientRPCAnswer(alt::ICore* core, alt::IPlayer* target, uint16_t answerID, alt::MValueConst* answer, const char* error)
{
    if(answer == nullptr) return;
    core->TriggerClientRPCAnswer(target, answerID, answer->get()->Clone(), error);
}

uint16_t Core_TriggerClientRPCEvent(alt::ICore* core, alt::IPlayer* target, const char* ev, alt::MValueConst* args[],
    int size)
{
    alt::MValueArgs mValues = alt::MValueArgs(size);
    for (int i = 0; i < size; i++) {
        ToMValueArg(mValues, core, args[i], i);
    }
    return core->TriggerClientRPCEvent(target, ev, mValues);
}

void Core_AddClientConfigKey(alt::ICore* core, const char* key)
{
    core->AddClientConfigKey(key);
}

uint8_t Core_HasBenefit(alt::ICore* core, uint8_t benefit)
{
    return core->HasBenefit(static_cast<alt::Benefit>(benefit));
}

#endif

#ifdef ALT_CLIENT_API
uint8_t Core_Client_FileExists(alt::ICore* core, alt::IResource* resource, const char* path) {
    const auto resolvedPath = core->Resolve(resource, path, "");
    if (resolvedPath.pkg == nullptr) return false;
    return resolvedPath.pkg->FileExists(resolvedPath.fileName);
}

const char* Core_Client_FileRead(alt::ICore* core, alt::IResource* resource, const char* path, int32_t& size) {
    const auto resolvedPath = core->Resolve(resource, path, "");
    if (resolvedPath.pkg == nullptr) return nullptr;
    alt::IPackage::File* file = resolvedPath.pkg->OpenFile(resolvedPath.fileName);
    if (file == nullptr) return nullptr;
    std::string data(resolvedPath.pkg->GetFileSize(file), 0);
    resolvedPath.pkg->ReadFile(file, data.data(), data.size());
    resolvedPath.pkg->CloseFile(file);
    return AllocateString(data, size);
}


alt::IBlip* Core_Client_CreatePointBlip(alt::ICore* core, vector3_t position, alt::IResource* resource, uint32_t &id) {
    alt::Position pos;
    pos.x = position.x;
    pos.y = position.y;
    pos.z = position.z;
    auto blip = core->CreateBlip(alt::IBlip::BlipType::DESTINATION, pos, resource);
    if (!blip) return nullptr;

    if (blip != nullptr) {
        id = blip->GetID();
    }
    return blip;
}

alt::IBlip* Core_Client_CreateRadiusBlip(alt::ICore* core, vector3_t position, float radius, alt::IResource* resource, uint32_t &id) {
    alt::Position pos;
    pos.x = position.x;
    pos.y = position.y;
    pos.z = position.z;
    auto blip = core->CreateBlip(pos, radius, resource);
    if (!blip) return nullptr;

    if (blip != nullptr) {
        id = blip->GetID();
    }
    return blip;
}

alt::IBlip* Core_Client_CreateAreaBlip(alt::ICore* core, vector3_t position, float width, float height, alt::IResource* resource, uint32_t &id) {
    alt::Position pos;
    pos.x = position.x;
    pos.y = position.y;
    pos.z = position.z;
    auto blip = core->CreateBlip(pos, width, height, resource);
    if (!blip) return nullptr;

    if (blip != nullptr) {
        id = blip->GetID();
    }
    return blip;
}

alt::IWebView* Core_CreateWebView(alt::ICore* core, alt::IResource* resource, const char* url, vector2_t pos, vector2_t size, uint8_t isOverlay, uint32_t &id) {
    auto webView = core->CreateWebView(url, { pos.x, pos.y }, { size.x, size.y }, true, isOverlay, resource);
    if (!webView) return nullptr;

    if (webView != nullptr) {
        id = webView->GetID();
    }
    return webView;
}

alt::IWebView* Core_CreateWebView3D(alt::ICore* core, alt::IResource* resource, const char* url, uint32_t hash, const char* targetTexture, uint32_t &id) {
    auto webView = core->CreateWebView(url, hash, targetTexture, resource);
    if (!webView) return nullptr;

    if (webView != nullptr) {
        id = webView->GetID();
    }
    return webView;
}

alt::IRmlDocument* Core_CreateRmlDocument(alt::ICore* core, alt::IResource* resource, const char* url, uint32_t &id) {
    auto document = core->CreateDocument(url, resource->GetMain(), resource);
    if (!document) return nullptr;

    if (document != nullptr) {
        id = document->GetID();
    }
    return document;
}

alt::ICheckpoint* Core_CreateCheckpoint(alt::ICore* core, uint8_t type, vector3_t pos, vector3_t nextPos, float radius, float height, rgba_t color, rgba_t iconColor, uint32_t streamingDistance, alt::IResource* resource, uint32_t &id) {
    alt::Position position;
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;
    alt::Position nextPosition;
    nextPosition.x = nextPos.x;
    nextPosition.y = nextPos.y;
    nextPosition.z = nextPos.z;
    alt::RGBA rgba;
    rgba.r = color.r;
    rgba.g = color.g;
    rgba.b = color.b;
    rgba.a = color.a;

    alt::RGBA iconRgba;
    iconRgba.r = iconColor.r;
    iconRgba.g = iconColor.g;
    iconRgba.b = iconColor.b;
    iconRgba.a = iconColor.a;
    auto checkPoint = core->CreateCheckpoint(type, position, nextPosition, radius, height, rgba, iconRgba, streamingDistance, resource);
    if (checkPoint != nullptr) {
        id = checkPoint->GetID();
    }
    return checkPoint;
}


void Core_TriggerWebViewEvent(alt::ICore* core, alt::IWebView* webview, const char* event, alt::MValueConst* args[], int size) {
    alt::MValueArgs mValues = alt::MValueArgs(size);
    for (int i = 0; i < size; i++) {
        ToMValueArg(mValues, core, args[i], i);
    }
    webview->Trigger(event, mValues);
}

void Core_TriggerServerEvent(alt::ICore* core, const char* event, alt::MValueConst* args[], int size) {
    alt::MValueArgs mValues = alt::MValueArgs(size);
    for (int i = 0; i < size; i++) {
        ToMValueArg(mValues, core, args[i], i);
    }
    core->TriggerServerEvent(event, mValues);
}

void Core_TriggerServerEventUnreliable(alt::ICore* core, const char* event, alt::MValueConst* args[], int size) {
    alt::MValueArgs mValues = alt::MValueArgs(size);
    for (int i = 0; i < size; i++) {
        ToMValueArg(mValues, core, args[i], i);
    }
    core->TriggerServerEventUnreliable(event, mValues);
}

void Core_ShowCursor(alt::ICore* core, alt::IResource* resource, uint8_t state) {
    if(!resource->ToggleCursor(state))
    {
        core->LogWarning("Cursor state can't go < 0");
    }
}

uint8_t Core_IsCursorVisible(alt::ICore* core, alt::IResource* resource) {
    return resource->CursorVisible();
}


ClrDiscordUser* Core_GetDiscordUser(alt::ICore* core) {
    auto manager = core->GetDiscordManager();
    if (!manager->IsUserDataReady()) return nullptr;
    return new ClrDiscordUser(manager);
}

void Core_DeallocDiscordUser(ClrDiscordUser* user) {
    delete user;
}


void Core_Discord_GetOAuth2Token(alt::ICore* core, const char* appId, DiscordOAuth2TokenResultDelegate_t delegate) {
    core->DiscordRequestOAuth2Token(appId, [delegate](const uint8_t result, const std::string& token) {
        delegate(result, token.c_str());
    });
}


void Core_WorldToScreen(alt::ICore* core, vector3_t in, vector2_t& out) {
    auto vec = core->WorldToScreen({ in.x, in.y, in.z });
    out.x = vec[0];
    out.y = vec[1];
}

void Core_ScreenToWorld(alt::ICore* core, vector2_t in, vector3_t& out) {
    auto vec = core->ScreenToWorld({ in.x, in.y });
    out.x = vec[0];
    out.y = vec[1];
    out.z = vec[2];
}

void Core_LoadRmlFont(alt::ICore* core, alt::IResource* resource, const char* path, const char* name, uint8_t italic, uint8_t bold) {
    core->LoadRmlFontFace(resource, path, resource->GetMain(), name, italic, bold);
}

uint32_t Core_GetVoiceActivationKey(alt::ICore* core) {
    return core->GetVoiceActivationKey();
}

uint8_t Core_IsVoiceActivityInputEnabled(alt::ICore* core) {
    return core->IsVoiceActivationEnabled();
}

uint8_t Core_GetVoiceInputMuted(alt::ICore* core) {
    return core->IsVoiceInputMuted();
}

void Core_SetVoiceInputMuted(alt::ICore* core, uint8_t value) {
    core->SetVoiceInputMuted(value);
}

uint8_t Core_ToggleVoiceInput(alt::ICore* core, uint8_t state)
{
    return static_cast<uint8_t>(core->ToggleVoiceInput(state));
}

uint8_t Core_ToggleVoiceActivation(alt::ICore* core, uint8_t state)
{
    return static_cast<uint8_t>(core->ToggleVoiceActivation(state));
}

uint8_t Core_SetVoiceActivationLevel(alt::ICore* core, float level)
{
    return static_cast<uint8_t>(core->SetVoiceActivationLevel(level));
}

float Core_GetVoiceActivationLevel(alt::ICore* core)
{
    return core->GetVoiceActivationLevel();
}

uint8_t Core_ToggleNoiseSuppression(alt::ICore* core, uint8_t state)
{
    return static_cast<uint8_t>(core->ToggleNoiseSuppression(state));
}

uint8_t Core_IsNoiseSuppressionEnabled(alt::ICore* core)
{
    return core->IsNoiseSuppressionEnabled();
}

uint8_t Core_BeginScaleformMovieMethodMinimap(alt::ICore* core, const char* methodName) {
    return core->BeginScaleformMovieMethodMinimap(methodName);
}

void Core_SetMinimapComponentPosition(alt::ICore* core, const char* name, uint8_t alignX, uint8_t alignY, float posX, float posY, float sizeX, float sizeY) {
    core->SetMinimapComponentPosition(name, (char) alignX, (char) alignY, { posX, posY }, { sizeX, sizeY });
}

void Core_ResetMinimapComponentPosition(alt::ICore* core, const char* name)
{
    core->ResetMinimapComponentPosition(name);
}

void Core_SetMinimapIsRectangle(alt::ICore* core, uint8_t state) {
    core->SetMinimapIsRectangle(state);
}


uint8_t Core_CopyToClipboard(alt::ICore* core, const char* value) {
    return (uint8_t) core->CopyToClipboard(value);
}

uint16_t Core_GetFPS(alt::ICore* core) {
    return core->GetFps();
}

uint16_t Core_GetPing(alt::ICore* core) {
    return core->GetPing();
}

uint32_t Core_GetTotalPacketsLost(alt::ICore* core) {
    return core->GetTotalPacketsLost();
}

uint64_t Core_GetTotalPacketsSent(alt::ICore* core) {
    return core->GetTotalPacketsSent();
}

void Core_GetScreenResolution(alt::ICore* core, vector2_t& out) {
    auto vec = core->GetScreenResolution();
    out.x = (float) vec[0];
    out.y = (float) vec[1];
}

const char* Core_GetLicenseHash(alt::ICore* core, int32_t& size) {
    return AllocateString(core->GetLicenseHash(), size);
}

const char* Core_GetLocale(alt::ICore* core, int32_t& size) {
    return AllocateString(core->GetLocale(), size);
}

uint8_t Core_GetPermissionState(alt::ICore* core, uint8_t permission) {
    return (uint8_t) core->GetPermissionState((alt::Permission) permission);
}

const char* Core_GetServerIp(alt::ICore* core, int32_t& size) {
    return AllocateString(core->GetServerIp(), size);
}

uint16_t Core_GetServerPort(alt::ICore* core) {
    return core->GetServerPort();
}

uint8_t Core_IsGameFocused(alt::ICore* core) {
    return core->IsGameFocused();
}

uint8_t Core_IsInStreamerMode(alt::ICore* core) {
    return core->IsInStreamerMode();
}

uint8_t Core_IsMenuOpened(alt::ICore* core) {
    return core->IsMenuOpen();
}

uint8_t Core_IsConsoleOpen(alt::ICore* core) {
    return core->IsConsoleOpen();
}

uint8_t Core_IsTextureExistInArchetype(alt::ICore* core, uint32_t modelHash, const char* targetTextureName) {
    return core->GetTextureFromDrawable(modelHash, targetTextureName) != nullptr;
}

void Core_LoadModel(alt::ICore* core, uint32_t modelHash) {
    core->LoadModel(modelHash);
}

void Core_LoadModelAsync(alt::ICore* core, uint32_t modelHash) {
    core->LoadModelAsync(modelHash);
}

uint8_t Core_LoadYtyp(alt::ICore* core, const char* path) {
    return core->LoadYtyp(path);
}

uint8_t Core_UnloadYtyp(alt::ICore* core, const char* path) {
    return core->UnloadYtyp(path);
}

void Core_RequestIpl(alt::ICore* core, const char* path) {
    core->RequestIPL(path);
}

void Core_RemoveIpl(alt::ICore* core, const char* path) {
    core->RemoveIPL(path);
}

uint8_t Core_IsKeyDown(alt::ICore* core, uint32_t key) {
    return core->GetKeyState(key).IsDown();
}

uint8_t Core_IsKeyToggled(alt::ICore* core, uint32_t key) {
    return core->GetKeyState(key).IsToggled();
}

uint8_t Core_IsCamFrozen(alt::ICore* core) {
    return core->IsCamFrozen();
}

void Core_SetCamFrozen(alt::ICore* core, uint8_t value) {
    core->SetCamFrozen(value);
}

void Core_GetCamPos(alt::ICore* core, vector3_t& out) {
    auto vector = core->GetCamPos();
    out.x = vector[0];
    out.y = vector[1];
    out.z = vector[2];
}

void Core_AddGXTText(alt::ICore* core, alt::IResource* resource, uint32_t key, const char* value) {
    resource->AddGxtText(key, value);
}

const char* Core_GetGXTText(alt::ICore* core, alt::IResource* resource, uint32_t key, int32_t& size) {
    return AllocateString(core->GetGxtEntry(key), size);
}

void Core_RemoveGXTText(alt::ICore* core, alt::IResource* resource, uint32_t key) {
    resource->RemoveGxtText(key);
}

uint8_t Core_DoesConfigFlagExist(alt::ICore* core, const char* flag) {
    return core->DoesConfigFlagExist(flag);
}

uint8_t Core_GetConfigFlag(alt::ICore* core, const char* flag) {
    return core->GetConfigFlag(flag);
}

void Core_SetConfigFlag(alt::ICore* core, const char* flag, uint8_t state) {
    core->SetConfigFlag(flag, state);
}

uint8_t Core_AreGameControlsEnabled(alt::ICore* core) {
    return core->AreControlsEnabled();
}

void Core_ToggleGameControls(alt::ICore* core, alt::IResource* resource, uint8_t state) {
    return resource->ToggleGameControls(state);
}

void Core_ToggleRmlControls(alt::ICore* core, uint8_t state) {
    core->ToggleRmlControls(state);
}

uint8_t Core_AreRmlControlsEnabled(alt::ICore* core) {
    return core->AreRmlControlsEnabled();
}

uint8_t Core_AreVoiceControlsEnabled(alt::ICore* core) {
    return core->AreVoiceControlsEnabled();
}

void Core_ToggleVoiceControls(alt::ICore* core, uint8_t state) {
    core->ToggleVoiceControls(state);
}

void Core_GetCursorPos(alt::ICore* core, vector2_t& out, uint8_t normalized) {
    auto vector = core->GetCursorPosition(normalized);
    out.x = vector[0];
    out.y = vector[1];
}

void Core_SetCursorPos(alt::ICore* core, vector2_t pos, uint8_t normalized) {
    core->SetCursorPosition({ pos.x, pos.y }, normalized);
}

int32_t Core_GetMsPerGameMinute(alt::ICore* core) {
    return core->GetMsPerGameMinute();
}

void Core_SetMsPerGameMinute(alt::ICore* core, int32_t ms) {
    core->SetMsPerGameMinute(ms);
}

alt::IStatData* Core_GetStatData(alt::ICore* core, const char* stat) {
    return core->GetStatData(stat);
}

void Core_ResetStat(alt::ICore* core, const char* stat) {
    auto data = core->GetStatData(stat);
    if (data == nullptr) return;
    data->Reset();
}

const char* Core_GetStatType(alt::ICore* core, alt::IStatData* stat, int32_t& size) {
    return AllocateString(stat->GetStatType(), size);
}

int32_t Core_GetStatInt(alt::ICore* core, alt::IStatData* stat) {
    return stat->GetInt32Value();
}

int64_t Core_GetStatLong(alt::ICore* core, alt::IStatData* stat) {
    return stat->GetInt64Value();
}

float Core_GetStatFloat(alt::ICore* core, alt::IStatData* stat) {
    return stat->GetFloatValue();
}

uint8_t Core_GetStatBool(alt::ICore* core, alt::IStatData* stat) {
    return stat->GetBoolValue();
}

const char* Core_GetStatString(alt::ICore* core, alt::IStatData* stat, int32_t& size) {
    return AllocateString(stat->GetStringValue(), size);
}

uint8_t Core_GetStatUInt8(alt::ICore* core, alt::IStatData* stat) {
    return stat->GetUInt8Value();
}

uint16_t Core_GetStatUInt16(alt::ICore* core, alt::IStatData* stat) {
    return stat->GetUInt16Value();
}

uint32_t Core_GetStatUInt32(alt::ICore* core, alt::IStatData* stat) {
    return stat->GetUInt32Value();
}

uint64_t Core_GetStatUInt64(alt::ICore* core, alt::IStatData* stat) {
    return stat->GetUInt64Value();
}

void Core_SetStatInt(alt::ICore* core, alt::IStatData* stat, int32_t value) {
    stat->SetInt32Value(value);
}

void Core_SetStatLong(alt::ICore* core, alt::IStatData* stat, int64_t value) {
    stat->SetInt64Value(value);
}

void Core_SetStatFloat(alt::ICore* core, alt::IStatData* stat, float value) {
    stat->SetFloatValue(value);
}

void Core_SetStatBool(alt::ICore* core, alt::IStatData* stat, uint8_t value) {
    stat->SetBoolValue(value);
}

void Core_SetStatString(alt::ICore* core, alt::IStatData* stat, const char* value) {
    stat->SetStringValue(value);
}

void Core_SetStatUInt8(alt::ICore* core, alt::IStatData* stat, uint8_t value) {
    stat->SetUInt8Value(value);
}

void Core_SetStatUInt16(alt::ICore* core, alt::IStatData* stat, uint16_t value) {
    stat->SetUInt16Value(value);
}

void Core_SetStatUInt32(alt::ICore* core, alt::IStatData* stat, uint32_t value) {
    stat->SetUInt32Value(value);
}

void Core_SetStatUInt64(alt::ICore* core, alt::IStatData* stat, uint64_t value) {
    stat->SetUInt64Value(value);
}

void Core_ClearPedProp(alt::ICore* core, int32_t scriptID, uint8_t component) {
    core->ClearProps(scriptID, component);
}

void Core_SetPedDlcProp(alt::ICore* core, int32_t scriptID, uint32_t dlc, uint8_t component, uint8_t drawable, uint8_t texture) {
    core->SetDlcProps(scriptID, component, drawable, texture, dlc);
}

void Core_SetPedDlcClothes(alt::ICore* core, int32_t scriptID, uint32_t dlc, uint8_t component, uint8_t drawable, uint8_t texture, uint8_t palette) {
    core->SetDlcClothes(scriptID, component, drawable, texture, palette, dlc);
}

void Core_SetRotationVelocity(alt::ICore* core, int32_t scriptID, vector3_t velocity) {
    core->SetAngularVelocity(scriptID, { velocity.x, velocity.y, velocity.z, 0.0 });
}

void Core_SetWatermarkPosition(alt::ICore* core, uint8_t position) {
    core->SetWatermarkPosition(position);
}

const char* Core_StringToSHA256(alt::ICore* core, const char* string, int32_t& size) {
    return AllocateString(core->StringToSHA256(string), size);
}

void Core_SetWeatherCycle(alt::ICore* core, uint8_t weathers[], int32_t weathersSize, uint8_t multipliers[], int32_t multipliersSize) {
    std::vector<uint8_t> weathersBytes(weathersSize);
    for (auto i = 0; i < weathersSize; i++) {
        weathersBytes[i] = weathers[i];
    }

    std::vector<uint8_t> multipliersBytes(multipliersSize);
    for (auto i = 0; i < multipliersSize; i++) {
        multipliersBytes[i] = multipliers[i];
    }

    core->SetWeatherCycle(weathersBytes, multipliersBytes);
}

void Core_SetWeatherSyncActive(alt::ICore* core, uint8_t state) {
    core->SetWeatherSyncActive(state);
}

const char* Core_GetHeadshotBase64(alt::ICore* core, uint8_t id, int32_t& size) {
    return AllocateString(core->HeadshotToBase64(id), size);
}

uint8_t Core_TakeScreenshot(alt::ICore* core, ScreenshotDelegate_t delegate) {
    return (uint8_t) core->TakeScreenshot([delegate](const std::string& str) {
        delegate(str.c_str());
    });
}

uint8_t Core_TakeScreenshotGameOnly(alt::ICore* core, ScreenshotDelegate_t delegate) {
    return (uint8_t) core->TakeScreenshotGameOnly([delegate](const std::string& str) {
        delegate(str.c_str());
    });
}

alt::IMapData* Core_GetMapZoomDataByAlias(alt::ICore* core, const char* alias, uint32_t& id) {
    auto data = core->GetMapData(alias);
    if (!data) return nullptr;

    id = core->GetMapDataIDFromAlias(alias);
    return data.get();
}

void Core_ResetAllMapZoomData(alt::ICore* core) {
    core->ResetAllMapData();
}

void Core_ResetMapZoomData(alt::ICore* core, uint32_t id) {
    core->ResetMapData(id);
}

alt::IHttpClient* Core_CreateHttpClient(alt::ICore* core, alt::IResource* resource, uint32_t &id) {
    auto httpClient = core->CreateHttpClient(resource);
    if (httpClient != nullptr) {
        id = httpClient->GetID();
    }
    return httpClient;
}

alt::IWebSocketClient* Core_CreateWebsocketClient(alt::ICore* core, alt::IResource* resource, const char* url, uint32_t &id) {
    auto webSocketClient = core->CreateWebSocketClient(url, resource);
    if (webSocketClient != nullptr) {
        id = webSocketClient->GetID();
    }
    return webSocketClient;
}

alt::IAudio* Core_CreateAudio(alt::ICore* core, const char* source, float volume, uint8_t isRadio, uint8_t clearCache, const char* basePath, alt::IResource* resource, uint32_t &id) {
    auto audio = core->CreateAudio(source, volume, isRadio, clearCache, basePath, resource);
    if (audio != nullptr) {
        id = audio->GetID();
    }
    return audio;
}

alt::IAudioFilter* Core_CreateAudioFilter(alt::ICore* core, uint32_t hash, alt::IResource* resource, uint32_t& id)
{
    auto audioFilter = core->CreateAudioFilter(hash, resource);
    if (audioFilter != nullptr) {
        id = audioFilter->GetID();
    }
    return audioFilter;
}

alt::IAudioFrontendOutput* Core_CreateFrontendOutput(alt::ICore* core, uint32_t categoryHash, alt::IResource* resource, uint32_t& id)
{
    auto audioFrontendOutput = core->CreateFrontendOutput(categoryHash, resource);
    if (audioFrontendOutput != nullptr) {
        id = audioFrontendOutput->GetID();
    }
    return audioFrontendOutput;
}

alt::IAudioWorldOutput* Core_CreateWorldOutput(alt::ICore* core, uint32_t categoryHash, alt::Position pos,
    alt::IResource* resource, uint32_t& id)
{
    auto audioWorldOutput = core->CreateWorldOutput(categoryHash, pos, resource);
    if (audioWorldOutput != nullptr) {
        id = audioWorldOutput->GetID();
    }
    return audioWorldOutput;
}

alt::IAudioAttachedOutput* Core_CreateAttachedOutput(alt::ICore* core, uint32_t categoryHash, alt::IWorldObject* entity,
    alt::IResource* resource, uint32_t& id)
{
    auto audioAttachedOutput = core->CreateAttachedOutput(categoryHash, entity, resource);
    if (audioAttachedOutput != nullptr) {
        id = audioAttachedOutput->GetID();
    }
    return audioAttachedOutput;
}

uint8_t Core_HasLocalMeta(alt::ICore* core, const char* key) {
    return core->HasLocalMetaData(key);
}

alt::MValueConst* Core_GetLocalMeta(alt::ICore* core, const char* key) {
    return AllocMValue(core->GetLocalMetaData(key));
}

const char* Core_GetClientPath(alt::ICore* core, int32_t& size) {
    return AllocateString(core->GetClientPath(), size);
}


uint8_t Core_IsFocusOverriden(alt::ICore* core) {
    return core->IsFocusOverriden();
}

void Core_GetFocusOverridePos(alt::ICore* core, vector3_t& pos) {
    auto vec = core->GetFocusOverridePos();
    pos.x = vec[0];
    pos.y = vec[1];
    pos.z = vec[2];
}

void Core_GetFocusOverrideOffset(alt::ICore* core, vector3_t& offset) {
    auto vec = core->GetFocusOverrideOffset();
    offset.x = vec[0];
    offset.y = vec[1];
    offset.z = vec[2];
}

void* Core_GetFocusOverrideEntity(alt::ICore* core, uint8_t& type) {
    auto entity = core->GetFocusOverrideEntity();
    if (entity == nullptr) return nullptr;
    type = (uint8_t) entity->GetType();
    switch (entity->GetType()) {
        case alt::IBaseObject::Type::PLAYER:
        case alt::IBaseObject::Type::LOCAL_PLAYER:
            return dynamic_cast<alt::IPlayer*>(entity);
        case alt::IBaseObject::Type::VEHICLE:
            return dynamic_cast<alt::IVehicle*>(entity);
        case alt::IBaseObject::Type::PED:
            return dynamic_cast<alt::IPed*>(entity);
        default:
            return nullptr;
    }
}

void Core_OverrideFocusPosition(alt::ICore* core, vector3_t pos, vector3_t offset) {
    core->OverrideFocusPosition({ pos.x, pos.y, pos.z }, { offset.x, offset.y, offset.z });
}

void Core_OverrideFocusEntity(alt::ICore* core, alt::IEntity* entity) {
    core->OverrideFocusEntity(entity);
}

void Core_ClearFocusOverride(alt::ICore* core) {
    core->ClearFocusOverride();
}

void Core_LoadDefaultIpls(alt::ICore* core) {
    core->LoadDefaultIpls();
}

uint8_t Core_IsPointOnScreen(alt::ICore* core, vector3_t pos) {
    return core->IsPointOnScreen({ pos.x, pos.y, pos.z });
}

alt::ILocalObject* Core_CreateLocalObject(alt::ICore* core, uint32_t modelHash, vector3_t pos, vector3_t rot, uint8_t noOffset, uint8_t dynamic, uint8_t useStreaming, uint32_t streamingDistance, alt::IResource* resource, uint32_t &id) {
    auto object = core->CreateLocalObject(modelHash, { pos.x, pos.y, pos.z }, { rot.x, rot.y, rot.z }, noOffset, dynamic, useStreaming, streamingDistance, resource);
    if (object != nullptr) {
        id = object->GetID();
    }
    return object;
}

alt::ILocalObject* Core_CreateWeaponObject(alt::ICore* core, alt::Position pos, alt::Rotation rot, uint32_t weaponHash,
    uint32_t modelHash, int32_t numAmmo, uint8_t createDefaultComponents, float scale, uint8_t useStreaming,
    uint32_t streamingDistance, alt::IResource* resource, uint32_t& id)
{
    auto object = core->CreateWeaponObject(pos, rot, weaponHash, modelHash, numAmmo, createDefaultComponents, scale, useStreaming, streamingDistance, resource);
    if (object != nullptr) {
        id = object->GetID();
    }
    return object;
}

alt::ILocalObject** Core_GetLocalObjects(alt::ICore* core, uint32_t& size) {
    auto objects = core->GetBaseObjects(alt::IBaseObject::Type::LOCAL_OBJECT);
    size = objects.size();
    auto out = new alt::ILocalObject*[size];
    for (auto i = 0; i < size; i++) {
        out[i] = dynamic_cast<alt::ILocalObject*>(objects[i]);
    }

    return out;
}

alt::ILocalPed** Core_GetLocalPeds(alt::ICore* core, uint32_t& size)
{
    auto localPedsArray = core->GetBaseObjects(alt::IBaseObject::Type::LOCAL_PED);
    size = localPedsArray.size();
    auto out = new alt::ILocalPed * [size];
    for (auto i = 0; i < size; i++) {
        out[i] = dynamic_cast<alt::ILocalPed*>(localPedsArray[i]);
    }

    return out;
}

alt::ILocalVehicle** Core_GetLocalVehicles(alt::ICore* core, uint32_t& size)
{
    auto localVehiclesArray = core->GetBaseObjects(alt::IBaseObject::Type::LOCAL_VEHICLE);
    size = localVehiclesArray.size();
    auto out = new alt::ILocalVehicle * [size];
    for (auto i = 0; i < size; i++) {
        out[i] = dynamic_cast<alt::ILocalVehicle*>(localVehiclesArray[i]);
    }

    return out;
}

alt::ILocalObject** Core_GetWorldObjects(alt::ICore* core, uint32_t& size) {
    auto worldObjects = core->GetWorldObjects();
    size = worldObjects.size();
    auto out = new alt::ILocalObject*[size];
    for (auto i = 0; i < size; i++) {
        out[i] = worldObjects[i];
    }

    return out;
}

alt::ILocalObject** Core_GetWeaponObjects(alt::ICore* core, uint32_t& size)
{
    auto weaponObject = core->GetWeaponObjects();
    size = weaponObject.size();
    auto out = new alt::ILocalObject*[size];
    for (auto i = 0; i < size; i++) {
        out[i] = weaponObject[i];
    }

    return out;
}

void Core_GetPedBonePos(alt::ICore* core, int32_t scriptId, uint16_t boneId, vector3_t& pos) {
    auto vec = core->GetPedBonePos(scriptId, boneId);
    pos.x = vec[0];
    pos.y = vec[1];
    pos.z = vec[2];
}

uint64_t Core_GetWebViewCount(alt::ICore* core)
{
    return core->GetBaseObjects(alt::IBaseObject::Type::WEBVIEW).size();
}

void Core_GetWebViews(alt::ICore* core, alt::IWebView* webViews[], uint64_t size)
{
    auto webviewsArray = core->GetBaseObjects(alt::IBaseObject::Type::WEBVIEW);
    if (webviewsArray.size() < size) {
        size = webviewsArray.size();
    }
    for (uint64_t i = 0; i < size; i++) {
        webViews[i] = dynamic_cast<alt::IWebView*>(webviewsArray[i]);
    }
}

uint64_t Core_GetAudioCount(alt::ICore* core)
{
    return core->GetBaseObjects(alt::IBaseObject::Type::AUDIO).size();
}

alt::IAudio** Core_GetAudios(alt::ICore* core, uint64_t& size)
{
    auto audios = core->GetBaseObjects(alt::IBaseObject::Type::AUDIO);
    size = audios.size();
    auto out = new alt::IAudio*[size];
    for (auto i = 0; i < size; i++) {
        out[i] = dynamic_cast<alt::IAudio*>(audios[i]);
    }

    return out;
}

alt::IAudioOutput** Core_GetAudioOutputs(alt::ICore* core, uint64_t& size)
{
    auto audioOutputs = core->GetBaseObjects(alt::IBaseObject::Type::AUDIO_OUTPUT);
    size = audioOutputs.size();
    auto out = new alt::IAudioOutput*[size];
    for (auto i = 0; i < size; i++) {
        out[i] = dynamic_cast<alt::IAudioOutput*>(audioOutputs[i]);
    }

    return out;
}

alt::IMarker* Core_CreateMarker_Client(alt::ICore* core, uint8_t type, position_t position, rgba_t color, uint8_t useStreaming, uint32_t streamingDistance,
                                       alt::IResource* resource, uint32_t& id)
{
    alt::Position pos;
    pos.x = position.x;
    pos.y = position.y;
    pos.z = position.z;

    alt::RGBA rgbaColor;
    rgbaColor.r = color.r;
    rgbaColor.g = color.g;
    rgbaColor.b = color.b;
    rgbaColor.a = color.a;

    auto marker = core->CreateMarker((alt::IMarker::MarkerType)type, pos, rgbaColor, useStreaming, streamingDistance, resource);
    if (marker != nullptr) {
        id = marker->GetID();
    }
    return marker;
}

alt::ITextLabel* Core_CreateTextLabel(alt::ICore* core, const char* text, const char* fontName, float fontSize,
    float scale, position_t position, rotation_t rotation, rgba_t color, float outlineWith, rgba_t outlineColor,
    uint8_t useStreaming, uint32_t streamingDistance, alt::IResource* resource, uint32_t& id)
{
    alt::Position pos;
    pos.x = position.x;
    pos.y = position.y;
    pos.z = position.z;

    alt::Rotation rot;
    rot.roll = rotation.roll;
    rot.pitch = rotation.pitch;
    rot.yaw = rotation.yaw;

    alt::RGBA rgbaColor;
    rgbaColor.r = color.r;
    rgbaColor.g = color.g;
    rgbaColor.b = color.b;
    rgbaColor.a = color.a;

    alt::RGBA rgbaOutlineColor;
    rgbaOutlineColor.r = outlineColor.r;
    rgbaOutlineColor.g = outlineColor.g;
    rgbaOutlineColor.b = outlineColor.b;
    rgbaOutlineColor.a = outlineColor.a;

    auto textLabel = core->CreateTextLabel(text, fontName, fontSize, scale, pos, rot, rgbaColor, outlineWith, rgbaOutlineColor, useStreaming, streamingDistance, resource);
    if (textLabel != nullptr) {
        id = textLabel->GetID();
    }
    return textLabel;
}

alt::ILocalVehicle* Core_CreateLocalVehicle(alt::ICore* core, uint32_t modelHash, int32_t dimension, position_t position,
    rotation_t rotation, uint8_t useStreaming, uint32_t streamingDistance, alt::IResource* resource, uint32_t& id)
{
    alt::Position pos;
    pos.x = position.x;
    pos.y = position.y;
    pos.z = position.z;

    alt::Rotation rot;
    rot.roll = rotation.roll;
    rot.pitch = rotation.pitch;
    rot.yaw = rotation.yaw;

    auto localVehicle = core->CreateLocalVehicle(modelHash, dimension, pos, rot, useStreaming, streamingDistance, resource);
    if (localVehicle != nullptr) {
        id = localVehicle->GetID();
    }
    return localVehicle;
}

alt::ILocalPed* Core_CreateLocalPed(alt::ICore* core, uint32_t modelHash, int32_t dimension, position_t position,
    rotation_t rotation, uint8_t useStreaming, uint32_t streamingDistance, alt::IResource* resource, uint32_t& id)
{
    alt::Position pos;
    pos.x = position.x;
    pos.y = position.y;
    pos.z = position.z;

    alt::Rotation rot;
    rot.roll = rotation.roll;
    rot.pitch = rotation.pitch;
    rot.yaw = rotation.yaw;

    auto localPed = core->CreateLocalPed(modelHash, dimension, pos, rot, useStreaming, streamingDistance, resource);
    if (localPed != nullptr) {
        id = localPed->GetID();
    }
    return localPed;
}

alt::IFont* Core_RegisterFont(alt::ICore* core, alt::IResource* resource, const char* path, uint32_t& id)
{
    auto font = core->RegisterFont(resource, path, resource->GetMain());

    if (font != nullptr) {
        id = font->GetID();
    }
    return font;
}

uint8_t Core_IsFullScreen(alt::ICore* core)
{
    return core->IsFullScreen();
}

alt::IBlip* Core_GetBlipByGameID(alt::ICore* core, uint32_t gameId)
{
    return core->GetBlipByGameID(gameId);
}

alt::ICheckpoint* Core_GetCheckpointByGameID(alt::ICore* core, uint32_t gameId)
{
    return core->GetCheckpointByGameID(gameId);
}

uint8_t Core_IsWebViewGpuAccelerationActive(alt::ICore* core)
{
    return core->IsWebViewGpuAccelerationActive();
}

alt::IWorldObject* Core_GetWorldObjectByScriptID(alt::ICore* core, uint32_t scriptId)
{
    return core->GetWorldObjectByScriptID(scriptId);
}

uint64_t Core_GetAllWeaponDataCount(alt::ICore* core)
{
    return core->GetAllWeaponData().size();
}

void Core_GetAllWeaponData(alt::ICore* core, uint32_t weaponHashes[], uint64_t size)
{
    auto weaponData = core->GetAllWeaponData();
    if (weaponData.size() < size) {
        size = weaponData.size();
    }
    for (uint64_t i = 0; i < size; i++) {
        weaponHashes[i] = weaponData[i]->GetNameHash();
    }
}

void Core_TriggerServerRPCAnswer(alt::ICore* core, uint16_t answerID, alt::MValueConst* answer, const char* error)
{
    if(answer == nullptr) return;
    core->TriggerServerRPCAnswer(answerID, answer->get()->Clone(), error);
}

uint16_t Core_TriggerServerRPCEvent(alt::ICore* core, const char* ev, alt::MValueConst* args[], int size)
{
    alt::MValueArgs mValues = alt::MValueArgs(size);
    for (int i = 0; i < size; i++) {
        ToMValueArg(mValues, core, args[i], i);
    }
    return core->TriggerServerRPCEvent(ev, mValues);
}

uint32_t Core_GetPoolSize(alt::ICore* core, const char* pool)
{
    return core->GetPoolSize(pool);
}

uint32_t Core_GetPoolCount(alt::ICore* core, const char* pool)
{
    return core->GetPoolCount(pool);
}

void Core_GetPoolEntities(alt::ICore* core, const char* pool, const uint32_t*& poolEntities, uint32_t& size)
{
    poolEntities = AllocateUInt32Array(core->GetPoolEntities(pool), size);
}

void Core_GetVoicePlayers(alt::ICore* core, const uint32_t*& voicePlayers, uint32_t& size)
{
    voicePlayers = AllocateUInt32Array(core->GetVoicePlayers(), size);
}

void Core_RemoveVoicePlayer(alt::ICore* core, uint32_t playerRemodeId)
{
    core->RemoveVoicePlayer(playerRemodeId);
}

float Core_GetVoiceSpatialVolume(alt::ICore* core, uint32_t playerRemodeId)
{
    return core->GetVoiceSpatialVolume(playerRemodeId);
}

void Core_SetVoiceSpatialVolume(alt::ICore* core, uint32_t playerRemodeId, float volume)
{
    core->SetVoiceSpatialVolume(playerRemodeId, volume);
}

float Core_GetVoiceNonSpatialVolume(alt::ICore* core, uint32_t playerRemodeId)
{
    return core->GetVoiceNonSpatialVolume(playerRemodeId);
}

void Core_SetVoiceNonSpatialVolume(alt::ICore* core, uint32_t playerRemodeId, float volume)
{
    core->SetVoiceNonSpatialVolume(playerRemodeId, volume);
}

void Core_AddVoiceFilter(alt::ICore* core, uint32_t playerRemodeId, alt::IAudioFilter* filter)
{
    core->AddVoiceFilter(playerRemodeId, filter);
}

void Core_RemoveVoiceFilter(alt::ICore* core, uint32_t playerRemodeId)
{
    core->RemoveVoiceFilter(playerRemodeId);
}

alt::IAudioFilter* Core_GetVoiceFilter(alt::ICore* core, uint32_t playerRemodeId)
{
    return core->GetVoiceFilter(playerRemodeId);
}

void Core_UpdateClipContext(alt::ICore* core, const char* keys[], const char* values[], uint64_t size)
{
    std::unordered_map<std::string, std::string> context = {};

    for (uint64_t i = 0; i < size; i++) {
        context[keys[i]] = values[i];
    }

    return core->UpdateClipContext(context);
}
#endif

CAPI_END()
