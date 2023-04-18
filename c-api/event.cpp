#include "event.h"

#ifdef ALT_SERVER_API

void Event_PlayerBeforeConnect_Cancel(alt::CEvent* event, const char* reason) {
    ((alt::CPlayerBeforeConnectEvent*) event)->Cancel(reason);
}

void Event_WeaponDamageEvent_SetDamageValue(alt::CEvent* event, uint32_t damageValue) {
    ((alt::CWeaponDamageEvent*) event)->SetDamageValue(damageValue);
}
#endif

void Event_Cancel(alt::CEvent* event) {
    event->Cancel();
}

uint8_t Event_WasCancelled(alt::CEvent* event) {
    return event->WasCancelled();
}

#ifdef ALT_CLIENT_API
#define SetDelegate(name) void Event_Set##name##Delegate(CSharpResourceImpl* resource, name##Delegate_t delegate) {\
    resource->On##name##Delegate = delegate;\
}

SetDelegate(Tick);
SetDelegate(ClientEvent);
SetDelegate(ServerEvent);
SetDelegate(WebViewEvent);
SetDelegate(ConsoleCommand);
SetDelegate(RmlEvent);
SetDelegate(WebSocketEvent);

SetDelegate(PlayerSpawn);
SetDelegate(PlayerDisconnect);
SetDelegate(PlayerEnterVehicle);
SetDelegate(PlayerLeaveVehicle);

SetDelegate(GameEntityCreate);
SetDelegate(GameEntityDestroy);
SetDelegate(RemoveEntity);

SetDelegate(AnyResourceError);
SetDelegate(AnyResourceStart);
SetDelegate(AnyResourceStop);

SetDelegate(KeyUp);
SetDelegate(KeyDown);

SetDelegate(PlayerChangeVehicleSeat);
SetDelegate(PlayerChangeAnimation);
SetDelegate(PlayerChangeInterior)

SetDelegate(ConnectionComplete);

SetDelegate(GlobalMetaChange);
SetDelegate(GlobalSyncedMetaChange);
SetDelegate(LocalMetaChange);
SetDelegate(StreamSyncedMetaChange);
SetDelegate(SyncedMetaChange);

SetDelegate(NetOwnerChange);

SetDelegate(TaskChange);

SetDelegate(WindowFocusChange);
SetDelegate(WindowResolutionChange);

SetDelegate(PlayerWeaponShoot);
SetDelegate(PlayerWeaponChange);
SetDelegate(WeaponDamage);

SetDelegate(WorldObjectPositionChange);


SetDelegate(CreateBaseObject);
SetDelegate(RemoveBaseObject);
#endif