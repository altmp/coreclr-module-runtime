#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "data/config_node_data.h"
#include "data/types.h"
#include "data/vehicle_model_info.h"
#include "data/ped_model_info.h"
#include "data/weapon_model_info.h"
#include "utils/export.h"

#ifdef ALT_SERVER_API
#include <CSharpResourceImpl.h>
#elif ALT_CLIENT_API
#include "../client/src/runtime/CSharpResourceImpl.h"
#include "mvalue.h"
#include "data/discord_user.h"

#endif


#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_SHARED void Core_LogInfo(alt::ICore* core, const char* str);
EXPORT_SHARED void Core_LogDebug(alt::ICore* core, const char* str);
EXPORT_SHARED void Core_LogWarning(alt::ICore* core, const char* str);
EXPORT_SHARED void Core_LogError(alt::ICore* core, const char* str);
EXPORT_SHARED void Core_LogColored(alt::ICore* core, const char* str);

EXPORT_SHARED alt::MValueConst* Core_CreateMValueNil(alt::ICore* core);
EXPORT_SHARED alt::MValueConst* Core_CreateMValueBool(alt::ICore* core, uint8_t value);
EXPORT_SHARED alt::MValueConst* Core_CreateMValueInt(alt::ICore* core, int64_t value);
EXPORT_SHARED alt::MValueConst* Core_CreateMValueUInt(alt::ICore* core, uint64_t value);
EXPORT_SHARED alt::MValueConst* Core_CreateMValueDouble(alt::ICore* core, double value);
EXPORT_SHARED alt::MValueConst* Core_CreateMValueString(alt::ICore* core, const char* value);
EXPORT_SHARED alt::MValueConst* Core_CreateMValueList(alt::ICore* core, alt::MValueConst* val[], uint64_t size);
EXPORT_SHARED alt::MValueConst* Core_CreateMValueDict(alt::ICore* core, const char* keys[], alt::MValueConst* val[], uint64_t size);
EXPORT_SHARED alt::MValueConst* Core_CreateMValueBaseObject(alt::ICore* core, alt::IBaseObject* value);
EXPORT_SHARED alt::MValueConst* Core_CreateMValueVector3(alt::ICore* core, position_t value);
EXPORT_SHARED alt::MValueConst* Core_CreateMValueVector2(alt::ICore* core, vector2_t value);
EXPORT_SHARED alt::MValueConst* Core_CreateMValueRgba(alt::ICore* core, rgba_t value);
EXPORT_SHARED alt::MValueConst* Core_CreateMValueByteArray(alt::ICore* core, uint64_t size, const void* data);
EXPORT_SHARED alt::MValueConst* Core_CreateMValueFunction(alt::ICore* core, CustomInvoker* value);
EXPORT_SHARED uint64_t Core_GetMValueSize(alt::ICore* core, alt::MValueConst* args);
EXPORT_SHARED uint64_t Core_GetMValueArgsSize(alt::ICore* core, alt::MValueConst* args[], int size);


EXPORT_SHARED alt::IPlayer** Core_GetPlayers(alt::ICore* core, uint64_t& size);
EXPORT_SHARED alt::IVehicle** Core_GetVehicles(alt::ICore* core, uint64_t& size);
EXPORT_SHARED alt::IPed** Core_GetPeds(alt::ICore* core, uint64_t& size);
EXPORT_SHARED alt::IBlip** Core_GetBlips(alt::ICore* core, uint64_t& size);
EXPORT_SHARED void* Core_GetBaseObjectByID(alt::ICore* core, uint8_t type, uint32_t id);
EXPORT_SHARED alt::IResource* Core_GetResource(alt::ICore* core, const char* resourceName);
EXPORT_SHARED alt::IResource** Core_GetAllResources(alt::ICore* core, uint32_t& size);

EXPORT_SHARED uint8_t Core_IsDebug(alt::ICore* core);
EXPORT_SHARED const char* Core_GetVersion(alt::ICore* core,int32_t &size);
EXPORT_SHARED const char* Core_GetBranch(alt::ICore* core, int32_t &size);

EXPORT_SHARED void Core_DestroyBaseObject(alt::ICore* core, alt::IBaseObject* baseObject);
EXPORT_SHARED alt::MValueConst* Core_GetMetaData(alt::ICore* core, const char* key);
EXPORT_SHARED void Core_SetMetaData(alt::ICore* core, const char* key, alt::MValueConst* val);
EXPORT_SHARED uint8_t Core_HasMetaData(alt::ICore* core, const char* key);
EXPORT_SHARED void Core_DeleteMetaData(alt::ICore* core, const char* key);
EXPORT_SHARED alt::MValueConst* Core_GetSyncedMetaData(alt::ICore* core, const char* key);
EXPORT_SHARED uint8_t Core_HasSyncedMetaData(alt::ICore* core, const char* key);
EXPORT_SHARED void Core_TriggerLocalEvent(alt::ICore* core, const char* event, alt::MValueConst* args[], int size);
EXPORT_SHARED uint8_t Core_FileExists(alt::ICore* core, const char* path);
EXPORT_SHARED const char* Core_FileRead(alt::ICore* core, const char* path, int32_t& size);
EXPORT_SHARED alt::ICore* Core_GetCoreInstance();
EXPORT_SHARED void Core_ToggleEvent(alt::ICore* core, uint8_t event, uint8_t state);
EXPORT_SHARED uint8_t Core_GetEventTypeSize();
EXPORT_SHARED uint8_t Core_GetBaseObjectTypeSize();
EXPORT_SHARED uint8_t Core_GetVoiceConnectionState(alt::ICore* core);

EXPORT_SERVER uint8_t Core_SubscribeCommand(alt::ICore* core, const char* cmd, alt::CommandCallback cb);
EXPORT_SERVER void Core_TriggerServerEvent(alt::ICore* core, const char* ev, alt::MValueConst* args[], int size);

EXPORT_SERVER void Core_TriggerClientEvent(alt::ICore* core, alt::IPlayer* target, const char* ev, alt::MValueConst* args[], int size);
EXPORT_SERVER void Core_TriggerClientEventForSome(alt::ICore* core, alt::IPlayer* targets[], int targetsSize, const char* ev, alt::MValueConst* args[], int argsSize);
EXPORT_SERVER void Core_TriggerClientEventForAll(alt::ICore* core, const char* ev, alt::MValueConst* args[], int size);

EXPORT_SERVER void Core_TriggerClientEventUnreliable(alt::ICore* core, alt::IPlayer* target, const char* ev, alt::MValueConst* args[], int size);
EXPORT_SERVER void Core_TriggerClientEventUnreliableForSome(alt::ICore* core, alt::IPlayer* targets[], int targetsSize, const char* ev, alt::MValueConst* args[], int argsSize);
EXPORT_SERVER void Core_TriggerClientEventUnreliableForAll(alt::ICore* core, const char* ev, alt::MValueConst* args[], int size);

EXPORT_SERVER alt::IVehicle* Core_CreateVehicle(alt::ICore* core, uint32_t model, position_t pos, rotation_t rot, uint32_t streamingDistance, uint32_t &id);
EXPORT_SERVER alt::IPed* Core_CreatePed(alt::ICore* core, uint32_t model, position_t pos, rotation_t rot, uint32_t streamingDistance, uint32_t &id);
#ifdef ALT_SERVER_API
EXPORT_SERVER alt::ICheckpoint* Core_CreateCheckpoint(alt::ICore* core, uint8_t type, position_t pos, float radius, float height, rgba_t color, uint32_t streamingDistance, uint32_t &id);
#endif
EXPORT_SERVER alt::IBlip* Core_CreateBlip(alt::ICore* core, uint8_t global, uint8_t type, position_t pos, alt::IPlayer* targets[], int targetsSize, uint32_t &id);
EXPORT_SERVER alt::IBlip* Core_CreateBlipAttached(alt::ICore* core, uint8_t global, uint8_t type, alt::IEntity* attachTo, alt::IPlayer* targets[], int targetsSize, uint32_t &id);

EXPORT_SERVER ClrVehicleModelInfo* Core_GetVehicleModelInfo(alt::ICore* core, uint32_t hash);
EXPORT_SERVER void Core_GetLoadedVehicleModels(alt::ICore* core, uint32_t*& loadedVehicleModelsOut, uint64_t& size);
EXPORT_SERVER ClrPedModelInfo* Core_GetPedModelInfo(alt::ICore* core, uint32_t hash);
EXPORT_SERVER ClrWeaponModelInfo* Core_GetWeaponModelByHash(alt::ICore* core, uint32_t hash);
EXPORT_SERVER void Core_DeallocVehicleModelInfo(ClrVehicleModelInfo* modelInfo);
EXPORT_SERVER void Core_DeallocPedModelInfo(ClrPedModelInfo* modelInfo);
EXPORT_SERVER void Core_DeallocWeaponModelInfo(ClrWeaponModelInfo* modelInfo);


EXPORT_SERVER alt::IVoiceChannel* Core_CreateVoiceChannel(alt::ICore* core, uint8_t spatial, float maxDistance, uint32_t &id);
EXPORT_SHARED alt::IColShape* Core_CreateColShapeCylinder(alt::ICore* core, position_t pos, float radius, float height, uint32_t &id);
EXPORT_SHARED alt::IColShape* Core_CreateColShapeSphere(alt::ICore* core, position_t pos, float radius, uint32_t &id);
EXPORT_SHARED alt::IColShape* Core_CreateColShapeCircle(alt::ICore* core, position_t pos, float radius, uint32_t &id);
EXPORT_SHARED alt::IColShape* Core_CreateColShapeCube(alt::ICore* core, position_t pos, position_t pos2, uint32_t &id);
EXPORT_SHARED alt::IColShape* Core_CreateColShapeRectangle(alt::ICore* core, float x1, float y1, float x2, float y2, float z, uint32_t &id);
EXPORT_SHARED alt::IColShape* Core_CreateColShapePolygon(alt::ICore* core, float minZ, float maxZ, vector2_t points[], int pointSize, uint32_t &id);
EXPORT_SERVER void Core_DestroyVehicle(alt::ICore* core, alt::IVehicle* baseObject);
EXPORT_SERVER void Core_DestroyCheckpoint(alt::ICore* core, alt::ICheckpoint* baseObject);
EXPORT_SERVER void Core_DestroyVoiceChannel(alt::ICore* core, alt::IVoiceChannel* baseObject);
EXPORT_SERVER void Core_DestroyColShape(alt::ICore* core, alt::IColShape* baseObject);
EXPORT_SHARED int32_t Core_GetNetTime(alt::ICore* core);
EXPORT_SERVER const char* Core_GetRootDirectory(alt::ICore* core, int32_t& size);
EXPORT_SERVER void Core_StartResource(alt::ICore* core, const char* text);
EXPORT_SERVER void Core_StopResource(alt::ICore* core, const char* text);
EXPORT_SERVER void Core_RestartResource(alt::ICore* core, const char* text);
EXPORT_SERVER void Core_SetSyncedMetaData(alt::ICore* core, const char* key, alt::MValueConst* val);
EXPORT_SERVER void Core_DeleteSyncedMetaData(alt::ICore* core, const char* key);
EXPORT_SERVER uint64_t Core_HashPassword(alt::ICore* core, const char* password);
EXPORT_SERVER void Core_SetPassword(alt::ICore* core, const char* value);
EXPORT_SERVER void Core_StopServer(alt::ICore* core);
EXPORT_SERVER ClrConfigNodeData* Core_GetServerConfig(alt::ICore* core);

EXPORT_SERVER void Core_SetWorldProfiler(alt::ICore* core, uint8_t state);

EXPORT_SERVER uint64_t Core_GetEntitiesInDimensionCount(alt::ICore* core, int32_t dimension, uint64_t allowedTypes);
EXPORT_SERVER uint64_t Core_GetEntitiesInRangeCount(alt::ICore* core, vector3_t position, int32_t range, int32_t dimension, uint64_t allowedTypes);
EXPORT_SERVER uint64_t Core_GetClosestEntitiesCount(alt::ICore* core, vector3_t position, int32_t range, int32_t dimension, int32_t limit, uint64_t allowedTypes);
EXPORT_SERVER void Core_GetEntitiesInDimension(alt::ICore* core, int32_t dimension, uint64_t allowedTypes, void**& entities, uint8_t types[], uint64_t size);
EXPORT_SERVER void Core_GetEntitiesInRange(alt::ICore* core, vector3_t position, int32_t range, int32_t dimension, uint64_t allowedTypes, void**& entities, uint8_t types[], uint64_t size);
EXPORT_SERVER void Core_GetClosestEntities(alt::ICore* core, vector3_t position, int32_t range, int32_t dimension, int32_t limit, uint64_t allowedTypes, void**& entities, uint8_t types[], uint64_t size);

#ifdef ALT_CLIENT_API
EXPORT_CLIENT uint8_t Core_Client_FileExists(alt::ICore* core, alt::IResource* resource, const char* path);
EXPORT_CLIENT const char* Core_Client_FileRead(alt::ICore* core, alt::IResource* resource, const char* path, int32_t& size);

EXPORT_CLIENT alt::ICheckpoint* Core_CreateCheckpoint(alt::ICore* core, uint8_t type, vector3_t pos, vector3_t nextPos, float radius, float height, rgba_t color, rgba_t iconColor, uint32_t streamingDistance, alt::IResource* resource, uint32_t &id);
#endif
EXPORT_CLIENT alt::IBlip* Core_Client_CreatePointBlip(alt::ICore* core, vector3_t position, alt::IResource* resource, uint32_t &id);
EXPORT_CLIENT alt::IBlip* Core_Client_CreateRadiusBlip(alt::ICore* core, vector3_t position, float radius, alt::IResource* resource, uint32_t &id);
EXPORT_CLIENT alt::IBlip* Core_Client_CreateAreaBlip(alt::ICore* core, vector3_t position, float width, float height, alt::IResource* resource, uint32_t &id);
EXPORT_CLIENT alt::IWebView* Core_CreateWebView(alt::ICore* core, alt::IResource* resource, const char* url, vector2_t pos, vector2_t size, uint8_t isOverlay, uint32_t &id);
EXPORT_CLIENT alt::IWebView* Core_CreateWebView3D(alt::ICore* core, alt::IResource* resource, const char* url, uint32_t hash, const char* targetTexture, uint32_t &id);
EXPORT_CLIENT alt::IRmlDocument* Core_CreateRmlDocument(alt::ICore* core, alt::IResource* resource, const char* url, uint32_t &id);

EXPORT_CLIENT void Core_TriggerWebViewEvent(alt::ICore* core, alt::IWebView* webview, const char* event, alt::MValueConst* args[], int size);
EXPORT_CLIENT void Core_TriggerServerEvent(alt::ICore* core, const char* event, alt::MValueConst* args[], int size);
EXPORT_CLIENT void Core_TriggerServerEventUnreliable(alt::ICore* core, const char* event, alt::MValueConst* args[], int size);

EXPORT_CLIENT void Core_ShowCursor(alt::ICore* core, alt::IResource* resource, uint8_t state);
EXPORT_CLIENT uint8_t Core_IsCursorVisible(alt::ICore* core, alt::IResource* resource);

#ifdef ALT_CLIENT_API
EXPORT_CLIENT ClrDiscordUser* Core_GetDiscordUser(alt::ICore* core);
EXPORT_CLIENT void Core_DeallocDiscordUser(ClrDiscordUser* user);
#endif

typedef void (* DiscordOAuth2TokenResultDelegate_t)(uint8_t success, const char* token);
EXPORT_CLIENT void Core_Discord_GetOAuth2Token(alt::ICore* core, const char* appId, /** ClientEvents.DiscordOAuth2TokenResultModuleDelegate */ DiscordOAuth2TokenResultDelegate_t delegate);

EXPORT_CLIENT void Core_WorldToScreen(alt::ICore* core, vector3_t in, vector2_t& out);
EXPORT_CLIENT void Core_ScreenToWorld(alt::ICore* core, vector2_t in, vector3_t& out);
EXPORT_CLIENT void Core_LoadRmlFont(alt::ICore* core, alt::IResource* resource, const char* path, const char* name, uint8_t italic, uint8_t bold);
EXPORT_CLIENT uint32_t Core_GetVoiceActivationKey(alt::ICore* core);
EXPORT_CLIENT uint8_t Core_IsVoiceActivityInputEnabled(alt::ICore* core);
EXPORT_CLIENT uint8_t Core_GetVoiceInputMuted(alt::ICore* core);
EXPORT_CLIENT void Core_SetVoiceInputMuted(alt::ICore* core, uint8_t value);

EXPORT_CLIENT uint8_t Core_ToggleVoiceInput(alt::ICore* core, uint8_t state);
EXPORT_CLIENT uint8_t Core_ToggleVoiceActivation(alt::ICore* core, uint8_t state);
EXPORT_CLIENT uint8_t Core_SetVoiceActivationLevel(alt::ICore* core, float level);
EXPORT_CLIENT float Core_GetVoiceActivationLevel(alt::ICore* core);
EXPORT_CLIENT uint8_t Core_ToggleNoiseSuppression(alt::ICore* core, uint8_t state);
EXPORT_CLIENT uint8_t Core_IsNoiseSuppressionEnabled(alt::ICore* core);

EXPORT_CLIENT uint8_t Core_BeginScaleformMovieMethodMinimap(alt::ICore* core, const char* methodName);
EXPORT_CLIENT void Core_SetMinimapComponentPosition(alt::ICore* core, const char* name, uint8_t alignX, uint8_t alignY, float posX, float posY, float sizeX, float sizeY);
EXPORT_CLIENT void Core_ResetMinimapComponentPosition(alt::ICore* core, const char* name);
EXPORT_CLIENT void Core_SetMinimapIsRectangle(alt::ICore* core, uint8_t state);



EXPORT_CLIENT uint8_t Core_CopyToClipboard(alt::ICore* core, const char* value);
EXPORT_CLIENT uint16_t Core_GetFPS(alt::ICore* core);
EXPORT_CLIENT uint16_t Core_GetPing(alt::ICore* core);
EXPORT_CLIENT uint32_t Core_GetTotalPacketsLost(alt::ICore* core);
EXPORT_CLIENT uint64_t Core_GetTotalPacketsSent(alt::ICore* core);
EXPORT_CLIENT void Core_GetScreenResolution(alt::ICore* core, vector2_t& out);
EXPORT_CLIENT const char* Core_GetLicenseHash(alt::ICore* core, int32_t& size);
EXPORT_CLIENT const char* Core_GetLocale(alt::ICore* core, int32_t& size);
EXPORT_CLIENT uint8_t Core_GetPermissionState(alt::ICore* core, uint8_t permission);
EXPORT_CLIENT const char* Core_GetServerIp(alt::ICore* core, int32_t& size);
EXPORT_CLIENT uint16_t Core_GetServerPort(alt::ICore* core);

EXPORT_CLIENT uint8_t Core_IsGameFocused(alt::ICore* core);
EXPORT_CLIENT uint8_t Core_IsInStreamerMode(alt::ICore* core);
EXPORT_CLIENT uint8_t Core_IsMenuOpened(alt::ICore* core);
EXPORT_CLIENT uint8_t Core_IsConsoleOpen(alt::ICore* core);
EXPORT_CLIENT uint8_t Core_IsTextureExistInArchetype(alt::ICore* core, uint32_t modelHash, const char* targetTextureName);

EXPORT_CLIENT void Core_LoadModel(alt::ICore* core, uint32_t modelHash);
EXPORT_CLIENT void Core_LoadModelAsync(alt::ICore* core, uint32_t modelHash);

EXPORT_CLIENT uint8_t Core_LoadYtyp(alt::ICore* core, const char* path);
EXPORT_CLIENT uint8_t Core_UnloadYtyp(alt::ICore* core, const char* path);

EXPORT_CLIENT void Core_RequestIpl(alt::ICore* core, const char* path);
EXPORT_CLIENT void Core_RemoveIpl(alt::ICore* core, const char* path);

EXPORT_CLIENT uint8_t Core_IsKeyDown(alt::ICore* core, uint32_t key);
EXPORT_CLIENT uint8_t Core_IsKeyToggled(alt::ICore* core, uint32_t key);

EXPORT_CLIENT uint8_t Core_IsCamFrozen(alt::ICore* core);
EXPORT_CLIENT void Core_SetCamFrozen(alt::ICore* core, uint8_t value);
EXPORT_CLIENT void Core_GetCamPos(alt::ICore* core, vector3_t& out);

EXPORT_CLIENT void Core_AddGXTText(alt::ICore* core, alt::IResource* resource, uint32_t key, const char* value);
EXPORT_CLIENT const char* Core_GetGXTText(alt::ICore* core, alt::IResource* resource, uint32_t key, int32_t& size);
EXPORT_CLIENT void Core_RemoveGXTText(alt::ICore* core, alt::IResource* resource, uint32_t key);

EXPORT_CLIENT uint8_t Core_DoesConfigFlagExist(alt::ICore* core, const char* flag);
EXPORT_CLIENT uint8_t Core_GetConfigFlag(alt::ICore* core, const char* flag);
EXPORT_CLIENT void Core_SetConfigFlag(alt::ICore* core, const char* flag, uint8_t state);

EXPORT_CLIENT uint8_t Core_AreGameControlsEnabled(alt::ICore* core);
EXPORT_CLIENT void Core_ToggleGameControls(alt::ICore* core, alt::IResource* resource, uint8_t state);
EXPORT_CLIENT void Core_ToggleRmlControls(alt::ICore* core, uint8_t state);
EXPORT_CLIENT uint8_t Core_AreRmlControlsEnabled(alt::ICore* core);
EXPORT_CLIENT uint8_t Core_AreVoiceControlsEnabled(alt::ICore* core);
EXPORT_CLIENT void Core_ToggleVoiceControls(alt::ICore* core, uint8_t state);

EXPORT_CLIENT void Core_GetCursorPos(alt::ICore* core, vector2_t& out, uint8_t normalized);
EXPORT_CLIENT void Core_SetCursorPos(alt::ICore* core, vector2_t pos, uint8_t normalized);

EXPORT_CLIENT int32_t Core_GetMsPerGameMinute(alt::ICore* core);
EXPORT_CLIENT void Core_SetMsPerGameMinute(alt::ICore* core, int32_t ms);

EXPORT_CLIENT alt::IStatData* Core_GetStatData(alt::ICore* core, const char* stat);
EXPORT_CLIENT void Core_ResetStat(alt::ICore* core, const char* stat);
EXPORT_CLIENT const char* Core_GetStatType(alt::ICore* core, alt::IStatData* stat, int32_t& size);
EXPORT_CLIENT int32_t Core_GetStatInt(alt::ICore* core, alt::IStatData* stat);
EXPORT_CLIENT int64_t Core_GetStatLong(alt::ICore* core, alt::IStatData* stat);
EXPORT_CLIENT float Core_GetStatFloat(alt::ICore* core, alt::IStatData* stat);
EXPORT_CLIENT uint8_t Core_GetStatBool(alt::ICore* core, alt::IStatData* stat);
EXPORT_CLIENT const char* Core_GetStatString(alt::ICore* core, alt::IStatData* stat, int32_t& size);
EXPORT_CLIENT uint8_t Core_GetStatUInt8(alt::ICore* core, alt::IStatData* stat);
EXPORT_CLIENT uint16_t Core_GetStatUInt16(alt::ICore* core, alt::IStatData* stat);
EXPORT_CLIENT uint32_t Core_GetStatUInt32(alt::ICore* core, alt::IStatData* stat);
EXPORT_CLIENT uint64_t Core_GetStatUInt64(alt::ICore* core, alt::IStatData* stat);
EXPORT_CLIENT void Core_SetStatInt(alt::ICore* core, alt::IStatData* stat, int32_t value);
EXPORT_CLIENT void Core_SetStatLong(alt::ICore* core, alt::IStatData* stat, int64_t value);
EXPORT_CLIENT void Core_SetStatFloat(alt::ICore* core, alt::IStatData* stat, float value);
EXPORT_CLIENT void Core_SetStatBool(alt::ICore* core, alt::IStatData* stat, uint8_t value);
EXPORT_CLIENT void Core_SetStatString(alt::ICore* core, alt::IStatData* stat, const char* value);
EXPORT_CLIENT void Core_SetStatUInt8(alt::ICore* core, alt::IStatData* stat, uint8_t value);
EXPORT_CLIENT void Core_SetStatUInt16(alt::ICore* core, alt::IStatData* stat, uint16_t value);
EXPORT_CLIENT void Core_SetStatUInt32(alt::ICore* core, alt::IStatData* stat, uint32_t value);
EXPORT_CLIENT void Core_SetStatUInt64(alt::ICore* core, alt::IStatData* stat, uint64_t value);

EXPORT_CLIENT void Core_ClearPedProp(alt::ICore* core, int32_t scriptID, uint8_t component);
EXPORT_CLIENT void Core_SetPedDlcProp(alt::ICore* core, int32_t scriptID, uint32_t dlc, uint8_t component, uint8_t drawable, uint8_t texture);
EXPORT_CLIENT void Core_SetPedDlcClothes(alt::ICore* core, int32_t scriptID, uint32_t dlc, uint8_t component, uint8_t drawable, uint8_t texture, uint8_t palette);

EXPORT_CLIENT void Core_SetRotationVelocity(alt::ICore* core, int32_t scriptID, vector3_t velocity);
EXPORT_CLIENT void Core_SetWatermarkPosition(alt::ICore* core, uint8_t position);
EXPORT_CLIENT const char* Core_StringToSHA256(alt::ICore* core, const char* string, int32_t& size);
EXPORT_CLIENT void Core_SetWeatherCycle(alt::ICore* core, uint8_t weathers[], int32_t weathersSize, uint8_t multipliers[], int32_t multipliersSize);
EXPORT_CLIENT void Core_SetWeatherSyncActive(alt::ICore* core, uint8_t state);
EXPORT_CLIENT const char* Core_GetHeadshotBase64(alt::ICore* core, uint8_t id, int32_t& size);

typedef void (* ScreenshotDelegate_t)(const char* string);
EXPORT_CLIENT uint8_t Core_TakeScreenshot(alt::ICore* core, /** ClientEvents.ScreenshotResultModuleDelegate */ ScreenshotDelegate_t delegate);
EXPORT_CLIENT uint8_t Core_TakeScreenshotGameOnly(alt::ICore* core, /** ClientEvents.ScreenshotResultModuleDelegate */ ScreenshotDelegate_t delegate);

EXPORT_CLIENT alt::IMapData* Core_GetMapZoomDataByAlias(alt::ICore* core, const char* alias, uint32_t& id);
EXPORT_CLIENT void Core_ResetAllMapZoomData(alt::ICore* core);
EXPORT_CLIENT void Core_ResetMapZoomData(alt::ICore* core, uint32_t id);

EXPORT_CLIENT alt::IHttpClient* Core_CreateHttpClient(alt::ICore* core, alt::IResource* resource, uint32_t &id);
EXPORT_CLIENT alt::IWebSocketClient* Core_CreateWebsocketClient(alt::ICore* core, alt::IResource* resource, const char* url, uint32_t &id);

EXPORT_CLIENT alt::IAudio* Core_CreateAudio(alt::ICore* core, const char* source, float volume, uint8_t isRadio, uint8_t clearCache, const char* basePath, alt::IResource* resource, uint32_t &id);
EXPORT_CLIENT alt::IAudioFilter* Core_CreateAudioFilter(alt::ICore* core, uint32_t hash, alt::IResource* resource, uint32_t &id);
EXPORT_CLIENT alt::IAudioFrontendOutput* Core_CreateFrontendOutput(alt::ICore* core, uint32_t categoryHash, alt::IResource* resource, uint32_t &id);
EXPORT_CLIENT alt::IAudioWorldOutput* Core_CreateWorldOutput(alt::ICore* core, uint32_t categoryHash, alt::Position pos, alt::IResource* resource, uint32_t &id);
EXPORT_CLIENT alt::IAudioAttachedOutput* Core_CreateAttachedOutput(alt::ICore* core, uint32_t categoryHash, alt::IWorldObject* entity, alt::IResource* resource, uint32_t &id);

EXPORT_CLIENT uint8_t Core_HasLocalMeta(alt::ICore* core, const char* key);
EXPORT_CLIENT alt::MValueConst* Core_GetLocalMeta(alt::ICore* core, const char* key);

EXPORT_CLIENT const char* Core_GetClientPath(alt::ICore* core, int32_t& size);

EXPORT_CLIENT uint8_t Core_IsFocusOverriden(alt::ICore* core);
EXPORT_CLIENT void Core_GetFocusOverridePos(alt::ICore* core, vector3_t& pos);
EXPORT_CLIENT void Core_GetFocusOverrideOffset(alt::ICore* core, vector3_t& offset);
EXPORT_CLIENT void* Core_GetFocusOverrideEntity(alt::ICore* core, uint8_t& type);
EXPORT_CLIENT void Core_OverrideFocusPosition(alt::ICore* core, vector3_t pos, vector3_t offset);
EXPORT_CLIENT void Core_OverrideFocusEntity(alt::ICore* core, alt::IEntity* entity);
EXPORT_CLIENT void Core_ClearFocusOverride(alt::ICore* core);
EXPORT_CLIENT void Core_LoadDefaultIpls(alt::ICore* core);

EXPORT_CLIENT uint8_t Core_IsPointOnScreen(alt::ICore* core, vector3_t pos);

EXPORT_CLIENT alt::ILocalObject* Core_CreateLocalObject(alt::ICore* core, uint32_t modelHash, vector3_t position, vector3_t rot, uint8_t noOffset, uint8_t dynamic, uint8_t useStreaming, uint32_t streamingDistance, alt::IResource* resource, uint32_t &id);
EXPORT_CLIENT alt::ILocalObject* Core_CreateWeaponObject(alt::ICore* core, alt::Position pos, alt::Rotation rot, uint32_t weaponHash, uint32_t modelHash, int32_t numAmmo, uint8_t createDefaultComponents, float scale, uint8_t useStreaming, uint32_t streamingDistance, alt::IResource* resource, uint32_t &id);
EXPORT_CLIENT alt::ILocalObject** Core_GetLocalObjects(alt::ICore* core, uint32_t& size);
EXPORT_CLIENT alt::ILocalObject** Core_GetWorldObjects(alt::ICore* core, uint32_t& size);
EXPORT_CLIENT alt::ILocalObject** Core_GetWeaponObjects(alt::ICore* core, uint32_t& size);
EXPORT_CLIENT alt::ILocalPed** Core_GetLocalPeds(alt::ICore* core, uint32_t& size);
EXPORT_CLIENT alt::ILocalVehicle** Core_GetLocalVehicles(alt::ICore* core, uint32_t& size);

EXPORT_CLIENT void Core_GetPedBonePos(alt::ICore* core, int32_t scriptId, uint16_t boneId, vector3_t& pos);

EXPORT_SHARED alt::IVirtualEntity* Core_CreateVirtualEntity(alt::ICore* core, alt::IVirtualEntityGroup* group, vector3_t position, uint32_t streamingDistance, const char* keys[], alt::MValueConst* values[], uint64_t size, uint32_t &id);
EXPORT_SHARED alt::IVirtualEntityGroup* Core_CreateVirtualEntityGroup(alt::ICore* core, uint32_t maxEntitiesInStream, uint32_t &id);

EXPORT_SHARED alt::IVirtualEntity** Core_GetVirtualEntities(alt::ICore* core, uint64_t& size);
EXPORT_SHARED alt::IVirtualEntityGroup** Core_GetVirtualEntityGroups(alt::ICore* core, uint64_t& size);
EXPORT_SHARED alt::IObject** Core_GetNetworkObjects(alt::ICore* core, uint64_t& size);
EXPORT_SHARED alt::ICheckpoint** Core_GetCheckpoints(alt::ICore* core, uint64_t& size);
EXPORT_SHARED alt::IMarker** Core_GetMarkers(alt::ICore* core, uint64_t& size);
EXPORT_SHARED alt::IColShape** Core_GetColShapes(alt::ICore* core, uint64_t& size);
EXPORT_SHARED alt::ITextLabel** Core_GetTextLabels(alt::ICore* core, uint64_t& size);
EXPORT_SERVER alt::IConnectionInfo** Core_GetConnectionInfos(alt::ICore* core, uint64_t& size);

EXPORT_CLIENT uint64_t Core_GetWebViewCount(alt::ICore* core);
EXPORT_CLIENT void Core_GetWebViews(alt::ICore* core, alt::IWebView* webViews[], uint64_t size);

EXPORT_CLIENT uint64_t Core_GetAudioCount(alt::ICore* core);
EXPORT_CLIENT alt::IAudio** Core_GetAudios(alt::ICore* core, uint64_t& size);
EXPORT_CLIENT alt::IAudioOutput** Core_GetAudioOutputs(alt::ICore* core, uint64_t& size);

EXPORT_SERVER alt::IMarker* Core_CreateMarker(alt::ICore* core, alt::IPlayer* target, uint8_t type, position_t pos, rgba_t color, alt::IResource* resource, uint32_t& id);
EXPORT_CLIENT alt::IMarker* Core_CreateMarker_Client(alt::ICore* core, uint8_t type, position_t pos, rgba_t color, uint8_t useStreaming, uint32_t streamingDistance, alt::IResource* resource, uint32_t& id);

EXPORT_CLIENT alt::ITextLabel* Core_CreateTextLabel(alt::ICore* core, const char* text, const char* fontName, float fontSize, float scale, position_t pos, rotation_t rot, rgba_t color, float outlineWith, rgba_t outlineColor, uint8_t useStreaming, uint32_t streamingDistance, alt::IResource* resource, uint32_t& id);

EXPORT_CLIENT alt::ILocalVehicle* Core_CreateLocalVehicle(alt::ICore* core, uint32_t modelHash, int32_t dimension, position_t pos, rotation_t rot, uint8_t useStreaming, uint32_t streamingDistance, alt::IResource* resource, uint32_t& id);
EXPORT_CLIENT alt::ILocalPed* Core_CreateLocalPed(alt::ICore* core, uint32_t modelHash, int32_t dimension, position_t pos, rotation_t rot, uint8_t useStreaming, uint32_t streamingDistance, alt::IResource* resource, uint32_t& id);

EXPORT_CLIENT alt::IFont* Core_RegisterFont(alt::ICore* core, alt::IResource* resource, const char* path, uint32_t& id);

EXPORT_CLIENT uint8_t Core_IsFullScreen(alt::ICore* core);

EXPORT_SERVER alt::IObject* Core_CreateObject(alt::ICore* core, uint32_t model, position_t position, rotation_t rotation, uint8_t alpha, uint8_t textureVariation, uint16_t lodDistance, uint32_t streamingDistance, uint32_t& id);

EXPORT_SERVER alt::Metric* Core_RegisterMetric(alt::ICore* core, const char* metricName, uint8_t type, const char* keys[], const char* values[], uint64_t size);
EXPORT_SERVER void Core_UnregisterMetric(alt::ICore* core, alt::Metric* metric);

EXPORT_CLIENT alt::IBlip* Core_GetBlipByGameID(alt::ICore* core, uint32_t gameId);
EXPORT_CLIENT alt::ICheckpoint* Core_GetCheckpointByGameID(alt::ICore* core, uint32_t gameId);
EXPORT_CLIENT uint8_t Core_IsWebViewGpuAccelerationActive(alt::ICore* core);

EXPORT_CLIENT alt::IWorldObject* Core_GetWorldObjectByScriptID(alt::ICore* core, uint32_t scriptId);

EXPORT_CLIENT uint64_t Core_GetAllWeaponDataCount(alt::ICore* core);
EXPORT_CLIENT void Core_GetAllWeaponData(alt::ICore* core, uint32_t weaponHashes[], uint64_t size);

EXPORT_SERVER void Core_SetVoiceExternalPublic(alt::ICore* core, const char* host, uint16_t port);
EXPORT_SERVER void Core_SetVoiceExternal(alt::ICore* core, const char* host, uint16_t port);

EXPORT_SERVER uint16_t Core_GetMaxStreamingPeds(alt::ICore* core);
EXPORT_SERVER void Core_SetMaxStreamingPeds(alt::ICore* core, uint16_t limit);
EXPORT_SERVER uint16_t Core_GetMaxStreamingObjects(alt::ICore* core);
EXPORT_SERVER void Core_SetMaxStreamingObjects(alt::ICore* core, uint16_t limit);
EXPORT_SERVER uint16_t Core_GetMaxStreamingVehicles(alt::ICore* core);
EXPORT_SERVER void Core_SetMaxStreamingVehicles(alt::ICore* core, uint16_t limit);

EXPORT_SERVER uint8_t Core_GetStreamerThreadCount(alt::ICore* core);
EXPORT_SERVER void Core_SetStreamerThreadCount(alt::ICore* core, uint8_t limit);

EXPORT_SERVER uint32_t Core_GetStreamingTickRate(alt::ICore* core);
EXPORT_SERVER void Core_SetStreamingTickRate(alt::ICore* core, uint32_t limit);

EXPORT_SERVER uint32_t Core_GetStreamingDistance(alt::ICore* core);
EXPORT_SERVER void Core_SetStreamingDistance(alt::ICore* core, uint32_t limit);

EXPORT_SERVER uint8_t Core_GetMigrationThreadCount(alt::ICore* core);
EXPORT_SERVER void Core_SetMigrationThreadCount(alt::ICore* core, uint8_t limit);

EXPORT_SERVER uint8_t Core_GetSyncSendThreadCount(alt::ICore* core);
EXPORT_SERVER void Core_SetSyncSendThreadCount(alt::ICore* core, uint8_t limit);

EXPORT_SERVER uint8_t Core_GetSyncReceiveThreadCount(alt::ICore* core);
EXPORT_SERVER void Core_SetSyncReceiveThreadCount(alt::ICore* core, uint8_t limit);

EXPORT_SERVER uint32_t Core_GetMigrationTickRate(alt::ICore* core);
EXPORT_SERVER void Core_SetMigrationTickRate(alt::ICore* core, uint32_t limit);

EXPORT_SERVER uint32_t Core_GetColShapeTickRate(alt::ICore* core);
EXPORT_SERVER void Core_SetColShapeTickRate(alt::ICore* core, uint32_t limit);

EXPORT_SERVER uint32_t Core_GetMigrationDistance(alt::ICore* core);
EXPORT_SERVER void Core_SetMigrationDistance(alt::ICore* core, uint32_t limit);

EXPORT_SERVER void Core_TriggerClientRPCAnswer(alt::ICore* core, alt::IPlayer* target, uint16_t answerID, alt::MValueConst* answer, const char* error);
EXPORT_SERVER uint16_t Core_TriggerClientRPCEvent(alt::ICore* core, alt::IPlayer* target, const char* ev, alt::MValueConst* args[], int size);
EXPORT_CLIENT void Core_TriggerServerRPCAnswer(alt::ICore* core, uint16_t answerID, alt::MValueConst* answer, const char* error);
EXPORT_CLIENT uint16_t Core_TriggerServerRPCEvent(alt::ICore* core, const char* ev, alt::MValueConst* args[], int size);

EXPORT_SERVER void Core_AddClientConfigKey(alt::ICore* core, const char* key);

EXPORT_SERVER uint8_t Core_HasBenefit(alt::ICore* core, uint8_t benefit);

EXPORT_CLIENT uint32_t Core_GetPoolSize(alt::ICore* core, const char* pool);
EXPORT_CLIENT uint32_t Core_GetPoolCount(alt::ICore* core, const char* pool);
EXPORT_CLIENT void Core_GetPoolEntities(alt::ICore* core, const char* pool, const uint32_t*& poolEntities, uint32_t& size);

EXPORT_CLIENT void Core_GetVoicePlayers(alt::ICore* core, const uint32_t*& voicePlayers, uint32_t& size);
EXPORT_CLIENT void Core_RemoveVoicePlayer(alt::ICore* core, uint32_t playerRemodeId);

EXPORT_CLIENT float Core_GetVoiceSpatialVolume(alt::ICore* core, uint32_t playerRemodeId);
EXPORT_CLIENT void Core_SetVoiceSpatialVolume(alt::ICore* core, uint32_t playerRemodeId, float volume);

EXPORT_CLIENT float Core_GetVoiceNonSpatialVolume(alt::ICore* core, uint32_t playerRemodeId);
EXPORT_CLIENT void Core_SetVoiceNonSpatialVolume(alt::ICore* core, uint32_t playerRemodeId, float volume);

EXPORT_CLIENT void Core_AddVoiceFilter(alt::ICore* core, uint32_t playerRemodeId, alt::IAudioFilter* filter);
EXPORT_CLIENT void Core_RemoveVoiceFilter(alt::ICore* core, uint32_t playerRemodeId);
EXPORT_CLIENT alt::IAudioFilter* Core_GetVoiceFilter(alt::ICore* core, uint32_t playerRemodeId);
EXPORT_CLIENT void Core_UpdateClipContext(alt::ICore* core, const char* keys[], const char* values[], uint64_t size);