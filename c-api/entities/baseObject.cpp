#include "baseObject.h"
#include "../mvalue.h"
#include "../utils/macros.h"

CAPI_START()

using namespace alt;

void BaseObject_SetMetaData(alt::IBaseObject* baseObject, const char* key, alt::MValueConst* value) {
    baseObject->SetMetaData(key, value->get()->Clone());
}

uint8_t BaseObject_HasMetaData(alt::IBaseObject* baseObject, const char* key) {
    return baseObject->HasMetaData(key);
}

void BaseObject_DeleteMetaData(alt::IBaseObject* baseObject, const char* key) {
    baseObject->DeleteMetaData(key);
}

alt::MValueConst* BaseObject_GetMetaData(alt::IBaseObject* baseObject, const char* key) {
    return AllocMValue(baseObject->GetMetaData(key));
}

void* BaseObject_TryCache(alt::IBaseObject* baseObject) {
    switch (baseObject->GetType()) {
    case alt::IBaseObject::Type::PLAYER:
        return dynamic_cast<alt::IPlayer*>(new cache::CachedPlayer(dynamic_cast<alt::IPlayer*>(baseObject)));
    case alt::IBaseObject::Type::VEHICLE:
        return dynamic_cast<alt::IVehicle*>(new cache::CachedVehicle(dynamic_cast<alt::IVehicle*>(baseObject)));
    case alt::IBaseObject::Type::PED:
        return dynamic_cast<alt::IPed*>(new cache::CachedPed(dynamic_cast<alt::IPed*>(baseObject)));
    case alt::IBaseObject::Type::OBJECT:
        return dynamic_cast<alt::IObject*>(new cache::CachedObject(dynamic_cast<alt::IObject*>(baseObject)));
        default:
            return nullptr;
    }
}

void BaseObject_DestructCache(alt::IBaseObject* baseObject) {
    delete dynamic_cast<cache::CachedBaseObject*>(baseObject);
}

uint8_t BaseObject_GetType(alt::IBaseObject* baseObject)
{
    return (uint8_t) baseObject->GetType();
}

uint8_t BaseObject_HasSyncedMetaData(alt::IBaseObject* baseObject, const char* key) {
    return baseObject->HasSyncedMetaData(key);
}

alt::MValueConst* BaseObject_GetSyncedMetaData(alt::IBaseObject* baseObject, const char* key) {
    return AllocMValue(baseObject->GetSyncedMetaData(key));
}

#ifdef ALT_SERVER_API

void BaseObject_SetSyncedMetaData(alt::IBaseObject* baseObject, const char* key, alt::MValueConst* val) {
    if (val == nullptr) return;
    baseObject->SetSyncedMetaData(key, val->get()->Clone());
}

void BaseObject_DeleteSyncedMetaData(alt::IBaseObject* baseObject, const char* key) {
    baseObject->DeleteSyncedMetaData(key);
}

#endif

#ifdef ALT_CLIENT_API
uint32_t BaseObject_GetRemoteID(alt::IBaseObject* baseObject)
{
    return baseObject->GetRemoteID();
}

uint8_t BaseObject_IsRemote(alt::IBaseObject* baseObject)
{
    return baseObject->IsRemote();
}
#endif

CAPI_END()