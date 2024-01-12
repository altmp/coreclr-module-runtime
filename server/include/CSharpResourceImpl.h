#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "../../cpp-sdk/ICore.h"
#include <../../cpp-sdk/script-objects/IConnectionInfo.h>

#ifdef _WIN32
#define RESOURCES_PATH "\\resources\\"
#define ASSEMBLY_PATH "\\assembly.cfg"
#else
#define RESOURCES_PATH "/resources/"
#define ASSEMBLY_PATH "/assembly.cfg"
#endif

#ifdef _WIN32
#include <iostream>
#include <stdio.h>
#include <direct.h>
#else

#include <unistd.h>

#endif

#include "CoreClr.h"
#include "../../c-api/data/invoker.h"
#include "../../c-api/data/types.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif

typedef void (* MainDelegate_t)(alt::ICore* server, alt::IResource* resource, const char* resourceName,
                                const char* entryPoint);

typedef void (* TickDelegate_t)();

typedef void (* ServerEventDelegate_t)(const char* name, alt::MValueConst** args, uint64_t size);

typedef void (* CheckpointDelegate_t)(alt::ICheckpoint* checkpoint, void* entity, alt::IBaseObject::Type type,
                                      uint8_t state);

typedef void (* ClientEventDelegate_t)(alt::IPlayer* player, const char* name, alt::MValueConst** args, uint64_t);

typedef void (* PlayerConnectDelegate_t)(alt::IPlayer* player, const char* reason);

typedef void (* PlayerConnectDeniedDelegate_t)(alt::CPlayerConnectDeniedEvent::Reason reason, const char* name, const char* ip, uint64_t passwortHash, uint8_t isDebug, const char* branch, uint16_t versionMajor, uint16_t versionMinor, const char* cdnUrl, int64_t discordId);

typedef void (* ResourceEventDelegate_t)(alt::IResource* resource);

typedef void (* PlayerDamageDelegate_t)(alt::IPlayer* player, void* attacker,
                                        alt::IBaseObject::Type attackerType, uint32_t weapon,
                                        uint16_t healthDamage, uint16_t armourDamage);

typedef void (* PlayerDeathDelegate_t)(alt::IPlayer* player, void* killer, alt::IBaseObject::Type killerType,
                                       uint32_t weapon);

typedef void (* PlayerDisconnectDelegate_t)(alt::IPlayer* player, const char* reason);

typedef void (* PlayerRemoveDelegate_t)(alt::IPlayer* player);

typedef void (* VehicleRemoveDelegate_t)(alt::IVehicle* vehicle);

typedef void (* PlayerChangeVehicleSeatDelegate_t)(alt::IVehicle* vehicle, alt::IPlayer* player, uint8_t oldSeat,
                                                   uint8_t newSeat);

typedef void (* PlayerEnterVehicleDelegate_t)(alt::IVehicle* vehicle, alt::IPlayer* player, uint8_t seat);

typedef void (* PlayerEnteringVehicleDelegate_t)(alt::IVehicle* vehicle, alt::IPlayer* player, uint8_t seat);

typedef void (* PlayerLeaveVehicleDelegate_t)(alt::IVehicle* vehicle, alt::IPlayer* player, uint8_t seat);

typedef void (* StopDelegate_t)();

typedef void (* ConsoleCommandDelegate_t)(const char* name, const char* args[], uint64_t argsSize);

typedef void (* MetaChangeDelegate_t)(void* entity, alt::IBaseObject::Type type, const char* key,
                                      alt::MValueConst* value);

typedef void (* ColShapeDelegate_t)(void* colShape, void* entity, alt::IBaseObject::Type baseObjectType,
                                    uint8_t state);

typedef void (* WeaponDamageDelegate_t)(const alt::CEvent* event, alt::IPlayer* source, void* target,
                                        alt::IBaseObject::Type targetBaseObjectType,
                                        uint32_t weaponHash, uint32_t damageValue, position_t shotOffset,
                                        alt::CWeaponDamageEvent::BodyPart bodyPart);

typedef void (* ExplosionDelegate_t)(const alt::CEvent* event, alt::IPlayer* source,
                                     alt::CExplosionEvent::ExplosionType explosionType,
                                     position_t position, uint32_t explosionFX, void* targetEntity,
                                     alt::IBaseObject::Type targetType);

typedef void (* VehicleDestroyDelegate_t)(alt::IVehicle* vehicle);

typedef void (* FireDelegate_t)(const alt::CEvent* event, alt::IPlayer* source, alt::CFireEvent::FireInfo fires[],
                                uint64_t fireSize);

typedef void (* StartProjectileDelegate_t)(const alt::CEvent* event, alt::IPlayer* source, position_t startPosition,
                                           position_t direction,
                                           uint32_t ammoHash, uint32_t weaponHash);

typedef void (* PlayerWeaponChangeDelegate_t)(const alt::CEvent* event, alt::IPlayer* target, uint32_t oldWeapon,
                                              uint32_t newWeapon);

typedef void (* NetOwnerChangeDelegate_t)(const alt::CEvent* event, void* target, alt::IBaseObject::Type targetType, alt::IPlayer* oldNetOwner, alt::IPlayer* newNetOwner);

typedef void (* VehicleAttachDelegate_t)(const alt::CEvent* event, alt::IVehicle* target, alt::IVehicle* attached);

typedef void (* VehicleDetachDelegate_t)(const alt::CEvent* event, alt::IVehicle* target, alt::IVehicle* detached);

typedef void (* VehicleDamageDelegate_t)(const alt::CEvent* event, alt::IVehicle* target, void* attacker, alt::IBaseObject::Type attackerBaseObjectType,
    uint32_t bodyHealthDamage, uint32_t additionalBodyHealthDamage, uint32_t engineHealthDamage, uint32_t petrolTankDamage, uint32_t weaponHash);

typedef void (* VehicleHornDelegate_t)(const alt::CEvent* event, alt::IVehicle* target, alt::IPlayer* reporter, uint8_t toggle);

typedef void (* VehicleSirenDelegate_t)( alt::IVehicle* target, uint8_t toggle);

typedef void (* ConnectionQueueAddDelegate_t)(alt::IConnectionInfo* connectionInfo);

typedef void (* ConnectionQueueRemoveDelegate_t)(alt::IConnectionInfo* connectionInfo);

typedef void (* ServerStartedDelegate_t)();

typedef void (* PlayerRequestControlDelegate_t)(const alt::CEvent* event, void* target, alt::IBaseObject::Type targetBaseObjectType, alt::IPlayer* player);

typedef void (* PlayerDimensionChangeDelegate_t)(alt::IPlayer* player, int32_t oldDimension, int32_t newDimension);

typedef void (* PlayerChangeAnimationDelegate_t)(void* target, uint32_t oldDict, uint32_t newDict, uint32_t oldName, uint32_t newName);

typedef void (* PlayerChangeInteriorDelegate_t)(void* target, uint32_t oldIntLoc, uint32_t newIntLoc);

typedef void (* PlayerSpawnDelegate_t)(alt::IPlayer* player);

typedef void (* CreateBaseObjectDelegate_t)(void* baseObject, alt::IBaseObject::Type targetBaseObjectType, uint32_t id);

typedef void (* RemoveBaseObjectDelegate_t)(void* baseObject, alt::IBaseObject::Type targetBaseObjectType);

typedef void (* VoiceConnectionDelegate_t)(uint8_t state);

typedef void (* RequestSyncedSceneDelegate_t)(const alt::CEvent* event, alt::IPlayer* source, int32_t sceneId);

typedef void (* StartSyncedSceneDelegate_t)(alt::IPlayer* source, int32_t sceneId, position_t startPosition, rotation_t startRotation, uint32_t animDictHash, void* entities[], alt::IBaseObject::Type types[], uint32_t animHash[], uint64_t size);

typedef void (* StopSyncedSceneDelegate_t)(alt::IPlayer* source, int32_t sceneId);

typedef void (* UpdateSyncedSceneDelegate_t)(alt::IPlayer* source, float startRate, int32_t sceneId);

typedef void (* ClientRequestObjectDelegate_t)(const alt::CEvent* event, alt::IPlayer* target, uint32_t model, position_t position);

typedef void (* ClientDeleteObjectDelegate_t)(const alt::CEvent* event, alt::IPlayer* target);

typedef void (* PlayerHealDelegate_t)(alt::IPlayer* target, uint16_t oldHealth, uint16_t newHealth, uint16_t oldArmour, uint16_t newArmour);

typedef void (* GivePedScriptedTaskDelegate_t)(const alt::CEvent* event, alt::IPlayer* source, alt::IPed* target, uint32_t taskType);

typedef void (* PedDamageDelegate_t)(alt::IPed* target, void* attacker,
                                        alt::IBaseObject::Type attackerType, uint32_t weapon,
                                        uint16_t healthDamage, uint16_t armourDamage);

typedef void (* PedDeathDelegate_t)(alt::IPed* target, void* killer, alt::IBaseObject::Type killerType,
                                       uint32_t weapon);

typedef void (* PedHealDelegate_t)(alt::IPed* target, uint16_t oldHealth, uint16_t newHealth, uint16_t oldArmour, uint16_t newArmour);

typedef void (* PlayerStartTalkingDelegate_t)(alt::IPlayer* player);
typedef void (* PlayerStopTalkingDelegate_t)(alt::IPlayer* player);

typedef void (* ScriptRPCDelegate_t)(const alt::CEvent* event, alt::IPlayer* target, const char* name, alt::MValueConst** args, uint64_t size, uint16_t answerID);

typedef void (* ScriptRPCAnswerDelegate_t)(alt::IPlayer* target, uint16_t answerID, alt::MValueConst* answer, const char* answerError);

class CSharpResourceImpl : public alt::IResource::Impl {
    void OnEvent(const alt::CEvent* ev) override;

    void OnTick() override;

    bool Start() override;

    bool Stop() override;

    void OnCreateBaseObject(alt::IBaseObject* object) override;

    void OnRemoveBaseObject(alt::IBaseObject* object) override;

    static void* GetBaseObjectPointer(alt::IBaseObject* baseObject);

    static void* GetWorldObjectPointer(alt::IWorldObject* worldObject);

    static void* GetEntityPointer(alt::IEntity* entity);

    static alt::IBaseObject::Type GetEntityType(alt::IEntity* entity);

    void ResetDelegates();

public:
    CSharpResourceImpl(alt::ICore* server, CoreClr* coreClr, alt::IResource* resource);

    ~CSharpResourceImpl() override;

    bool MakeClient(alt::IResource::CreationInfo* info, std::vector<std::string> files) override;

    CheckpointDelegate_t OnCheckpointDelegate = nullptr;

    ClientEventDelegate_t OnClientEventDelegate = nullptr;

    PlayerConnectDelegate_t OnPlayerConnectDelegate = nullptr;

    PlayerConnectDeniedDelegate_t OnPlayerConnectDeniedDelegate = nullptr;

    ResourceEventDelegate_t OnResourceStartDelegate = nullptr;

    ResourceEventDelegate_t OnResourceStopDelegate = nullptr;

    ResourceEventDelegate_t OnResourceErrorDelegate = nullptr;

    PlayerDamageDelegate_t OnPlayerDamageDelegate = nullptr;

    PlayerDeathDelegate_t OnPlayerDeathDelegate = nullptr;

    ExplosionDelegate_t OnExplosionDelegate = nullptr;

    WeaponDamageDelegate_t OnWeaponDamageDelegate = nullptr;

    PlayerDisconnectDelegate_t OnPlayerDisconnectDelegate = nullptr;

    PlayerRemoveDelegate_t OnPlayerRemoveDelegate = nullptr;

    VehicleRemoveDelegate_t OnVehicleRemoveDelegate = nullptr;

    ServerEventDelegate_t OnServerEventDelegate = nullptr;

    PlayerChangeVehicleSeatDelegate_t OnPlayerChangeVehicleSeatDelegate = nullptr;

    PlayerEnterVehicleDelegate_t OnPlayerEnterVehicleDelegate = nullptr;

    PlayerEnteringVehicleDelegate_t OnPlayerEnteringVehicleDelegate = nullptr;

    PlayerLeaveVehicleDelegate_t OnPlayerLeaveVehicleDelegate = nullptr;

    StopDelegate_t OnStopDelegate = nullptr;

    MainDelegate_t MainDelegate = nullptr;

    TickDelegate_t OnTickDelegate = nullptr;

    ConsoleCommandDelegate_t OnConsoleCommandDelegate = nullptr;

    MetaChangeDelegate_t OnMetaChangeDelegate = nullptr;

    MetaChangeDelegate_t OnSyncedMetaChangeDelegate = nullptr;

    ColShapeDelegate_t OnColShapeDelegate = nullptr;

    VehicleDestroyDelegate_t OnVehicleDestroyDelegate = nullptr;

    FireDelegate_t OnFireDelegate = nullptr;

    StartProjectileDelegate_t OnStartProjectileDelegate = nullptr;

    PlayerWeaponChangeDelegate_t OnPlayerWeaponChangeDelegate = nullptr;

    NetOwnerChangeDelegate_t OnNetOwnerChangeDelegate = nullptr;

    VehicleAttachDelegate_t OnVehicleAttachDelegate = nullptr;

    VehicleDetachDelegate_t OnVehicleDetachDelegate = nullptr;

    VehicleDamageDelegate_t OnVehicleDamageDelegate = nullptr;

    VehicleHornDelegate_t OnVehicleHornDelegate = nullptr;

    VehicleSirenDelegate_t OnVehicleSirenDelegate = nullptr;

    ConnectionQueueAddDelegate_t OnConnectionQueueAddDelegate = nullptr;

    ConnectionQueueRemoveDelegate_t OnConnectionQueueRemoveDelegate = nullptr;

    ServerStartedDelegate_t OnServerStartedDelegate = nullptr;

    PlayerRequestControlDelegate_t OnPlayerRequestControlDelegate = nullptr;

    PlayerDimensionChangeDelegate_t OnPlayerDimensionChangeDelegate = nullptr;

    PlayerChangeAnimationDelegate_t OnPlayerChangeAnimationDelegate = nullptr;

    PlayerChangeInteriorDelegate_t OnPlayerChangeInteriorDelegate = nullptr;

    PlayerSpawnDelegate_t OnPlayerSpawnDelegate = nullptr;

    CreateBaseObjectDelegate_t OnCreateBaseObjectDelegate = nullptr;
    RemoveBaseObjectDelegate_t OnRemoveBaseObjectDelegate = nullptr;

    VoiceConnectionDelegate_t OnVoiceConnectionDelegate = nullptr;

    RequestSyncedSceneDelegate_t OnRequestSyncedSceneDelegate = nullptr;
    StartSyncedSceneDelegate_t OnStartSyncedSceneDelegate = nullptr;
    StopSyncedSceneDelegate_t OnStopSyncedSceneDelegate = nullptr;
    UpdateSyncedSceneDelegate_t OnUpdateSyncedSceneDelegate = nullptr;

    ClientRequestObjectDelegate_t OnClientRequestObjectDelegate = nullptr;
    ClientDeleteObjectDelegate_t OnClientDeleteObjectDelegate = nullptr;

    PlayerHealDelegate_t OnPlayerHealDelegate = nullptr;

    GivePedScriptedTaskDelegate_t OnGivePedScriptedTaskDelegate = nullptr;

    PedDamageDelegate_t OnPedDamageDelegate = nullptr;
    PedDeathDelegate_t OnPedDeathDelegate = nullptr;
    PedHealDelegate_t OnPedHealDelegate = nullptr;

    PlayerStartTalkingDelegate_t OnPlayerStartTalkingDelegate = nullptr;
    PlayerStopTalkingDelegate_t OnPlayerStopTalkingDelegate = nullptr;

    ScriptRPCDelegate_t OnScriptRPCDelegate = nullptr;

    ScriptRPCAnswerDelegate_t OnScriptRPCAnswerDelegate = nullptr;

    std::vector<CustomInvoker*> invokers;
    std::mutex invokersLock = {};
    CoreClr* coreClr;
    alt::ICore* core;
    alt::IResource* resource;
};

class BaseObjectWeakReference : public alt::IWeakRef {

public:
    alt::IBaseObject* baseObject;
    CSharpResourceImpl* cSharpResource;

    BaseObjectWeakReference(alt::IBaseObject* baseObject, CSharpResourceImpl* cSharpResource) {
        this->baseObject = baseObject;
        this->cSharpResource = cSharpResource;
    }

    void OnDestroy() override {
        auto object = this->baseObject;
        if (object != nullptr) {
            switch (object->GetType()) {
                case alt::IBaseObject::Type::PLAYER:
                    this->cSharpResource->OnRemoveBaseObjectDelegate(dynamic_cast<alt::IPlayer*>(object), object->GetType());
                    break;
                case alt::IBaseObject::Type::VEHICLE:
                    this->cSharpResource->OnRemoveBaseObjectDelegate(dynamic_cast<alt::IVehicle*>(object), object->GetType());
                    break;
                case alt::IBaseObject::Type::BLIP:
                    this->cSharpResource->OnRemoveBaseObjectDelegate(dynamic_cast<alt::IBlip*>(object), object->GetType());
                    break;
                case alt::IBaseObject::Type::VOICE_CHANNEL:
                    this->cSharpResource->OnRemoveBaseObjectDelegate(dynamic_cast<alt::IVoiceChannel*>(object), object->GetType());
                    break;
                case alt::IBaseObject::Type::COLSHAPE:
                    this->cSharpResource->OnRemoveBaseObjectDelegate(dynamic_cast<alt::IColShape*>(object), object->GetType());
                    break;
                case alt::IBaseObject::Type::CHECKPOINT:
                    this->cSharpResource->OnRemoveBaseObjectDelegate(dynamic_cast<alt::ICheckpoint*>(object), object->GetType());
                    break;
                case alt::IBaseObject::Type::LOCAL_OBJECT:
                    this->cSharpResource->OnRemoveBaseObjectDelegate(dynamic_cast<alt::ILocalObject*>(object), object->GetType());
                break;
                case alt::IBaseObject::Type::PED:
                    this->cSharpResource->OnRemoveBaseObjectDelegate(dynamic_cast<alt::IPed*>(object), object->GetType());
                    break;
                case alt::IBaseObject::Type::VIRTUAL_ENTITY:
                    this->cSharpResource->OnRemoveBaseObjectDelegate(dynamic_cast<alt::IVirtualEntity*>(object), object->GetType());
                    break;
                case alt::IBaseObject::Type::VIRTUAL_ENTITY_GROUP:
                    this->cSharpResource->OnRemoveBaseObjectDelegate(dynamic_cast<alt::IVirtualEntityGroup*>(object), object->GetType());
                    break;
                case alt::IBaseObject::Type::OBJECT:
                    this->cSharpResource->OnRemoveBaseObjectDelegate(dynamic_cast<alt::IObject*>(object), object->GetType());
                    break;
            }
        }
        delete this;
    }
};

EXPORT void CSharpResourceImpl_SetMainDelegate(CSharpResourceImpl* resource,
                                               MainDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetStopDelegate(CSharpResourceImpl* resource,
                                               StopDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetTickDelegate(CSharpResourceImpl* resource,
                                               TickDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetServerEventDelegate(CSharpResourceImpl* resource,
                                                      ServerEventDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetCheckpointDelegate(CSharpResourceImpl* resource,
                                                     CheckpointDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetClientEventDelegate(CSharpResourceImpl* resource,
                                                      ClientEventDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPlayerDamageDelegate(CSharpResourceImpl* resource,
                                                       PlayerDamageDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPlayerConnectDelegate(CSharpResourceImpl* resource,
                                                        PlayerConnectDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPlayerConnectDeniedDelegate(CSharpResourceImpl* resource,
                                                              PlayerConnectDeniedDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetResourceStartDelegate(CSharpResourceImpl* resource,
                                                        ResourceEventDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetResourceStopDelegate(CSharpResourceImpl* resource,
                                                       ResourceEventDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetResourceErrorDelegate(CSharpResourceImpl* resource,
                                                        ResourceEventDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPlayerDeathDelegate(CSharpResourceImpl* resource,
                                                      PlayerDeathDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetExplosionDelegate(CSharpResourceImpl* resource,
                                                    ExplosionDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetWeaponDamageDelegate(CSharpResourceImpl* resource,
                                                       WeaponDamageDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPlayerDisconnectDelegate(CSharpResourceImpl* resource,
                                                           PlayerDisconnectDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPlayerRemoveDelegate(CSharpResourceImpl* resource,
                                                       PlayerRemoveDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetVehicleRemoveDelegate(CSharpResourceImpl* resource,
                                                        VehicleRemoveDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPlayerChangeVehicleSeatDelegate(CSharpResourceImpl* resource,
                                                                  PlayerChangeVehicleSeatDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPlayerEnterVehicleDelegate(CSharpResourceImpl* resource,
                                                             PlayerEnterVehicleDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPlayerEnteringVehicleDelegate(CSharpResourceImpl* resource,
                                                                PlayerEnteringVehicleDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPlayerLeaveVehicleDelegate(CSharpResourceImpl* resource,
                                                             PlayerLeaveVehicleDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetConsoleCommandDelegate(CSharpResourceImpl* resource,
                                                         ConsoleCommandDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetMetaChangeDelegate(CSharpResourceImpl* resource,
                                                     MetaChangeDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetSyncedMetaChangeDelegate(CSharpResourceImpl* resource,
                                                           MetaChangeDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetColShapeDelegate(CSharpResourceImpl* resource,
                                                   ColShapeDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetVehicleDestroyDelegate(CSharpResourceImpl* resource,
                                                         VehicleDestroyDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetFireDelegate(CSharpResourceImpl* resource,
                                               FireDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetStartProjectileDelegate(CSharpResourceImpl* resource,
                                                          StartProjectileDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPlayerWeaponChangeDelegate(CSharpResourceImpl* resource,
                                                             PlayerWeaponChangeDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetNetOwnerChangeDelegate(CSharpResourceImpl* resource,
                                                         NetOwnerChangeDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetVehicleAttachDelegate(CSharpResourceImpl* resource,
                                                 VehicleAttachDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetVehicleDetachDelegate(CSharpResourceImpl* resource,
                                                 VehicleDetachDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetVehicleDamageDelegate(CSharpResourceImpl* resource,
    VehicleDamageDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetVehicleHornDelegate(CSharpResourceImpl* resource, VehicleHornDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetVehicleSirenDelegate(CSharpResourceImpl* resource, VehicleSirenDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetConnectionQueueAddDelegate(CSharpResourceImpl* resource,
                                                      ConnectionQueueAddDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetConnectionQueueRemoveDelegate(CSharpResourceImpl* resource,
                                                         ConnectionQueueRemoveDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetServerStartedDelegate(CSharpResourceImpl* resource,
                                                         ServerStartedDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPlayerRequestControlDelegate(CSharpResourceImpl* resource,
                                                            PlayerRequestControlDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPlayerDimensionChangeDelegate(CSharpResourceImpl* resource,
                                                            PlayerDimensionChangeDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPlayerChangeAnimationDelegate(CSharpResourceImpl* resource,
                                                            PlayerChangeAnimationDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPlayerChangeInteriorDelegate(CSharpResourceImpl* resource,
                                                            PlayerChangeInteriorDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPlayerSpawnDelegate(CSharpResourceImpl* resource, PlayerSpawnDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetVoiceConnectionDelegate(CSharpResourceImpl* resource, VoiceConnectionDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetCreateBaseObjectDelegate(CSharpResourceImpl* resource, CreateBaseObjectDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetRemoveBaseObjectDelegate(CSharpResourceImpl* resource, RemoveBaseObjectDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetRequestSyncedSceneDelegate(CSharpResourceImpl* resource, RequestSyncedSceneDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetStartSyncedSceneDelegate(CSharpResourceImpl* resource, StartSyncedSceneDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetStopSyncedSceneDelegate(CSharpResourceImpl* resource, StopSyncedSceneDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetUpdateSyncedSceneDelegate(CSharpResourceImpl* resource, UpdateSyncedSceneDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetClientRequestObjectDelegate(CSharpResourceImpl* resource, ClientRequestObjectDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetClientDeleteObjectDelegate(CSharpResourceImpl* resource, ClientDeleteObjectDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPlayerHealDelegate(CSharpResourceImpl* resource, PlayerHealDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetGivePedScriptedTaskDelegate(CSharpResourceImpl* resource, GivePedScriptedTaskDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPedDamageDelegate(CSharpResourceImpl* resource, PedDamageDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPedDeathDelegate(CSharpResourceImpl* resource, PedDeathDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPedHealDelegate(CSharpResourceImpl* resource, PedHealDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetPlayerStartTalkingDelegate(CSharpResourceImpl* resource, PlayerStartTalkingDelegate_t delegate);
EXPORT void CSharpResourceImpl_SetPlayerStopTalkingDelegate(CSharpResourceImpl* resource, PlayerStopTalkingDelegate_t delegate);

EXPORT void CSharpResourceImpl_SetScriptRPCDelegate(CSharpResourceImpl* resource, ScriptRPCDelegate_t delegate);
EXPORT void CSharpResourceImpl_SetScriptRPCAnswerDelegate(CSharpResourceImpl* resource, ScriptRPCAnswerDelegate_t delegate);


