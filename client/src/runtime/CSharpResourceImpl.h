#pragma once
#include <objidlbase.h>
#include "cpp-sdk/SDK.h"
#include "./CSharpScriptRuntime.h"
#include "eventDelegates.h"
#include "../../../c-api/data/invoker.h"

class CSharpResourceImpl : public alt::IResource::Impl
{
    CSharpScriptRuntime* runtime;
    alt::IResource* resource;
    alt::ICore* core;

    void ResetDelegates();

public:
    CSharpResourceImpl(CSharpScriptRuntime* runtime, alt::IResource* resource, alt::ICore* core) : runtime(runtime), resource(resource), core(core) {
        invokers = {};
        ResetDelegates();
    };

    ~CSharpResourceImpl() = default;

    bool Start() override;
    bool Stop() override;

    void OnEvent(const alt::CEvent* event) override;
    void OnTick() override;

    void OnCreateBaseObject(alt::IBaseObject* object) override;
    void OnRemoveBaseObject(alt::IBaseObject* object) override;

    std::vector<CustomInvoker*> invokers;
    std::mutex invokersLock = {};

    TickDelegate_t OnTickDelegate = nullptr;
    ServerEventDelegate_t OnServerEventDelegate = nullptr;
    ClientEventDelegate_t OnClientEventDelegate = nullptr;
    WebViewEventDelegate_t OnWebViewEventDelegate = nullptr;
    ConsoleCommandDelegate_t OnConsoleCommandDelegate = nullptr;
    WebSocketEventDelegate_t OnWebSocketEventDelegate = nullptr;
    AudioEventDelegate_t OnAudioEventDelegate = nullptr;
    RmlEventDelegate_t OnRmlEventDelegate = nullptr;

    PlayerSpawnDelegate_t OnPlayerSpawnDelegate = nullptr;
    PlayerDisconnectDelegate_t OnPlayerDisconnectDelegate = nullptr;
    PlayerEnterVehicleDelegate_t OnPlayerEnterVehicleDelegate = nullptr;
    PlayerLeaveVehicleDelegate_t OnPlayerLeaveVehicleDelegate = nullptr;

    GameEntityCreateDelegate_t OnGameEntityCreateDelegate = nullptr;
    GameEntityDestroyDelegate_t OnGameEntityDestroyDelegate = nullptr;

    AnyResourceErrorDelegate_t OnAnyResourceErrorDelegate = nullptr;
    AnyResourceStartDelegate_t OnAnyResourceStartDelegate = nullptr;
    AnyResourceStopDelegate_t OnAnyResourceStopDelegate = nullptr;

    KeyUpDelegate_t OnKeyUpDelegate = nullptr;
    KeyDownDelegate_t OnKeyDownDelegate = nullptr;

    PlayerChangeVehicleSeatDelegate_t OnPlayerChangeVehicleSeatDelegate = nullptr;
    PlayerChangeAnimationDelegate_t OnPlayerChangeAnimationDelegate = nullptr;
    PlayerChangeInteriorDelegate_t OnPlayerChangeInteriorDelegate = nullptr;

    ConnectionCompleteDelegate_t OnConnectionCompleteDelegate = nullptr;

    GlobalMetaChangeDelegate_t OnGlobalMetaChangeDelegate = nullptr;
    GlobalSyncedMetaChangeDelegate_t OnGlobalSyncedMetaChangeDelegate = nullptr;
    LocalMetaChangeDelegate_t OnLocalMetaChangeDelegate = nullptr;
    StreamSyncedMetaChangeDelegate_t OnStreamSyncedMetaChangeDelegate = nullptr;
    SyncedMetaChangeDelegate_t OnSyncedMetaChangeDelegate = nullptr;
    MetaChangeDelegate_t OnMetaChangeDelegate = nullptr;

    NetOwnerChangeDelegate_t OnNetOwnerChangeDelegate = nullptr;

    TaskChangeDelegate_t OnTaskChangeDelegate = nullptr;

    WindowFocusChangeDelegate_t OnWindowFocusChangeDelegate = nullptr;
    WindowResolutionChangeDelegate_t OnWindowResolutionChangeDelegate = nullptr;

    WorldObjectPositionChangeDelegate_t OnWorldObjectPositionChangeDelegate = nullptr;
    WorldObjectStreamInDelegate_t OnWorldObjectStreamInDelegate = nullptr;
    WorldObjectStreamOutDelegate_t OnWorldObjectStreamOutDelegate = nullptr;

    PlayerWeaponShootDelegate_t OnPlayerWeaponShootDelegate = nullptr;

    PlayerWeaponChangeDelegate_t OnPlayerWeaponChangeDelegate = nullptr;

    WeaponDamageDelegate_t OnWeaponDamageDelegate = nullptr;

    CreateBaseObjectDelegate_t OnCreateBaseObjectDelegate = nullptr;
    RemoveBaseObjectDelegate_t OnRemoveBaseObjectDelegate = nullptr;

    ColShapeDelegate_t OnColShapeDelegate = nullptr;
    CheckpointDelegate_t OnCheckpointDelegate = nullptr;

    EntityHitEntityDelegate_t OnEntityHitEntityDelegate = nullptr;

    PlayerStartEnterVehicleDelegate_t OnPlayerStartEnterVehicleDelegate = nullptr;
    PlayerStartLeaveVehicleDelegate_t OnPlayerStartLeaveVehicleDelegate = nullptr;

    PlayerBulletHitDelegate_t OnPlayerBulletHitDelegate = nullptr;

    VoiceConnectionDelegate_t OnVoiceConnectionDelegate = nullptr;


    bool MakeClient(alt::IResource::CreationInfo* info, std::vector<std::string> files)
    {
        // When also having a client module that is inteded to be used with this module,
        // change uncomment the next line and change to your own module type
        // info->type = "bp";
        return true;
    }

    // Gets the alt:V IResource instance
    alt::IResource* GetIResource()
    {
        return resource;
    }
    // Gets the module runtime that instantiated this resource
    CSharpScriptRuntime* GetRuntime()
    {
        return runtime;
    }

    // Yoinked from v8 helpers
    int64_t GetTime()
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
    }

    // Reads a file using the alt:V API, so it works both on server- and clientside
    std::string ReadFile(std::string path);
};