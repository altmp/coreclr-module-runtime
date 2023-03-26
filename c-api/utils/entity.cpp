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
            case alt::IBaseObject::Type::BLIP:
                return dynamic_cast<alt::IBlip*>(entity);
            case alt::IBaseObject::Type::NETWORK_OBJECT:
                return dynamic_cast<alt::INetworkObject*>(entity);
            case alt::IBaseObject::Type::VIRTUAL_ENTITY:
                return dynamic_cast<alt::IVirtualEntity*>(entity);
            case alt::IBaseObject::Type::VIRTUAL_ENTITY_GROUP:
                return dynamic_cast<alt::IVirtualEntityGroup*>(entity);
            case alt::IBaseObject::Type::WEBVIEW:
                return dynamic_cast<alt::IWebView*>(entity);
            case alt::IBaseObject::Type::VOICE_CHANNEL:
                return dynamic_cast<alt::IVoiceChannel*>(entity);
            case alt::IBaseObject::Type::COLSHAPE:
                return dynamic_cast<alt::IColShape*>(entity);
            case alt::IBaseObject::Type::CHECKPOINT:
                return dynamic_cast<alt::ICheckpoint*>(entity);
            case alt::IBaseObject::Type::WEBSOCKET_CLIENT:
                return dynamic_cast<alt::IWebSocketClient*>(entity);
            case alt::IBaseObject::Type::HTTP_CLIENT:
                return dynamic_cast<alt::IHttpClient*>(entity);
            case alt::IBaseObject::Type::AUDIO:
                return dynamic_cast<alt::IAudio*>(entity);
            case alt::IBaseObject::Type::RML_ELEMENT:
                return dynamic_cast<alt::IRmlElement*>(entity);
            case alt::IBaseObject::Type::RML_DOCUMENT:
                return dynamic_cast<alt::IRmlDocument*>(entity);
            default:
                return nullptr;
        }
    }
    return nullptr;
}