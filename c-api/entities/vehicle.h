#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "../data/types.h"
#include "../utils/export.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_SHARED uint32_t Vehicle_GetID(alt::IVehicle* vehicle);
EXPORT_SHARED alt::IEntity* Vehicle_GetEntity(alt::IVehicle* vehicle);

EXPORT_SHARED uint8_t Vehicle_GetWheelsCount(alt::IVehicle* vehicle);
EXPORT_SHARED int32_t Vehicle_GetPetrolTankHealth(alt::IVehicle* vehicle);

EXPORT_SERVER alt::IPlayer* Vehicle_GetDriver(alt::IVehicle* vehicle);
EXPORT_SERVER uint8_t Vehicle_GetDriverID(alt::IVehicle* vehicle, uint32_t& id);

EXPORT_SERVER uint8_t Vehicle_IsDestroyed(alt::IVehicle* vehicle);

EXPORT_SERVER uint8_t Vehicle_GetMod(alt::IVehicle* vehicle, uint8_t category);
EXPORT_SERVER uint8_t Vehicle_GetModsCount(alt::IVehicle* vehicle, uint8_t category);
EXPORT_SERVER uint8_t Vehicle_SetMod(alt::IVehicle* vehicle, uint8_t category, uint8_t id);
EXPORT_SERVER uint8_t Vehicle_GetModKitsCount(alt::IVehicle* vehicle);
EXPORT_SERVER uint8_t Vehicle_GetModKit(alt::IVehicle* vehicle);
EXPORT_SERVER uint8_t Vehicle_SetModKit(alt::IVehicle* vehicle, uint8_t id);

EXPORT_SERVER uint8_t Vehicle_IsPrimaryColorRGB(alt::IVehicle* vehicle);
EXPORT_SERVER uint8_t Vehicle_GetPrimaryColor(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_GetPrimaryColorRGB(alt::IVehicle* vehicle, rgba_t &primaryColor);
EXPORT_SERVER void Vehicle_SetPrimaryColor(alt::IVehicle* vehicle, uint8_t color);
EXPORT_SERVER void Vehicle_SetPrimaryColorRGB(alt::IVehicle* vehicle, rgba_t color);

EXPORT_SERVER uint8_t Vehicle_IsSecondaryColorRGB(alt::IVehicle* vehicle);
EXPORT_SERVER uint8_t Vehicle_GetSecondaryColor(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_GetSecondaryColorRGB(alt::IVehicle* vehicle, rgba_t &secondaryColor);
EXPORT_SERVER void Vehicle_SetSecondaryColor(alt::IVehicle* vehicle, uint8_t color);
EXPORT_SERVER void Vehicle_SetSecondaryColorRGB(alt::IVehicle* vehicle, rgba_t color);

EXPORT_SERVER uint8_t Vehicle_GetPearlColor(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetPearlColor(alt::IVehicle* vehicle, uint8_t color);

EXPORT_SERVER uint8_t Vehicle_GetWheelColor(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetWheelColor(alt::IVehicle* vehicle, uint8_t color);

EXPORT_SERVER uint8_t Vehicle_GetInteriorColor(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetInteriorColor(alt::IVehicle* vehicle, uint8_t color);

EXPORT_SERVER uint8_t Vehicle_GetDashboardColor(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetDashboardColor(alt::IVehicle* vehicle, uint8_t color);

EXPORT_SERVER uint8_t Vehicle_IsTireSmokeColorCustom(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_GetTireSmokeColor(alt::IVehicle* vehicle, rgba_t &tireSmokeColor);
EXPORT_SERVER void Vehicle_SetTireSmokeColor(alt::IVehicle* vehicle, rgba_t color);

EXPORT_SERVER uint8_t Vehicle_GetWheelType(alt::IVehicle* vehicle);
EXPORT_SERVER uint8_t Vehicle_GetWheelVariation(alt::IVehicle* vehicle);
EXPORT_SERVER uint8_t Vehicle_GetRearWheelVariation(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetWheels(alt::IVehicle* vehicle, uint8_t type, uint8_t variation);
EXPORT_SERVER void Vehicle_SetRearWheels(alt::IVehicle* vehicle, uint8_t variation);

EXPORT_SERVER uint8_t Vehicle_GetCustomTires(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetCustomTires(alt::IVehicle* vehicle, uint8_t state);

EXPORT_SERVER uint8_t Vehicle_GetSpecialDarkness(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetSpecialDarkness(alt::IVehicle* vehicle, uint8_t value);

EXPORT_SERVER uint32_t Vehicle_GetNumberplateIndex(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetNumberplateIndex(alt::IVehicle* vehicle, uint32_t index);

EXPORT_SERVER const char* Vehicle_GetNumberplateText(alt::IVehicle* vehicle, int32_t& size);
EXPORT_SERVER void Vehicle_SetNumberplateText(alt::IVehicle* vehicle, const char* text);

EXPORT_SERVER uint8_t Vehicle_GetWindowTint(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetWindowTint(alt::IVehicle* vehicle, uint8_t tint);

EXPORT_SERVER uint8_t Vehicle_GetDirtLevel(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetDirtLevel(alt::IVehicle* vehicle, uint8_t level);

EXPORT_SERVER uint8_t Vehicle_IsExtraOn(alt::IVehicle* vehicle, uint8_t extraID);
EXPORT_SERVER void Vehicle_ToggleExtra(alt::IVehicle* vehicle, uint8_t extraID, uint8_t state);

EXPORT_SERVER uint8_t Vehicle_IsNeonActive(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_GetNeonActive(alt::IVehicle* vehicle, uint8_t* left, uint8_t* right, uint8_t* front, uint8_t* back);
EXPORT_SERVER void Vehicle_SetNeonActive(alt::IVehicle* vehicle, uint8_t left, uint8_t right, uint8_t front, uint8_t back);
EXPORT_SERVER void Vehicle_GetNeonColor(alt::IVehicle* vehicle, rgba_t &neonColor);
EXPORT_SERVER void Vehicle_SetNeonColor(alt::IVehicle* vehicle, rgba_t color);

EXPORT_SERVER uint8_t Vehicle_GetLivery(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetLivery(alt::IVehicle* vehicle, uint8_t livery);

EXPORT_SERVER uint8_t Vehicle_GetRoofLivery(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetRoofLivery(alt::IVehicle* vehicle, uint8_t roofLivery);

EXPORT_SERVER const char* Vehicle_GetAppearanceDataBase64(alt::IVehicle* vehicle, int32_t& size);
EXPORT_SERVER void Vehicle_LoadAppearanceDataFromBase64(alt::IVehicle* vehicle, const char* base64);

EXPORT_SERVER uint8_t Vehicle_IsEngineOn(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetEngineOn(alt::IVehicle* vehicle, uint8_t state);

EXPORT_SERVER uint8_t Vehicle_IsHandbrakeActive(alt::IVehicle* vehicle);

EXPORT_SERVER uint8_t Vehicle_GetHeadlightColor(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetHeadlightColor(alt::IVehicle* vehicle, uint8_t color);

EXPORT_SERVER uint32_t Vehicle_GetRadioStationIndex(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetRadioStationIndex(alt::IVehicle* vehicle, uint32_t stationIndex);

EXPORT_SERVER uint8_t Vehicle_IsSirenActive(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetSirenActive(alt::IVehicle* vehicle, uint8_t state);

// TODO document available values. Enum?
EXPORT_SERVER uint8_t Vehicle_GetLockState(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetLockState(alt::IVehicle* vehicle, uint8_t state);

// TODO document available values. Enum?
EXPORT_SERVER uint8_t Vehicle_GetDoorState(alt::IVehicle* vehicle, uint8_t doorId);
EXPORT_SERVER void Vehicle_SetDoorState(alt::IVehicle* vehicle, uint8_t doorId, uint8_t state);

EXPORT_SERVER uint8_t Vehicle_IsWindowOpened(alt::IVehicle* vehicle, uint8_t windowId);
EXPORT_SERVER void Vehicle_SetWindowOpened(alt::IVehicle* vehicle, uint8_t windowId, uint8_t state);

EXPORT_SERVER uint8_t Vehicle_IsDaylightOn(alt::IVehicle* vehicle);
EXPORT_SERVER uint8_t Vehicle_IsNightlightOn(alt::IVehicle* vehicle);

EXPORT_SERVER uint8_t Vehicle_GetRoofState(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetRoofState(alt::IVehicle* vehicle, uint8_t state);

EXPORT_SERVER uint8_t Vehicle_IsFlamethrowerActive(alt::IVehicle* vehicle);

EXPORT_SERVER float Vehicle_GetLightsMultiplier(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetLightsMultiplier(alt::IVehicle* vehicle, float multiplier);

EXPORT_SERVER const char* Vehicle_GetGameStateBase64(alt::IVehicle* vehicle, int32_t& size);
EXPORT_SERVER void Vehicle_LoadGameStateFromBase64(alt::IVehicle* vehicle, const char* base64);

EXPORT_SERVER int32_t Vehicle_GetEngineHealth(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetEngineHealth(alt::IVehicle* vehicle, int32_t health);

EXPORT_SERVER void Vehicle_SetPetrolTankHealth(alt::IVehicle* vehicle, int32_t health);

EXPORT_SERVER uint8_t Vehicle_IsWheelBurst(alt::IVehicle* vehicle, uint8_t wheelId);
EXPORT_SERVER void Vehicle_SetWheelBurst(alt::IVehicle* vehicle, uint8_t wheelId, uint8_t state);

EXPORT_SERVER uint8_t Vehicle_DoesWheelHasTire(alt::IVehicle* vehicle, uint8_t wheelId);
EXPORT_SERVER void Vehicle_SetWheelHasTire(alt::IVehicle* vehicle, uint8_t wheelId, uint8_t state);

EXPORT_SERVER uint8_t Vehicle_IsWheelDetached(alt::IVehicle* vehicle, uint8_t wheelId);
EXPORT_SERVER void Vehicle_SetWheelDetached(alt::IVehicle* vehicle, uint8_t wheelId, uint8_t state);

EXPORT_SERVER uint8_t Vehicle_IsWheelOnFire(alt::IVehicle* vehicle, uint8_t wheelId);
EXPORT_SERVER void Vehicle_SetWheelOnFire(alt::IVehicle* vehicle, uint8_t wheelId, uint8_t state);

EXPORT_SERVER float Vehicle_GetWheelHealth(alt::IVehicle* vehicle, uint8_t wheelId);
EXPORT_SERVER void Vehicle_SetWheelHealth(alt::IVehicle* vehicle, uint8_t wheelId, float health);

EXPORT_SERVER void Vehicle_SetWheelFixed(alt::IVehicle* vehicle, uint8_t wheelId);

EXPORT_SERVER uint8_t Vehicle_GetRepairsCount(alt::IVehicle* vehicle);

EXPORT_SERVER uint32_t Vehicle_GetBodyHealth(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetBodyHealth(alt::IVehicle* vehicle, uint32_t health);
EXPORT_SERVER uint32_t Vehicle_GetBodyAdditionalHealth(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetBodyAdditionalHealth(alt::IVehicle* vehicle, uint32_t health);

EXPORT_SERVER const char* Vehicle_GetHealthDataBase64(alt::IVehicle* vehicle, int32_t& size);
EXPORT_SERVER void Vehicle_LoadHealthDataFromBase64(alt::IVehicle* vehicle, const char* base64);

EXPORT_SERVER uint8_t Vehicle_GetPartDamageLevel(alt::IVehicle* vehicle, uint8_t partId);
EXPORT_SERVER void Vehicle_SetPartDamageLevel(alt::IVehicle* vehicle, uint8_t partId, uint8_t damage);
EXPORT_SERVER uint8_t Vehicle_GetPartBulletHoles(alt::IVehicle* vehicle, uint8_t partId);
EXPORT_SERVER void Vehicle_SetPartBulletHoles(alt::IVehicle* vehicle, uint8_t partId, uint8_t shootsCount);
EXPORT_SERVER uint8_t Vehicle_IsLightDamaged(alt::IVehicle* vehicle, uint8_t lightId);
EXPORT_SERVER void Vehicle_SetLightDamaged(alt::IVehicle* vehicle, uint8_t lightId, uint8_t isDamaged);
EXPORT_SERVER uint8_t Vehicle_IsWindowDamaged(alt::IVehicle* vehicle, uint8_t windowId);
EXPORT_SERVER void Vehicle_SetWindowDamaged(alt::IVehicle* vehicle, uint8_t windowId, uint8_t isDamaged);
EXPORT_SERVER uint8_t Vehicle_IsSpecialLightDamaged(alt::IVehicle* vehicle, uint8_t specialLightId);
EXPORT_SERVER void Vehicle_SetSpecialLightDamaged(alt::IVehicle* vehicle, uint8_t specialLightId, uint8_t isDamaged);
EXPORT_SERVER uint8_t Vehicle_HasArmoredWindows(alt::IVehicle* vehicle);
EXPORT_SERVER float Vehicle_GetArmoredWindowHealth(alt::IVehicle* vehicle, uint8_t windowId);
EXPORT_SERVER void Vehicle_SetArmoredWindowHealth(alt::IVehicle* vehicle, uint8_t windowId, float health);
EXPORT_SERVER uint8_t Vehicle_GetArmoredWindowShootCount(alt::IVehicle* vehicle, uint8_t windowId);
EXPORT_SERVER void Vehicle_SetArmoredWindowShootCount(alt::IVehicle* vehicle, uint8_t windowId, uint8_t count);
EXPORT_SERVER uint8_t Vehicle_GetBumperDamageLevel(alt::IVehicle* vehicle, uint8_t bumperId);
EXPORT_SERVER void Vehicle_SetBumperDamageLevel(alt::IVehicle* vehicle, uint8_t bumperId, uint8_t damageLevel);

EXPORT_SERVER const char* Vehicle_GetDamageDataBase64(alt::IVehicle* vehicle, int32_t& size);
EXPORT_SERVER void Vehicle_LoadDamageDataFromBase64(alt::IVehicle* vehicle, const char* base64);

EXPORT_SERVER void Vehicle_SetManualEngineControl(alt::IVehicle* vehicle, uint8_t state);
EXPORT_SERVER uint8_t Vehicle_IsManualEngineControl(alt::IVehicle* vehicle);

EXPORT_SERVER const char* Vehicle_GetScriptDataBase64(alt::IVehicle* vehicle, int32_t& size);
EXPORT_SERVER void Vehicle_LoadScriptDataFromBase64(alt::IVehicle* vehicle, const char* base64);

EXPORT_SERVER alt::IVehicle* Vehicle_GetAttached(alt::IVehicle* vehicle);
EXPORT_SERVER alt::IVehicle* Vehicle_GetAttachedTo(alt::IVehicle* vehicle);

EXPORT_SERVER void Vehicle_Repair(alt::IVehicle* vehicle);

EXPORT_SERVER void Vehicle_GetVelocity(alt::IVehicle* vehicle, position_t &velocity);

EXPORT_SERVER void Vehicle_SetDriftMode(alt::IVehicle* vehicle, uint8_t state);
EXPORT_SERVER uint8_t Vehicle_IsDriftMode(alt::IVehicle* vehicle);

EXPORT_SERVER uint8_t Vehicle_SetSearchLight(alt::IVehicle* vehicle, uint8_t state, alt::IEntity* spottedEntity);

EXPORT_SERVER uint8_t Vehicle_IsTrainMissionTrain(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetTrainMissionTrain(alt::IVehicle* vehicle, uint8_t state);
EXPORT_SERVER int8_t Vehicle_GetTrainTrackId(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetTrainTrackId(alt::IVehicle* vehicle, int8_t trackId);
EXPORT_SERVER alt::IVehicle* Vehicle_GetTrainEngineId(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetTrainEngineId(alt::IVehicle* vehicle, alt::IVehicle* entity);
EXPORT_SERVER int8_t Vehicle_GetTrainConfigIndex(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetTrainConfigIndex(alt::IVehicle* vehicle, int8_t index);
EXPORT_SERVER float Vehicle_GetTrainDistanceFromEngine(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetTrainDistanceFromEngine(alt::IVehicle* vehicle, float distanceFromEngine);
EXPORT_SERVER uint8_t Vehicle_IsTrainEngine(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetTrainIsEngine(alt::IVehicle* vehicle, uint8_t state);
EXPORT_SERVER uint8_t Vehicle_IsTrainCaboose(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetTrainIsCaboose(alt::IVehicle* vehicle, uint8_t isCaboose);
EXPORT_SERVER uint8_t Vehicle_GetTrainDirection(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetTrainDirection(alt::IVehicle* vehicle, uint8_t direction);
EXPORT_SERVER uint8_t Vehicle_HasTrainPassengerCarriages(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetTrainHasPassengerCarriages(alt::IVehicle* vehicle, uint8_t hasPassengerCarriages);
EXPORT_SERVER uint8_t Vehicle_GetTrainRenderDerailed(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetTrainRenderDerailed(alt::IVehicle* vehicle, uint8_t renderDerailed);
EXPORT_SERVER uint8_t Vehicle_GetTrainForceDoorsOpen(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetTrainForceDoorsOpen(alt::IVehicle* vehicle, uint8_t forceDoorsOpen);
EXPORT_SERVER float Vehicle_GetTrainCruiseSpeed(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetTrainCruiseSpeed(alt::IVehicle* vehicle, float cruiseSpeed);
EXPORT_SERVER int8_t Vehicle_GetTrainCarriageConfigIndex(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetTrainCarriageConfigIndex(alt::IVehicle* vehicle, int8_t carriageConfigIndex);
EXPORT_SERVER alt::IVehicle* Vehicle_GetTrainLinkedToBackwardId(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetTrainLinkedToBackwardId(alt::IVehicle* vehicle, alt::IVehicle* entity);
EXPORT_SERVER alt::IVehicle* Vehicle_GetTrainLinkedToForwardId(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetTrainLinkedToForwardId(alt::IVehicle* vehicle, alt::IVehicle* entity);

EXPORT_SERVER uint8_t Vehicle_GetBoatAnchor(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetBoatAnchor(alt::IVehicle* vehicle, uint8_t state);

EXPORT_SERVER uint8_t Vehicle_GetLightState(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetLightState(alt::IVehicle* vehicle, uint8_t value);

EXPORT_SERVER uint8_t Vehicle_HasTimedExplosion(alt::IVehicle* vehicle);
EXPORT_SERVER alt::IPlayer* Vehicle_GetTimedExplosionCulprit(alt::IVehicle* vehicle);
EXPORT_SERVER uint32_t Vehicle_GetTimedExplosionTime(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetTimedExplosion(alt::IVehicle* vehicle, uint8_t state, alt::IPlayer* culprit, uint32_t time);

EXPORT_SERVER uint8_t Vehicle_IsTowingDisabled(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetDisableTowing(alt::IVehicle* vehicle, uint8_t state);

EXPORT_SERVER float Vehicle_GetRocketRefuelSpeed(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetRocketRefuelSpeed(alt::IVehicle* vehicle, float rocketRefuleSpeed);

EXPORT_SERVER uint32_t Vehicle_GetCounterMeasureCount(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetCounterMeasureCount(alt::IVehicle* vehicle, uint32_t counterMeasureCount);

EXPORT_SERVER float Vehicle_GetScriptMaxSpeed(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetScriptMaxSpeed(alt::IVehicle* vehicle, float scriptMaxSpeed);

EXPORT_SERVER int32_t Vehicle_GetWeaponCapacity(alt::IVehicle* vehicle, uint8_t index);
EXPORT_SERVER void Vehicle_SetWeaponCapacity(alt::IVehicle* vehicle, uint8_t index, int32_t state);

EXPORT_SERVER uint8_t Vehicle_GetHybridExtraActive(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetHybridExtraActive(alt::IVehicle* vehicle, uint8_t state);

EXPORT_SERVER uint8_t Vehicle_GetHybridExtraState(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetHybridExtraState(alt::IVehicle* vehicle, uint8_t state);

EXPORT_CLIENT float Vehicle_GetWheelSpeed(alt::IVehicle* vehicle);
EXPORT_CLIENT uint16_t Vehicle_GetCurrentGear(alt::IVehicle* vehicle);
EXPORT_CLIENT float Vehicle_GetCurrentRPM(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_SetCurrentRPM(alt::IVehicle* vehicle, float rpm);
EXPORT_CLIENT void Vehicle_GetSpeedVector(alt::IVehicle* vehicle, vector3_t& vector);
EXPORT_CLIENT uint16_t Vehicle_GetMaxGear(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_SetSteeringAngle(alt::IVehicle* vehicle, float value);

EXPORT_CLIENT void Vehicle_SetCurrentGear(alt::IVehicle* vehicle, uint16_t value);
EXPORT_CLIENT void Vehicle_SetMaxGear(alt::IVehicle* vehicle, uint16_t value);

EXPORT_CLIENT uint8_t Vehicle_IsHandlingModified(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_ResetHandling(alt::IVehicle* vehicle);

EXPORT_CLIENT uint8_t Vehicle_GetLightsIndicator(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_SetLightsIndicator(alt::IVehicle* vehicle, uint8_t value);

EXPORT_CLIENT uint8_t Vehicle_GetSeatCount(alt::IVehicle* vehicle);
EXPORT_CLIENT uint8_t Vehicle_GetOccupiedSeatsCount(alt::IVehicle* vehicle);

EXPORT_CLIENT void Vehicle_ToggleTaxiLight(alt::IVehicle* vehicle, uint8_t state);
EXPORT_CLIENT uint8_t Vehicle_IsTaxiLightOn(alt::IVehicle* vehicle);

EXPORT_CLIENT float Vehicle_GetWheelCamber(alt::IVehicle* vehicle, uint8_t wheel);
EXPORT_CLIENT void Vehicle_SetWheelCamber(alt::IVehicle* vehicle, uint8_t wheel, float value);
EXPORT_CLIENT float Vehicle_GetWheelTrackWidth(alt::IVehicle* vehicle, uint8_t wheel);
EXPORT_CLIENT void Vehicle_SetWheelTrackWidth(alt::IVehicle* vehicle, uint8_t wheel, float value);
EXPORT_CLIENT float Vehicle_GetWheelHeight(alt::IVehicle* vehicle, uint8_t wheel);
EXPORT_CLIENT void Vehicle_SetWheelHeight(alt::IVehicle* vehicle, uint8_t wheel, float value);
EXPORT_CLIENT float Vehicle_GetWheelTyreRadius(alt::IVehicle* vehicle, uint8_t wheel);
EXPORT_CLIENT void Vehicle_SetWheelTyreRadius(alt::IVehicle* vehicle, uint8_t wheel, float value);
EXPORT_CLIENT float Vehicle_GetWheelRimRadius(alt::IVehicle* vehicle, uint8_t wheel);
EXPORT_CLIENT void Vehicle_SetWheelRimRadius(alt::IVehicle* vehicle, uint8_t wheel, float value);
EXPORT_CLIENT float Vehicle_GetWheelTyreWidth(alt::IVehicle* vehicle, uint8_t wheel);
EXPORT_CLIENT void Vehicle_SetWheelTyreWidth(alt::IVehicle* vehicle, uint8_t wheel, float value);
EXPORT_CLIENT uint32_t Vehicle_GetWheelSurfaceMaterial(alt::IVehicle* vehicle, uint8_t wheel);

EXPORT_CLIENT float Vehicle_GetEngineTemperature(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_SetEngineTemperature(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_GetFuelLevel(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_SetFuelLevel(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_GetOilLevel(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_SetOilLevel(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT uint8_t Vehicle_GetEngineLightState(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_SetEngineLightState(alt::IVehicle* vehicle, uint8_t state);
EXPORT_CLIENT uint8_t Vehicle_GetAbsLightState(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_SetAbsLightState(alt::IVehicle* vehicle, uint8_t state);
EXPORT_CLIENT uint8_t Vehicle_GetPetrolLightState(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_SetPetrolLightState(alt::IVehicle* vehicle, uint8_t state);
EXPORT_CLIENT uint8_t Vehicle_GetOilLightState(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_SetOilLightState(alt::IVehicle* vehicle, uint8_t state);
EXPORT_CLIENT uint8_t Vehicle_GetBatteryLightState(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_SetBatteryLightState(alt::IVehicle* vehicle, uint8_t state);
EXPORT_CLIENT void Vehicle_ResetDashboardLights(alt::IVehicle* vehicle);

EXPORT_CLIENT uint32_t Vehicle_Handling_GetHandlingNameHash(alt::IVehicle* vehicle);
EXPORT_CLIENT float Vehicle_Handling_GetMass(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetMass(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetInitialDragCoeff(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetInitialDragCoeff(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetDownforceModifier(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetDownforceModifier(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetunkFloat1(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetunkFloat1(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetunkFloat2(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetunkFloat2(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT void Vehicle_Handling_GetCentreOfMassOffset(alt::IVehicle* vehicle, vector3_t& offset);
EXPORT_CLIENT void Vehicle_Handling_SetCentreOfMassOffset(alt::IVehicle* vehicle, vector3_t value);
EXPORT_CLIENT void Vehicle_Handling_GetInertiaMultiplier(alt::IVehicle* vehicle, vector3_t& offset);
EXPORT_CLIENT void Vehicle_Handling_SetInertiaMultiplier(alt::IVehicle* vehicle, vector3_t value);
EXPORT_CLIENT float Vehicle_Handling_GetPercentSubmerged(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetPercentSubmerged(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetPercentSubmergedRatio(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetPercentSubmergedRatio(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetDriveBiasFront(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetDriveBiasFront(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetAcceleration(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetAcceleration(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT uint32_t Vehicle_Handling_GetInitialDriveGears(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetInitialDriveGears(alt::IVehicle* vehicle, uint32_t value);
EXPORT_CLIENT float Vehicle_Handling_GetDriveInertia(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetDriveInertia(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetClutchChangeRateScaleUpShift(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetClutchChangeRateScaleUpShift(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetClutchChangeRateScaleDownShift(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetClutchChangeRateScaleDownShift(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetInitialDriveForce(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetInitialDriveForce(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetDriveMaxFlatVel(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetDriveMaxFlatVel(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetInitialDriveMaxFlatVel(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetInitialDriveMaxFlatVel(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetBrakeForce(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetBrakeForce(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetunkFloat4(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetunkFloat4(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetBrakeBiasFront(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetBrakeBiasFront(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetBrakeBiasRear(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetBrakeBiasRear(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetHandBrakeForce(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetHandBrakeForce(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetSteeringLock(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetSteeringLock(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetSteeringLockRatio(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetSteeringLockRatio(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetTractionCurveMax(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetTractionCurveMax(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetTractionCurveMaxRatio(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetTractionCurveMaxRatio(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetTractionCurveMin(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetTractionCurveMin(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetTractionCurveMinRatio(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetTractionCurveMinRatio(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetTractionCurveLateral(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetTractionCurveLateral(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetTractionCurveLateralRatio(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetTractionCurveLateralRatio(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetTractionSpringDeltaMax(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetTractionSpringDeltaMax(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetTractionSpringDeltaMaxRatio(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetTractionSpringDeltaMaxRatio(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetLowSpeedTractionLossMult(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetLowSpeedTractionLossMult(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetCamberStiffness(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetCamberStiffness(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetTractionBiasFront(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetTractionBiasFront(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetTractionBiasRear(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetTractionBiasRear(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetTractionLossMult(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetTractionLossMult(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetSuspensionForce(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetSuspensionForce(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetSuspensionCompDamp(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetSuspensionCompDamp(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetSuspensionReboundDamp(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetSuspensionReboundDamp(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetSuspensionUpperLimit(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetSuspensionUpperLimit(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetSuspensionLowerLimit(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetSuspensionLowerLimit(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetSuspensionRaise(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetSuspensionRaise(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetSuspensionBiasFront(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetSuspensionBiasFront(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetSuspensionBiasRear(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetSuspensionBiasRear(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetAntiRollBarForce(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetAntiRollBarForce(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetAntiRollBarBiasFront(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetAntiRollBarBiasFront(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetAntiRollBarBiasRear(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetAntiRollBarBiasRear(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetRollCentreHeightFront(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetRollCentreHeightFront(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetRollCentreHeightRear(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetRollCentreHeightRear(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetCollisionDamageMult(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetCollisionDamageMult(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetWeaponDamageMult(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetWeaponDamageMult(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetDeformationDamageMult(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetDeformationDamageMult(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetEngineDamageMult(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetEngineDamageMult(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetPetrolTankVolume(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetPetrolTankVolume(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetOilVolume(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetOilVolume(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetunkFloat5(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetunkFloat5(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetSeatOffsetDistX(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetSeatOffsetDistX(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetSeatOffsetDistY(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetSeatOffsetDistY(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT float Vehicle_Handling_GetSeatOffsetDistZ(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetSeatOffsetDistZ(alt::IVehicle* vehicle, float value);
EXPORT_CLIENT uint32_t Vehicle_Handling_GetMonetaryValue(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetMonetaryValue(alt::IVehicle* vehicle, uint32_t value);
EXPORT_CLIENT uint32_t Vehicle_Handling_GetModelFlags(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetModelFlags(alt::IVehicle* vehicle, uint32_t value);
EXPORT_CLIENT uint32_t Vehicle_Handling_GetHandlingFlags(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetHandlingFlags(alt::IVehicle* vehicle, uint32_t value);
EXPORT_CLIENT uint32_t Vehicle_Handling_GetDamageFlags(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_Handling_SetDamageFlags(alt::IVehicle* vehicle, uint32_t value);

EXPORT_SERVER alt::Quaternion Vehicle_GetQuaternion(alt::IVehicle* vehicle);
EXPORT_SERVER void Vehicle_SetQuaternion(alt::IVehicle* vehicle, alt::Quaternion quaternion);

EXPORT_SHARED float Vehicle_GetSteeringAngle(alt::IVehicle* vehicle);

EXPORT_SERVER uint8_t Vehicle_IsHornActive(alt::IVehicle* vehicle);
EXPORT_SERVER float Vehicle_GetAccelerationLevel(alt::IVehicle* vehicle);
EXPORT_SERVER float Vehicle_GetBrakeLevel(alt::IVehicle* vehicle);

EXPORT_CLIENT float Vehicle_GetSuspensionHeight(alt::IVehicle* vehicle);
EXPORT_CLIENT void Vehicle_SetSuspensionHeight(alt::IVehicle* vehicle, float value);

EXPORT_SERVER void Vehicle_SetBadge(alt::IVehicle* vehicle, uint32_t textureDictionary, uint32_t texture, vehicleBadgePosition_t vehicleBadgePosition[], uint16_t size);