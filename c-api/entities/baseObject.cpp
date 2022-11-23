#include "baseObject.h"

using namespace alt;

void BaseObject_SetMetaData(alt::IBaseObject* baseObject, const char* key, alt::MValueConst* value) {
    baseObject->SetMetaData(key, value->Get()->Clone());
}

uint8_t BaseObject_HasMetaData(alt::IBaseObject* baseObject, const char* key) {
    return baseObject->HasMetaData(key);
}

void BaseObject_DeleteMetaData(alt::IBaseObject* baseObject, const char* key) {
    baseObject->DeleteMetaData(key);
}

alt::MValueConst* BaseObject_GetMetaData(alt::IBaseObject* baseObject, const char* key) {
    return new MValueConst(baseObject->GetMetaData(key));
}

void* BaseObject_TryCache(alt::IBaseObject* baseObject) {
    switch (baseObject->GetType()) {
        case alt::IBaseObject::Type::PLAYER:
            return dynamic_cast<alt::IPlayer*>(new cache::CachedPlayer(dynamic_cast<alt::IPlayer*>(baseObject)));
        case alt::IBaseObject::Type::VEHICLE: {
            return dynamic_cast<alt::IVehicle*>(new cache::CachedVehicle(dynamic_cast<alt::IVehicle*>(baseObject)));
        }
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
