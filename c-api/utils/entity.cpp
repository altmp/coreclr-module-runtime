#include "entity.h"

void* GetEntityPointer(alt::IBaseObject* entity) {
    if (entity != nullptr) {
        switch (entity->GetType()) {
            case alt::IBaseObject::Type::LOCAL_PLAYER:
            case alt::IBaseObject::Type::PLAYER:
                return dynamic_cast<alt::IPlayer*>(entity);
            case alt::IBaseObject::Type::VEHICLE:
                return dynamic_cast<alt::IVehicle*>(entity);
            case alt::IBaseObject::Type::OBJECT:
                return dynamic_cast<alt::IObject*>(entity);
            case alt::IBaseObject::Type::PED:
                return dynamic_cast<alt::IPed*>(entity);
            default:
                return nullptr;
        }
    }
    return nullptr;
}