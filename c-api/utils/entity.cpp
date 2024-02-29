#include "entity.h"

void* Util_GetEntityPointer(alt::IBaseObject* entity)
{
    if (entity != nullptr)
    {
        switch (entity->GetType())
        {
        case alt::IBaseObject::Type::LOCAL_PLAYER:
        case alt::IBaseObject::Type::PLAYER:
            return dynamic_cast<alt::IPlayer*>(entity);
        case alt::IBaseObject::Type::VEHICLE:
            return dynamic_cast<alt::IVehicle*>(entity);
        case alt::IBaseObject::Type::PED:
            return dynamic_cast<alt::IPed*>(entity);
        case alt::IBaseObject::Type::OBJECT:
            return dynamic_cast<alt::IObject*>(entity);
        case alt::IBaseObject::Type::LOCAL_OBJECT:
            return dynamic_cast<alt::ILocalObject*>(entity);
#ifdef ALT_CLIENT_API
        case alt::IBaseObject::Type::LOCAL_PED:
            return dynamic_cast<alt::ILocalPed*>(entity);
        case alt::IBaseObject::Type::LOCAL_VEHICLE:
            return dynamic_cast<alt::ILocalVehicle*>(entity);
#endif
        default:
            return nullptr;
        }
    }
    return nullptr;
}

void* Util_GetWorldObjectPointer(alt::IWorldObject* worldObject)
{
    if (worldObject != nullptr)
    {
        switch (worldObject->GetType())
        {
        case alt::IBaseObject::Type::LOCAL_PLAYER:
        case alt::IBaseObject::Type::PLAYER:
            return dynamic_cast<alt::IPlayer*>(worldObject);
        case alt::IBaseObject::Type::VEHICLE:
            return dynamic_cast<alt::IVehicle*>(worldObject);
        case alt::IBaseObject::Type::PED:
            return dynamic_cast<alt::IPed*>(worldObject);
        case alt::IBaseObject::Type::OBJECT:
            return dynamic_cast<alt::IObject*>(worldObject);
        case alt::IBaseObject::Type::BLIP:
            return dynamic_cast<alt::IBlip*>(worldObject);
        case alt::IBaseObject::Type::COLSHAPE:
            return dynamic_cast<alt::IColShape*>(worldObject);
        case alt::IBaseObject::Type::CHECKPOINT:
            return dynamic_cast<alt::ICheckpoint*>(worldObject);
        case alt::IBaseObject::Type::LOCAL_OBJECT:
            return dynamic_cast<alt::ILocalObject*>(worldObject);
        case alt::IBaseObject::Type::VIRTUAL_ENTITY:
            return dynamic_cast<alt::IVirtualEntity*>(worldObject);
        case alt::IBaseObject::Type::MARKER:
            return dynamic_cast<alt::IMarker*>(worldObject);
        case alt::IBaseObject::Type::TEXT_LABEL:
            return dynamic_cast<alt::ITextLabel*>(worldObject);
#ifdef ALT_CLIENT_API
        case alt::IBaseObject::Type::LOCAL_PED:
            return dynamic_cast<alt::ILocalPed*>(worldObject);
        case alt::IBaseObject::Type::LOCAL_VEHICLE:
            return dynamic_cast<alt::ILocalVehicle*>(worldObject);
#endif
        default:
            return nullptr;
        }
    }
    return nullptr;
}

void* Util_GetBaseObjectPointer(alt::IBaseObject* baseObject)
{
    if (baseObject != nullptr)
    {
        switch (baseObject->GetType())
        {
        case alt::IBaseObject::Type::LOCAL_PLAYER:
        case alt::IBaseObject::Type::PLAYER:
            return dynamic_cast<alt::IPlayer*>(baseObject);
        case alt::IBaseObject::Type::VEHICLE:
            return dynamic_cast<alt::IVehicle*>(baseObject);
        case alt::IBaseObject::Type::PED:
            return dynamic_cast<alt::IPed*>(baseObject);
        case alt::IBaseObject::Type::OBJECT:
            return dynamic_cast<alt::IObject*>(baseObject);
        case alt::IBaseObject::Type::BLIP:
            return dynamic_cast<alt::IBlip*>(baseObject);
        case alt::IBaseObject::Type::WEBVIEW:
            return dynamic_cast<alt::IWebView*>(baseObject);
        case alt::IBaseObject::Type::VOICE_CHANNEL:
            return dynamic_cast<alt::IVoiceChannel*>(baseObject);
        case alt::IBaseObject::Type::COLSHAPE:
            return dynamic_cast<alt::IColShape*>(baseObject);
        case alt::IBaseObject::Type::CHECKPOINT:
            return dynamic_cast<alt::ICheckpoint*>(baseObject);
        case alt::IBaseObject::Type::WEBSOCKET_CLIENT:
            return dynamic_cast<alt::IWebSocketClient*>(baseObject);
        case alt::IBaseObject::Type::HTTP_CLIENT:
            return dynamic_cast<alt::IHttpClient*>(baseObject);
        case alt::IBaseObject::Type::AUDIO:
            return dynamic_cast<alt::IAudio*>(baseObject);
        case alt::IBaseObject::Type::RML_ELEMENT:
            return dynamic_cast<alt::IRmlElement*>(baseObject);
        case alt::IBaseObject::Type::RML_DOCUMENT:
            return dynamic_cast<alt::IRmlDocument*>(baseObject);
        case alt::IBaseObject::Type::LOCAL_OBJECT:
            return dynamic_cast<alt::ILocalObject*>(baseObject);
        case alt::IBaseObject::Type::VIRTUAL_ENTITY:
            return dynamic_cast<alt::IVirtualEntity*>(baseObject);
        case alt::IBaseObject::Type::VIRTUAL_ENTITY_GROUP:
            return dynamic_cast<alt::IVirtualEntityGroup*>(baseObject);
        case alt::IBaseObject::Type::MARKER:
            return dynamic_cast<alt::IMarker*>(baseObject);
        case alt::IBaseObject::Type::TEXT_LABEL:
            return dynamic_cast<alt::ITextLabel*>(baseObject);
#ifdef ALT_CLIENT_API
        case alt::IBaseObject::Type::LOCAL_PED:
            return dynamic_cast<alt::ILocalPed*>(baseObject);
        case alt::IBaseObject::Type::LOCAL_VEHICLE:
            return dynamic_cast<alt::ILocalVehicle*>(baseObject);
#endif
        case alt::IBaseObject::Type::AUDIO_FILTER:
            return dynamic_cast<alt::IAudioFilter*>(baseObject);
        default:
            return nullptr;
        }
    }
    return nullptr;
}
