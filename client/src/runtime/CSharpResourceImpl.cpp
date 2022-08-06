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
#include "../../c-api/utils/entity.h"

using namespace std;

bool CSharpResourceImpl::Start()
{
    Log::Info << "Starting resource" << Log::Endl;
    try {
        runtime->clr.Initialize();
    } catch(std::runtime_error& e) {
        Log::Error << "Failed to initialize CLR: " << e.what() << Log::Endl;
        abort();
    }
    resource->EnableNatives();
    auto scope = resource->PushNativesScope();
    ResetDelegates();
    return CoreClr::StartResource(resource, core);
}

bool CSharpResourceImpl::Stop()
{
    auto scope = resource->PushNativesScope();
    auto res = CoreClr::StopResource(resource);
    ResetDelegates();
    return res;
}

bool CSharpResourceImpl::OnEvent(const alt::CEvent* ev)
{
    if (ev == nullptr) return true;
    auto scope = resource->PushNativesScope();
    switch(ev->GetType()) {
        case alt::CEvent::Type::SERVER_SCRIPT_EVENT: {
            auto serverScriptEvent = (alt::CServerScriptEvent *) ev;
            alt::MValueArgs serverArgs = serverScriptEvent->GetArgs();
            uint64_t size = serverArgs.GetSize();
            if (size == 0) {
                OnServerEventDelegate(serverScriptEvent->GetName().c_str(), nullptr, 0);
            } else {
                auto constArgs = new alt::MValueConst *[size];
                for (uint64_t i = 0; i < size; i++) {
                    constArgs[i] = &serverArgs[i];
                }
                OnServerEventDelegate(serverScriptEvent->GetName().c_str(), constArgs, size);
                delete[] constArgs;
            }
            break;
        }
        case alt::CEvent::Type::CLIENT_SCRIPT_EVENT: {
            auto clientScriptEvent = (alt::CClientScriptEvent *) ev;
            alt::MValueArgs serverArgs = clientScriptEvent->GetArgs();
            uint64_t size = serverArgs.GetSize();
            if (size == 0) {
                OnClientEventDelegate(clientScriptEvent->GetName().c_str(), nullptr, 0);
            } else {
                auto constArgs = new alt::MValueConst *[size];
                for (uint64_t i = 0; i < size; i++) {
                    constArgs[i] = &serverArgs[i];
                }
                OnClientEventDelegate(clientScriptEvent->GetName().c_str(), constArgs, size);
                delete[] constArgs;
            }
            break;
        }
        case alt::CEvent::Type::CONSOLE_COMMAND_EVENT: {
            auto consoleCommandEvent = (alt::CConsoleCommandEvent *) ev;
            auto args = consoleCommandEvent->GetArgs();
            uint64_t size = args.size();
            auto cArgs = new const char *[size];
            for (uint64_t i = 0; i < size; i++) {
                cArgs[i] = args[i].c_str();
            }
            auto name = consoleCommandEvent->GetName();
            OnConsoleCommandDelegate(name.c_str(), cArgs, (uint32_t) size);
            delete[] cArgs;
            break;
        }
        case alt::CEvent::Type::WEB_VIEW_EVENT: {
            auto webViewEvent = (alt::CWebViewEvent *) ev;
            auto args = webViewEvent->GetArgs();
            auto name = webViewEvent->GetName();
            auto size = args.GetSize();
            auto constArgs = new alt::MValueConst *[size];

            for (auto i = 0; i < size; i++) {
                constArgs[i] = &args[i];
            }
            OnWebViewEventDelegate(webViewEvent->GetTarget().Get(), name.c_str(), constArgs, size);
            delete[] constArgs;
            break;
        }
        case alt::CEvent::Type::RMLUI_EVENT: {
            auto rmlUiEvent = (alt::CRmlEvent *) ev;
            auto args = rmlUiEvent->GetArgs();
            auto name = rmlUiEvent->GetName();
            auto size = args->GetSize();
            
            OnRmlEventDelegate(rmlUiEvent->GetElement().Get(), name.c_str(), rmlUiEvent->GetArgs().Get(), size);
            break;
        }
        case alt::CEvent::Type::WEB_SOCKET_CLIENT_EVENT: {
            auto webSocketClientEvent = (alt::CWebSocketClientEvent *) ev;
            auto args = webSocketClientEvent->GetArgs();
            auto name = webSocketClientEvent->GetName();
            auto size = args.GetSize();
            auto constArgs = new alt::MValueConst *[size];

            for (auto i = 0; i < size; i++) {
                constArgs[i] = &args[i];
            }
            OnWebSocketEventDelegate(webSocketClientEvent->GetTarget().Get(), name.c_str(), constArgs, size);
            break;
        }
#pragma region Player Events
        case alt::CEvent::Type::SPAWNED: {
            OnPlayerSpawnDelegate();
            break;
        }
        case alt::CEvent::Type::DISCONNECT_EVENT: {
            OnPlayerDisconnectDelegate();
            break;
        }
        case alt::CEvent::Type::PLAYER_ENTER_VEHICLE: {
            auto playerEnterVehicleEvent = (alt::CPlayerEnterVehicleEvent *) ev;
            OnPlayerEnterVehicleDelegate(playerEnterVehicleEvent->GetTarget().Get(),
                                         playerEnterVehicleEvent->GetSeat());
            break;
        }
        case alt::CEvent::Type::PLAYER_LEAVE_VEHICLE: {
            auto playerLeaveVehicleEvent = (alt::CPlayerLeaveVehicleEvent *) ev;
            OnPlayerLeaveVehicleDelegate(playerLeaveVehicleEvent->GetTarget().Get(),
                                         playerLeaveVehicleEvent->GetSeat());
            break;
        }
        case alt::CEvent::Type::PLAYER_CHANGE_VEHICLE_SEAT: {
            auto playerChangeVehicleSeatEvent = (alt::CPlayerChangeVehicleSeatEvent *) ev;
            OnPlayerChangeVehicleSeatDelegate(playerChangeVehicleSeatEvent->GetTarget().Get(),
                                         playerChangeVehicleSeatEvent->GetOldSeat(),
                                         playerChangeVehicleSeatEvent->GetNewSeat());
            break;
        }
        case alt::CEvent::Type::PLAYER_CHANGE_ANIMATION_EVENT: {
            auto playerAnimationChangeEvent = (alt::CPlayerChangeAnimationEvent *) ev;
            auto oldDict = playerAnimationChangeEvent->GetOldAnimationDict();
            auto oldName = playerAnimationChangeEvent->GetOldAnimationName();
            auto newDict = playerAnimationChangeEvent->GetNewAnimationDict();
            auto newName = playerAnimationChangeEvent->GetNewAnimationName();
            OnPlayerChangeAnimationDelegate(playerAnimationChangeEvent->GetTarget().Get(), oldDict, newDict, oldName, newName);
            break;
        }
        case alt::CEvent::Type::PLAYER_CHANGE_INTERIOR_EVENT: {
            auto playerChangeInteriorEvent = (alt::CPlayerChangeInteriorEvent *) ev;
            auto oldInteriorLocation = playerChangeInteriorEvent->GetOldInteriorLocation();
            auto newInteriorLocation = playerChangeInteriorEvent->GetNewInteriorLocation();
            OnPlayerChangeInteriorDelegate(playerChangeInteriorEvent->GetTarget().Get(), oldInteriorLocation, newInteriorLocation);
            break;
        }
#pragma endregion
#pragma region Entity events
        case alt::CEvent::Type::GAME_ENTITY_CREATE: {
            auto gameEntityCreateEvent = (alt::CGameEntityCreateEvent *) ev;
            auto entity = gameEntityCreateEvent->GetTarget().Get();
            auto type = (uint8_t) entity->GetType();
            void *ptr;

            switch (entity->GetType()) {
                case alt::IBaseObject::Type::PLAYER:
                    ptr = dynamic_cast<alt::IPlayer *>(entity);
                    break;
                case alt::IBaseObject::Type::VEHICLE:
                    ptr = dynamic_cast<alt::IVehicle *>(entity);
                    break;
                case alt::IBaseObject::Type::OBJECT:
                    ptr = dynamic_cast<alt::IObject *>(entity);
                    break;
                default:
                    ptr = nullptr;
            }

            OnGameEntityCreateDelegate(ptr, type);
            break;
        }
        case alt::CEvent::Type::GAME_ENTITY_DESTROY: {
            auto gameEntityDestroyEvent = (alt::CGameEntityDestroyEvent *) ev;
            auto entity = gameEntityDestroyEvent->GetTarget().Get();
            auto type = (uint8_t) entity->GetType();
            void *ptr;

            switch (entity->GetType()) {
                case alt::IBaseObject::Type::PLAYER:
                    ptr = dynamic_cast<alt::IPlayer *>(entity);
                    break;
                case alt::IBaseObject::Type::VEHICLE:
                    ptr = dynamic_cast<alt::IVehicle *>(entity);
                    break;
                case alt::IBaseObject::Type::OBJECT:
                    ptr = dynamic_cast<alt::IObject *>(entity);
                    break;
                default:
                    ptr = nullptr;
            }

            OnGameEntityDestroyDelegate(ptr, type);
            break;
        }
        case alt::CEvent::Type::REMOVE_ENTITY_EVENT: {
            auto removeEntityEvent = (alt::CRemoveEntityEvent *) ev;
            OnRemoveEntityDelegate(GetEntityPointer(removeEntityEvent->GetEntity().Get()),
                                   removeEntityEvent->GetEntity().Get()->GetType());
            break;
        }
#pragma endregion
#pragma region Misc
        case alt::CEvent::Type::RESOURCE_ERROR: {
            auto resourceErrorEvent = (alt::CResourceErrorEvent *) ev;
            OnAnyResourceErrorDelegate(resourceErrorEvent->GetResource()->GetName().c_str());
            break;
        }
        case alt::CEvent::Type::RESOURCE_START: {
            auto resourceStartEvent = (alt::CResourceStartEvent *) ev;
            OnAnyResourceStartDelegate(resourceStartEvent->GetResource()->GetName().c_str());
            break;
        }
        case alt::CEvent::Type::RESOURCE_STOP: {
            auto resourceStopEvent = (alt::CResourceStopEvent *) ev;
            OnAnyResourceStopDelegate(resourceStopEvent->GetResource()->GetName().c_str());
            break;
        }
        case alt::CEvent::Type::KEYBOARD_EVENT: {
            auto keyboardEvent = (alt::CKeyboardEvent *) ev;
            if (keyboardEvent->GetKeyState() == alt::CKeyboardEvent::KeyState::UP)
                OnKeyUpDelegate(keyboardEvent->GetKeyCode());
            else
                OnKeyDownDelegate(keyboardEvent->GetKeyCode());
            break;
        }
        case alt::CEvent::Type::CONNECTION_COMPLETE: {
            OnConnectionCompleteDelegate();
            break;
        }
        case alt::CEvent::Type::GLOBAL_META_CHANGE: {
            auto globalMetaChangeEvent = (alt::CGlobalMetaDataChangeEvent *) ev;
            auto constValue = alt::MValueConst(globalMetaChangeEvent->GetVal());
            auto constOldValue = alt::MValueConst(globalMetaChangeEvent->GetOldVal());
            OnGlobalMetaChangeDelegate(globalMetaChangeEvent->GetKey().c_str(),
                                       &constValue,
                                       &constOldValue);
            break;
        }
        case alt::CEvent::Type::GLOBAL_SYNCED_META_CHANGE: {
            auto globalSyncedMetaChangeEvent = (alt::CGlobalSyncedMetaDataChangeEvent *) ev;
            auto constValue = alt::MValueConst(globalSyncedMetaChangeEvent->GetVal());
            auto constOldValue = alt::MValueConst(globalSyncedMetaChangeEvent->GetOldVal());
            OnGlobalSyncedMetaChangeDelegate(globalSyncedMetaChangeEvent->GetKey().c_str(),
                                             &constValue,
                                             &constOldValue);
            break;
        }
        case alt::CEvent::Type::LOCAL_SYNCED_META_CHANGE: {
            auto metaChangeEvent = (alt::CLocalMetaDataChangeEvent *) ev;
            auto constValue = alt::MValueConst(metaChangeEvent->GetVal());
            auto constOldValue = alt::MValueConst(metaChangeEvent->GetOldVal());
            OnLocalMetaChangeDelegate(metaChangeEvent->GetKey().c_str(),
                                 &constValue,
                                 &constOldValue);
            break;
        }
        case alt::CEvent::Type::NETOWNER_CHANGE: {
            auto netOwnerChangeEvent = (alt::CNetOwnerChangeEvent *) ev;
            OnNetOwnerChangeDelegate(GetEntityPointer(netOwnerChangeEvent->GetTarget().Get()),
                                     netOwnerChangeEvent->GetTarget().Get()->GetType(),
                                     netOwnerChangeEvent->GetNewOwner().Get(),
                                     netOwnerChangeEvent->GetOldOwner().Get());
            break;
        }
        case alt::CEvent::Type::STREAM_SYNCED_META_CHANGE: {
            auto streamSyncedMetaChangeEvent = (alt::CStreamSyncedMetaDataChangeEvent *) ev;
            auto constValue = alt::MValueConst(streamSyncedMetaChangeEvent->GetVal());
            auto constOldValue = alt::MValueConst(streamSyncedMetaChangeEvent->GetOldVal());
            OnStreamSyncedMetaChangeDelegate(GetEntityPointer(streamSyncedMetaChangeEvent->GetTarget().Get()),
                                             streamSyncedMetaChangeEvent->GetTarget()->GetType(),
                                             streamSyncedMetaChangeEvent->GetKey().c_str(),
                                             &constValue,
                                             &constOldValue);
            break;
        }
        case alt::CEvent::Type::SYNCED_META_CHANGE: {
            auto syncedMetaChangeEvent = (alt::CSyncedMetaDataChangeEvent *) ev;
            auto constValue = alt::MValueConst(syncedMetaChangeEvent->GetVal());
            auto constOldValue = alt::MValueConst(syncedMetaChangeEvent->GetOldVal());
            OnSyncedMetaChangeDelegate(GetEntityPointer(syncedMetaChangeEvent->GetTarget().Get()),
                                       syncedMetaChangeEvent->GetTarget()->GetType(),
                                       syncedMetaChangeEvent->GetKey().c_str(),
                                       &constValue,
                                       &constOldValue);
            break;
        }
        case alt::CEvent::Type::TASK_CHANGE: {
            auto taskChangeEvent = (alt::CTaskChangeEvent *) ev;
            OnTaskChangeDelegate(taskChangeEvent->GetOldTask(),
                                 taskChangeEvent->GetNewTask());
            break;
        }
        case alt::CEvent::Type::WINDOW_FOCUS_CHANGE: {
            auto windowFocusChangeEvent = (alt::CWindowFocusChangeEvent *) ev;
            OnWindowFocusChangeDelegate(windowFocusChangeEvent->GetState());
            break;
        }
        case alt::CEvent::Type::WINDOW_RESOLUTION_CHANGE: {
            auto windowResolutionChangeEvent = (alt::CWindowResolutionChangeEvent *) ev;
            auto oldRes = windowResolutionChangeEvent->GetOldResolution();
            auto newRes = windowResolutionChangeEvent->GetNewResolution();
            OnWindowResolutionChangeDelegate({ static_cast<float>(oldRes[0]), static_cast<float>(oldRes[1]) },
                                             { static_cast<float>(newRes[0]), static_cast<float>(newRes[1]) });
            break;
        }
#pragma endregion
    }
    return true;
}

void CSharpResourceImpl::OnTick()
{
    auto scope = resource->PushNativesScope();
    OnTickDelegate();
}

void CSharpResourceImpl::OnCreateBaseObject(alt::Ref<alt::IBaseObject> objectRef)
{
    auto object = objectRef.Get();
    if (object == nullptr) return;
    object->AddRef();

    switch (object->GetType()) {
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
        case alt::IBaseObject::Type::BLIP: {
            OnCreateBlipDelegate(dynamic_cast<alt::IBlip*>(object));
            break;
        }
        case alt::IBaseObject::Type::WEBVIEW: {
            OnCreateWebViewDelegate(dynamic_cast<alt::IWebView*>(object));
            break;
        }
        case alt::IBaseObject::Type::CHECKPOINT: {
            OnCreateCheckpointDelegate(dynamic_cast<alt::ICheckpoint*>(object));
            break;
        }
        case alt::IBaseObject::Type::WEBSOCKET_CLIENT: {
            OnCreateWebSocketClientDelegate(dynamic_cast<alt::IWebSocketClient*>(object));
            break;
        }
        case alt::IBaseObject::Type::HTTP_CLIENT: {
            OnCreateHttpClientDelegate(dynamic_cast<alt::IHttpClient*>(object));
            break;
        }
        case alt::IBaseObject::Type::AUDIO: {
            OnCreateAudioDelegate(dynamic_cast<alt::IAudio*>(object));
            break;
        }
        case alt::IBaseObject::Type::RML_ELEMENT: {
            OnCreateRmlElementDelegate(dynamic_cast<alt::IRmlElement*>(object));
            break;
        }
        case alt::IBaseObject::Type::RML_DOCUMENT: {
            OnCreateRmlDocumentDelegate(dynamic_cast<alt::IRmlDocument*>(object));
            break;
        }
        case alt::IBaseObject::Type::OBJECT: {
            auto altObject = dynamic_cast<alt::IObject*>(object);
            OnCreateObjectDelegate(altObject, altObject->GetID());
            break;
        }
    }
}

void CSharpResourceImpl::OnRemoveBaseObject(alt::Ref<alt::IBaseObject> objectRef)
{
    auto object = objectRef.Get();
    if (object == nullptr) return;
    object->RemoveRef();

    switch (object->GetType()) {
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
        case alt::IBaseObject::Type::BLIP: {
            OnRemoveBlipDelegate(dynamic_cast<alt::IBlip*>(object));
            break;
        }
        case alt::IBaseObject::Type::WEBVIEW: {
            OnRemoveWebViewDelegate(dynamic_cast<alt::IWebView*>(object));
            break;
        }
        case alt::IBaseObject::Type::CHECKPOINT: {
            OnRemoveCheckpointDelegate(dynamic_cast<alt::ICheckpoint*>(object));
            break;
        }
        case alt::IBaseObject::Type::WEBSOCKET_CLIENT: {
            OnRemoveWebSocketClientDelegate(dynamic_cast<alt::IWebSocketClient*>(object));
            break;
        }
        case alt::IBaseObject::Type::HTTP_CLIENT: {
            OnRemoveHttpClientDelegate(dynamic_cast<alt::IHttpClient*>(object));
            break;
        }
        case alt::IBaseObject::Type::AUDIO: {
            OnRemoveAudioDelegate(dynamic_cast<alt::IAudio*>(object));
            break;
        }
        case alt::IBaseObject::Type::RML_ELEMENT: {
            OnRemoveRmlElementDelegate(dynamic_cast<alt::IRmlElement*>(object));
            break;
        }
        case alt::IBaseObject::Type::RML_DOCUMENT: {
            OnRemoveRmlDocumentDelegate(dynamic_cast<alt::IRmlDocument*>(object));
            break;
        }
        case alt::IBaseObject::Type::OBJECT: {
            OnRemoveObjectDelegate(dynamic_cast<alt::IObject*>(object));
            break;
        }
    }
}

std::string CSharpResourceImpl::ReadFile(std::string path)
{
    auto pkg = resource->GetPackage();
    if(!pkg->FileExists(path)) return {};
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
    
    OnCreateBlipDelegate = [](auto var) {};
    OnCreateWebViewDelegate = [](auto var) {};
    OnCreateCheckpointDelegate = [](auto var) {};
    OnCreateWebSocketClientDelegate = [](auto var) {};
    OnCreateHttpClientDelegate = [](auto var) {};
    OnCreateAudioDelegate = [](auto var) {};
    OnCreateRmlElementDelegate = [](auto var) {};
    OnCreateRmlDocumentDelegate = [](auto var) {};
    
    OnRemoveBlipDelegate = [](auto var) {};
    OnRemoveWebViewDelegate = [](auto var) {};
    OnRemoveCheckpointDelegate = [](auto var) {};
    OnRemoveWebSocketClientDelegate = [](auto var) {};
    OnRemoveHttpClientDelegate = [](auto var) {};
    OnRemoveAudioDelegate = [](auto var) {};
    OnRemoveRmlElementDelegate = [](auto var) {};
    OnRemoveRmlDocumentDelegate = [](auto var) {};
}