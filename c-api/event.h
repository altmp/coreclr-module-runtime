#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "data/types.h"
#include "utils/export.h"

#ifdef ALT_CLIENT_API
#include "../client/src/runtime/CSharpResourceImpl.h"
#include "../client/src/runtime/eventDelegates.h"
#endif

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_SHARED void Event_Cancel(alt::CCancellableEvent* event);
EXPORT_SERVER void Event_WeaponDamageEvent_SetDamageValue(alt::CEvent* event, uint32_t damageValue);
EXPORT_SHARED uint8_t Event_WasCancelled(alt::CCancellableEvent* event);

#ifdef ALT_CLIENT_API
EXPORT_CLIENT void Event_SetTickDelegate(CSharpResourceImpl* resource, /** ClientEvents.TickModuleDelegate */ TickDelegate_t delegate);
EXPORT_CLIENT void Event_SetServerEventDelegate(CSharpResourceImpl* resource,  /** ClientEvents.ServerEventModuleDelegate */ ServerEventDelegate_t delegate);
EXPORT_CLIENT void Event_SetClientEventDelegate(CSharpResourceImpl* resource,  /** ClientEvents.ClientEventModuleDelegate */ ClientEventDelegate_t delegate);
EXPORT_CLIENT void Event_SetConsoleCommandDelegate(CSharpResourceImpl* resource,  /** ClientEvents.ConsoleCommandModuleDelegate */ ConsoleCommandDelegate_t delegate);
EXPORT_CLIENT void Event_SetWebViewEventDelegate(CSharpResourceImpl* resource,  /** ClientEvents.WebViewEventModuleDelegate */ WebViewEventDelegate_t delegate);
EXPORT_CLIENT void Event_SetWebSocketEventDelegate(CSharpResourceImpl* resource,  /** ClientEvents.WebSocketEventModuleDelegate */ WebSocketEventDelegate_t delegate);
EXPORT_CLIENT void Event_SetAudioEventDelegate(CSharpResourceImpl* resource,  /** ClientEvents.AudioEventModuleDelegate */ AudioEventDelegate_t delegate);
EXPORT_CLIENT void Event_SetRmlEventDelegate(CSharpResourceImpl* resource,  /** ClientEvents.RmlEventModuleDelegate */ RmlEventDelegate_t delegate);

EXPORT_CLIENT void Event_SetPlayerSpawnDelegate(CSharpResourceImpl* resource, /** ClientEvents.PlayerSpawnModuleDelegate */ PlayerSpawnDelegate_t delegate);
EXPORT_CLIENT void Event_SetPlayerDisconnectDelegate(CSharpResourceImpl* resource, /** ClientEvents.PlayerDisconnectModuleDelegate */ PlayerDisconnectDelegate_t delegate);
EXPORT_CLIENT void Event_SetPlayerEnterVehicleDelegate(CSharpResourceImpl* resource, /** ClientEvents.PlayerEnterVehicleModuleDelegate */ PlayerEnterVehicleDelegate_t delegate);
EXPORT_CLIENT void Event_SetPlayerLeaveVehicleDelegate(CSharpResourceImpl* resource, /** ClientEvents.PlayerLeaveVehicleModuleDelegate */ PlayerLeaveVehicleDelegate_t delegate);

EXPORT_CLIENT void Event_SetGameEntityCreateDelegate(CSharpResourceImpl* resource, /** ClientEvents.GameEntityCreateModuleDelegate */ GameEntityCreateDelegate_t delegate);
EXPORT_CLIENT void Event_SetGameEntityDestroyDelegate(CSharpResourceImpl* resource, /** ClientEvents.GameEntityDestroyModuleDelegate */ GameEntityDestroyDelegate_t delegate);

EXPORT_CLIENT void Event_SetAnyResourceErrorDelegate(CSharpResourceImpl* resource, /** ClientEvents.AnyResourceErrorModuleDelegate */ AnyResourceErrorDelegate_t delegate);
EXPORT_CLIENT void Event_SetAnyResourceStartDelegate(CSharpResourceImpl* resource, /** ClientEvents.AnyResourceStartModuleDelegate */ AnyResourceStartDelegate_t delegate);
EXPORT_CLIENT void Event_SetAnyResourceStopDelegate(CSharpResourceImpl* resource, /** ClientEvents.AnyResourceStopModuleDelegate */ AnyResourceStopDelegate_t delegate);

EXPORT_CLIENT void Event_SetKeyUpDelegate(CSharpResourceImpl* resource, /** ClientEvents.KeyUpModuleDelegate */ KeyUpDelegate_t delegate);
EXPORT_CLIENT void Event_SetKeyDownDelegate(CSharpResourceImpl* resource, /** ClientEvents.KeyDownModuleDelegate */ KeyDownDelegate_t delegate);

EXPORT_CLIENT void Event_SetPlayerChangeVehicleSeatDelegate(CSharpResourceImpl* resource, /** ClientEvents.PlayerChangeVehicleSeatModuleDelegate */ PlayerChangeVehicleSeatDelegate_t delegate);
EXPORT_CLIENT void Event_SetPlayerChangeAnimationDelegate(CSharpResourceImpl* resource, /** ClientEvents.PlayerChangeAnimationModuleDelegate */ PlayerChangeAnimationDelegate_t delegate);
EXPORT_CLIENT void Event_SetPlayerChangeInteriorDelegate(CSharpResourceImpl* resource, /** ClientEvents.PlayerChangeInteriorModuleDelegate */ PlayerChangeInteriorDelegate_t delegate);

EXPORT_CLIENT void Event_SetConnectionCompleteDelegate(CSharpResourceImpl* resource, /** ClientEvents.ConnectionCompleteModuleDelegate */ ConnectionCompleteDelegate_t delegate);

EXPORT_CLIENT void Event_SetGlobalMetaChangeDelegate(CSharpResourceImpl* resource, /** ClientEvents.GlobalMetaChangeModuleDelegate */ GlobalMetaChangeDelegate_t delegate);
EXPORT_CLIENT void Event_SetGlobalSyncedMetaChangeDelegate(CSharpResourceImpl* resource, /** ClientEvents.GlobalSyncedMetaChangeModuleDelegate */ GlobalMetaChangeDelegate_t delegate);
EXPORT_CLIENT void Event_SetLocalMetaChangeDelegate(CSharpResourceImpl* resource, /** ClientEvents.LocalMetaChangeModuleDelegate */ LocalMetaChangeDelegate_t delegate);
EXPORT_CLIENT void Event_SetStreamSyncedMetaChangeDelegate(CSharpResourceImpl* resource, /** ClientEvents.StreamSyncedMetaChangeModuleDelegate */ StreamSyncedMetaChangeDelegate_t delegate);
EXPORT_CLIENT void Event_SetSyncedMetaChangeDelegate(CSharpResourceImpl* resource, /** ClientEvents.SyncedMetaChangeModuleDelegate */ SyncedMetaChangeDelegate_t delegate);
EXPORT_CLIENT void Event_SetMetaChangeDelegate(CSharpResourceImpl* resource, /** ClientEvents.MetaChangeModuleDelegate */ MetaChangeDelegate_t delegate);

EXPORT_CLIENT void Event_SetNetOwnerChangeDelegate(CSharpResourceImpl* resource, /** ClientEvents.NetOwnerChangeModuleDelegate */ NetOwnerChangeDelegate_t delegate);

EXPORT_CLIENT void Event_SetTaskChangeDelegate(CSharpResourceImpl* resource, /** ClientEvents.TaskChangeModuleDelegate */ TaskChangeDelegate_t delegate);

EXPORT_CLIENT void Event_SetWindowFocusChangeDelegate(CSharpResourceImpl* resource, /** ClientEvents.WindowFocusChangeModuleDelegate */ WindowFocusChangeDelegate_t delegate);
EXPORT_CLIENT void Event_SetWindowResolutionChangeDelegate(CSharpResourceImpl* resource, /** ClientEvents.WindowResolutionChangeModuleDelegate */ WindowResolutionChangeDelegate_t delegate);

EXPORT_CLIENT void Event_SetWorldObjectPositionChangeDelegate(CSharpResourceImpl* resource, /** ClientEvents.WorldObjectPositionChangeModuleDelegate */ WorldObjectPositionChangeDelegate_t delegate);
EXPORT_CLIENT void Event_SetWorldObjectStreamInDelegate(CSharpResourceImpl* resource, /** ClientEvents.WorldObjectStreamInModuleDelegate */ WorldObjectStreamInDelegate_t delegate);
EXPORT_CLIENT void Event_SetWorldObjectStreamOutDelegate(CSharpResourceImpl* resource, /** ClientEvents.WorldObjectStreamOutModuleDelegate */ WorldObjectStreamOutDelegate_t delegate);

EXPORT_CLIENT void Event_SetPlayerWeaponShootDelegate(CSharpResourceImpl* resource, /** ClientEvents.PlayerWeaponShootModuleDelegate */ PlayerWeaponShootDelegate_t delegate);

EXPORT_CLIENT void Event_SetPlayerWeaponChangeDelegate(CSharpResourceImpl* resource, /** ClientEvents.PlayerWeaponChangeModuleDelegate */ PlayerWeaponChangeDelegate_t delegate);

EXPORT_CLIENT void Event_SetWeaponDamageDelegate(CSharpResourceImpl* resource, /** ClientEvents.WeaponDamageModuleDelegate */ WeaponDamageDelegate_t delegate);


EXPORT_CLIENT void Event_SetCreateBaseObjectDelegate(CSharpResourceImpl* resource, /** ClientEvents.CreateBaseObjectModuleDelegate */ CreateBaseObjectDelegate_t delegate);
EXPORT_CLIENT void Event_SetRemoveBaseObjectDelegate(CSharpResourceImpl* resource, /** ClientEvents.RemoveBaseObjectModuleDelegate */ RemoveBaseObjectDelegate_t delegate);

EXPORT_CLIENT void Event_SetColShapeDelegate(CSharpResourceImpl* resource, /** ClientEvents.ColShapeModuleDelegate */ ColShapeDelegate_t delegate);
EXPORT_CLIENT void Event_SetCheckpointDelegate(CSharpResourceImpl* resource, /** ClientEvents.CheckpointModuleDelegate */ CheckpointDelegate_t delegate);

EXPORT_CLIENT void Event_SetEntityHitEntityDelegate(CSharpResourceImpl* resource, /** ClientEvents.EntityHitEntityModuleDelegate */ EntityHitEntityDelegate_t delegate);

EXPORT_CLIENT void Event_SetPlayerStartEnterVehicleDelegate(CSharpResourceImpl* resource, /** ClientEvents.PlayerStartEnterVehicleModuleDelegate */ PlayerStartEnterVehicleDelegate_t delegate);
EXPORT_CLIENT void Event_SetPlayerStartLeaveVehicleDelegate(CSharpResourceImpl* resource, /** ClientEvents.PlayerStartLeaveVehicleModuleDelegate */ PlayerStartLeaveVehicleDelegate_t delegate);

EXPORT_CLIENT void Event_SetPlayerBulletHitDelegate(CSharpResourceImpl* resource, /** ClientEvents.PlayerBulletHitModuleDelegate */ PlayerBulletHitDelegate_t delegate);
EXPORT_CLIENT void Event_SetVoiceConnectionDelegate(CSharpResourceImpl* resource, /** ClientEvents.VoiceConnectionModuleDelegate */ VoiceConnectionDelegate_t delegate);
#endif
