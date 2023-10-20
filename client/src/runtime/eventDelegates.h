#pragma once
#include "cpp-sdk/ICore.h"
#include "../../../c-api/data/types.h"

typedef void (* TickDelegate_t)();
typedef void (* ClientEventDelegate_t)(const char* name, alt::MValueConst** args, uint64_t size);
typedef void (* ServerEventDelegate_t)(const char* name, alt::MValueConst** args, uint64_t size);
typedef void (* WebViewEventDelegate_t)(alt::IWebView*, const char* name, alt::MValueConst** args, uint64_t size);
typedef void (* ConsoleCommandDelegate_t)(const char* name, const char* args[], uint64_t size);
typedef void (* WebSocketEventDelegate_t)(alt::IWebSocketClient*, const char* name, alt::MValueConst** args, uint64_t size);
typedef void (* RmlEventDelegate_t)(alt::IRmlElement*, const char* name, alt::MValueConst* args);
typedef void (* AudioEventDelegate_t)(alt::IAudio*, const char* name, alt::MValueConst** args, uint64_t size);

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
typedef void (* MetaChangeDelegate_t)(void* target, alt::IBaseObject::Type type, const char* key, alt::MValueConst* value, alt::MValueConst* oldValue);

typedef void (* NetOwnerChangeDelegate_t)(void* target, alt::IBaseObject::Type targetBaseObjectType, alt::IPlayer* newOwner, alt::IPlayer* oldOwner);

typedef void (* TaskChangeDelegate_t)(uint32_t oldTask, uint32_t newTask);

typedef void (* WindowFocusChangeDelegate_t)(uint8_t state);
typedef void (* WindowResolutionChangeDelegate_t)(vector2_t oldRes, vector2_t newRes);

typedef void (* WorldObjectPositionChangeDelegate_t)(void* target, alt::IBaseObject::Type type, position_t position);
typedef void (* WorldObjectStreamInDelegate_t)(void* target, alt::IBaseObject::Type type);
typedef void (* WorldObjectStreamOutDelegate_t)(void* target, alt::IBaseObject::Type type);

typedef void (* PlayerWeaponShootDelegate_t)(uint32_t weapon, uint16_t totalAmmo, uint16_t ammoInClip);

typedef void (* PlayerWeaponChangeDelegate_t)(uint32_t oldWeapon, uint32_t newWeapon);

typedef void (* WeaponDamageDelegate_t)(const alt::CEvent* event, void* target,
                                        alt::IBaseObject::Type targetBaseObjectType,
                                        uint32_t weaponHash, uint32_t damageValue, position_t shotOffset,
                                        alt::CWeaponDamageEvent::BodyPart bodyPart,
                                        void* sourceEntity,
                                        alt::IBaseObject::Type sourceEntityType);

typedef void (* CreateBaseObjectDelegate_t)(void* baseObject, alt::IBaseObject::Type targetBaseObjectType, uint32_t id);

typedef void (* RemoveBaseObjectDelegate_t)(void* baseObject, alt::IBaseObject::Type targetBaseObjectType);


typedef void (* CheckpointDelegate_t)(alt::ICheckpoint* checkpoint, void* entity, alt::IBaseObject::Type type, uint8_t state);
typedef void (* ColShapeDelegate_t)(alt::IColShape* colShape, void* entity, alt::IBaseObject::Type type, uint8_t state);

typedef void (* EntityHitEntityDelegate_t)(void* target, alt::IBaseObject::Type targetType, void* damager, alt::IBaseObject::Type damagerType, uint32_t weaponHash);

typedef void (* PlayerStartEnterVehicleDelegate_t)(void* target, void* player, uint8_t seat);
typedef void (* PlayerStartLeaveVehicleDelegate_t)(void* target, void* player, uint8_t seat);

typedef void (* PlayerBulletHitDelegate_t)(uint32_t weapon, void* victim, alt::IBaseObject::Type victimType, position_t pos);

typedef void (* VoiceConnectionDelegate_t)(uint8_t state);
typedef void (* ScriptRPCDelegate_t)(const alt::CEvent* event, const char* name, alt::MValueConst** args, uint64_t size, uint16_t answerID);
typedef void (* ScriptRPCAnswerDelegate_t)(uint16_t answerId, alt::MValueConst* answer, const char* answerError);
