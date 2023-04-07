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
#include "cpp-sdk/events/CPlayerChangeAnimationEvent.h"
#include "cpp-sdk/events/CPlayerWeaponShootEvent.h"
#include "cpp-sdk/events/CWeaponDamageEvent.h"
#include "../../c-api/utils/entity.h"

using namespace std;

bool CSharpResourceImpl::Start()
{
    cs::Log::Info << "Starting resource" << cs::Log::Endl;
    ResetDelegates();
    resource->EnableNatives();
    auto scope = resource->PushNativesScope();
    return CoreClr::StartResource(resource, core);
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
            auto size = serverArgs.GetSize();

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
            auto size = serverArgs.GetSize();
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
            auto size = args.GetSize();
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
            auto args = rmlUiEvent->GetArgs();
            auto name = rmlUiEvent->GetName();
            auto size = args->GetSize();

            OnRmlEventDelegate(rmlUiEvent->GetElement(),
                               name.c_str(),
                               rmlUiEvent->GetArgs().Get(),
                               size);
            break;
        }
    case alt::CEvent::Type::WEB_SOCKET_CLIENT_EVENT:
        {
            auto webSocketClientEvent = dynamic_cast<const alt::CWebSocketClientEvent*>(ev);
            auto args = webSocketClientEvent->GetArgs();
            auto name = webSocketClientEvent->GetName();
            auto size = args.GetSize();
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
            OnWeaponDamageDelegate(ev,
                                   GetEntityPointer(targetEntity),
                                   targetEntity->GetType(),
                                   weaponDamageEvent->GetWeaponHash(),
                                   weaponDamageEvent->GetDamageValue(),
                                   shotOffset,
                                   weaponDamageEvent->GetBodyPart());
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
            case alt::IBaseObject::Type::OBJECT:
                ptr = dynamic_cast<alt::IObject*>(entity);
                break;
            case alt::IBaseObject::Type::PED:
                ptr = dynamic_cast<alt::IPed*>(entity);
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
            case alt::IBaseObject::Type::OBJECT:
                ptr = dynamic_cast<alt::IObject*>(entity);
                break;
            case alt::IBaseObject::Type::PED:
                ptr = dynamic_cast<alt::IPed*>(entity);
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
            OnNetOwnerChangeDelegate(GetEntityPointer(netOwnerChangeEvent->GetTarget()),
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
            OnStreamSyncedMetaChangeDelegate(GetEntityPointer(streamSyncedMetaChangeEvent->GetTarget()),
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
            OnSyncedMetaChangeDelegate(GetEntityPointer(syncedMetaChangeEvent->GetTarget()),
                                       syncedMetaChangeEvent->GetTarget()->GetType(),
                                       syncedMetaChangeEvent->GetKey().c_str(),
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

            OnWorldObjectPositionChangeDelegate(GetEntityPointer(worldObjectPositionChangeEvent->GetWorldObject()),
                                                worldObjectPositionChangeEvent->GetWorldObject()->GetType(),
                                                {oldPosition.x, oldPosition.y, oldPosition.z});
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
            OnCreateVehicleDelegate(vehicle, vehicle->GetID());
            break;
        }
    case alt::IBaseObject::Type::PLAYER:
        {
            auto player = dynamic_cast<alt::IPlayer*>(object);
            OnCreatePlayerDelegate(player, player->GetID());
            break;
        }
    case alt::IBaseObject::Type::PED:
        {
            auto ped = dynamic_cast<alt::IPed*>(object);
            OnCreatePedDelegate(ped, ped->GetID());
            break;
        }
    case alt::IBaseObject::Type::BLIP:
        {
            auto blip = dynamic_cast<alt::IBlip*>(object);
            OnCreateBlipDelegate(blip, blip->GetID());
            break;
        }
    case alt::IBaseObject::Type::WEBVIEW:
        {
            auto webview = dynamic_cast<alt::IWebView*>(object);
            OnCreateWebViewDelegate(webview, webview->GetID());
            break;
        }
    case alt::IBaseObject::Type::CHECKPOINT:
        {
            auto checkPoint = dynamic_cast<alt::ICheckpoint*>(object);
            OnCreateCheckpointDelegate(checkPoint, checkPoint->GetID());
            break;
        }
    case alt::IBaseObject::Type::WEBSOCKET_CLIENT:
        {
            auto webSocketClient = dynamic_cast<alt::IWebSocketClient*>(object);
            OnCreateWebSocketClientDelegate(webSocketClient, webSocketClient->GetID());
            break;
        }
    case alt::IBaseObject::Type::HTTP_CLIENT:
        {
            auto httpClient = dynamic_cast<alt::IHttpClient*>(object);
            OnCreateHttpClientDelegate(httpClient, httpClient->GetID());
            break;
        }
    case alt::IBaseObject::Type::AUDIO:
        {
            auto audio = dynamic_cast<alt::IAudio*>(object);
            OnCreateAudioDelegate(audio, audio->GetID());
            break;
        }
    case alt::IBaseObject::Type::RML_ELEMENT:
        {
            auto rmlElement = dynamic_cast<alt::IRmlElement*>(object);
            OnCreateRmlElementDelegate(rmlElement, 0);
            break;
        }
    case alt::IBaseObject::Type::RML_DOCUMENT:
        {
            auto rmlDocument = dynamic_cast<alt::IRmlDocument*>(object);
            OnCreateRmlDocumentDelegate(rmlDocument, 0);
            break;
        }
    case alt::IBaseObject::Type::OBJECT:
        {
            auto altObject = dynamic_cast<alt::IObject*>(object);
            OnCreateObjectDelegate(altObject, altObject->GetID());
            break;
        }
    case alt::IBaseObject::Type::VIRTUAL_ENTITY:
        {
            auto virtualEntity = dynamic_cast<alt::IVirtualEntity*>(object);
            OnCreateVirtualEntityDelegate(virtualEntity, virtualEntity->GetID());
            break;
        }
    case alt::IBaseObject::Type::VIRTUAL_ENTITY_GROUP:
        {
            auto virtualEntityGroup = dynamic_cast<alt::IVirtualEntityGroup*>(object);
            OnCreateVirtualEntityGroupDelegate(virtualEntityGroup, virtualEntityGroup->GetID());
            break;
        }
    case alt::IBaseObject::Type::LOCAL_PLAYER:
        break;
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
            OnRemoveVehicleDelegate(dynamic_cast<alt::IVehicle*>(object));
            break;
        }
    case alt::IBaseObject::Type::PLAYER:
        {
            OnRemovePlayerDelegate(dynamic_cast<alt::IPlayer*>(object));
            break;
        }
    case alt::IBaseObject::Type::PED:
        {
            OnRemovePedDelegate(dynamic_cast<alt::IPed*>(object));
            break;
        }
    case alt::IBaseObject::Type::BLIP:
        {
            OnRemoveBlipDelegate(dynamic_cast<alt::IBlip*>(object));
            break;
        }
    case alt::IBaseObject::Type::WEBVIEW:
        {
            OnRemoveWebViewDelegate(dynamic_cast<alt::IWebView*>(object));
            break;
        }
    case alt::IBaseObject::Type::CHECKPOINT:
        {
            OnRemoveCheckpointDelegate(dynamic_cast<alt::ICheckpoint*>(object));
            break;
        }
    case alt::IBaseObject::Type::WEBSOCKET_CLIENT:
        {
            OnRemoveWebSocketClientDelegate(dynamic_cast<alt::IWebSocketClient*>(object));
            break;
        }
    case alt::IBaseObject::Type::HTTP_CLIENT:
        {
            OnRemoveHttpClientDelegate(dynamic_cast<alt::IHttpClient*>(object));
            break;
        }
    case alt::IBaseObject::Type::AUDIO:
        {
            OnRemoveAudioDelegate(dynamic_cast<alt::IAudio*>(object));
            break;
        }
    case alt::IBaseObject::Type::RML_ELEMENT:
        {
            OnRemoveRmlElementDelegate(dynamic_cast<alt::IRmlElement*>(object));
            break;
        }
    case alt::IBaseObject::Type::RML_DOCUMENT:
        {
            OnRemoveRmlDocumentDelegate(dynamic_cast<alt::IRmlDocument*>(object));
            break;
        }
    case alt::IBaseObject::Type::OBJECT:
        {
            OnRemoveObjectDelegate(dynamic_cast<alt::IObject*>(object));
            break;
        }
    case alt::IBaseObject::Type::VIRTUAL_ENTITY:
        {
            OnRemoveVirtualEntityDelegate(dynamic_cast<alt::IVirtualEntity*>(object));
            break;
        }
    case alt::IBaseObject::Type::VIRTUAL_ENTITY_GROUP:
        {
            OnRemoveVirtualEntityGroupDelegate(dynamic_cast<alt::IVirtualEntityGroup*>(object));
            break;
        }
    case alt::IBaseObject::Type::LOCAL_PLAYER:
        break;
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
    OnRmlEventDelegate = [](auto var, auto var2, auto var3, auto var4) {};

    OnCreatePlayerDelegate = [](auto var, auto var2) {};
    OnRemovePlayerDelegate = [](auto var) {};

    OnCreateObjectDelegate = [](auto var, auto var2) {};
    OnRemoveObjectDelegate = [](auto var) {};

    OnCreateVehicleDelegate = [](auto var, auto var2) {};
    OnRemoveVehicleDelegate = [](auto var) {};

    OnCreatePedDelegate = [](auto var, auto var2) {};
    OnRemovePedDelegate = [](auto var) {};

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

    OnNetOwnerChangeDelegate = [](auto var, auto var2, auto var3, auto var4) {};

    OnRemoveEntityDelegate = [](auto var, auto var2) {};

    OnTaskChangeDelegate = [](auto var, auto var2) {};

    OnWindowFocusChangeDelegate = [](auto var) {};
    OnWindowResolutionChangeDelegate = [](auto var, auto var2) {};

    OnWorldObjectPositionChangeDelegate = [](auto var, auto var2, auto var3){};

    OnPlayerWeaponShootDelegate = [](auto var, auto var2, auto var3) {};

    OnPlayerWeaponChangeDelegate = [](auto var, auto var2) {};

    OnWeaponDamageDelegate = [](auto var, auto var2, auto var3, auto var4, auto var5, auto var6, auto var7) {};

    OnCreateBlipDelegate = [](auto var, auto var2) {};
    OnCreateWebViewDelegate = [](auto var, auto var2) {};
    OnCreateCheckpointDelegate = [](auto var, auto var2) {};
    OnCreateWebSocketClientDelegate = [](auto var, auto var2) {};
    OnCreateHttpClientDelegate = [](auto var, auto var2) {};
    OnCreateAudioDelegate = [](auto var, auto var2) {};
    OnCreateRmlElementDelegate = [](auto var, auto var2) {};
    OnCreateRmlDocumentDelegate = [](auto var, auto var2) {};

    OnRemoveBlipDelegate = [](auto var) {};
    OnRemoveWebViewDelegate = [](auto var) {};
    OnRemoveCheckpointDelegate = [](auto var) {};
    OnRemoveWebSocketClientDelegate = [](auto var) {};
    OnRemoveHttpClientDelegate = [](auto var) {};
    OnRemoveAudioDelegate = [](auto var) {};
    OnRemoveRmlElementDelegate = [](auto var) {};
    OnRemoveRmlDocumentDelegate = [](auto var) {};

    OnCreateVirtualEntityDelegate = [](auto var, auto var2){};
    OnRemoveVirtualEntityDelegate = [](auto var){};
    OnCreateVirtualEntityGroupDelegate = [](auto var, auto var2){};
    OnRemoveVirtualEntityGroupDelegate = [](auto var){};
}