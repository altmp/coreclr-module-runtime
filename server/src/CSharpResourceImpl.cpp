#include "CSharpResourceImpl.h"
#include "../../c-api/utils/entity.h"
#include "../../c-api/mvalue.h"

CSharpResourceImpl::CSharpResourceImpl(alt::ICore* core, CoreClr* coreClr, alt::IResource* resource)
    : alt::IResource::Impl()
{
    ResetDelegates();
    this->resource = resource;
    this->core = core;
    this->invokers = {};
    this->coreClr = coreClr;
}

void CSharpResourceImpl::ResetDelegates()
{
    MainDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnClientEventDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnPlayerConnectDelegate = [](auto var, auto var2) {};
    OnPlayerConnectDeniedDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5, auto var6, auto var7, auto var8, auto var9, auto var10) {};
    OnResourceStartDelegate = [](auto var) {};
    OnResourceStopDelegate = [](auto var) {};
    OnResourceErrorDelegate = [](auto var) {};
    OnPlayerDamageDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5, auto var6) {};
    OnPlayerDeathDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnExplosionDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5, auto var6, auto var7) {};
    OnWeaponDamageDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5, auto var6, auto var7,
                                auto var8) {};
    OnPlayerDisconnectDelegate = [](auto var, auto var2) {};
    OnServerEventDelegate = [](auto var, auto var2, auto var3) {};
    OnPlayerChangeVehicleSeatDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnPlayerEnterVehicleDelegate = [](auto var, auto var2, auto var3) {};
    OnPlayerEnteringVehicleDelegate = [](auto var, auto var2, auto var3) {};
    OnPlayerLeaveVehicleDelegate = [](auto var, auto var2, auto var3) {};
    OnStopDelegate = []() {};
    OnTickDelegate = []() {};
    OnConsoleCommandDelegate = [](auto var, auto var2, auto var3) {};
    OnMetaChangeDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnSyncedMetaChangeDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnColShapeDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnCheckpointDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnVehicleDestroyDelegate = [](auto var) {};
    OnFireDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnStartProjectileDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5, auto var6) {};
    OnPlayerWeaponChangeDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnNetOwnerChangeDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5) {};
    OnVehicleAttachDelegate = [](auto var, auto var2, auto var3) {};
    OnVehicleDetachDelegate = [](auto var, auto var2, auto var3) {};
    OnVehicleDamageDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5, auto var6, auto var7,
        auto var8, auto var9) {};
    OnVehicleHornDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnVehicleSirenDelegate = [](auto var, auto var2) {};
    OnConnectionQueueAddDelegate = [](auto var){};
    OnConnectionQueueRemoveDelegate = [](auto var){};
    OnServerStartedDelegate = []() {};
    OnPlayerRequestControlDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnPlayerDimensionChangeDelegate = [](auto var, auto var2, auto var3) {};
    OnPlayerSpawnDelegate = [](auto var) {};

    OnVoiceConnectionDelegate = [](auto var) {};

    OnCreateBaseObjectDelegate = [](auto var, auto var2, auto var3) {};
    OnRemoveBaseObjectDelegate = [](auto var, auto var2) {};

    OnRequestSyncedSceneDelegate = [](auto var, auto var2, auto var3) {};
    OnStartSyncedSceneDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5, auto var6, auto var7, auto var8, auto var9) {};
    OnStopSyncedSceneDelegate = [](auto var, auto var2) {};
    OnUpdateSyncedSceneDelegate = [](auto var, auto var2, auto var3) {};

    OnClientRequestObjectDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnClientDeleteObjectDelegate = [](auto var, auto var2) {};

    OnPlayerHealDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5) {};

    OnGivePedScriptedTaskDelegate = [](auto var, auto var2, auto var3, auto var4) {};

    OnPedDamageDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5, auto var6) {};
    OnPedDeathDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnPedHealDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5) {};

    OnScriptRPCDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5, auto var6) {};

    OnScriptRPCAnswerDelegate = [](auto var, auto var2, auto var3, auto var4) {};
}

bool CSharpResourceImpl::Start()
{
    ResetDelegates();

    if (!coreClr->ExecuteManagedResource(
        this->resource->GetPath().c_str(),
        this->resource->GetName().c_str(),
        this->resource->GetMain().c_str(),
        this->resource))
    {
        return false;
    }
    if (MainDelegate == nullptr) return false;
    MainDelegate(this->core, this->resource, this->resource->GetName().c_str(), resource->GetMain().c_str());
    return true;
}

bool CSharpResourceImpl::Stop()
{
    if (OnStopDelegate == nullptr) return false;
    OnStopDelegate();
    ResetDelegates();
    return coreClr->ExecuteManagedResourceUnload(this->resource->GetPath().c_str(), this->resource->GetMain().c_str());
}

CSharpResourceImpl::~CSharpResourceImpl() {
    //TODO: fix segmentation fault
    /*for (alt::Size i = 0, length = invokers->GetSize(); i < length; i++) {
        auto invoker = (*invokers)[i];
        delete invoker;
    }*/
    //delete[] invokers;
}

void CSharpResourceImpl::OnEvent(const alt::CEvent* ev)
{
    if (ev == nullptr) return;
    switch (ev->GetType())
    {
    /*
case alt::CEvent::Type::META_CHANGE:
    {
        auto event = ((alt::CMetaChangeEvent*) (ev));
        auto entity = event->GetTarget().Get();
        if (entity == nullptr) return;
        auto key = event->GetKey();
        auto value = event->GetVal();
        const char* keyCStr;
        if (key == nullptr) {
            keyCStr = "";
        } else {
            keyCStr = key.c_str();
            if (keyCStr == nullptr) {
                keyCStr = "";
            }
        }
        auto constValue = alt::MValueConst(value);
        OnMetaChangeDelegate(GetEntityPointer(entity), entity->GetType(), keyCStr, &constValue);
        break;
    }
case alt::CEvent::Type::SYNCED_META_CHANGE:
    {
        auto event = ((alt::CSyncedMetaDataChangeEvent*) (ev));
        auto entity = event->GetTarget().Get();
        if (entity == nullptr) return;
        auto key = event->GetKey();
        auto value = event->GetVal();
        const char* keyCStr;
        if (key == nullptr) {
            keyCStr = "";
        } else {
            keyCStr = key.c_str();
            if (keyCStr == nullptr) {
                keyCStr = "";
            }
        }
        auto constValue = alt::MValueConst(value);
        OnSyncedMetaChangeDelegate(GetEntityPointer(entity), entity->GetType(), keyCStr, &constValue);
        break;
    }*/
    case alt::CEvent::Type::CLIENT_SCRIPT_EVENT:
        {
            auto clientScriptEvent = dynamic_cast<const alt::CClientScriptEvent*>(ev);
            alt::MValueArgs clientArgs = clientScriptEvent->GetArgs();
            uint64_t size = clientArgs.size();
            if (size == 0)
            {
                OnClientEventDelegate(clientScriptEvent->GetTarget(),
                                      clientScriptEvent->GetName().c_str(),
                                      nullptr, 0);
            }
            else
            {
#ifdef _WIN32
                auto constArgs = new alt::MValueConst*[size];
#else
                alt::MValueConst* constArgs[size];
#endif
                for (uint64_t i = 0; i < size; i++)
                {
                    constArgs[i] = &clientArgs[i];
                }
                OnClientEventDelegate(clientScriptEvent->GetTarget(),
                                      clientScriptEvent->GetName().c_str(),
                                      constArgs, size);

#ifdef _WIN32
                delete[] constArgs;
#endif
            }
            break;
        }
    case alt::CEvent::Type::PLAYER_CONNECT:
        {
            auto playerConnectEvent = dynamic_cast<const alt::CPlayerConnectEvent*>(ev);
            auto connectPlayer = playerConnectEvent->GetTarget();
            OnPlayerConnectDelegate(connectPlayer,
                                    playerConnectEvent->GetReason().c_str());
            break;
        }
    case alt::CEvent::Type::PLAYER_CONNECT_DENIED:
        {
            auto playerConnectDeniedEvent = dynamic_cast<const alt::CPlayerConnectDeniedEvent*>(ev);

            OnPlayerConnectDeniedDelegate(playerConnectDeniedEvent->GetReason(),
                                          playerConnectDeniedEvent->GetName().c_str(),
                                          playerConnectDeniedEvent->GetIp().c_str(),
                                          playerConnectDeniedEvent->GetPasswordHash(),
                                          playerConnectDeniedEvent->IsDebug(),
                                          playerConnectDeniedEvent->GetBranch().c_str(),
                                          playerConnectDeniedEvent->GetVersionMajor(),
                                          playerConnectDeniedEvent->GetVersionMinor(),
                                          playerConnectDeniedEvent->GetCdnUrl().c_str(),
                                          playerConnectDeniedEvent->GetDiscordId()
            );

            break;
        }
    case alt::CEvent::Type::RESOURCE_START:
        {
            OnResourceStartDelegate(dynamic_cast<const alt::CResourceStartEvent*>(ev)->GetResource());
            break;
        }
    case alt::CEvent::Type::RESOURCE_STOP:
        {
            OnResourceStopDelegate(dynamic_cast<const alt::CResourceStopEvent*>(ev)->GetResource());
            break;
        }
    case alt::CEvent::Type::RESOURCE_ERROR:
        {
            OnResourceErrorDelegate(dynamic_cast<const alt::CResourceErrorEvent*>(ev)->GetResource());
            break;
        }
    case alt::CEvent::Type::PLAYER_DAMAGE:
        {
            auto damageEvent = dynamic_cast<const alt::CPlayerDamageEvent*>(ev);
            auto entity = damageEvent->GetAttacker();
            auto entityPtr = GetEntityPointer(entity);
            if (entity != nullptr && entityPtr != nullptr)
            {
                OnPlayerDamageDelegate(damageEvent->GetTarget(),
                                       entityPtr,
                                       entity->GetType(),
                                       damageEvent->GetWeapon(),
                                       damageEvent->GetHealthDamage(),
                                       damageEvent->GetArmourDamage());
            }
            else
            {
                OnPlayerDamageDelegate(damageEvent->GetTarget(),
                                       nullptr,
                                       alt::IBaseObject::Type::PLAYER,
                                       damageEvent->GetWeapon(),
                                       damageEvent->GetHealthDamage(),
                                       damageEvent->GetArmourDamage());
            }
            break;
        }
    case alt::CEvent::Type::PLAYER_DEATH:
        {
            auto playerDeathEvent = dynamic_cast<const alt::CPlayerDeathEvent*>(ev);
            auto entity = playerDeathEvent->GetKiller();

            auto type = alt::IBaseObject::Type::PLAYER;
            void* entityPtr = nullptr;

            if (entity != nullptr)
            {
                entityPtr = GetEntityPointer(entity);
                type = entity->GetType();
            }

            OnPlayerDeathDelegate(playerDeathEvent->GetTarget(),
                                  entityPtr,
                                  type,
                                  playerDeathEvent->GetWeapon());
            break;
        }
    case alt::CEvent::Type::FIRE_EVENT:
        {
            auto fireEvent = dynamic_cast<const alt::CFireEvent*>(ev);
            auto source = fireEvent->GetSource();
            auto fires = fireEvent->GetFires();
            uint64_t length = fires.size();

            if (length == 0)
            {
                OnFireDelegate(fireEvent,
                               source,
                               nullptr,
                               0);
            }
            else
            {
                auto fireArray = new alt::CFireEvent::FireInfo[length];
                for (uint64_t i = 0; i < length; ++i)
                {
                    auto const fire = fires[i];
                    fireArray[i] = fire;
                }
                OnFireDelegate(fireEvent,
                               source,
                               fireArray,
                               length);
                delete[] fireArray;
            }
            break;
        }
    case alt::CEvent::Type::EXPLOSION_EVENT:
        {
            auto explosionEvent = dynamic_cast<const alt::CExplosionEvent*>(ev);
            auto eventPosition = explosionEvent->GetPosition();
            auto targetEntity = explosionEvent->GetTarget();
            position_t position = {eventPosition.x, eventPosition.y, eventPosition.z};

            OnExplosionDelegate(explosionEvent,
                                explosionEvent->GetSource(),
                                explosionEvent->GetExplosionType(),
                                position,
                                explosionEvent->GetExplosionFX(),
                                GetEntityPointer(targetEntity),
                                GetEntityType(targetEntity));

            break;
        }
    case alt::CEvent::Type::WEAPON_DAMAGE_EVENT:
        {
            auto weaponDamageEvent = dynamic_cast<const alt::CWeaponDamageEvent*>(ev);
            auto targetEntity = weaponDamageEvent->GetTarget();

            if (targetEntity == nullptr) return;

            auto eventShotOffset = weaponDamageEvent->GetShotOffset();
            position_t shotOffset = {eventShotOffset[0], eventShotOffset[1], eventShotOffset[2]};

            OnWeaponDamageDelegate(ev,
                                   weaponDamageEvent->GetSource(),
                                   GetEntityPointer(targetEntity),
                                   targetEntity->GetType(),
                                   weaponDamageEvent->GetWeaponHash(),
                                   weaponDamageEvent->GetDamageValue(),
                                   shotOffset,
                                   weaponDamageEvent->GetBodyPart());

            break;
        }
    case alt::CEvent::Type::PLAYER_DISCONNECT:
        {
            auto disconnectEvent = dynamic_cast<const alt::CPlayerDisconnectEvent*>(ev);
            auto disconnectPlayer = disconnectEvent->GetTarget();

            //TODO: Implement disconnect reason
            //auto reason = disconnectEvent->GetReason();

            OnPlayerDisconnectDelegate(disconnectPlayer,
                                       "");
            break;
        }
    case alt::CEvent::Type::SERVER_SCRIPT_EVENT:
        {
            auto serverScriptEvent = dynamic_cast<const alt::CServerScriptEvent*>(ev);
            alt::MValueArgs serverArgs = serverScriptEvent->GetArgs();
            uint64_t size = serverArgs.size();
            if (size == 0)
            {
                OnServerEventDelegate(serverScriptEvent->GetName().c_str(),
                                      nullptr,
                                      0);
            }
            else
            {
#ifdef _WIN32
                auto constArgs = new alt::MValueConst*[size];
#else
                alt::MValueConst* constArgs[size];
#endif
                for (uint64_t i = 0; i < size; i++)
                {
                    constArgs[i] = &serverArgs[i];
                }
                OnServerEventDelegate(serverScriptEvent->GetName().c_str(),
                                      constArgs,
                                      size);
#ifdef _WIN32
                delete[] constArgs;
#endif
            }
            break;
        }
    case alt::CEvent::Type::PLAYER_CHANGE_VEHICLE_SEAT:
        {
            auto changeSeatEvent = dynamic_cast<const alt::CPlayerChangeVehicleSeatEvent*>(ev);
            OnPlayerChangeVehicleSeatDelegate(changeSeatEvent->GetTarget(),
                                              changeSeatEvent->GetPlayer(),
                                              changeSeatEvent->GetOldSeat(),
                                              changeSeatEvent->GetNewSeat());
            break;
        }
    case alt::CEvent::Type::PLAYER_ENTER_VEHICLE:
        {
            auto enterEvent = dynamic_cast<const alt::CPlayerEnterVehicleEvent*>(ev);
            OnPlayerEnterVehicleDelegate(enterEvent->GetTarget(),
                                         enterEvent->GetPlayer(),
                                         enterEvent->GetSeat());
            break;
        }
    case alt::CEvent::Type::PLAYER_ENTERING_VEHICLE:
        {
            auto enteringEvent = dynamic_cast<const alt::CPlayerEnteringVehicleEvent*>(ev);
            OnPlayerEnteringVehicleDelegate(enteringEvent->GetTarget(),
                                            enteringEvent->GetPlayer(),
                                            enteringEvent->GetSeat());
            break;
        }
    case alt::CEvent::Type::PLAYER_LEAVE_VEHICLE:
        {
            auto leaveEvent = dynamic_cast<const alt::CPlayerLeaveVehicleEvent*>(ev);
            OnPlayerLeaveVehicleDelegate(leaveEvent->GetTarget(),
                                         leaveEvent->GetPlayer(),
                                         leaveEvent->GetSeat());
            break;
        }
    case alt::CEvent::Type::PLAYER_CHANGE_ANIMATION_EVENT:
        {
            auto animationEvent = dynamic_cast<const alt::CPlayerChangeAnimationEvent*>(ev);
            OnPlayerChangeAnimationDelegate(animationEvent->GetTarget(),
                                            animationEvent->GetOldAnimationDict(),
                                            animationEvent->GetNewAnimationDict(),
                                            animationEvent->GetOldAnimationName(),
                                            animationEvent->GetNewAnimationName());
            break;
        }
    case alt::CEvent::Type::PLAYER_CHANGE_INTERIOR_EVENT:
        {
            auto interiorEvent = dynamic_cast<const alt::CPlayerChangeInteriorEvent*>(ev);
            OnPlayerChangeInteriorDelegate(interiorEvent->GetTarget(),
                                           interiorEvent->GetOldInteriorLocation(),
                                           interiorEvent->GetNewInteriorLocation());
            break;
        }
    case alt::CEvent::Type::CONSOLE_COMMAND_EVENT:
        {
            auto consoleCommandEvent = dynamic_cast<const alt::CConsoleCommandEvent*>(ev);
            std::vector<std::string> args = consoleCommandEvent->GetArgs();

            uint64_t size = args.size();
            if (size == 0)
            {
                OnConsoleCommandDelegate(consoleCommandEvent->GetName().c_str(),
                                         nullptr,
                                         0);
            }
            else
            {
#ifdef _WIN32
                auto constArgs = new const char*[size];
#else
                const char* constArgs[size];
#endif
                for (uint64_t i = 0; i < size; i++)
                {
                    constArgs[i] = args[i].c_str();
                }

                OnConsoleCommandDelegate(consoleCommandEvent->GetName().c_str(),
                                         constArgs,
                                         size);

#ifdef _WIN32
                delete[] constArgs;
#endif
            }
            break;
        }
    case alt::CEvent::Type::COLSHAPE_EVENT:
        {
            auto colShapeEvent = dynamic_cast<const alt::CColShapeEvent*>(ev);
            auto entity = colShapeEvent->GetEntity();
            auto worldObjectPointer = GetWorldObjectPointer(entity);
            if (entity != nullptr && worldObjectPointer != nullptr)
            {
                auto colShapePointer = colShapeEvent->GetTarget();
                if (colShapePointer->GetType() == alt::IBaseObject::Type::COLSHAPE)
                {
                    OnColShapeDelegate(colShapePointer,
                                       worldObjectPointer,
                                       entity->GetType(),
                                       colShapeEvent->GetState());
                }
                else if (colShapePointer->GetType() == alt::IBaseObject::Type::CHECKPOINT)
                {
                    OnCheckpointDelegate(dynamic_cast<alt::ICheckpoint*>(colShapePointer),
                                         worldObjectPointer,
                                         entity->GetType(),
                                         colShapeEvent->GetState());
                }
            }
            break;
        }
    case alt::CEvent::Type::VEHICLE_DESTROY:
        {
            auto vehicleDestroyEvent = dynamic_cast<const alt::CVehicleDestroyEvent*>(ev);
            OnVehicleDestroyDelegate(vehicleDestroyEvent->GetTarget());
            break;
        }
    case alt::CEvent::Type::START_PROJECTILE_EVENT:
        {
            auto startProjectileEvent = dynamic_cast<const alt::CStartProjectileEvent*>(ev);

            auto startPosition = startProjectileEvent->GetStartPosition();
            position_t startPositionStruct = {startPosition.x, startPosition.y, startPosition.z};

            auto direction = startProjectileEvent->GetDirection();
            position_t directionStruct = {direction[0], direction[1], direction[2]};

            OnStartProjectileDelegate(startProjectileEvent,
                                      startProjectileEvent->GetSource(),
                                      startPositionStruct,
                                      directionStruct,
                                      startProjectileEvent->GetAmmoHash(),
                                      startProjectileEvent->GetWeaponHash());
            break;
        }
    case alt::CEvent::Type::PLAYER_WEAPON_CHANGE:
        {
            auto playerWeaponChangeEvent = dynamic_cast<const alt::CPlayerWeaponChangeEvent*>(ev);

            OnPlayerWeaponChangeDelegate(playerWeaponChangeEvent,
                                         playerWeaponChangeEvent->GetTarget(),
                                         playerWeaponChangeEvent->GetOldWeapon(),
                                         playerWeaponChangeEvent->GetNewWeapon());
            break;
        }
    case alt::CEvent::Type::NETOWNER_CHANGE:
        {
            auto netOwnerChangeEvent = dynamic_cast<const alt::CNetOwnerChangeEvent*>(ev);
            auto target = netOwnerChangeEvent->GetTarget();
            auto targetPointer = GetEntityPointer(target);
            if (target != nullptr && targetPointer != nullptr)
            {
                OnNetOwnerChangeDelegate(netOwnerChangeEvent,
                                         targetPointer,
                                         target->GetType(),
                                         netOwnerChangeEvent->GetOldOwner(),
                                         netOwnerChangeEvent->GetNewOwner());
            }
            break;
        }
    case alt::CEvent::Type::VEHICLE_ATTACH:
        {
            auto vehicleAttachEvent = dynamic_cast<const alt::CVehicleAttachEvent*>(ev);
            OnVehicleAttachDelegate(vehicleAttachEvent,
                                    vehicleAttachEvent->GetTarget(),
                                    vehicleAttachEvent->GetAttached());
            break;
        }
    case alt::CEvent::Type::VEHICLE_DETACH:
        {
            auto vehicleDetachEvent = dynamic_cast<const alt::CVehicleDetachEvent*>(ev);
            OnVehicleDetachDelegate(vehicleDetachEvent,
                                    vehicleDetachEvent->GetTarget(),
                                    vehicleDetachEvent->GetDetached());
            break;
        }
    case alt::CEvent::Type::VEHICLE_DAMAGE:
        {
            auto vehicleDamageEvent = dynamic_cast<const alt::CVehicleDamageEvent*>(ev);
            auto damager = vehicleDamageEvent->GetDamager();

            auto type = alt::IBaseObject::Type::PLAYER;
            void* entityPtr = nullptr;

            if (damager != nullptr)
            {
                entityPtr = GetEntityPointer(damager);
                type = damager->GetType();
            }

            OnVehicleDamageDelegate(vehicleDamageEvent,
                                    vehicleDamageEvent->GetTarget(),
                                    entityPtr,
                                    type,
                                    vehicleDamageEvent->GetBodyHealthDamage(),
                                    vehicleDamageEvent->GetBodyAdditionalHealthDamage(),
                                    vehicleDamageEvent->GetEngineHealthDamage(),
                                    vehicleDamageEvent->GetPetrolTankHealthDamage(),
                                    vehicleDamageEvent->GetDamagedWith());
            break;
        }
    case alt::CEvent::Type::VEHICLE_HORN:
        {
            auto vehicleHornEvent = dynamic_cast<const alt::CVehicleHornEvent*>(ev);

            OnVehicleHornDelegate(vehicleHornEvent,
                                  vehicleHornEvent->GetTarget(),
                                  vehicleHornEvent->GetReporter(),
                                  vehicleHornEvent->GetToggle());
            break;
        }
    case alt::CEvent::Type::VEHICLE_SIREN:
        {
            auto vehicleSirenEvent = dynamic_cast<const alt::CVehicleSirenEvent*>(ev);

            OnVehicleSirenDelegate(vehicleSirenEvent->GetTarget(),
                                   vehicleSirenEvent->GetToggle());
            break;
        }
    case alt::CEvent::Type::CONNECTION_QUEUE_ADD:
        {
            auto connectionQueueAddEvent = dynamic_cast<const alt::CConnectionQueueAddEvent*>(ev);

            OnConnectionQueueAddDelegate(connectionQueueAddEvent->GetConnectionInfo());
            break;
        }
    case alt::CEvent::Type::CONNECTION_QUEUE_REMOVE:
        {
            auto connectionQueueRemoveEvent = dynamic_cast<const alt::CConnectionQueueRemoveEvent*>(ev);

            OnConnectionQueueRemoveDelegate(connectionQueueRemoveEvent->GetConnectionInfo());
            break;
        }
    case alt::CEvent::Type::SERVER_STARTED:
        {
            OnServerStartedDelegate();
            break;
        }
    case alt::CEvent::Type::PLAYER_REQUEST_CONTROL:
        {
            auto playerRequestControlEvent = dynamic_cast<const alt::CPlayerRequestControlEvent*>(ev);
            auto targetPtr = GetEntityPointer(playerRequestControlEvent->GetTarget());
            OnPlayerRequestControlDelegate(playerRequestControlEvent,
                                           targetPtr,
                                           playerRequestControlEvent->GetTarget()->GetType(),
                                           playerRequestControlEvent->GetPlayer());
            break;
        }
    case alt::CEvent::Type::PLAYER_DIMENSION_CHANGE:
        {
            auto playerDimensionChangeEvent = dynamic_cast<const alt::CPlayerDimensionChangeEvent*>(ev);

            OnPlayerDimensionChangeDelegate(playerDimensionChangeEvent->GetTarget(),
                                            playerDimensionChangeEvent->GetOldDimension(),
                                            playerDimensionChangeEvent->GetNewDimension());
            break;
        }
    case alt::CEvent::Type::PLAYER_SPAWN:
        {
            auto playerSpawnEvent = dynamic_cast<const alt::CPlayerSpawnEvent*>(ev);

            OnPlayerSpawnDelegate(playerSpawnEvent->GetPlayer());
            break;
        }
    case alt::CEvent::Type::VOICE_CONNECTION_EVENT:
        {
            auto voiceConnectionEvent = dynamic_cast<const alt::CVoiceConnectionEvent*>(ev);

            OnVoiceConnectionDelegate(static_cast<uint8_t>(voiceConnectionEvent->GetState()));

            break;
        }
    case alt::CEvent::Type::REQUEST_SYNCED_SCENE:
        {
            auto requestSyncedSceneEvent = dynamic_cast<const alt::CRequestSyncedSceneEvent*>(ev);

            OnRequestSyncedSceneDelegate(requestSyncedSceneEvent, requestSyncedSceneEvent->GetSource(), requestSyncedSceneEvent->GetSceneID());
            break;
        }
    case alt::CEvent::Type::START_SYNCED_SCENE:
        {
            auto startSyncedSceneEvent = dynamic_cast<const alt::CStartSyncedSceneEvent*>(ev);
            position_t startPosition = {startSyncedSceneEvent->GetStartPosition().x, startSyncedSceneEvent->GetStartPosition().y, startSyncedSceneEvent->GetStartPosition().z};
            rotation_t startRotation = {startSyncedSceneEvent->GetStartRotation().roll, startSyncedSceneEvent->GetStartRotation().pitch, startSyncedSceneEvent->GetStartRotation().yaw};

            auto entities = new void*[startSyncedSceneEvent->GetEntityAndAnimHashPairs().size()];
            auto types = new alt::IBaseObject::Type[startSyncedSceneEvent->GetEntityAndAnimHashPairs().size()];
            auto animHashes = new uint32_t[startSyncedSceneEvent->GetEntityAndAnimHashPairs().size()];
            uint64_t size = 0;

            for (const auto& hash_pair : startSyncedSceneEvent->GetEntityAndAnimHashPairs())
            {
                auto entity = hash_pair.first.get();
                entities[size] = Util_GetEntityPointer(entity);
                types[size] = entity->GetType();
                animHashes[size] = hash_pair.second;
                size = size + 1;
            }

            OnStartSyncedSceneDelegate(startSyncedSceneEvent->GetSource(),
                                       startSyncedSceneEvent->GetSceneID(),
                                       startPosition,
                                       startRotation,
                                       startSyncedSceneEvent->GetAnimDictHash(),
                                       entities,
                                       types,
                                       animHashes,
                                       size);
            break;
        }
    case alt::CEvent::Type::STOP_SYNCED_SCENE:
        {
            auto stopSyncedSceneEvent = dynamic_cast<const alt::CStopSyncedSceneEvent*>(ev);

            OnStopSyncedSceneDelegate(stopSyncedSceneEvent->GetSource(), stopSyncedSceneEvent->GetSceneID());
            break;
        }
    case alt::CEvent::Type::UPDATE_SYNCED_SCENE:
        {
            auto updateSyncedSceneEvent = dynamic_cast<const alt::CUpdateSyncedSceneEvent*>(ev);
            OnUpdateSyncedSceneDelegate(updateSyncedSceneEvent->GetSource(), updateSyncedSceneEvent->GetStartRate(), updateSyncedSceneEvent->GetSceneID());
            break;
        }
    case alt::CEvent::Type::CLIENT_REQUEST_OBJECT_EVENT:
        {
            auto clientRequestObjectEvent = dynamic_cast<const alt::CClientRequestObjectEvent*>(ev);

            auto target = clientRequestObjectEvent->GetTarget();
            if (target == nullptr) return;

            OnClientRequestObjectDelegate(
                clientRequestObjectEvent,
                target,
                clientRequestObjectEvent->GetModel(),
                {clientRequestObjectEvent->GetPosition().x, clientRequestObjectEvent->GetPosition().y, clientRequestObjectEvent->GetPosition().z});
            break;
        }
    case alt::CEvent::Type::CLIENT_DELETE_OBJECT_EVENT:
        {
            auto clientDeleteObjectEvent = dynamic_cast<const alt::CClientDeleteObjectEvent*>(ev);

            auto target = clientDeleteObjectEvent->GetTarget();
            if (target == nullptr) return;

            OnClientDeleteObjectDelegate(
                clientDeleteObjectEvent,
                target);
            break;
        }
    case alt::CEvent::Type::PLAYER_HEAL:
        {
            auto playerHealEvent = dynamic_cast<const alt::CPlayerHealEvent*>(ev);

            auto target = playerHealEvent->GetTarget();
            if (target == nullptr) return;
            OnPlayerHealDelegate(target,
                                 playerHealEvent->GetOldHealth(),
                                 playerHealEvent->GetNewHealth(),
                                 playerHealEvent->GetOldArmour(),
                                 playerHealEvent->GetNewArmour());
            break;
        }
    case alt::CEvent::Type::GIVE_PED_SCRIPTED_TASK:
        {
            auto givePedScriptedTaskEvent = dynamic_cast<const alt::CGivePedScriptedTaskEvent*>(ev);

            auto target = givePedScriptedTaskEvent->GetTarget();
            auto source = givePedScriptedTaskEvent->GetSource();

            if (target == nullptr) return;
            if (source == nullptr) return;

            OnGivePedScriptedTaskDelegate(givePedScriptedTaskEvent, source, target, givePedScriptedTaskEvent->GetTaskType());

            break;
        }
    case alt::CEvent::Type::PED_DAMAGE:
        {
            auto damageEvent = dynamic_cast<const alt::CPedDamageEvent*>(ev);
            auto entity = damageEvent->GetAttacker();
            auto entityPtr = GetEntityPointer(entity);
            if (entity != nullptr && entityPtr != nullptr)
            {
                OnPedDamageDelegate(damageEvent->GetTarget(),
                                       entityPtr,
                                       entity->GetType(),
                                       damageEvent->GetWeapon(),
                                       damageEvent->GetHealthDamage(),
                                       damageEvent->GetArmourDamage());
            }
            else
            {
                OnPedDamageDelegate(damageEvent->GetTarget(),
                                       nullptr,
                                       alt::IBaseObject::Type::PLAYER,
                                       damageEvent->GetWeapon(),
                                       damageEvent->GetHealthDamage(),
                                       damageEvent->GetArmourDamage());
            }
            break;
        }
    case alt::CEvent::Type::PED_DEATH:
        {
            auto deathEvent = dynamic_cast<const alt::CPedDeathEvent*>(ev);
            auto entity = deathEvent->GetKiller();

            auto type = alt::IBaseObject::Type::PLAYER;
            void* entityPtr = nullptr;

            if (entity != nullptr)
            {
                entityPtr = GetEntityPointer(entity);
                type = entity->GetType();
            }

            OnPedDeathDelegate(deathEvent->GetTarget(),
                                  entityPtr,
                                  type,
                                  deathEvent->GetWeapon());
            break;
        }
    case alt::CEvent::Type::PED_HEAL:
        {
            auto healEvent = dynamic_cast<const alt::CPedHealEvent*>(ev);

            auto target = healEvent->GetTarget();
            if (target == nullptr) return;
            OnPedHealDelegate(target,
                                 healEvent->GetOldHealth(),
                                 healEvent->GetNewHealth(),
                                 healEvent->GetOldArmour(),
                                 healEvent->GetNewArmour());
            break;
        }
    case alt::CEvent::Type::PLAYER_START_TALKING:
        {
            auto playerStartTalkingEvent = dynamic_cast<const alt::CPlayerStartTalkingEvent*>(ev);

            auto player = playerStartTalkingEvent->GetPlayer();
            if (player == nullptr) return;
            OnPlayerStartTalkingDelegate(player);
            break;
        }
    case alt::CEvent::Type::PLAYER_STOP_TALKING:
        {
            auto playerStopTalkingEvent = dynamic_cast<const alt::CPlayerStopTalkingEvent*>(ev);

            auto player = playerStopTalkingEvent->GetPlayer();
            if (player == nullptr) return;
            OnPlayerStopTalkingDelegate(player);
            break;
        }
    case alt::CEvent::Type::SCRIPT_RPC_EVENT:
        {
            auto scriptRPCEvent = dynamic_cast<const alt::CScriptRPCEvent*>(ev);

            auto target = scriptRPCEvent->GetTarget();
            if (target == nullptr) return;

            auto name = scriptRPCEvent->GetName();
            auto args = scriptRPCEvent->GetArgs();
            auto size = args.size();
            auto constArgs = new alt::MValueConst*[size];

            for (uint64_t i = 0; i < size; i++)
            {
                constArgs[i] = &args[i];
            }

            OnScriptRPCDelegate(scriptRPCEvent,
                                target,
                                name.c_str(),
                                constArgs,
                                size,
                                scriptRPCEvent->GetAnswerID()
                                );
            break;
        }
    case alt::CEvent::Type::SCRIPT_RPC_ANSWER_EVENT:
        {
            auto scriptRPCAnswerEvent = dynamic_cast<const alt::CScriptRPCAnswerEvent*>(ev);

            auto target = scriptRPCAnswerEvent->GetTarget();
            if (target == nullptr) return;

            auto answers = scriptRPCAnswerEvent->GetAnswer();
            OnScriptRPCAnswerDelegate(target,
                                      scriptRPCAnswerEvent->GetAnswerID(),
                                      AllocMValue(answers),
                                      scriptRPCAnswerEvent->GetAnswerError().c_str()
                                      );
            break;
        }
    default:
        {
            std::cout << "Unhandled server event #" << static_cast<int>(ev->GetType()) << " got called" << std::endl;
            break;
        }
    }
}

void CSharpResourceImpl::OnCreateBaseObject(alt::IBaseObject* object)
{
    if (object != nullptr)
    {
        switch (object->GetType())
        {
        case alt::IBaseObject::Type::PLAYER:
            {
                const auto player = dynamic_cast<alt::IPlayer*>(object);
                OnCreateBaseObjectDelegate(player, player->GetType(), player->GetID());
                break;
            }
        case alt::IBaseObject::Type::VEHICLE:
            {
                const auto vehicle = dynamic_cast<alt::IVehicle*>(object);
                OnCreateBaseObjectDelegate(vehicle, vehicle->GetType(), vehicle->GetID());
                break;
            }
        case alt::IBaseObject::Type::BLIP:
            {
                auto blip = dynamic_cast<alt::IBlip*>(object);
                OnCreateBaseObjectDelegate(blip, blip->GetType(), blip->GetID());
                break;
            }
        case alt::IBaseObject::Type::VOICE_CHANNEL:
            {
                auto voiceChannel = dynamic_cast<alt::IVoiceChannel*>(object);
                OnCreateBaseObjectDelegate(voiceChannel, voiceChannel->GetType(), voiceChannel->GetID());
                break;
            }
        case alt::IBaseObject::Type::COLSHAPE:
            {
                auto colShape = dynamic_cast<alt::IColShape*>(object);
                OnCreateBaseObjectDelegate(colShape, colShape->GetType(), colShape->GetID());
                break;
            }
        case alt::IBaseObject::Type::CHECKPOINT:
            {
                auto checkPoint = dynamic_cast<alt::ICheckpoint*>(object);
                OnCreateBaseObjectDelegate(checkPoint, checkPoint->GetType(), checkPoint->GetID());
                break;
            }
        case alt::IBaseObject::Type::LOCAL_OBJECT:
            {
                const auto altObject = dynamic_cast<alt::ILocalObject*>(object);
                OnCreateBaseObjectDelegate(altObject, altObject->GetType(), altObject->GetID());
                break;
            }
        case alt::IBaseObject::Type::PED:
            {
                const auto ped = dynamic_cast<alt::IPed*>(object);
                OnCreateBaseObjectDelegate(ped, ped->GetType(), ped->GetID());
                break;
            }
        case alt::IBaseObject::Type::VIRTUAL_ENTITY:
            {
                const auto virtualEntity = dynamic_cast<alt::IVirtualEntity*>(object);
                OnCreateBaseObjectDelegate(virtualEntity, virtualEntity->GetType(), virtualEntity->GetID());
                break;
            }
        case alt::IBaseObject::Type::VIRTUAL_ENTITY_GROUP:
            {
                const auto virtualEntityGroup = dynamic_cast<alt::IVirtualEntityGroup*>(object);
                OnCreateBaseObjectDelegate(virtualEntityGroup, virtualEntityGroup->GetType(),
                                           virtualEntityGroup->GetID());
                break;
            }
        case alt::IBaseObject::Type::OBJECT:
            {
                const auto iOject = dynamic_cast<alt::IObject*>(object);
                OnCreateBaseObjectDelegate(iOject, iOject->GetType(), iOject->GetID());
                break;
            }
        case alt::IBaseObject::Type::MARKER:
            {
                auto marker = dynamic_cast<alt::IMarker*>(object);
                OnCreateBaseObjectDelegate(marker, marker->GetType(), marker->GetID());
                break;
            }
        case alt::IBaseObject::Type::TEXT_LABEL:
            {
                auto textLabel = dynamic_cast<alt::ITextLabel*>(object);
                OnCreateBaseObjectDelegate(textLabel, textLabel->GetType(), textLabel->GetID());
                break;
            }
        case alt::IBaseObject::Type::CONNECTION_INFO:
            {
                auto connectionInfo = dynamic_cast<alt::IConnectionInfo*>(object);
                OnCreateBaseObjectDelegate(connectionInfo, connectionInfo->GetType(), connectionInfo->GetID());
                break;
            }
        default:
            {
                std::cout << "Unhandled type #" << static_cast<int>(object->GetType()) <<
                    " for create base object got called" << std::endl;
                break;
            }
        }
    }
}

void CSharpResourceImpl::OnRemoveBaseObject(alt::IBaseObject* object)
{
    if (object != nullptr)
    {
        switch (object->GetType())
        {
        case alt::IBaseObject::Type::PLAYER:
            {
                const auto player = dynamic_cast<alt::IPlayer*>(object);
                OnRemoveBaseObjectDelegate(player, player->GetType());
                break;
            }
        case alt::IBaseObject::Type::VEHICLE:
            {
                const auto vehicle = dynamic_cast<alt::IVehicle*>(object);
                OnRemoveBaseObjectDelegate(vehicle, vehicle->GetType());
                break;
            }
        case alt::IBaseObject::Type::BLIP:
            {
                auto blip = dynamic_cast<alt::IBlip*>(object);
                OnRemoveBaseObjectDelegate(blip, blip->GetType());
                break;
            }
        case alt::IBaseObject::Type::VOICE_CHANNEL:
            {
                auto voiceChannel = dynamic_cast<alt::IVoiceChannel*>(object);
                OnRemoveBaseObjectDelegate(voiceChannel, voiceChannel->GetType());
                break;
            }
        case alt::IBaseObject::Type::COLSHAPE:
            {
                auto colShape = dynamic_cast<alt::IColShape*>(object);
                OnRemoveBaseObjectDelegate(colShape, colShape->GetType());
                break;
            }
        case alt::IBaseObject::Type::CHECKPOINT:
            {
                auto checkPoint = dynamic_cast<alt::ICheckpoint*>(object);
                OnRemoveBaseObjectDelegate(checkPoint, checkPoint->GetType());
                break;
            }
        case alt::IBaseObject::Type::LOCAL_OBJECT:
            {
                const auto altObject = dynamic_cast<alt::ILocalObject*>(object);
                OnRemoveBaseObjectDelegate(altObject, altObject->GetType());
                break;
            }
        case alt::IBaseObject::Type::PED:
            {
                const auto ped = dynamic_cast<alt::IPed*>(object);
                OnRemoveBaseObjectDelegate(ped, ped->GetType());
                break;
            }
        case alt::IBaseObject::Type::VIRTUAL_ENTITY:
            {
                const auto virtualEntity = dynamic_cast<alt::IVirtualEntity*>(object);
                OnRemoveBaseObjectDelegate(virtualEntity, virtualEntity->GetType());
                break;
            }
        case alt::IBaseObject::Type::VIRTUAL_ENTITY_GROUP:
            {
                const auto virtualEntityGroup = dynamic_cast<alt::IVirtualEntityGroup*>(object);
                OnRemoveBaseObjectDelegate(virtualEntityGroup, virtualEntityGroup->GetType());
                break;
            }
        case alt::IBaseObject::Type::OBJECT:
            {
                const auto iObject = dynamic_cast<alt::IObject*>(object);
                OnRemoveBaseObjectDelegate(iObject, iObject->GetType());
                break;
            }
        case alt::IBaseObject::Type::MARKER:
            {
                const auto marker = dynamic_cast<alt::IMarker*>(object);
                OnRemoveBaseObjectDelegate(marker, marker->GetType());
                break;
            }
        case alt::IBaseObject::Type::TEXT_LABEL:
            {
                const auto textLabel = dynamic_cast<alt::ITextLabel*>(object);
                OnRemoveBaseObjectDelegate(textLabel, textLabel->GetType());
                break;
            }
        case alt::IBaseObject::Type::CONNECTION_INFO:
            {
                const auto connectionInfo = dynamic_cast<alt::IConnectionInfo*>(object);
                OnRemoveBaseObjectDelegate(connectionInfo, connectionInfo->GetType());
                break;
            }
        default:
            {
                std::cout << "Unhandled type #" << static_cast<int>(object->GetType()) <<
                    " for remove base object got called" << std::endl;
                break;
            }
        }
    }
}

void CSharpResourceImpl::OnTick()
{
    OnTickDelegate();
}

void CSharpResourceImpl_SetMainDelegate(CSharpResourceImpl* resource,
                                        MainDelegate_t delegate)
{
    resource->MainDelegate = delegate;
}

void CSharpResourceImpl_SetStopDelegate(CSharpResourceImpl* resource,
                                        StopDelegate_t delegate)
{
    resource->OnStopDelegate = delegate;
}

void CSharpResourceImpl_SetTickDelegate(CSharpResourceImpl* resource,
                                        TickDelegate_t delegate)
{
    resource->OnTickDelegate = delegate;
}

void CSharpResourceImpl_SetServerEventDelegate(CSharpResourceImpl* resource,
                                               ServerEventDelegate_t delegate)
{
    resource->OnServerEventDelegate = delegate;
}

void CSharpResourceImpl_SetCheckpointDelegate(CSharpResourceImpl* resource,
                                              CheckpointDelegate_t delegate)
{
    resource->OnCheckpointDelegate = delegate;
}

void CSharpResourceImpl_SetClientEventDelegate(CSharpResourceImpl* resource,
                                               ClientEventDelegate_t delegate)
{
    resource->OnClientEventDelegate = delegate;
}

void CSharpResourceImpl_SetPlayerDamageDelegate(CSharpResourceImpl* resource,
                                                PlayerDamageDelegate_t delegate)
{
    resource->OnPlayerDamageDelegate = delegate;
}

void CSharpResourceImpl_SetPlayerConnectDelegate(CSharpResourceImpl* resource,
                                                 PlayerConnectDelegate_t delegate)
{
    resource->OnPlayerConnectDelegate = delegate;
}

void CSharpResourceImpl_SetPlayerConnectDeniedDelegate(CSharpResourceImpl* resource,
                                                       PlayerConnectDeniedDelegate_t delegate)
{
    resource->OnPlayerConnectDeniedDelegate = delegate;
}

void CSharpResourceImpl_SetResourceStartDelegate(CSharpResourceImpl* resource, ResourceEventDelegate_t delegate)
{
    resource->OnResourceStartDelegate = delegate;
}

void CSharpResourceImpl_SetResourceStopDelegate(CSharpResourceImpl* resource, ResourceEventDelegate_t delegate)
{
    resource->OnResourceStopDelegate = delegate;
}

void CSharpResourceImpl_SetResourceErrorDelegate(CSharpResourceImpl* resource, ResourceEventDelegate_t delegate)
{
    resource->OnResourceErrorDelegate = delegate;
}

void CSharpResourceImpl_SetPlayerDeathDelegate(CSharpResourceImpl* resource,
                                               PlayerDeathDelegate_t delegate)
{
    resource->OnPlayerDeathDelegate = delegate;
}

void CSharpResourceImpl_SetExplosionDelegate(CSharpResourceImpl* resource,
                                             ExplosionDelegate_t delegate)
{
    resource->OnExplosionDelegate = delegate;
}

void CSharpResourceImpl_SetWeaponDamageDelegate(CSharpResourceImpl* resource,
                                                WeaponDamageDelegate_t delegate)
{
    resource->OnWeaponDamageDelegate = delegate;
}

void CSharpResourceImpl_SetPlayerDisconnectDelegate(CSharpResourceImpl* resource,
                                                    PlayerDisconnectDelegate_t delegate)
{
    resource->OnPlayerDisconnectDelegate = delegate;
}

void CSharpResourceImpl_SetPlayerChangeVehicleSeatDelegate(CSharpResourceImpl* resource,
                                                           PlayerChangeVehicleSeatDelegate_t delegate)
{
    resource->OnPlayerChangeVehicleSeatDelegate = delegate;
}

void CSharpResourceImpl_SetPlayerEnterVehicleDelegate(CSharpResourceImpl* resource,
                                                      PlayerEnterVehicleDelegate_t delegate)
{
    resource->OnPlayerEnterVehicleDelegate = delegate;
}

void CSharpResourceImpl_SetPlayerEnteringVehicleDelegate(CSharpResourceImpl* resource,
                                                         PlayerEnteringVehicleDelegate_t delegate)
{
    resource->OnPlayerEnteringVehicleDelegate = delegate;
}

void CSharpResourceImpl_SetPlayerLeaveVehicleDelegate(CSharpResourceImpl* resource,
                                                      PlayerLeaveVehicleDelegate_t delegate)
{
    resource->OnPlayerLeaveVehicleDelegate = delegate;
}

void CSharpResourceImpl_SetConsoleCommandDelegate(CSharpResourceImpl* resource,
                                                  ConsoleCommandDelegate_t delegate)
{
    resource->OnConsoleCommandDelegate = delegate;
}

void CSharpResourceImpl_SetMetaChangeDelegate(CSharpResourceImpl* resource,
                                              MetaChangeDelegate_t delegate)
{
    resource->OnMetaChangeDelegate = delegate;
}

void CSharpResourceImpl_SetSyncedMetaChangeDelegate(CSharpResourceImpl* resource,
                                                    MetaChangeDelegate_t delegate)
{
    resource->OnSyncedMetaChangeDelegate = delegate;
}

void CSharpResourceImpl_SetColShapeDelegate(CSharpResourceImpl* resource,
                                            ColShapeDelegate_t delegate)
{
    resource->OnColShapeDelegate = delegate;
}

void CSharpResourceImpl_SetVehicleDestroyDelegate(CSharpResourceImpl* resource,
                                                  VehicleDestroyDelegate_t delegate)
{
    resource->OnVehicleDestroyDelegate = delegate;
}

void CSharpResourceImpl_SetFireDelegate(CSharpResourceImpl* resource,
                                        FireDelegate_t delegate)
{
    resource->OnFireDelegate = delegate;
}

void CSharpResourceImpl_SetStartProjectileDelegate(CSharpResourceImpl* resource,
                                                   StartProjectileDelegate_t delegate)
{
    resource->OnStartProjectileDelegate = delegate;
}

void CSharpResourceImpl_SetPlayerWeaponChangeDelegate(CSharpResourceImpl* resource,
                                                      PlayerWeaponChangeDelegate_t delegate)
{
    resource->OnPlayerWeaponChangeDelegate = delegate;
}

void CSharpResourceImpl_SetNetOwnerChangeDelegate(CSharpResourceImpl* resource,
                                                  NetOwnerChangeDelegate_t delegate)
{
    resource->OnNetOwnerChangeDelegate = delegate;
}

void CSharpResourceImpl_SetVehicleAttachDelegate(CSharpResourceImpl* resource,
                                                 VehicleAttachDelegate_t delegate)
{
    resource->OnVehicleAttachDelegate = delegate;
}

void CSharpResourceImpl_SetVehicleDetachDelegate(CSharpResourceImpl* resource,
                                                 VehicleDetachDelegate_t delegate)
{
    resource->OnVehicleDetachDelegate = delegate;
}

void CSharpResourceImpl_SetVehicleDamageDelegate(CSharpResourceImpl* resource,
                                                 VehicleDamageDelegate_t delegate)
{
    resource->OnVehicleDamageDelegate = delegate;
}

void CSharpResourceImpl_SetVehicleHornDelegate(CSharpResourceImpl* resource, VehicleHornDelegate_t delegate)
{
    resource->OnVehicleHornDelegate = delegate;
}

void CSharpResourceImpl_SetVehicleSirenDelegate(CSharpResourceImpl* resource, VehicleSirenDelegate_t delegate)
{
    resource->OnVehicleSirenDelegate = delegate;
}

void CSharpResourceImpl_SetConnectionQueueAddDelegate(CSharpResourceImpl* resource,
                                                      ConnectionQueueAddDelegate_t delegate)
{
    resource->OnConnectionQueueAddDelegate = delegate;
}

void CSharpResourceImpl_SetConnectionQueueRemoveDelegate(CSharpResourceImpl* resource,
                                                         ConnectionQueueRemoveDelegate_t delegate)
{
    resource->OnConnectionQueueRemoveDelegate = delegate;
}

void CSharpResourceImpl_SetServerStartedDelegate(CSharpResourceImpl* resource,
                                                 ServerStartedDelegate_t delegate)
{
    resource->OnServerStartedDelegate = delegate;
}

void CSharpResourceImpl_SetPlayerRequestControlDelegate(CSharpResourceImpl* resource,
                                                        PlayerRequestControlDelegate_t delegate)
{
    resource->OnPlayerRequestControlDelegate = delegate;
}

void CSharpResourceImpl_SetPlayerDimensionChangeDelegate(CSharpResourceImpl* resource,
                                                         PlayerDimensionChangeDelegate_t delegate)
{
    resource->OnPlayerDimensionChangeDelegate = delegate;
}

void CSharpResourceImpl_SetPlayerChangeAnimationDelegate(CSharpResourceImpl* resource,
                                                         PlayerChangeAnimationDelegate_t delegate)
{
    resource->OnPlayerChangeAnimationDelegate = delegate;
}

void CSharpResourceImpl_SetPlayerChangeInteriorDelegate(CSharpResourceImpl* resource,
                                                        PlayerChangeInteriorDelegate_t delegate)
{
    resource->OnPlayerChangeInteriorDelegate = delegate;
}

void CSharpResourceImpl_SetPlayerSpawnDelegate(CSharpResourceImpl* resource, PlayerSpawnDelegate_t delegate)
{
    resource->OnPlayerSpawnDelegate = delegate;
}

void CSharpResourceImpl_SetVoiceConnectionDelegate(CSharpResourceImpl* resource, VoiceConnectionDelegate_t delegate)
{
    resource->OnVoiceConnectionDelegate = delegate;
}

void CSharpResourceImpl_SetCreateBaseObjectDelegate(CSharpResourceImpl* resource, CreateBaseObjectDelegate_t delegate)
{
    resource->OnCreateBaseObjectDelegate = delegate;
}

void CSharpResourceImpl_SetRemoveBaseObjectDelegate(CSharpResourceImpl* resource, RemoveBaseObjectDelegate_t delegate)
{
    resource->OnRemoveBaseObjectDelegate = delegate;
}

void CSharpResourceImpl_SetRequestSyncedSceneDelegate(CSharpResourceImpl* resource, RequestSyncedSceneDelegate_t delegate)
{
    resource->OnRequestSyncedSceneDelegate = delegate;
}

void CSharpResourceImpl_SetStartSyncedSceneDelegate(CSharpResourceImpl* resource, StartSyncedSceneDelegate_t delegate)
{
    resource->OnStartSyncedSceneDelegate = delegate;
}

void CSharpResourceImpl_SetStopSyncedSceneDelegate(CSharpResourceImpl* resource, StopSyncedSceneDelegate_t delegate)
{
    resource->OnStopSyncedSceneDelegate = delegate;
}

void CSharpResourceImpl_SetUpdateSyncedSceneDelegate(CSharpResourceImpl* resource, UpdateSyncedSceneDelegate_t delegate)
{
    resource->OnUpdateSyncedSceneDelegate = delegate;
}

void CSharpResourceImpl_SetClientRequestObjectDelegate(CSharpResourceImpl* resource, ClientRequestObjectDelegate_t delegate)
{
    resource->OnClientRequestObjectDelegate = delegate;
}

void CSharpResourceImpl_SetClientDeleteObjectDelegate(CSharpResourceImpl* resource, ClientDeleteObjectDelegate_t delegate)
{
    resource->OnClientDeleteObjectDelegate = delegate;
}

void CSharpResourceImpl_SetPlayerHealDelegate(CSharpResourceImpl* resource, PlayerHealDelegate_t delegate)
{
    resource->OnPlayerHealDelegate = delegate;
}

void CSharpResourceImpl_SetGivePedScriptedTaskDelegate(CSharpResourceImpl* resource, GivePedScriptedTaskDelegate_t delegate)
{
    resource->OnGivePedScriptedTaskDelegate = delegate;
}

void CSharpResourceImpl_SetPedDamageDelegate(CSharpResourceImpl* resource, PedDamageDelegate_t delegate)
{
    resource->OnPedDamageDelegate = delegate;
}

void CSharpResourceImpl_SetPedDeathDelegate(CSharpResourceImpl* resource, PedDeathDelegate_t delegate)
{
    resource->OnPedDeathDelegate = delegate;
}

void CSharpResourceImpl_SetPedHealDelegate(CSharpResourceImpl* resource, PedHealDelegate_t delegate)
{
    resource->OnPedHealDelegate = delegate;
}

void CSharpResourceImpl_SetPlayerStartTalkingDelegate(CSharpResourceImpl* resource,
    PlayerStartTalkingDelegate_t delegate)
{
    resource->OnPlayerStartTalkingDelegate = delegate;
}

void CSharpResourceImpl_SetPlayerStopTalkingDelegate(CSharpResourceImpl* resource, PlayerStopTalkingDelegate_t delegate)
{
    resource->OnPlayerStopTalkingDelegate = delegate;
}

void CSharpResourceImpl_SetScriptRPCDelegate(CSharpResourceImpl* resource, ScriptRPCDelegate_t delegate)
{
    resource->OnScriptRPCDelegate = delegate;
}

void CSharpResourceImpl_SetScriptRPCAnswerDelegate(CSharpResourceImpl* resource, ScriptRPCAnswerDelegate_t delegate)
{
    resource->OnScriptRPCAnswerDelegate = delegate;
}

bool CSharpResourceImpl::MakeClient(alt::IResource::CreationInfo* info, std::vector<std::string> files)
{
    const std::string clientMain = resource->GetClientMain();
    const std::string suffix = ".dll";
    if (clientMain.size() >= suffix.size() &&
        clientMain.compare(clientMain.size() - suffix.size(), suffix.size(), suffix) == 0)
    {
        info->type = "csharp";
    }
    else
    {
        info->type = "js";
    }
    return true;
}

void* CSharpResourceImpl::GetBaseObjectPointer(alt::IBaseObject* baseObject)
{
    return Util_GetBaseObjectPointer(baseObject);
}

void* CSharpResourceImpl::GetWorldObjectPointer(alt::IWorldObject* worldObject)
{
    return Util_GetWorldObjectPointer(worldObject);
}

void* CSharpResourceImpl::GetEntityPointer(alt::IEntity* entity)
{
    return Util_GetEntityPointer(entity);
}

alt::IBaseObject::Type CSharpResourceImpl::GetEntityType(alt::IEntity* entity)
{
    if (entity != nullptr)
    {
        return entity->GetType();
    }
    return alt::IBaseObject::Type::PLAYER;
}
