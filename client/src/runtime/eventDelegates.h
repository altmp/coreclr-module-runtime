#pragma once
#include "cpp-sdk/ICore.h"
#include "../../../c-api/data/types.h"

typedef void (* TickDelegate_t)();
typedef void (* ClientEventDelegate_t)(const char* name, alt::MValueConst** args, uint64_t size);
typedef void (* ServerEventDelegate_t)(const char* name, alt::MValueConst** args, uint64_t size);
typedef void (* WebViewEventDelegate_t)(alt::IWebView*, const char* name, alt::MValueConst** args, uint64_t size);
typedef void (* ConsoleCommandDelegate_t)(const char* name, const char* args[], uint64_t size);
typedef void (* WebSocketEventDelegate_t)(alt::IWebSocketClient*, const char* name, alt::MValueConst** args, uint64_t size);
typedef void (* RmlEventDelegate_t)(alt::IRmlElement*, const char* name, alt::IMValueDict* args, uint64_t size);

typedef void (* CreatePlayerDelegate_t)(alt::IPlayer*, uint16_t id);
typedef void (* RemovePlayerDelegate_t)(alt::IPlayer*);

typedef void (* CreateObjectDelegate_t)(alt::IObject*, uint16_t id);
typedef void (* RemoveObjectDelegate_t)(alt::IObject*);

typedef void (* CreateVehicleDelegate_t)(alt::IVehicle*, uint16_t id);
typedef void (* RemoveVehicleDelegate_t)(alt::IVehicle*);

typedef void (* CreatePedDelegate_t)(alt::IPed*, uint16_t id);
typedef void (* RemovePedDelegate_t)(alt::IPed*);

typedef void (* PlayerSpawnDelegate_t)();
typedef void (* PlayerDisconnectDelegate_t)();
typedef void (* PlayerEnterVehicleDelegate_t)(alt::IVehicle*, uint8_t seat);
typedef void (* PlayerLeaveVehicleDelegate_t)(alt::IVehicle*, uint8_t seat);

typedef void (* GameEntityCreateDelegate_t)(void*, uint8_t type);
typedef void (* GameEntityDestroyDelegate_t)(void*, uint8_t type);

typedef void (* AnyResourceErrorDelegate_t)(const char* name);
typedef void (* AnyResourceStartDelegate_t)(const char* name);
typedef void (* AnyResourceStopDelegate_t)(const char* name);

typedef void (* KeyUpDelegate_t)(uint32_t key);
typedef void (* KeyDownDelegate_t)(uint32_t key);

typedef void (* PlayerChangeVehicleSeatDelegate_t)(alt::IVehicle*, uint8_t oldSeat, uint8_t newSeat);
typedef void (* PlayerChangeAnimationDelegate_t)(alt::IPlayer* player, uint32_t oldDict, uint32_t newDict, uint32_t oldName, uint32_t newName);
typedef void (* PlayerChangeInteriorDelegate_t)(alt::IPlayer* player, uint32_t oldIntLoc, uint32_t newIntLoc);

typedef void (* ConnectionCompleteDelegate_t)();

typedef void (* GlobalMetaChangeDelegate_t)(const char* key, alt::MValueConst* value, alt::MValueConst* oldValue);
typedef void (* GlobalSyncedMetaChangeDelegate_t)(const char* key, alt::MValueConst* value, alt::MValueConst* oldValue);
typedef void (* LocalMetaChangeDelegate_t)(const char* key, alt::MValueConst* value, alt::MValueConst* oldValue);
typedef void (* StreamSyncedMetaChangeDelegate_t)(void* target, alt::IBaseObject::Type type, const char* key, alt::MValueConst* value, alt::MValueConst* oldValue);
typedef void (* SyncedMetaChangeDelegate_t)(void* target, alt::IBaseObject::Type type, const char* key, alt::MValueConst* value, alt::MValueConst* oldValue);

typedef void (* NetOwnerChangeDelegate_t)(void* target, alt::IBaseObject::Type targetBaseObjectType, alt::IPlayer* newOwner, alt::IPlayer* oldOwner);
typedef void (* RemoveEntityDelegate_t)(void* target, alt::IBaseObject::Type targetBaseObjectType);

typedef void (* TaskChangeDelegate_t)(uint32_t oldTask, uint32_t newTask);

typedef void (* WindowFocusChangeDelegate_t)(uint8_t state);
typedef void (* WindowResolutionChangeDelegate_t)(vector2_t oldRes, vector2_t newRes);

typedef void (* WorldObjectPositionChangeDelegate_t)(void* target, alt::IBaseObject::Type type, vector3_t position);

typedef void (* PlayerWeaponShootDelegate_t)(uint32_t weapon, uint16_t totalAmmo, uint16_t ammoInClip);

typedef void (* PlayerWeaponChangeDelegate_t)(uint32_t oldWeapon, uint32_t newWeapon);

typedef void (* WeaponDamageDelegate_t)(const alt::CEvent* event, void* target,
                                        alt::IBaseObject::Type targetBaseObjectType,
                                        uint32_t weaponHash, uint32_t damageValue, position_t shotOffset,
                                        alt::CWeaponDamageEvent::BodyPart bodyPart);

typedef void (* CreateBlipDelegate_t)(alt::IBlip*);
typedef void (* CreateWebViewDelegate_t)(alt::IWebView*);
typedef void (* CreateCheckpointDelegate_t)(alt::ICheckpoint*);
typedef void (* CreateWebSocketClientDelegate_t)(alt::IWebSocketClient*);
typedef void (* CreateHttpClientDelegate_t)(alt::IHttpClient*);
typedef void (* CreateAudioDelegate_t)(alt::IAudio*);
typedef void (* CreateRmlElementDelegate_t)(alt::IRmlElement*);
typedef void (* CreateRmlDocumentDelegate_t)(alt::IRmlDocument*);

typedef void (* RemoveBlipDelegate_t)(alt::IBlip*);
typedef void (* RemoveWebViewDelegate_t)(alt::IWebView*);
typedef void (* RemoveCheckpointDelegate_t)(alt::ICheckpoint*);
typedef void (* RemoveWebSocketClientDelegate_t)(alt::IWebSocketClient*);
typedef void (* RemoveHttpClientDelegate_t)(alt::IHttpClient*);
typedef void (* RemoveAudioDelegate_t)(alt::IAudio*);
typedef void (* RemoveRmlElementDelegate_t)(alt::IRmlElement*);
typedef void (* RemoveRmlDocumentDelegate_t)(alt::IRmlDocument*);