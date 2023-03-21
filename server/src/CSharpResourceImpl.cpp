#include "CSharpResourceImpl.h"
#include "../../cpp-sdk/events/CPlayerRequestControlEvent.h"
#include "../../cpp-sdk/events/CPlayerChangeAnimationEvent.h"
#include "../../cpp-sdk/events/CPlayerChangeInteriorEvent.h"
#include "../../cpp-sdk/events/CPlayerDimensionChangeEvent.h"
#include "../../c-api/utils/entity.h"

CSharpResourceImpl::CSharpResourceImpl(alt::ICore* server, CoreClr* coreClr, alt::IResource* resource)
    : alt::IResource::Impl()
{
    ResetDelegates();
    this->resource = resource;
    this->server = server;
    this->invokers = new alt::Array<CustomInvoker*>();
    this->coreClr = coreClr;
}

void CSharpResourceImpl::ResetDelegates()
{
    MainDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnClientEventDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnPlayerConnectDelegate = [](auto var, auto var2, auto var3) {};
    OnPlayerBeforeConnectDelegate = [](auto var, auto var2, auto var3) {};
    OnPlayerConnectDeniedDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5, auto var6, auto var7, auto var8, auto var9) {};
    OnResourceStartDelegate = [](auto var) {};
    OnResourceStopDelegate = [](auto var) {};
    OnResourceErrorDelegate = [](auto var) {};
    OnPlayerDamageDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5, auto var6, auto var7) {};
    OnPlayerDeathDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnExplosionDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5, auto var6, auto var7) {};
    OnWeaponDamageDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5, auto var6, auto var7,
                                auto var8) {};
    OnPlayerDisconnectDelegate = [](auto var, auto var2) {};
    OnPlayerRemoveDelegate = [](auto var) {};
    OnVehicleRemoveDelegate = [](auto var) {};
    OnServerEventDelegate = [](auto var, auto var2, auto var3) {};
    OnPlayerChangeVehicleSeatDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnPlayerEnterVehicleDelegate = [](auto var, auto var2, auto var3) {};
    OnPlayerEnteringVehicleDelegate = [](auto var, auto var2, auto var3) {};
    OnPlayerLeaveVehicleDelegate = [](auto var, auto var2, auto var3) {};
    OnStopDelegate = []() {};
    OnTickDelegate = []() {};
    OnCreatePlayerDelegate = [](auto var, auto var2) {};
    OnRemovePlayerDelegate = [](auto var) {};
    OnCreateObjectDelegate = [](auto var, auto var2) {};
    OnRemoveObjectDelegate = [](auto var) {};
    OnCreateVehicleDelegate = [](auto var, auto var2) {};
    OnRemoveVehicleDelegate = [](auto var) {};
    OnCreateBlipDelegate = [](auto var) {};
    OnRemoveBlipDelegate = [](auto var) {};
    OnCreateCheckpointDelegate = [](auto var) {};
    OnRemoveCheckpointDelegate = [](auto var) {};
    OnCreateVoiceChannelDelegate = [](auto var) {};
    OnRemoveVoiceChannelDelegate = [](auto var) {};
    OnConsoleCommandDelegate = [](auto var, auto var2, auto var3) {};
    OnMetaChangeDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnSyncedMetaChangeDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnCreateColShapeDelegate = [](auto var) {};
    OnRemoveColShapeDelegate = [](auto var) {};
    OnColShapeDelegate = [](auto var, auto var2, auto var3, auto var4) {};
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
    OnConnectionQueueAddDelegate = [](auto var){};
    OnConnectionQueueRemoveDelegate = [](auto var){};
    OnServerStartedDelegate = []() {};
    OnPlayerRequestControlDelegate = [](auto var, auto var2, auto var3) {};
    OnPlayerDimensionChangeDelegate = [](auto var, auto var2, auto var3) {};
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
    MainDelegate(this->server, this->resource, this->resource->GetName().c_str(), resource->GetMain().c_str());
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
            uint64_t size = clientArgs.GetSize();
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
            auto connectPlayer = dynamic_cast<const alt::CPlayerConnectEvent*>(ev)->GetTarget();
            OnPlayerConnectDelegate(connectPlayer,
                                    connectPlayer->GetID(),
                                    ""); //TODO: maybe better solution
            break;
        }
    case alt::CEvent::Type::PLAYER_BEFORE_CONNECT:
        {
            auto beforeConnectEvent = dynamic_cast<const alt::CPlayerBeforeConnectEvent*>(ev);
            auto clrInfo = new ClrConnectionInfo(beforeConnectEvent->GetConnectionInfo());

            OnPlayerBeforeConnectDelegate(beforeConnectEvent,
                                          clrInfo,
                                          "");

            clrInfo->dealloc();
            delete clrInfo;
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
                                          playerConnectDeniedEvent->GetMajorVersion(),
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
                                       entity->GetID(),
                                       damageEvent->GetWeapon(),
                                       damageEvent->GetHealthDamage(),
                                       damageEvent->GetArmourDamage());
            }
            else
            {
                OnPlayerDamageDelegate(damageEvent->GetTarget(),
                                       nullptr,
                                       alt::IBaseObject::Type::PLAYER,
                                       0,
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
            uint64_t length = fires.GetSize();

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
            uint64_t size = serverArgs.GetSize();
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
            auto entityPointer = GetEntityPointer(entity);
            if (entity != nullptr && entityPointer != nullptr)
            {
                auto colShapePointer = colShapeEvent->GetTarget();
                if (colShapePointer->GetType() == alt::IBaseObject::Type::COLSHAPE)
                {
                    OnColShapeDelegate(colShapePointer,
                                       entityPointer,
                                       entity->GetType(),
                                       colShapeEvent->GetState());
                }
                else if (colShapePointer->GetType() == alt::IBaseObject::Type::CHECKPOINT)
                {
                    OnCheckpointDelegate(dynamic_cast<alt::ICheckpoint*>(colShapePointer),
                                         entityPointer,
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
            OnPlayerRequestControlDelegate(targetPtr,
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
                OnCreatePlayerDelegate(player, player->GetID());
                break;
            }
        case alt::IBaseObject::Type::VEHICLE:
            {
                const auto vehicle = dynamic_cast<alt::IVehicle*>(object);
                OnCreateVehicleDelegate(vehicle, vehicle->GetID());
                break;
            }
        case alt::IBaseObject::Type::BLIP:
            {
                OnCreateBlipDelegate(dynamic_cast<alt::IBlip*>(object));
                break;
            }
        case alt::IBaseObject::Type::VOICE_CHANNEL:
            {
                OnCreateVoiceChannelDelegate(dynamic_cast<alt::IVoiceChannel*>(object));
                break;
            }
        case alt::IBaseObject::Type::COLSHAPE:
            {
                OnCreateColShapeDelegate(dynamic_cast<alt::IColShape*>(object));
                break;
            }
        case alt::IBaseObject::Type::CHECKPOINT:
            {
                OnCreateCheckpointDelegate(dynamic_cast<alt::ICheckpoint*>(object));
                break;
            }
        case alt::IBaseObject::Type::OBJECT:
            {
                const auto altObject = dynamic_cast<alt::IObject*>(object);
                OnCreateObjectDelegate(altObject, altObject->GetID());
                break;
            }
        default:
            {
                std::cout << "Unhandled type #" << static_cast<int>(object->GetType()) << " for create base object got called" << std::endl;
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
                OnRemovePlayerDelegate(dynamic_cast<alt::IPlayer*>(object));
                break;
            }
        case alt::IBaseObject::Type::VEHICLE:
            {
                OnRemoveVehicleDelegate(dynamic_cast<alt::IVehicle*>(object));
                break;
            }
        case alt::IBaseObject::Type::BLIP:
            {
                OnRemoveBlipDelegate(dynamic_cast<alt::IBlip*>(object));
                break;
            }
        case alt::IBaseObject::Type::VOICE_CHANNEL:
            {
                OnRemoveVoiceChannelDelegate(dynamic_cast<alt::IVoiceChannel*>(object));
                break;
            }
        case alt::IBaseObject::Type::COLSHAPE:
            {
                OnRemoveColShapeDelegate(dynamic_cast<alt::IColShape*>(object));
                break;
            }
        case alt::IBaseObject::Type::CHECKPOINT:
            {
                OnRemoveCheckpointDelegate(dynamic_cast<alt::ICheckpoint*>(object));
                break;
            }
        case alt::IBaseObject::Type::OBJECT:
            {
                OnRemoveObjectDelegate(dynamic_cast<alt::IObject*>(object));
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

void CSharpResourceImpl_SetPlayerBeforeConnectDelegate(CSharpResourceImpl* resource,
                                                       PlayerBeforeConnectDelegate_t delegate)
{
    resource->OnPlayerBeforeConnectDelegate = delegate;
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

void CSharpResourceImpl_SetPlayerRemoveDelegate(CSharpResourceImpl* resource,
                                                PlayerRemoveDelegate_t delegate)
{
    resource->OnPlayerRemoveDelegate = delegate;
}

void CSharpResourceImpl_SetVehicleRemoveDelegate(CSharpResourceImpl* resource,
                                                 VehicleRemoveDelegate_t delegate)
{
    resource->OnVehicleRemoveDelegate = delegate;
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

void CSharpResourceImpl_SetCreatePlayerDelegate(CSharpResourceImpl* resource,
                                                CreatePlayerDelegate_t delegate)
{
    resource->OnCreatePlayerDelegate = delegate;
}

void CSharpResourceImpl_SetRemovePlayerDelegate(CSharpResourceImpl* resource,
                                                RemovePlayerDelegate_t delegate)
{
    resource->OnRemovePlayerDelegate = delegate;
}

void CSharpResourceImpl_SetCreateObjectDelegate(CSharpResourceImpl* resource,
                                                CreateObjectDelegate_t delegate)
{
    resource->OnCreateObjectDelegate = delegate;
}

void CSharpResourceImpl_SetRemoveObjectDelegate(CSharpResourceImpl* resource,
                                                RemoveObjectDelegate_t delegate)
{
    resource->OnRemoveObjectDelegate = delegate;
}

void CSharpResourceImpl_SetCreateVehicleDelegate(CSharpResourceImpl* resource,
                                                 CreateVehicleDelegate_t delegate)
{
    resource->OnCreateVehicleDelegate = delegate;
}

void CSharpResourceImpl_SetRemoveVehicleDelegate(CSharpResourceImpl* resource,
                                                 RemoveVehicleDelegate_t delegate)
{
    resource->OnRemoveVehicleDelegate = delegate;
}

void CSharpResourceImpl_SetCreateBlipDelegate(CSharpResourceImpl* resource,
                                              CreateBlipDelegate_t delegate)
{
    resource->OnCreateBlipDelegate = delegate;
}

void CSharpResourceImpl_SetRemoveBlipDelegate(CSharpResourceImpl* resource,
                                              RemoveBlipDelegate_t delegate)
{
    resource->OnRemoveBlipDelegate = delegate;
}

void CSharpResourceImpl_SetCreateCheckpointDelegate(CSharpResourceImpl* resource,
                                                    CreateCheckpointDelegate_t delegate)
{
    resource->OnCreateCheckpointDelegate = delegate;
}

void CSharpResourceImpl_SetRemoveCheckpointDelegate(CSharpResourceImpl* resource,
                                                    RemoveCheckpointDelegate_t delegate)
{
    resource->OnRemoveCheckpointDelegate = delegate;
}

void CSharpResourceImpl_SetCreateVoiceChannelDelegate(CSharpResourceImpl* resource,
                                                      CreateVoiceChannelDelegate_t delegate)
{
    resource->OnCreateVoiceChannelDelegate = delegate;
}

void CSharpResourceImpl_SetRemoveVoiceChannelDelegate(CSharpResourceImpl* resource,
                                                      RemoveVoiceChannelDelegate_t delegate)
{
    resource->OnRemoveVoiceChannelDelegate = delegate;
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

void CSharpResourceImpl_SetCreateColShapeDelegate(CSharpResourceImpl* resource,
                                                  CreateColShapeDelegate_t delegate)
{
    resource->OnCreateColShapeDelegate = delegate;
}

void CSharpResourceImpl_SetRemoveColShapeDelegate(CSharpResourceImpl* resource,
                                                  RemoveColShapeDelegate_t delegate)
{
    resource->OnRemoveColShapeDelegate = delegate;
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

bool CSharpResourceImpl::MakeClient(alt::IResource::CreationInfo* info, alt::Array<std::string> files)
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
    if (baseObject != nullptr)
    {
        switch (baseObject->GetType())
        {
        case alt::IBaseObject::Type::PLAYER:
            return dynamic_cast<alt::IPlayer*>(baseObject);
        case alt::IBaseObject::Type::VEHICLE:
            return dynamic_cast<alt::IVehicle*>(baseObject);
        case alt::IBaseObject::Type::BLIP:
            return dynamic_cast<alt::IBlip*>(baseObject);
        case alt::IBaseObject::Type::COLSHAPE:
            return dynamic_cast<alt::IColShape*>(baseObject);
        case alt::IBaseObject::Type::CHECKPOINT:
            return dynamic_cast<alt::ICheckpoint*>(baseObject);
        default:
            return nullptr;
        }
    }
    return nullptr;
}

void* CSharpResourceImpl::GetEntityPointer(alt::IEntity* entity)
{
    if (entity != nullptr)
    {
        switch (entity->GetType())
        {
        case alt::IBaseObject::Type::PLAYER:
        case alt::IBaseObject::Type::LOCAL_PLAYER:
            return dynamic_cast<alt::IPlayer*>(entity);
        case alt::IBaseObject::Type::VEHICLE:
            return dynamic_cast<alt::IVehicle*>(entity);
        default:
            return nullptr;
        }
    }
    return nullptr;
}

alt::IBaseObject::Type CSharpResourceImpl::GetEntityType(alt::IEntity* entity)
{
    if (entity != nullptr)
    {
        return entity->GetType();
    }
    return alt::IBaseObject::Type::PLAYER;
}
