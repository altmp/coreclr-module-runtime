#include <utils.h>
#include <fstream>
#include <vector>
#include "CSharpScriptRuntime.h"
#include "CSharpResourceImpl.h"
#include <Log.h>
#include "CRC.h"
#include <sstream>
#include <string>
#include <iomanip>
#include "natives.h"
#include "exceptions/LoadException.h"
#include "../../c-api/utils/entity.h"
#include "../../c-api/mvalue.h"

using namespace std;

bool CSharpResourceImpl::Start()
{
    cs::Log::Info << "Starting resource" << cs::Log::Endl;
    ResetDelegates();
    resource->EnableNatives();
    auto scope = resource->PushNativesScope();
    return runtime->clr.StartResource(resource, core);
}

bool CSharpResourceImpl::Stop()
{
    auto scope = resource->PushNativesScope();
    auto res = CoreClr::StopResource(resource);
    ResetDelegates();
    return res;
}

void CSharpResourceImpl::OnEvent(const alt::CEvent* ev)
{
    if (ev == nullptr) return;
    auto scope = resource->PushNativesScope();
    switch (ev->GetType())
    {
    case alt::CEvent::Type::SERVER_SCRIPT_EVENT:
        {
            auto serverScriptEvent = dynamic_cast<const alt::CServerScriptEvent*>(ev);
            alt::MValueArgs serverArgs = serverScriptEvent->GetArgs();
            auto size = serverArgs.size();

            if (size == 0)
            {
                OnServerEventDelegate(serverScriptEvent->GetName().c_str(), nullptr, 0);
            }
            else
            {
                auto constArgs = new alt::MValueConst*[size];
                for (uint64_t i = 0; i < size; i++)
                {
                    constArgs[i] = &serverArgs[i];
                }
                OnServerEventDelegate(serverScriptEvent->GetName().c_str(),
                                      constArgs,
                                      size);
                delete[] constArgs;
            }
            break;
        }
    case alt::CEvent::Type::CLIENT_SCRIPT_EVENT:
        {
            auto clientScriptEvent = dynamic_cast<const alt::CClientScriptEvent*>(ev);
            alt::MValueArgs serverArgs = clientScriptEvent->GetArgs();
            auto size = serverArgs.size();
            if (size == 0)
            {
                OnClientEventDelegate(clientScriptEvent->GetName().c_str(), nullptr, 0);
            }
            else
            {
                auto constArgs = new alt::MValueConst*[size];
                for (uint64_t i = 0; i < size; i++)
                {
                    constArgs[i] = &serverArgs[i];
                }
                OnClientEventDelegate(clientScriptEvent->GetName().c_str(),
                                      constArgs,
                                      size);
                delete[] constArgs;
            }
            break;
        }
    case alt::CEvent::Type::CONSOLE_COMMAND_EVENT:
        {
            auto consoleCommandEvent = dynamic_cast<const alt::CConsoleCommandEvent*>(ev);
            auto args = consoleCommandEvent->GetArgs();
            uint64_t size = args.size();
            auto cArgs = new const char*[size];

            for (uint64_t i = 0; i < size; i++)
            {
                cArgs[i] = args[i].c_str();
            }

            auto name = consoleCommandEvent->GetName();
            OnConsoleCommandDelegate(name.c_str(),
                                     cArgs,
                                     size);
            delete[] cArgs;
            break;
        }
    case alt::CEvent::Type::WEB_VIEW_EVENT:
        {
            auto webViewEvent = dynamic_cast<const alt::CWebViewEvent*>(ev);
            auto args = webViewEvent->GetArgs();
            auto name = webViewEvent->GetName();
            auto size = args.size();
            auto constArgs = new alt::MValueConst*[size];

            for (uint64_t i = 0; i < size; i++)
            {
                constArgs[i] = &args[i];
            }
            OnWebViewEventDelegate(webViewEvent->GetTarget(),
                                   name.c_str(),
                                   constArgs,
                                   size);
            delete[] constArgs;
            break;
        }
    case alt::CEvent::Type::RMLUI_EVENT:
        {
            auto rmlUiEvent = dynamic_cast<const alt::CRmlEvent*>(ev);
            auto name = rmlUiEvent->GetName();

            OnRmlEventDelegate(rmlUiEvent->GetElement(),
                               name.c_str(),
                               AllocMValue(std::move(rmlUiEvent->GetArgs())));
            break;
        }
    case alt::CEvent::Type::WEB_SOCKET_CLIENT_EVENT:
        {
            auto webSocketClientEvent = dynamic_cast<const alt::CWebSocketClientEvent*>(ev);
            auto args = webSocketClientEvent->GetArgs();
            auto name = webSocketClientEvent->GetName();
            auto size = args.size();
            auto constArgs = new alt::MValueConst*[size];

            for (uint64_t i = 0; i < size; i++)
            {
                constArgs[i] = &args[i];
            }
            OnWebSocketEventDelegate(webSocketClientEvent->GetTarget(),
                                     name.c_str(),
                                     constArgs,
                                     size);
            break;
        }
#pragma region Player Events
    case alt::CEvent::Type::SPAWNED:
        {
            OnPlayerSpawnDelegate();
            break;
        }
    case alt::CEvent::Type::DISCONNECT_EVENT:
        {
            OnPlayerDisconnectDelegate();
            break;
        }
    case alt::CEvent::Type::PLAYER_ENTER_VEHICLE:
        {
            auto playerEnterVehicleEvent = dynamic_cast<const alt::CPlayerEnterVehicleEvent*>(ev);
            OnPlayerEnterVehicleDelegate(playerEnterVehicleEvent->GetTarget(),
                                         playerEnterVehicleEvent->GetSeat());
            break;
        }
    case alt::CEvent::Type::PLAYER_LEAVE_VEHICLE:
        {
            auto playerLeaveVehicleEvent = dynamic_cast<const alt::CPlayerLeaveVehicleEvent*>(ev);
            OnPlayerLeaveVehicleDelegate(playerLeaveVehicleEvent->GetTarget(),
                                         playerLeaveVehicleEvent->GetSeat());
            break;
        }
    case alt::CEvent::Type::PLAYER_CHANGE_VEHICLE_SEAT:
        {
            auto playerChangeVehicleSeatEvent = dynamic_cast<const alt::CPlayerChangeVehicleSeatEvent*>(ev);
            OnPlayerChangeVehicleSeatDelegate(playerChangeVehicleSeatEvent->GetTarget(),
                                              playerChangeVehicleSeatEvent->GetOldSeat(),
                                              playerChangeVehicleSeatEvent->GetNewSeat());
            break;
        }
    case alt::CEvent::Type::PLAYER_CHANGE_ANIMATION_EVENT:
        {
            auto playerAnimationChangeEvent = dynamic_cast<const alt::CPlayerChangeAnimationEvent*>(ev);
            OnPlayerChangeAnimationDelegate(playerAnimationChangeEvent->GetTarget(),
                                            playerAnimationChangeEvent->GetOldAnimationDict(),
                                            playerAnimationChangeEvent->GetNewAnimationDict(),
                                            playerAnimationChangeEvent->GetOldAnimationName(),
                                            playerAnimationChangeEvent->GetNewAnimationName());
            break;
        }
    case alt::CEvent::Type::PLAYER_CHANGE_INTERIOR_EVENT:
        {
            auto playerChangeInteriorEvent = dynamic_cast<const alt::CPlayerChangeInteriorEvent*>(ev);
            auto oldInteriorLocation = playerChangeInteriorEvent->GetOldInteriorLocation();
            auto newInteriorLocation = playerChangeInteriorEvent->GetNewInteriorLocation();
            OnPlayerChangeInteriorDelegate(playerChangeInteriorEvent->GetTarget(),
                                           oldInteriorLocation,
                                           newInteriorLocation);
            break;
        }
    case alt::CEvent::Type::PLAYER_WEAPON_SHOOT_EVENT:
        {
            auto playerWeaponShootEvent = dynamic_cast<const alt::CPlayerWeaponShootEvent*>(ev);
            OnPlayerWeaponShootDelegate(playerWeaponShootEvent->GetWeapon(),
                                        playerWeaponShootEvent->GetTotalAmmo(),
                                        playerWeaponShootEvent->GetAmmoInClip());
            break;
        }
    case alt::CEvent::Type::PLAYER_WEAPON_CHANGE:
        {
            auto playerWeaponChangeEvent = dynamic_cast<const alt::CPlayerWeaponChangeEvent*>(ev);
            OnPlayerWeaponChangeDelegate(playerWeaponChangeEvent->GetOldWeapon(),
                                         playerWeaponChangeEvent->GetNewWeapon());
            break;
        }
    case alt::CEvent::Type::WEAPON_DAMAGE_EVENT:
        {
            auto weaponDamageEvent = dynamic_cast<const alt::CWeaponDamageEvent*>(ev);
            auto targetEntity = weaponDamageEvent->GetTarget();
            if (targetEntity == nullptr) return;
            auto eventShotOffset = weaponDamageEvent->GetShotOffset();
            position_t shotOffset = {eventShotOffset[0], eventShotOffset[1], eventShotOffset[2]};

            auto sourceEntity = weaponDamageEvent->GetSourceEntity();

            auto sourceType = alt::IBaseObject::Type::PLAYER;
            void* sourceTPtr = nullptr;

            if (sourceEntity != nullptr)
            {
                sourceTPtr = Util_GetEntityPointer(sourceEntity);
                sourceType = sourceEntity->GetType();
            }

            OnWeaponDamageDelegate(ev,
                                   Util_GetEntityPointer(targetEntity),
                                   targetEntity->GetType(),
                                   weaponDamageEvent->GetWeaponHash(),
                                   weaponDamageEvent->GetDamageValue(),
                                   shotOffset,
                                   weaponDamageEvent->GetBodyPart(),
                                   sourceTPtr,
                                   sourceType);
            break;
        }
    case alt::CEvent::Type::PLAYER_BULLET_HIT_EVENT:
        {
            auto playerBulletHitEvent = dynamic_cast<const alt::CPlayerBulletHitEvent*>(ev);
            auto victimEntity = playerBulletHitEvent->GetVictim();
            if (victimEntity == nullptr) return;
            auto position = playerBulletHitEvent->GetPosition();
            position_t pos = {position.x, position.y, position.z};

            OnPlayerBulletHitDelegate(playerBulletHitEvent->GetWeapon(),
                                      Util_GetEntityPointer(victimEntity),
                                      victimEntity->GetType(),
                                      pos);

            break;
        }
#pragma endregion
#pragma region Entity events
    case alt::CEvent::Type::GAME_ENTITY_CREATE:
        {
            auto gameEntityCreateEvent = dynamic_cast<const alt::CGameEntityCreateEvent*>(ev);
            auto entity = gameEntityCreateEvent->GetTarget();
            auto type = static_cast<uint8_t>(entity->GetType());
            void* ptr;

            switch (entity->GetType())
            {
            case alt::IBaseObject::Type::PLAYER:
                ptr = dynamic_cast<alt::IPlayer*>(entity);
                break;
            case alt::IBaseObject::Type::VEHICLE:
                ptr = dynamic_cast<alt::IVehicle*>(entity);
                break;
            case alt::IBaseObject::Type::LOCAL_OBJECT:
                ptr = dynamic_cast<alt::ILocalObject*>(entity);
                break;
            case alt::IBaseObject::Type::PED:
                ptr = dynamic_cast<alt::IPed*>(entity);
                break;
            case alt::IBaseObject::Type::OBJECT:
                ptr = dynamic_cast<alt::IObject*>(entity);
                break;
            default:
                ptr = nullptr;
            }

            OnGameEntityCreateDelegate(ptr,
                                       type);
            break;
        }
    case alt::CEvent::Type::GAME_ENTITY_DESTROY:
        {
            auto gameEntityDestroyEvent = dynamic_cast<const alt::CGameEntityDestroyEvent*>(ev);
            auto entity = gameEntityDestroyEvent->GetTarget();
            auto type = static_cast<uint8_t>(entity->GetType());
            void* ptr;

            switch (entity->GetType())
            {
            case alt::IBaseObject::Type::PLAYER:
                ptr = dynamic_cast<alt::IPlayer*>(entity);
                break;
            case alt::IBaseObject::Type::VEHICLE:
                ptr = dynamic_cast<alt::IVehicle*>(entity);
                break;
            case alt::IBaseObject::Type::LOCAL_OBJECT:
                ptr = dynamic_cast<alt::ILocalObject*>(entity);
                break;
            case alt::IBaseObject::Type::PED:
                ptr = dynamic_cast<alt::IPed*>(entity);
                break;
            case alt::IBaseObject::Type::OBJECT:
                ptr = dynamic_cast<alt::IObject*>(entity);
                break;
            default:
                ptr = nullptr;
            }

            OnGameEntityDestroyDelegate(ptr,
                                        type);
            break;
        }
#pragma endregion
#pragma region Misc
    case alt::CEvent::Type::RESOURCE_ERROR:
        {
            auto resourceErrorEvent = dynamic_cast<const alt::CResourceErrorEvent*>(ev);
            OnAnyResourceErrorDelegate(resourceErrorEvent->GetResource()->GetName().c_str());
            break;
        }
    case alt::CEvent::Type::RESOURCE_START:
        {
            auto resourceStartEvent = dynamic_cast<const alt::CResourceStartEvent*>(ev);
            OnAnyResourceStartDelegate(resourceStartEvent->GetResource()->GetName().c_str());
            break;
        }
    case alt::CEvent::Type::RESOURCE_STOP:
        {
            auto resourceStopEvent = dynamic_cast<const alt::CResourceStopEvent*>(ev);
            OnAnyResourceStopDelegate(resourceStopEvent->GetResource()->GetName().c_str());
            break;
        }
    case alt::CEvent::Type::KEYBOARD_EVENT:
        {
            auto keyboardEvent = dynamic_cast<const alt::CKeyboardEvent*>(ev);
            if (keyboardEvent->GetKeyState() == alt::CKeyboardEvent::KeyState::UP)
                OnKeyUpDelegate(keyboardEvent->GetKeyCode());
            else
                OnKeyDownDelegate(keyboardEvent->GetKeyCode());
            break;
        }
    case alt::CEvent::Type::CONNECTION_COMPLETE:
        {
            OnConnectionCompleteDelegate();
            break;
        }
    case alt::CEvent::Type::GLOBAL_META_CHANGE:
        {
            auto globalMetaChangeEvent = dynamic_cast<const alt::CGlobalMetaDataChangeEvent*>(ev);
            auto constValue = alt::MValueConst(globalMetaChangeEvent->GetVal());
            auto constOldValue = alt::MValueConst(globalMetaChangeEvent->GetOldVal());
            OnGlobalMetaChangeDelegate(globalMetaChangeEvent->GetKey().c_str(),
                                       &constValue,
                                       &constOldValue);
            break;
        }
    case alt::CEvent::Type::GLOBAL_SYNCED_META_CHANGE:
        {
            auto globalSyncedMetaChangeEvent = dynamic_cast<const alt::CGlobalSyncedMetaDataChangeEvent*>(ev);
            auto constValue = alt::MValueConst(globalSyncedMetaChangeEvent->GetVal());
            auto constOldValue = alt::MValueConst(globalSyncedMetaChangeEvent->GetOldVal());
            OnGlobalSyncedMetaChangeDelegate(globalSyncedMetaChangeEvent->GetKey().c_str(),
                                             &constValue,
                                             &constOldValue);
            break;
        }
    case alt::CEvent::Type::LOCAL_SYNCED_META_CHANGE:
        {
            auto metaChangeEvent = dynamic_cast<const alt::CLocalMetaDataChangeEvent*>(ev);
            auto constValue = alt::MValueConst(metaChangeEvent->GetVal());
            auto constOldValue = alt::MValueConst(metaChangeEvent->GetOldVal());
            OnLocalMetaChangeDelegate(metaChangeEvent->GetKey().c_str(),
                                      &constValue,
                                      &constOldValue);
            break;
        }
    case alt::CEvent::Type::NETOWNER_CHANGE:
        {
            auto netOwnerChangeEvent = dynamic_cast<const alt::CNetOwnerChangeEvent*>(ev);
            OnNetOwnerChangeDelegate(Util_GetEntityPointer(netOwnerChangeEvent->GetTarget()),
                                     netOwnerChangeEvent->GetTarget()->GetType(),
                                     netOwnerChangeEvent->GetNewOwner(),
                                     netOwnerChangeEvent->GetOldOwner());
            break;
        }
    case alt::CEvent::Type::STREAM_SYNCED_META_CHANGE:
        {
            auto streamSyncedMetaChangeEvent = dynamic_cast<const alt::CStreamSyncedMetaDataChangeEvent*>(ev);
            auto constValue = alt::MValueConst(streamSyncedMetaChangeEvent->GetVal());
            auto constOldValue = alt::MValueConst(streamSyncedMetaChangeEvent->GetOldVal());
            OnStreamSyncedMetaChangeDelegate(Util_GetBaseObjectPointer(streamSyncedMetaChangeEvent->GetTarget()),
                                             streamSyncedMetaChangeEvent->GetTarget()->GetType(),
                                             streamSyncedMetaChangeEvent->GetKey().c_str(),
                                             &constValue,
                                             &constOldValue);
            break;
        }
    case alt::CEvent::Type::SYNCED_META_CHANGE:
        {
            auto syncedMetaChangeEvent = dynamic_cast<const alt::CSyncedMetaDataChangeEvent*>(ev);
            auto constValue = alt::MValueConst(syncedMetaChangeEvent->GetVal());
            auto constOldValue = alt::MValueConst(syncedMetaChangeEvent->GetOldVal());
            OnSyncedMetaChangeDelegate(Util_GetBaseObjectPointer(syncedMetaChangeEvent->GetTarget()),
                                       syncedMetaChangeEvent->GetTarget()->GetType(),
                                       syncedMetaChangeEvent->GetKey().c_str(),
                                       &constValue,
                                       &constOldValue);
            break;
        }
    case alt::CEvent::Type::META_CHANGE:
        {
            auto metaChangeEvent = dynamic_cast<const alt::CMetaChangeEvent*>(ev);
            auto constValue = alt::MValueConst(metaChangeEvent->GetVal());
            auto constOldValue = alt::MValueConst(metaChangeEvent->GetOldVal());

            OnMetaChangeDelegate(Util_GetBaseObjectPointer(metaChangeEvent->GetTarget()),
                                 metaChangeEvent->GetTarget()->GetType(),
                                 metaChangeEvent->GetKey().c_str(),
                                 &constValue,
                                 &constOldValue);
            break;
        }
    case alt::CEvent::Type::TASK_CHANGE:
        {
            auto taskChangeEvent = dynamic_cast<const alt::CTaskChangeEvent*>(ev);
            OnTaskChangeDelegate(taskChangeEvent->GetOldTask(),
                                 taskChangeEvent->GetNewTask());
            break;
        }
    case alt::CEvent::Type::WINDOW_FOCUS_CHANGE:
        {
            auto windowFocusChangeEvent = dynamic_cast<const alt::CWindowFocusChangeEvent*>(ev);
            OnWindowFocusChangeDelegate(windowFocusChangeEvent->GetState());
            break;
        }
    case alt::CEvent::Type::WINDOW_RESOLUTION_CHANGE:
        {
            auto windowResolutionChangeEvent = dynamic_cast<const alt::CWindowResolutionChangeEvent*>(ev);
            auto oldRes = windowResolutionChangeEvent->GetOldResolution();
            auto newRes = windowResolutionChangeEvent->GetNewResolution();
            OnWindowResolutionChangeDelegate({static_cast<float>(oldRes[0]), static_cast<float>(oldRes[1])},
                                             {static_cast<float>(newRes[0]), static_cast<float>(newRes[1])});
            break;
        }
#pragma endregion
    case alt::CEvent::Type::WORLD_OBJECT_POSITION_CHANGE:
        {
            auto worldObjectPositionChangeEvent = dynamic_cast<const alt::CWorldObjectPositionChangeEvent*>(ev);

            auto oldPosition = worldObjectPositionChangeEvent->GetOldPosition();

            OnWorldObjectPositionChangeDelegate(Util_GetWorldObjectPointer(worldObjectPositionChangeEvent->GetWorldObject()),
                                                worldObjectPositionChangeEvent->GetWorldObject()->GetType(),
                                                {oldPosition.x, oldPosition.y, oldPosition.z});
            break;
        }
    case alt::CEvent::Type::WORLD_OBJECT_STREAM_IN:
        {
            auto worldObjectStreamInEvent = dynamic_cast<const alt::CWorldObjectStreamInEvent*>(ev);

            OnWorldObjectStreamInDelegate(Util_GetWorldObjectPointer(worldObjectStreamInEvent->GetWorldObject()),
                                          worldObjectStreamInEvent->GetWorldObject()->GetType());
            break;
        }
    case alt::CEvent::Type::WORLD_OBJECT_STREAM_OUT:
        {
            auto worldObjectStreamOutEvent = dynamic_cast<const alt::CWorldObjectStreamOutEvent*>(ev);

            OnWorldObjectStreamOutDelegate(Util_GetWorldObjectPointer(worldObjectStreamOutEvent->GetWorldObject()),
                                           worldObjectStreamOutEvent->GetWorldObject()->GetType());
            break;
        }
    case alt::CEvent::Type::COLSHAPE_EVENT:
        {
            auto colShapeEvent = dynamic_cast<const alt::CColShapeEvent*>(ev);
            auto entity = colShapeEvent->GetEntity();
            auto worldObjectPointer = Util_GetWorldObjectPointer(entity);
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
    case alt::CEvent::Type::ENTITY_HIT_ENTITY:
        {
            auto entityHitEntityEvent = dynamic_cast<const alt::CEntityHitEntityEvent*>(ev);
            auto target = entityHitEntityEvent->GetTarget();
            auto targetPointer = Util_GetEntityPointer(target);

            auto damager = entityHitEntityEvent->GetDamager();
            auto damagerPointer = Util_GetEntityPointer(damager);

            OnEntityHitEntityDelegate(targetPointer,
                                      target->GetType(),
                                      damagerPointer,
                                      damager->GetType(),
                                      entityHitEntityEvent->GetWeapon());
            break;
        }
    case alt::CEvent::Type::PLAYER_START_ENTER_VEHICLE:
        {
            auto playerStartEnterVehicleEvent = dynamic_cast<const alt::CPlayerStartEnterVehicleEvent*>(ev);
            auto target = playerStartEnterVehicleEvent->GetTarget();
            auto targetPointer = Util_GetEntityPointer(target);

            auto player = playerStartEnterVehicleEvent->GetPlayer();
            auto playerPointer = Util_GetEntityPointer(player);

            OnPlayerStartEnterVehicleDelegate(targetPointer,
                                              playerPointer,
                                              playerStartEnterVehicleEvent->GetSeat());
            break;
        }
    case alt::CEvent::Type::PLAYER_START_LEAVE_VEHICLE:
        {
            auto playerStartLeaveVehicleEvent = dynamic_cast<const alt::CPlayerStartLeaveVehicleEvent*>(ev);
            auto target = playerStartLeaveVehicleEvent->GetTarget();
            auto targetPointer = Util_GetEntityPointer(target);

            auto player = playerStartLeaveVehicleEvent->GetPlayer();
            auto playerPointer = Util_GetEntityPointer(player);

            OnPlayerStartLeaveVehicleDelegate(targetPointer,
                                              playerPointer,
                                              playerStartLeaveVehicleEvent->GetSeat());
            break;
        }
    case alt::CEvent::Type::VOICE_CONNECTION_EVENT:
        {
            auto voiceConnectionEvent = dynamic_cast<const alt::CVoiceConnectionEvent*>(ev);

            OnVoiceConnectionDelegate(static_cast<uint8_t>(voiceConnectionEvent->GetState()));

            break;
        }
    case alt::CEvent::Type::AUDIO_EVENT:
        {
            auto audioEvent = dynamic_cast<const alt::CAudioEvent*>(ev);

            auto args = audioEvent->GetArgs();
            auto name = audioEvent->GetName();
            auto size = args.size();
            auto constArgs = new alt::MValueConst*[size];

            for (uint64_t i = 0; i < size; i++)
            {
                constArgs[i] = &args[i];
            }
            OnAudioEventDelegate(audioEvent->GetTarget(),
                                 name.c_str(),
                                 constArgs,
                                 size);
            break;
        }
    default:
        {
            std::cout << "Unhandled client event #" << static_cast<int>(ev->GetType()) << " got called" << std::endl;
            break;
        }
    }
}

void CSharpResourceImpl::OnTick()
{
    auto scope = resource->PushNativesScope();
    OnTickDelegate();
}

void CSharpResourceImpl::OnCreateBaseObject(alt::IBaseObject* object)
{
    switch (object->GetType())
    {
    case alt::IBaseObject::Type::VEHICLE:
        {
            auto vehicle = dynamic_cast<alt::IVehicle*>(object);
            OnCreateBaseObjectDelegate(vehicle, vehicle->GetType(), vehicle->GetID());
            break;
        }
    case alt::IBaseObject::Type::PLAYER:
        {
            auto player = dynamic_cast<alt::IPlayer*>(object);
            OnCreateBaseObjectDelegate(player, player->GetType(), player->GetID());
            break;
        }
    case alt::IBaseObject::Type::PED:
        {
            auto ped = dynamic_cast<alt::IPed*>(object);
            OnCreateBaseObjectDelegate(ped, ped->GetType(), ped->GetID());
            break;
        }
    case alt::IBaseObject::Type::BLIP:
        {
            auto blip = dynamic_cast<alt::IBlip*>(object);
            OnCreateBaseObjectDelegate(blip, blip->GetType(), blip->GetID());
            break;
        }
    case alt::IBaseObject::Type::WEBVIEW:
        {
            auto webview = dynamic_cast<alt::IWebView*>(object);
            OnCreateBaseObjectDelegate(webview, webview->GetType(), webview->GetID());
            break;
        }
    case alt::IBaseObject::Type::CHECKPOINT:
        {
            auto checkPoint = dynamic_cast<alt::ICheckpoint*>(object);
            OnCreateBaseObjectDelegate(checkPoint, checkPoint->GetType(), checkPoint->GetID());
            break;
        }
    case alt::IBaseObject::Type::COLSHAPE:
        {
            auto colshape = dynamic_cast<alt::IColShape*>(object);
            OnCreateBaseObjectDelegate(colshape, colshape->GetType(), colshape->GetID());
            break;
        }
    case alt::IBaseObject::Type::WEBSOCKET_CLIENT:
        {
            auto webSocketClient = dynamic_cast<alt::IWebSocketClient*>(object);
            OnCreateBaseObjectDelegate(webSocketClient, webSocketClient->GetType(), webSocketClient->GetID());
            break;
        }
    case alt::IBaseObject::Type::HTTP_CLIENT:
        {
            auto httpClient = dynamic_cast<alt::IHttpClient*>(object);
            OnCreateBaseObjectDelegate(httpClient, httpClient->GetType(), httpClient->GetID());
            break;
        }
    case alt::IBaseObject::Type::AUDIO:
        {
            auto audio = dynamic_cast<alt::IAudio*>(object);
            OnCreateBaseObjectDelegate(audio, audio->GetType(), audio->GetID());
            break;
        }
    case alt::IBaseObject::Type::AUDIO_OUTPUT:
        {
            auto audioOutput = dynamic_cast<alt::IAudioOutput*>(object);
            OnCreateBaseObjectDelegate(audioOutput, audioOutput->GetType(), audioOutput->GetID());
            break;
        }
    case alt::IBaseObject::Type::AUDIO_OUTPUT_WORLD:
        {
            auto audioWorldOutput = dynamic_cast<alt::IAudioWorldOutput*>(object);
            OnCreateBaseObjectDelegate(audioWorldOutput, audioWorldOutput->GetType(), audioWorldOutput->GetID());
            break;
        }
    case alt::IBaseObject::Type::AUDIO_OUTPUT_ATTACHED:
        {
            auto audioAttachedOutput = dynamic_cast<alt::IAudioAttachedOutput*>(object);
            OnCreateBaseObjectDelegate(audioAttachedOutput, audioAttachedOutput->GetType(), audioAttachedOutput->GetID());
            break;
        }
    case alt::IBaseObject::Type::AUDIO_OUTPUT_FRONTEND:
        {
            auto audioFrontendOutput = dynamic_cast<alt::IAudioFrontendOutput*>(object);
            OnCreateBaseObjectDelegate(audioFrontendOutput, audioFrontendOutput->GetType(), audioFrontendOutput->GetID());
            break;
        }
    case alt::IBaseObject::Type::AUDIO_FILTER:
        {
            auto audioFilter = dynamic_cast<alt::IAudioFilter*>(object);
            OnCreateBaseObjectDelegate(audioFilter, audioFilter->GetType(), audioFilter->GetID());
            break;
        }
    case alt::IBaseObject::Type::RML_ELEMENT:
        {
            auto rmlElement = dynamic_cast<alt::IRmlElement*>(object);
            OnCreateBaseObjectDelegate(rmlElement, rmlElement->GetType(), rmlElement->GetID());
            break;
        }
    case alt::IBaseObject::Type::RML_DOCUMENT:
        {
            auto rmlDocument = dynamic_cast<alt::IRmlDocument*>(object);
            OnCreateBaseObjectDelegate(rmlDocument, rmlDocument->GetType(), rmlDocument->GetID());
            break;
        }
    case alt::IBaseObject::Type::LOCAL_OBJECT:
        {
            auto altObject = dynamic_cast<alt::ILocalObject*>(object);
            OnCreateBaseObjectDelegate(altObject, altObject->GetType(), altObject->GetID());
            break;
        }
    case alt::IBaseObject::Type::VIRTUAL_ENTITY:
        {
            auto virtualEntity = dynamic_cast<alt::IVirtualEntity*>(object);
            OnCreateBaseObjectDelegate(virtualEntity, virtualEntity->GetType(), virtualEntity->GetID());
            break;
        }
    case alt::IBaseObject::Type::VIRTUAL_ENTITY_GROUP:
        {
            auto virtualEntityGroup = dynamic_cast<alt::IVirtualEntityGroup*>(object);
            OnCreateBaseObjectDelegate(virtualEntityGroup, virtualEntityGroup->GetType(), virtualEntityGroup->GetID());
            break;
        }
    case alt::IBaseObject::Type::LOCAL_PLAYER:
        break;
    case alt::IBaseObject::Type::LOCAL_VEHICLE:
        {
            auto localVehicle = dynamic_cast<alt::ILocalVehicle*>(object);
            OnCreateBaseObjectDelegate(localVehicle, localVehicle->GetType(), localVehicle->GetID());
            break;
        }
    case alt::IBaseObject::Type::LOCAL_PED:
        {
            auto localPed = dynamic_cast<alt::ILocalPed*>(object);
            OnCreateBaseObjectDelegate(localPed, localPed->GetType(), localPed->GetID());
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
    default:
        {
            std::cout << "Unhandled type #" << static_cast<int>(object->GetType()) <<
                " for create base object got called" << std::endl;
            break;
        }
    }
}

void CSharpResourceImpl::OnRemoveBaseObject(alt::IBaseObject* object)
{
    switch (object->GetType())
    {
    case alt::IBaseObject::Type::VEHICLE:
        {
            const auto vehicle = dynamic_cast<alt::IVehicle*>(object);
            OnRemoveBaseObjectDelegate(vehicle, vehicle->GetType());
            break;
        }
    case alt::IBaseObject::Type::PLAYER:
        {
            const auto player = dynamic_cast<alt::IPlayer*>(object);
            OnRemoveBaseObjectDelegate(player, player->GetType());
            break;
        }
    case alt::IBaseObject::Type::PED:
        {
            const auto ped = dynamic_cast<alt::IPed*>(object);
            OnRemoveBaseObjectDelegate(ped, ped->GetType());
            break;
        }
    case alt::IBaseObject::Type::BLIP:
        {
            const auto blip = dynamic_cast<alt::IBlip*>(object);
            OnRemoveBaseObjectDelegate(blip, blip->GetType());
            break;
        }
    case alt::IBaseObject::Type::WEBVIEW:
        {
            const auto webView = dynamic_cast<alt::IWebView*>(object);
            OnRemoveBaseObjectDelegate(webView, webView->GetType());
            break;
        }
    case alt::IBaseObject::Type::CHECKPOINT:
        {
            const auto checkpoint = dynamic_cast<alt::ICheckpoint*>(object);
            OnRemoveBaseObjectDelegate(checkpoint, checkpoint->GetType());
            break;
        }
    case alt::IBaseObject::Type::COLSHAPE:
        {
            const auto colshape = dynamic_cast<alt::IColShape*>(object);
            OnRemoveBaseObjectDelegate(colshape, colshape->GetType());
            break;
        }
    case alt::IBaseObject::Type::WEBSOCKET_CLIENT:
        {
            const auto webSocketClient = dynamic_cast<alt::IWebSocketClient*>(object);
            OnRemoveBaseObjectDelegate(webSocketClient, webSocketClient->GetType());
            break;
        }
    case alt::IBaseObject::Type::HTTP_CLIENT:
        {
            const auto httpClient = dynamic_cast<alt::IHttpClient*>(object);
            OnRemoveBaseObjectDelegate(httpClient, httpClient->GetType());
            break;
        }
    case alt::IBaseObject::Type::AUDIO:
        {
            const auto audio = dynamic_cast<alt::IAudio*>(object);
            OnRemoveBaseObjectDelegate(audio, audio->GetType());
            break;
        }
    case alt::IBaseObject::Type::AUDIO_OUTPUT:
        {
            const auto audioOutput = dynamic_cast<alt::IAudioOutput*>(object);
            OnRemoveBaseObjectDelegate(audioOutput, audioOutput->GetType());
            break;
        }
    case alt::IBaseObject::Type::AUDIO_OUTPUT_WORLD:
        {
            const auto audioWorldOutput = dynamic_cast<alt::IAudioWorldOutput*>(object);
            OnRemoveBaseObjectDelegate(audioWorldOutput, audioWorldOutput->GetType());
            break;
        }
    case alt::IBaseObject::Type::AUDIO_OUTPUT_ATTACHED:
        {
            const auto audioAttachedOutput = dynamic_cast<alt::IAudioAttachedOutput*>(object);
            OnRemoveBaseObjectDelegate(audioAttachedOutput, audioAttachedOutput->GetType());
            break;
        }
    case alt::IBaseObject::Type::AUDIO_OUTPUT_FRONTEND:
        {
            const auto audioFrontendOutput = dynamic_cast<alt::IAudioFrontendOutput*>(object);
            OnRemoveBaseObjectDelegate(audioFrontendOutput, audioFrontendOutput->GetType());
            break;
        }
    case alt::IBaseObject::Type::AUDIO_FILTER:
        {
            const auto audioFilter = dynamic_cast<alt::IAudioFilter*>(object);
            OnRemoveBaseObjectDelegate(audioFilter, audioFilter->GetType());
            break;
        }
    case alt::IBaseObject::Type::RML_ELEMENT:
        {
            const auto rmlElement = dynamic_cast<alt::IRmlElement*>(object);
            OnRemoveBaseObjectDelegate(rmlElement, rmlElement->GetType());
            break;
        }
    case alt::IBaseObject::Type::RML_DOCUMENT:
        {
            const auto rmlDocument = dynamic_cast<alt::IRmlDocument*>(object);
            OnRemoveBaseObjectDelegate(rmlDocument, rmlDocument->GetType());
            break;
        }
    case alt::IBaseObject::Type::LOCAL_OBJECT:
        {
            const auto altObject = dynamic_cast<alt::ILocalObject*>(object);
            OnRemoveBaseObjectDelegate(altObject, altObject->GetType());
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
    case alt::IBaseObject::Type::LOCAL_PLAYER:
        break;
    case alt::IBaseObject::Type::LOCAL_VEHICLE:
        {
            const auto localVehicle = dynamic_cast<alt::ILocalVehicle*>(object);
            OnRemoveBaseObjectDelegate(localVehicle, localVehicle->GetType());
            break;
        }
    case alt::IBaseObject::Type::LOCAL_PED:
        {
            const auto localPed = dynamic_cast<alt::ILocalPed*>(object);
            OnRemoveBaseObjectDelegate(localPed, localPed->GetType());
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
    default:
        {
            std::cout << "Unhandled type #" << static_cast<int>(object->GetType()) <<
                " for remove base object got called" << std::endl;
            break;
        }
    }
}

std::string CSharpResourceImpl::ReadFile(std::string path)
{
    auto pkg = resource->GetPackage();
    if (!pkg->FileExists(path)) return {};
    alt::IPackage::File* pkgFile = pkg->OpenFile(path);
    std::string src(pkg->GetFileSize(pkgFile), 0);
    pkg->ReadFile(pkgFile, src.data(), src.size());
    pkg->CloseFile(pkgFile);

    return src;
}


void CSharpResourceImpl::ResetDelegates() {
    OnTickDelegate = []() {};
    OnClientEventDelegate = [](auto var, auto var2, auto var3) {};
    OnServerEventDelegate = [](auto var, auto var2, auto var3) {};
    OnWebViewEventDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnConsoleCommandDelegate = [](auto var, auto var2, auto var3) {};
    OnWebSocketEventDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnRmlEventDelegate = [](auto var, auto var2, auto var3) {};
    OnAudioEventDelegate = [](auto var, auto var2, auto var3, auto var4) {};

    OnPlayerSpawnDelegate = [](){};
    OnPlayerDisconnectDelegate = [](){};
    OnPlayerEnterVehicleDelegate = [](auto var, auto var2) {};
    OnPlayerLeaveVehicleDelegate = [](auto var, auto var2) {};

    OnGameEntityCreateDelegate = [](auto var, auto var2) {};
    OnGameEntityDestroyDelegate = [](auto var, auto var2) {};

    OnAnyResourceErrorDelegate = [](auto var) {};
    OnAnyResourceStartDelegate = [](auto var) {};
    OnAnyResourceStopDelegate = [](auto var) {};

    OnKeyUpDelegate = [](auto var) {};
    OnKeyDownDelegate = [](auto var) {};

    OnPlayerChangeVehicleSeatDelegate = [](auto var, auto var2, auto var3) {};
    OnPlayerChangeAnimationDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5) {};
    OnPlayerChangeInteriorDelegate = [](auto var, auto var2, auto var3) {};

    OnConnectionCompleteDelegate = []() {};

    OnGlobalMetaChangeDelegate = [](auto var, auto var2, auto var3) {};
    OnGlobalSyncedMetaChangeDelegate = [](auto var, auto var2, auto var3) {};
    OnLocalMetaChangeDelegate = [](auto var, auto var2, auto var3) {};
    OnStreamSyncedMetaChangeDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5) {};
    OnSyncedMetaChangeDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5) {};
    OnMetaChangeDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5) {};

    OnNetOwnerChangeDelegate = [](auto var, auto var2, auto var3, auto var4) {};

    OnTaskChangeDelegate = [](auto var, auto var2) {};

    OnWindowFocusChangeDelegate = [](auto var) {};
    OnWindowResolutionChangeDelegate = [](auto var, auto var2) {};

    OnWorldObjectPositionChangeDelegate = [](auto var, auto var2, auto var3){};
    OnWorldObjectStreamInDelegate = [](auto var, auto var2){};
    OnWorldObjectStreamOutDelegate = [](auto var, auto var2){};

    OnPlayerWeaponShootDelegate = [](auto var, auto var2, auto var3) {};

    OnPlayerWeaponChangeDelegate = [](auto var, auto var2) {};

    OnWeaponDamageDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5, auto var6, auto var7, auto var8, auto var9) {};

    OnCreateBaseObjectDelegate = [](auto var, auto var2, auto var3) {};
    OnRemoveBaseObjectDelegate = [](auto var, auto var2) {};

    OnColShapeDelegate = [](auto var, auto var2, auto var3, auto var4) {};
    OnCheckpointDelegate = [](auto var, auto var2, auto var3, auto var4) {};

    OnEntityHitEntityDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5) {};

    OnPlayerStartEnterVehicleDelegate = [](auto var, auto var2, auto var3) {};
    OnPlayerStartLeaveVehicleDelegate = [](auto var, auto var2, auto var3) {};

    OnPlayerBulletHitDelegate = [](auto var, auto var2, auto var3, auto var4) {};

    OnVoiceConnectionDelegate = [](auto var) {};
}