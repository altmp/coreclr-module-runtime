#include "vehicle.h"
#include "../utils/strings.h"
#include "../cache/CachedVehicle.h"
#include "../utils/macros.h"

CAPI_START()

uint32_t Vehicle_GetID(alt::IVehicle* entity) {
    return entity->GetID();
}

alt::IEntity* Vehicle_GetEntity(alt::IVehicle* entity) {
    return dynamic_cast<alt::IEntity*>(entity);
}

uint8_t Vehicle_GetWheelsCount(alt::IVehicle* vehicle) {
    return vehicle->GetWheelsCount();
}

int32_t Vehicle_GetPetrolTankHealth(alt::IVehicle* vehicle) {
    return vehicle->GetPetrolTankHealth();
}

float Vehicle_GetSteeringAngle(alt::IVehicle* vehicle)
{
    return vehicle->GetSteeringAngle();
}


#ifdef ALT_SERVER_API
alt::IPlayer* Vehicle_GetDriver(alt::IVehicle* vehicle) {
    return vehicle->GetDriver();
}

uint8_t Vehicle_GetDriverID(alt::IVehicle* vehicle, uint32_t& id) {
    auto driver = vehicle->GetDriver();
    if (driver == nullptr) return false;
    id = driver->GetID();
    return true;
}


uint8_t Vehicle_IsDestroyed(alt::IVehicle* vehicle) {
    return vehicle->IsDestroyed();
}


uint8_t Vehicle_GetMod(alt::IVehicle* vehicle, uint8_t category) {
    return vehicle->GetMod(category);
}

uint8_t Vehicle_GetModsCount(alt::IVehicle* vehicle, uint8_t category) {
    return vehicle->GetModsCount(category);
}

uint8_t Vehicle_SetMod(alt::IVehicle* vehicle, uint8_t category, uint8_t id) {
    return vehicle->SetMod(category, id);
}

uint8_t Vehicle_GetModKitsCount(alt::IVehicle* vehicle) {
    return vehicle->GetModKitsCount();
}

uint8_t Vehicle_GetModKit(alt::IVehicle* vehicle) {
    return vehicle->GetModKit();
}

uint8_t Vehicle_SetModKit(alt::IVehicle* vehicle, uint8_t id) {
    return vehicle->SetModKit(id);
}


uint8_t Vehicle_IsPrimaryColorRGB(alt::IVehicle* vehicle) {
    return vehicle->IsPrimaryColorRGB();
}

uint8_t Vehicle_GetPrimaryColor(alt::IVehicle* vehicle) {
    return vehicle->GetPrimaryColor();
}

void Vehicle_GetPrimaryColorRGB(alt::IVehicle* vehicle, rgba_t &primaryColor) {
    auto vehiclePrimaryColor = vehicle->GetPrimaryColorRGB();
    primaryColor.r = vehiclePrimaryColor.r;
    primaryColor.g = vehiclePrimaryColor.g;
    primaryColor.b = vehiclePrimaryColor.b;
    primaryColor.a = vehiclePrimaryColor.a;
}

void Vehicle_SetPrimaryColor(alt::IVehicle* vehicle, uint8_t color) {
    vehicle->SetPrimaryColor(color);
}

void Vehicle_SetPrimaryColorRGB(alt::IVehicle* vehicle, rgba_t primaryColor) {
    alt::RGBA color;
    color.r = primaryColor.r;
    color.g = primaryColor.g;
    color.b = primaryColor.b;
    color.a = primaryColor.a;
    vehicle->SetPrimaryColorRGB(color);
}


uint8_t Vehicle_IsSecondaryColorRGB(alt::IVehicle* vehicle) {
    return vehicle->IsSecondaryColorRGB();
}

uint8_t Vehicle_GetSecondaryColor(alt::IVehicle* vehicle) {
    return vehicle->GetSecondaryColor();
}

void Vehicle_GetSecondaryColorRGB(alt::IVehicle* vehicle, rgba_t &secondaryColor) {
    auto vehicleSecondaryColor = vehicle->GetSecondaryColorRGB();
    secondaryColor.r = vehicleSecondaryColor.r;
    secondaryColor.g = vehicleSecondaryColor.g;
    secondaryColor.b = vehicleSecondaryColor.b;
    secondaryColor.a = vehicleSecondaryColor.a;
}

void Vehicle_SetSecondaryColor(alt::IVehicle* vehicle, uint8_t color) {
    vehicle->SetSecondaryColor(color);
}

void Vehicle_SetSecondaryColorRGB(alt::IVehicle* vehicle,rgba_t secondaryColor) {
    alt::RGBA color;
    color.r = secondaryColor.r;
    color.g = secondaryColor.g;
    color.b = secondaryColor.b;
    color.a = secondaryColor.a;
    vehicle->SetSecondaryColorRGB(color);
}


uint8_t Vehicle_GetPearlColor(alt::IVehicle* vehicle) {
    return vehicle->GetPearlColor();
}

void Vehicle_SetPearlColor(alt::IVehicle* vehicle, uint8_t color) {
    vehicle->SetPearlColor(color);
}


uint8_t Vehicle_GetWheelColor(alt::IVehicle* vehicle) {
    return vehicle->GetWheelColor();
}

void Vehicle_SetWheelColor(alt::IVehicle* vehicle, uint8_t color) {
    vehicle->SetWheelColor(color);
}


uint8_t Vehicle_GetInteriorColor(alt::IVehicle* vehicle) {
    return vehicle->GetInteriorColor();
}

void Vehicle_SetInteriorColor(alt::IVehicle* vehicle, uint8_t color) {
    vehicle->SetInteriorColor(color);
}


uint8_t Vehicle_GetDashboardColor(alt::IVehicle* vehicle) {
    return vehicle->GetDashboardColor();
}

void Vehicle_SetDashboardColor(alt::IVehicle* vehicle, uint8_t color) {
    vehicle->SetDashboardColor(color);
}


uint8_t Vehicle_IsTireSmokeColorCustom(alt::IVehicle* vehicle) {
    return vehicle->IsTireSmokeColorCustom();
}

void Vehicle_GetTireSmokeColor(alt::IVehicle* vehicle, rgba_t &tireSmokeColor) {
    auto vehicleTireSmokeColor = vehicle->GetTireSmokeColor();
    tireSmokeColor.r = vehicleTireSmokeColor.r;
    tireSmokeColor.g = vehicleTireSmokeColor.g;
    tireSmokeColor.b = vehicleTireSmokeColor.b;
    tireSmokeColor.a = vehicleTireSmokeColor.a;
}

void Vehicle_SetTireSmokeColor(alt::IVehicle* vehicle, rgba_t tireSmokeColor) {
    alt::RGBA color;
    color.r = tireSmokeColor.r;
    color.g = tireSmokeColor.g;
    color.b = tireSmokeColor.b;
    color.a = tireSmokeColor.a;
    vehicle->SetTireSmokeColor(color);
}


uint8_t Vehicle_GetWheelType(alt::IVehicle* vehicle) {
    return vehicle->GetWheelType();
}

uint8_t Vehicle_GetWheelVariation(alt::IVehicle* vehicle) {
    return vehicle->GetWheelVariation();
}

uint8_t Vehicle_GetRearWheelVariation(alt::IVehicle* vehicle) {
    return vehicle->GetRearWheelVariation();
}

void Vehicle_SetWheels(alt::IVehicle* vehicle, uint8_t type, uint8_t variation) {
    vehicle->SetWheels(type, variation);
}

void Vehicle_SetRearWheels(alt::IVehicle* vehicle, uint8_t variation) {
    vehicle->SetRearWheels(variation);
}


uint8_t Vehicle_GetCustomTires(alt::IVehicle* vehicle) {
    return vehicle->GetCustomTires();
}

void Vehicle_SetCustomTires(alt::IVehicle* vehicle, uint8_t state) {
    return vehicle->SetCustomTires(state);
}


uint8_t Vehicle_GetSpecialDarkness(alt::IVehicle* vehicle) {
    return vehicle->GetSpecialDarkness();
}

void Vehicle_SetSpecialDarkness(alt::IVehicle* vehicle, uint8_t value) {
    vehicle->SetSpecialDarkness(value);
}


uint32_t Vehicle_GetNumberplateIndex(alt::IVehicle* vehicle) {
    return vehicle->GetNumberplateIndex();
}

void Vehicle_SetNumberplateIndex(alt::IVehicle* vehicle, uint32_t index) {
    vehicle->SetNumberplateIndex(index);
}


const char* Vehicle_GetNumberplateText(alt::IVehicle* vehicle, int32_t& size) {
    return AllocateString(vehicle->GetNumberplateText(), size);
}

void Vehicle_SetNumberplateText(alt::IVehicle* vehicle, const char* text) {
    vehicle->SetNumberplateText(text);
}


uint8_t Vehicle_GetWindowTint(alt::IVehicle* vehicle) {
    return vehicle->GetWindowTint();
}

void Vehicle_SetWindowTint(alt::IVehicle* vehicle, uint8_t tint) {
    vehicle->SetWindowTint(tint);
}


uint8_t Vehicle_GetDirtLevel(alt::IVehicle* vehicle) {
    return vehicle->GetDirtLevel();
}

void Vehicle_SetDirtLevel(alt::IVehicle* vehicle, uint8_t level) {
    vehicle->SetDirtLevel(level);
}


uint8_t Vehicle_IsExtraOn(alt::IVehicle* vehicle, uint8_t extraID) {
    return vehicle->IsExtraOn(extraID);
}

void Vehicle_ToggleExtra(alt::IVehicle* vehicle, uint8_t extraID, uint8_t state) {
    vehicle->ToggleExtra(extraID, state);
}


uint8_t Vehicle_IsNeonActive(alt::IVehicle* vehicle) {
    return vehicle->IsNeonActive();
}

void Vehicle_GetNeonActive(alt::IVehicle* vehicle, uint8_t* left, uint8_t* right, uint8_t* front, uint8_t* back) {
    bool bLeft, bRight, bFront, bBack;
    vehicle->GetNeonActive(&bLeft, &bRight, &bFront, &bBack);
    *left = bLeft;
    *right = bRight;
    *front = bFront;
    *back = bBack;
}

void Vehicle_SetNeonActive(alt::IVehicle* vehicle, uint8_t left, uint8_t right, uint8_t front, uint8_t back) {
    vehicle->SetNeonActive(left, right, front, back);
}

void Vehicle_GetNeonColor(alt::IVehicle* vehicle, rgba_t &neonColor) {
    auto vehicleNeonColor = vehicle->GetNeonColor();
    neonColor.r = vehicleNeonColor.r;
    neonColor.g = vehicleNeonColor.g;
    neonColor.b = vehicleNeonColor.b;
    neonColor.a = vehicleNeonColor.a;
}

void Vehicle_SetNeonColor(alt::IVehicle* vehicle, rgba_t neonColor) {
    alt::RGBA color;
    color.r = neonColor.r;
    color.g = neonColor.g;
    color.b = neonColor.b;
    color.a = neonColor.a;
    return vehicle->SetNeonColor(color);
}


uint8_t Vehicle_GetLivery(alt::IVehicle* vehicle) {
    return vehicle->GetLivery();
}

void Vehicle_SetLivery(alt::IVehicle* vehicle, uint8_t livery) {
    vehicle->SetLivery(livery);
}


uint8_t Vehicle_GetRoofLivery(alt::IVehicle* vehicle) {
    return vehicle->GetRoofLivery();
}

void Vehicle_SetRoofLivery(alt::IVehicle* vehicle, uint8_t roofLivery) {
    vehicle->SetRoofLivery(roofLivery);
}


const char* Vehicle_GetAppearanceDataBase64(alt::IVehicle* vehicle, int32_t& size) {
    return AllocateString(vehicle->GetAppearanceDataBase64(), size);
}

void Vehicle_LoadAppearanceDataFromBase64(alt::IVehicle* vehicle, const char* base64) {
    vehicle->LoadAppearanceDataFromBase64(base64);
}


uint8_t Vehicle_IsEngineOn(alt::IVehicle* vehicle) {
    return vehicle->IsEngineOn();
}

void Vehicle_SetEngineOn(alt::IVehicle* vehicle, uint8_t state) {
    vehicle->SetEngineOn(state);
}


uint8_t Vehicle_IsHandbrakeActive(alt::IVehicle* vehicle) {
    return vehicle->IsHandbrakeActive();
}


uint8_t Vehicle_GetHeadlightColor(alt::IVehicle* vehicle) {
    return vehicle->GetHeadlightColor();
}

void Vehicle_SetHeadlightColor(alt::IVehicle* vehicle, uint8_t color) {
    vehicle->SetHeadlightColor(color);
}


uint32_t Vehicle_GetRadioStationIndex(alt::IVehicle* vehicle) {
    return vehicle->GetRadioStationIndex();
}

void Vehicle_SetRadioStationIndex(alt::IVehicle* vehicle, uint32_t stationIndex) {
    vehicle->SetRadioStationIndex(stationIndex);
}


uint8_t Vehicle_IsSirenActive(alt::IVehicle* vehicle) {
    return vehicle->IsSirenActive();
}

void Vehicle_SetSirenActive(alt::IVehicle* vehicle, uint8_t state) {
    vehicle->SetSirenActive(state);
}


uint8_t Vehicle_GetLockState(alt::IVehicle* vehicle) {
    return vehicle->GetLockState();
}

void Vehicle_SetLockState(alt::IVehicle* vehicle, uint8_t state) {
    vehicle->SetLockState(state);
}


uint8_t Vehicle_GetDoorState(alt::IVehicle* vehicle, uint8_t doorId) {
    return vehicle->GetDoorState(doorId);
}

void Vehicle_SetDoorState(alt::IVehicle* vehicle, uint8_t doorId, uint8_t state) {
    vehicle->SetDoorState(doorId, state);
}


uint8_t Vehicle_IsWindowOpened(alt::IVehicle* vehicle, uint8_t windowId) {
    return vehicle->IsWindowOpened(windowId);
}

void Vehicle_SetWindowOpened(alt::IVehicle* vehicle, uint8_t windowId, uint8_t state) {
    vehicle->SetWindowOpened(windowId, state);
}


uint8_t Vehicle_IsDaylightOn(alt::IVehicle* vehicle) {
    return vehicle->IsDaylightOn();
}

uint8_t Vehicle_IsNightlightOn(alt::IVehicle* vehicle) {
    return vehicle->IsNightlightOn();
}


uint8_t Vehicle_GetRoofState(alt::IVehicle* vehicle) {
    return vehicle->GetRoofState();
}

void Vehicle_SetRoofState(alt::IVehicle* vehicle, uint8_t state) {
    vehicle->SetRoofState(state);
}


uint8_t Vehicle_IsFlamethrowerActive(alt::IVehicle* vehicle) {
    return vehicle->IsFlamethrowerActive();
}


float Vehicle_GetLightsMultiplier(alt::IVehicle* vehicle) {
    return vehicle->GetLightsMultiplier();
}

void Vehicle_SetLightsMultiplier(alt::IVehicle* vehicle, float multiplier) {
    vehicle->SetLightsMultiplier(multiplier);
}


const char* Vehicle_GetGameStateBase64(alt::IVehicle* vehicle, int32_t& size) {
    return AllocateString(vehicle->GetGameStateBase64(), size);
}

void Vehicle_LoadGameStateFromBase64(alt::IVehicle* vehicle, const char* base64) {
    vehicle->LoadGameStateFromBase64(base64);
}


int32_t Vehicle_GetEngineHealth(alt::IVehicle* vehicle) {
    return vehicle->GetEngineHealth();
}

void Vehicle_SetEngineHealth(alt::IVehicle* vehicle, int32_t health) {
    vehicle->SetEngineHealth(health);
}


void Vehicle_SetPetrolTankHealth(alt::IVehicle* vehicle, int32_t health) {
    vehicle->SetPetrolTankHealth(health);
}


uint8_t Vehicle_IsWheelBurst(alt::IVehicle* vehicle, uint8_t wheelId) {
    return vehicle->IsWheelBurst(wheelId);
}

void Vehicle_SetWheelBurst(alt::IVehicle* vehicle, uint8_t wheelId, uint8_t state) {
    vehicle->SetWheelBurst(wheelId, state);
}


uint8_t Vehicle_DoesWheelHasTire(alt::IVehicle* vehicle, uint8_t wheelId) {
    return vehicle->DoesWheelHasTire(wheelId);
}

void Vehicle_SetWheelHasTire(alt::IVehicle* vehicle, uint8_t wheelId, uint8_t state) {
    vehicle->SetWheelHasTire(wheelId, state);
}


uint8_t Vehicle_IsWheelDetached(alt::IVehicle* vehicle, uint8_t wheelId) {
    return vehicle->IsWheelDetached(wheelId);
}

void Vehicle_SetWheelDetached(alt::IVehicle* vehicle, uint8_t wheelId, uint8_t state) {
    vehicle->SetWheelDetached(wheelId, state);
}


uint8_t Vehicle_IsWheelOnFire(alt::IVehicle* vehicle, uint8_t wheelId) {
    return vehicle->IsWheelOnFire(wheelId);
}

void Vehicle_SetWheelOnFire(alt::IVehicle* vehicle, uint8_t wheelId, uint8_t state) {
    vehicle->SetWheelOnFire(wheelId, state);
}


float Vehicle_GetWheelHealth(alt::IVehicle* vehicle, uint8_t wheelId) {
    return vehicle->GetWheelHealth(wheelId);
}

void Vehicle_SetWheelHealth(alt::IVehicle* vehicle, uint8_t wheelId, float health) {
    vehicle->SetWheelHealth(wheelId, health);
}


void Vehicle_SetWheelFixed(alt::IVehicle* vehicle, uint8_t wheelId) {
    vehicle->SetWheelFixed(wheelId);
}


uint8_t Vehicle_GetRepairsCount(alt::IVehicle* vehicle) {
    return vehicle->GetRepairsCount();
}


uint32_t Vehicle_GetBodyHealth(alt::IVehicle* vehicle) {
    return vehicle->GetBodyHealth();
}


void Vehicle_SetBodyHealth(alt::IVehicle* vehicle, uint32_t health) {
    vehicle->SetBodyHealth(health);
}

uint32_t Vehicle_GetBodyAdditionalHealth(alt::IVehicle* vehicle) {
    return vehicle->GetBodyAdditionalHealth();
}

void Vehicle_SetBodyAdditionalHealth(alt::IVehicle* vehicle, uint32_t health) {
    vehicle->SetBodyAdditionalHealth(health);
}


const char* Vehicle_GetHealthDataBase64(alt::IVehicle* vehicle, int32_t& size) {
    return AllocateString(vehicle->GetHealthDataBase64(), size);
}

void Vehicle_LoadHealthDataFromBase64(alt::IVehicle* vehicle, const char* base64) {
    vehicle->LoadHealthDataFromBase64(base64);
}

uint8_t Vehicle_GetPartDamageLevel(alt::IVehicle* vehicle, uint8_t partId) {
    return vehicle->GetPartDamageLevel(partId);
}

void Vehicle_SetPartDamageLevel(alt::IVehicle* vehicle, uint8_t partId, uint8_t damage) {
    vehicle->SetPartDamageLevel(partId, damage);
}

uint8_t Vehicle_GetPartBulletHoles(alt::IVehicle* vehicle, uint8_t partId) {
    return vehicle->GetPartBulletHoles(partId);
}

void Vehicle_SetPartBulletHoles(alt::IVehicle* vehicle, uint8_t partId, uint8_t shootsCount) {
    vehicle->SetPartBulletHoles(partId, shootsCount);
}

uint8_t Vehicle_IsLightDamaged(alt::IVehicle* vehicle, uint8_t lightId) {
    return vehicle->IsLightDamaged(lightId);
}

void Vehicle_SetLightDamaged(alt::IVehicle* vehicle, uint8_t lightId, uint8_t isDamaged) {
    vehicle->SetLightDamaged(lightId, isDamaged);
}

uint8_t Vehicle_IsWindowDamaged(alt::IVehicle* vehicle, uint8_t windowId) {
    return vehicle->IsWindowDamaged(windowId);
}

void Vehicle_SetWindowDamaged(alt::IVehicle* vehicle, uint8_t windowId, uint8_t isDamaged) {
    vehicle->SetWindowDamaged(windowId, isDamaged);
}

uint8_t Vehicle_IsSpecialLightDamaged(alt::IVehicle* vehicle, uint8_t specialLightId) {
    return vehicle->IsSpecialLightDamaged(specialLightId);
}

void Vehicle_SetSpecialLightDamaged(alt::IVehicle* vehicle, uint8_t specialLightId, uint8_t isDamaged) {
    vehicle->SetSpecialLightDamaged(specialLightId, isDamaged);
}

uint8_t Vehicle_HasArmoredWindows(alt::IVehicle* vehicle) {
    return vehicle->HasArmoredWindows();
}

float Vehicle_GetArmoredWindowHealth(alt::IVehicle* vehicle, uint8_t windowId) {
    return vehicle->GetArmoredWindowHealth(windowId);
}

void Vehicle_SetArmoredWindowHealth(alt::IVehicle* vehicle, uint8_t windowId, float health) {
    vehicle->SetArmoredWindowHealth(windowId, health);
}

uint8_t Vehicle_GetArmoredWindowShootCount(alt::IVehicle* vehicle, uint8_t windowId) {
    return vehicle->GetArmoredWindowShootCount(windowId);
}

void Vehicle_SetArmoredWindowShootCount(alt::IVehicle* vehicle, uint8_t windowId, uint8_t count) {
    vehicle->SetArmoredWindowShootCount(windowId, count);
}

uint8_t Vehicle_GetBumperDamageLevel(alt::IVehicle* vehicle, uint8_t bumperId) {
    return vehicle->GetBumperDamageLevel(bumperId);
}

void Vehicle_SetBumperDamageLevel(alt::IVehicle* vehicle, uint8_t bumperId, uint8_t damageLevel) {
    vehicle->SetBumperDamageLevel(bumperId, damageLevel);
}

const char* Vehicle_GetDamageDataBase64(alt::IVehicle* vehicle, int32_t& size) {
    return AllocateString(vehicle->GetDamageDataBase64(), size);
}

void Vehicle_LoadDamageDataFromBase64(alt::IVehicle* vehicle, const char* base64) {
    vehicle->LoadDamageDataFromBase64(base64);
}


void Vehicle_SetManualEngineControl(alt::IVehicle* vehicle, uint8_t state) {
    vehicle->SetManualEngineControl(state);
}

uint8_t Vehicle_IsManualEngineControl(alt::IVehicle* vehicle) {
    return vehicle->IsManualEngineControl();
}


const char* Vehicle_GetScriptDataBase64(alt::IVehicle* vehicle, int32_t& size) {
    return AllocateString(vehicle->GetScriptDataBase64(), size);
}

void Vehicle_LoadScriptDataFromBase64(alt::IVehicle* vehicle, const char* base64) {
    vehicle->LoadScriptDataFromBase64(base64);
}


alt::IVehicle* Vehicle_GetAttached(alt::IVehicle* vehicle) {
    return vehicle->GetAttached();
}

alt::IVehicle* Vehicle_GetAttachedTo(alt::IVehicle* vehicle) {
    return vehicle->GetAttachedTo();
}


void Vehicle_Repair(alt::IVehicle* vehicle) {
    vehicle->SetFixed();
}

void Vehicle_GetVelocity(alt::IVehicle* vehicle, position_t &velocity) {
    auto vehicleVelocity = vehicle->GetVelocity();
    velocity.x = vehicleVelocity[0];
    velocity.y = vehicleVelocity[1];
    velocity.z = vehicleVelocity[2];
}


void Vehicle_SetDriftMode(alt::IVehicle* vehicle, uint8_t state) {
    vehicle->SetDriftMode(state);
}

uint8_t Vehicle_IsDriftMode(alt::IVehicle* vehicle) {
    return vehicle->IsDriftMode();
}


uint8_t Vehicle_SetSearchLight(alt::IVehicle* vehicle, uint8_t state, alt::IEntity* spottedEntity) {
    return vehicle->SetSearchLight(state, spottedEntity);
}


uint8_t Vehicle_IsTrainMissionTrain(alt::IVehicle* vehicle) {
    return vehicle->IsTrainMissionTrain();
}

void Vehicle_SetTrainMissionTrain(alt::IVehicle* vehicle, uint8_t state) {
    vehicle->SetTrainMissionTrain(state);
}

int8_t Vehicle_GetTrainTrackId(alt::IVehicle* vehicle) {
    return vehicle->GetTrainTrackId();
}

void Vehicle_SetTrainTrackId(alt::IVehicle* vehicle, int8_t trackId) {
    vehicle->SetTrainTrackId(trackId);
}

alt::IVehicle* Vehicle_GetTrainEngineId(alt::IVehicle* vehicle) {
    return vehicle->GetTrainEngineId();
}

void Vehicle_SetTrainEngineId(alt::IVehicle* vehicle, alt::IVehicle* entity) {
    vehicle->SetTrainEngineId(entity);
}

int8_t Vehicle_GetTrainConfigIndex(alt::IVehicle* vehicle) {
    return vehicle->GetTrainConfigIndex();
}

void Vehicle_SetTrainConfigIndex(alt::IVehicle* vehicle, int8_t index) {
    vehicle->SetTrainConfigIndex(index);
}

float Vehicle_GetTrainDistanceFromEngine(alt::IVehicle* vehicle) {
    return vehicle->GetTrainDistanceFromEngine();
}

void Vehicle_SetTrainDistanceFromEngine(alt::IVehicle* vehicle, float distanceFromEngine) {
    vehicle->SetTrainDistanceFromEngine(distanceFromEngine);
}

uint8_t Vehicle_IsTrainEngine(alt::IVehicle* vehicle) {
    return vehicle->IsTrainEngine();
}

void Vehicle_SetTrainIsEngine(alt::IVehicle* vehicle, uint8_t state) {
    vehicle->SetTrainIsEngine(state);
}

uint8_t Vehicle_IsTrainCaboose(alt::IVehicle* vehicle) {
    return vehicle->IsTrainCaboose();
}

void Vehicle_SetTrainIsCaboose(alt::IVehicle* vehicle, uint8_t isCaboose) {
    vehicle->SetTrainIsCaboose(isCaboose);
}

uint8_t Vehicle_GetTrainDirection(alt::IVehicle* vehicle) {
    return vehicle->GetTrainDirection();
}

void Vehicle_SetTrainDirection(alt::IVehicle* vehicle, uint8_t direction) {
    vehicle->SetTrainDirection(direction);
}

uint8_t Vehicle_HasTrainPassengerCarriages(alt::IVehicle* vehicle) {
    return vehicle->HasTrainPassengerCarriages();
}

void Vehicle_SetTrainHasPassengerCarriages(alt::IVehicle* vehicle, uint8_t hasPassengerCarriages) {
    vehicle->SetTrainHasPassengerCarriages(hasPassengerCarriages);
}

uint8_t Vehicle_GetTrainRenderDerailed(alt::IVehicle* vehicle) {
    return vehicle->GetTrainRenderDerailed();
}

void Vehicle_SetTrainRenderDerailed(alt::IVehicle* vehicle, uint8_t renderDerailed) {
    vehicle->SetTrainRenderDerailed(renderDerailed);
}

uint8_t Vehicle_GetTrainForceDoorsOpen(alt::IVehicle* vehicle) {
    return vehicle->GetTrainForceDoorsOpen();
}

void Vehicle_SetTrainForceDoorsOpen(alt::IVehicle* vehicle, uint8_t forceDoorsOpen) {
    vehicle->SetTrainForceDoorsOpen(forceDoorsOpen);
}

float Vehicle_GetTrainCruiseSpeed(alt::IVehicle* vehicle) {
    return vehicle->GetTrainCruiseSpeed();
}

void Vehicle_SetTrainCruiseSpeed(alt::IVehicle* vehicle, float cruiseSpeed) {
    vehicle->SetTrainCruiseSpeed(cruiseSpeed);
}

int8_t Vehicle_GetTrainCarriageConfigIndex(alt::IVehicle* vehicle) {
    return vehicle->GetTrainCarriageConfigIndex();
}

void Vehicle_SetTrainCarriageConfigIndex(alt::IVehicle* vehicle, int8_t carriageConfigIndex) {
    vehicle->SetTrainCarriageConfigIndex(carriageConfigIndex);
}

alt::IVehicle* Vehicle_GetTrainLinkedToBackwardId(alt::IVehicle* vehicle) {
    return vehicle->GetTrainLinkedToBackwardId();
}

void Vehicle_SetTrainLinkedToBackwardId(alt::IVehicle* vehicle, alt::IVehicle* entity) {
    vehicle->SetTrainLinkedToBackwardId(entity);
}

alt::IVehicle* Vehicle_GetTrainLinkedToForwardId(alt::IVehicle* vehicle) {
    return vehicle->GetTrainLinkedToForwardId();
}

void Vehicle_SetTrainLinkedToForwardId(alt::IVehicle* vehicle, alt::IVehicle* entity) {
    vehicle->SetTrainLinkedToForwardId(vehicle);
}

uint8_t Vehicle_GetBoatAnchor(alt::IVehicle* vehicle) {
  return vehicle->IsBoatAnchorActive();
}

void Vehicle_SetBoatAnchor(alt::IVehicle* vehicle, uint8_t state) {
  vehicle->SetBoatAnchorActive(state);
}


uint8_t Vehicle_GetLightState(alt::IVehicle* vehicle) {
    return vehicle->GetLightState();
}

void Vehicle_SetLightState(alt::IVehicle* vehicle, uint8_t value) {
    vehicle->SetLightState(value);
}

uint8_t Vehicle_HasTimedExplosion(alt::IVehicle* vehicle) {
    return vehicle->HasTimedExplosion();
}

alt::IPlayer* Vehicle_GetTimedExplosionCulprit(alt::IVehicle* vehicle) {
    return vehicle->GetTimedExplosionCulprit();
}

uint32_t Vehicle_GetTimedExplosionTime(alt::IVehicle* vehicle) {
    return vehicle->GetTimedExplosionTime();
}

void Vehicle_SetTimedExplosion(alt::IVehicle* vehicle, uint8_t state, alt::IPlayer* culprit, uint32_t time) {
    vehicle->SetTimedExplosion(state, culprit, time);
}

uint8_t Vehicle_IsTowingDisabled(alt::IVehicle* vehicle) {
    return vehicle->IsTowingDisabled();
}

void Vehicle_SetDisableTowing(alt::IVehicle* vehicle, uint8_t state) {
    vehicle->SetDisableTowing(state);
}

float Vehicle_GetRocketRefuelSpeed(alt::IVehicle* vehicle) {
    return vehicle->GetRocketRefuelSpeed();
}

void Vehicle_SetRocketRefuelSpeed(alt::IVehicle* vehicle, float rocketRefuleSpeed) {
    vehicle->SetRocketRefuelSpeed(rocketRefuleSpeed);
}

uint32_t Vehicle_GetCounterMeasureCount(alt::IVehicle* vehicle) {
    return vehicle->GetCounterMeasureCount();
}

void Vehicle_SetCounterMeasureCount(alt::IVehicle* vehicle, uint32_t counterMeasureCount) {
    vehicle->SetCounterMeasureCount(counterMeasureCount);
}

float Vehicle_GetScriptMaxSpeed(alt::IVehicle* vehicle) {
    return vehicle->GetScriptMaxSpeed();
}

void Vehicle_SetScriptMaxSpeed(alt::IVehicle* vehicle, float scriptMaxSpeed) {
    vehicle->SetScriptMaxSpeed(scriptMaxSpeed);
}

int32_t Vehicle_GetWeaponCapacity(alt::IVehicle* vehicle, uint8_t index) {
    return vehicle->GetWeaponCapacity(index);
}

void Vehicle_SetWeaponCapacity(alt::IVehicle* vehicle, uint8_t index, int32_t state) {
    vehicle->SetWeaponCapacity(index, state);
}

uint8_t Vehicle_GetHybridExtraActive(alt::IVehicle* vehicle) {
    return vehicle->GetHybridExtraActive();
}

void Vehicle_SetHybridExtraActive(alt::IVehicle* vehicle, uint8_t state) {
    vehicle->SetHybridExtraActive(state);
}

uint8_t Vehicle_GetHybridExtraState(alt::IVehicle* vehicle) {
    return vehicle->GetHybridExtraState();
}

void Vehicle_SetHybridExtraState(alt::IVehicle* vehicle, uint8_t state) {
    vehicle->SetHybridExtraState(state);
}

alt::Quaternion Vehicle_GetQuaternion(alt::IVehicle* vehicle)
{
    return vehicle->GetQuaternion();
}

void Vehicle_SetQuaternion(alt::IVehicle* vehicle, alt::Quaternion quaternion)
{
    vehicle->SetQuaternion(quaternion);
}

uint8_t Vehicle_IsHornActive(alt::IVehicle* vehicle)
{
    return vehicle->IsHornActive();
}

float Vehicle_GetAccelerationLevel(alt::IVehicle* vehicle)
{
    return vehicle->GetAccelerationLevel();
}

float Vehicle_GetBrakeLevel(alt::IVehicle* vehicle)
{
    return vehicle->GetBrakeLevel();
}

void Vehicle_SetBadge(alt::IVehicle* vehicle, uint32_t textureDictionary, uint32_t texture,
                      vehicleBadgePosition_t vehicleBadgePosition[], uint16_t size)
{
    const auto altVehicleBadgePositions = new alt::VehicleBadgePosition[4];

    for (int i = 0; i < size; ++i)
    {
        auto offset = vehicleBadgePosition[i].offset;
        auto direction = vehicleBadgePosition[i].direction;
        auto side = vehicleBadgePosition[i].side;

        altVehicleBadgePositions[i] = alt::VehicleBadgePosition(
            vehicleBadgePosition[i].alpha,
            vehicleBadgePosition[i].size,
            vehicleBadgePosition[i].boneIndex,
            alt::Vector3f(offset.x, offset.y, offset.z),
            alt::Vector3f(direction.x, direction.y, direction.z),
            alt::Vector3f(side.x, side.y, side.z)
        );

        altVehicleBadgePositions[i].active = vehicleBadgePosition[i].active;
    }

    if (size < 4)
    {
        for (int i = size; i < 4; ++i)
        {
            altVehicleBadgePositions[i] = alt::VehicleBadgePosition();
        }
    }

    vehicle->SetBadge(textureDictionary, texture, altVehicleBadgePositions);
}

#endif

#ifdef ALT_CLIENT_API
uint16_t Vehicle_GetCurrentGear(alt::IVehicle* vehicle)
{
    return vehicle->GetCurrentGear();
}

void Vehicle_SetCurrentGear(alt::IVehicle* vehicle, uint16_t value) {
    vehicle->SetCurrentGear(value);
}

uint8_t Vehicle_GetLightsIndicator(alt::IVehicle* vehicle) {
    return vehicle->GetLightsIndicator();
}

void Vehicle_SetLightsIndicator(alt::IVehicle* vehicle, uint8_t value) {
    vehicle->SetLightsIndicator(value);
}

uint16_t Vehicle_GetMaxGear(alt::IVehicle* vehicle) {
    return vehicle->GetMaxGear();
}

void Vehicle_SetSteeringAngle(alt::IVehicle* vehicle, float value)
{
    vehicle->SetSteeringAngle(value);
}

void Vehicle_SetMaxGear(alt::IVehicle* vehicle, uint16_t value) {
    vehicle->SetMaxGear(value);
}

float Vehicle_GetCurrentRPM(alt::IVehicle* vehicle) {
    return vehicle->GetCurrentRPM();
}

void Vehicle_SetCurrentRPM(alt::IVehicle* vehicle, float rpm) {
    vehicle->SetCurrentRPM(rpm);
}

uint8_t Vehicle_GetSeatCount(alt::IVehicle* vehicle) {
    return vehicle->GetSeatCount();
}

void Vehicle_ToggleTaxiLight(alt::IVehicle* vehicle, uint8_t state) {
    vehicle->ToggleTaxiLight(state);
}

uint8_t Vehicle_IsTaxiLightOn(alt::IVehicle* vehicle) {
    return vehicle->IsTaxiLightOn();
}

float Vehicle_GetWheelCamber(alt::IVehicle* vehicle, uint8_t wheel) {
    return vehicle->GetWheelCamber(wheel);
}

void Vehicle_SetWheelCamber(alt::IVehicle* vehicle, uint8_t wheel, float value) {
    vehicle->SetWheelCamber(wheel, value);
}

float Vehicle_GetWheelTrackWidth(alt::IVehicle* vehicle, uint8_t wheel) {
    return vehicle->GetWheelTrackWidth(wheel);
}

void Vehicle_SetWheelTrackWidth(alt::IVehicle* vehicle, uint8_t wheel, float value) {
    vehicle->SetWheelTrackWidth(wheel, value);
}

float Vehicle_GetWheelHeight(alt::IVehicle* vehicle, uint8_t wheel) {
    return vehicle->GetWheelHeight(wheel);
}

void Vehicle_SetWheelHeight(alt::IVehicle* vehicle, uint8_t wheel, float value) {
    vehicle->SetWheelHeight(wheel, value);
}

float Vehicle_GetWheelTyreRadius(alt::IVehicle* vehicle, uint8_t wheel) {
    return vehicle->GetWheelTyreRadius(wheel);
}

void Vehicle_SetWheelTyreRadius(alt::IVehicle* vehicle, uint8_t wheel, float value) {
    vehicle->SetWheelTyreRadius(wheel, value);
}

float Vehicle_GetWheelRimRadius(alt::IVehicle* vehicle, uint8_t wheel) {
    return vehicle->GetWheelRimRadius(wheel);
}

void Vehicle_SetWheelRimRadius(alt::IVehicle* vehicle, uint8_t wheel, float value) {
    vehicle->SetWheelRimRadius(wheel, value);
}

float Vehicle_GetWheelTyreWidth(alt::IVehicle* vehicle, uint8_t wheel) {
    return vehicle->GetWheelTyreWidth(wheel);
}

void Vehicle_SetWheelTyreWidth(alt::IVehicle* vehicle, uint8_t wheel, float value) {
    vehicle->SetWheelTyreWidth(wheel, value);
}

uint32_t Vehicle_GetWheelSurfaceMaterial(alt::IVehicle* vehicle, uint8_t wheel) {
    return vehicle->GetWheelSurfaceMaterial(wheel);
}

uint8_t Vehicle_GetOccupiedSeatsCount(alt::IVehicle* vehicle) {
    return vehicle->GetOccupiedSeatsCount();
}

float Vehicle_GetWheelSpeed(alt::IVehicle* vehicle) {
    return vehicle->GetWheelSpeed();
}

void Vehicle_GetSpeedVector(alt::IVehicle* vehicle, vector3_t& vector) {
    auto speed = vehicle->GetSpeedVector();
    vector.x = speed[0];
    vector.y = speed[1];
    vector.z = speed[2];
}

float Vehicle_GetEngineTemperature(alt::IVehicle* vehicle) {
    return vehicle->GetEngineTemperature();
}

float Vehicle_GetFuelLevel(alt::IVehicle* vehicle) {
    return vehicle->GetFuelLevel();
}

float Vehicle_GetOilLevel(alt::IVehicle* vehicle) {
    return vehicle->GetOilLevel();
}

void Vehicle_SetEngineTemperature(alt::IVehicle* vehicle, float value) {
    vehicle->SetEngineTemperature(value);
}

void Vehicle_SetFuelLevel(alt::IVehicle* vehicle, float value) {
    vehicle->SetFuelLevel(value);
}

void Vehicle_SetOilLevel(alt::IVehicle* vehicle, float value) {
    vehicle->SetOilLevel(value);
}

uint8_t Vehicle_GetEngineLightState(alt::IVehicle* vehicle) {
    return vehicle->GetEngineLightState();
}

void Vehicle_SetEngineLightState(alt::IVehicle* vehicle, uint8_t state) {
    vehicle->SetEngineLightState(state);
}

uint8_t Vehicle_GetAbsLightState(alt::IVehicle* vehicle) {
    return vehicle->GetAbsLightState();
}

void Vehicle_SetAbsLightState(alt::IVehicle* vehicle, uint8_t state) {
    vehicle->SetAbsLightState(state);
}

uint8_t Vehicle_GetPetrolLightState(alt::IVehicle* vehicle) {
    return vehicle->GetPetrolLightState();
}

void Vehicle_SetPetrolLightState(alt::IVehicle* vehicle, uint8_t state) {
    vehicle->SetPetrolLightState(state);
}

uint8_t Vehicle_GetOilLightState(alt::IVehicle* vehicle) {
    return vehicle->GetOilLightState();
}

void Vehicle_SetOilLightState(alt::IVehicle* vehicle, uint8_t state) {
    vehicle->SetOilLightState(state);
}

uint8_t Vehicle_GetBatteryLightState(alt::IVehicle* vehicle) {
    return vehicle->GetBatteryLightState();
}

void Vehicle_SetBatteryLightState(alt::IVehicle* vehicle, uint8_t state) {
    vehicle->SetBatteryLightState(state);
}

void Vehicle_ResetDashboardLights(alt::IVehicle* vehicle) {
    vehicle->ResetDashboardLights();
}

float Vehicle_GetSuspensionHeight(alt::IVehicle* vehicle)
{
    return vehicle->GetSuspensionHeight();
}

void Vehicle_SetSuspensionHeight(alt::IVehicle* vehicle, float value)
{
    vehicle->SetSuspensionHeight(value);
}

void Vehicle_ResetHandling(alt::IVehicle* vehicle) {
    vehicle->ResetHandling();
}

uint8_t Vehicle_IsHandlingModified(alt::IVehicle* vehicle) {
    return vehicle->IsHandlingModified();
}

uint32_t Vehicle_Handling_GetHandlingNameHash(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetHandlingNameHash();
}

float Vehicle_Handling_GetMass(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetMass();
}

void Vehicle_Handling_SetMass(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetMass(value);
}

float Vehicle_Handling_GetInitialDragCoeff(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetInitialDragCoeff();
}

void Vehicle_Handling_SetInitialDragCoeff(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetInitialDragCoeff(value);
}

float Vehicle_Handling_GetDownforceModifier(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetDownforceModifier();
}

void Vehicle_Handling_SetDownforceModifier(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetDownforceModifier(value);
}

float Vehicle_Handling_GetunkFloat1(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetunkFloat1();
}

void Vehicle_Handling_SetunkFloat1(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetunkFloat1(value);
}

float Vehicle_Handling_GetunkFloat2(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetunkFloat2();
}

void Vehicle_Handling_SetunkFloat2(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetunkFloat2(value);
}

void Vehicle_Handling_GetCentreOfMassOffset(alt::IVehicle* vehicle, vector3_t& offset) {
    auto vector = vehicle->GetHandling()->GetCentreOfMassOffset();
    offset.x = vector[0];
    offset.y = vector[1];
    offset.z = vector[2];
}

void Vehicle_Handling_SetCentreOfMassOffset(alt::IVehicle* vehicle, vector3_t value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetCentreOfMassOffset(alt::Vector3f(value.x, value.y, value.z));
}

void Vehicle_Handling_GetInertiaMultiplier(alt::IVehicle* vehicle, vector3_t& offset) {
    auto vector = vehicle->GetHandling()->GetInertiaMultiplier();
    offset.x = vector[0];
    offset.y = vector[1];
    offset.z = vector[2];
}

void Vehicle_Handling_SetInertiaMultiplier(alt::IVehicle* vehicle, vector3_t value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetInertiaMultiplier(alt::Vector3f(value.x, value.y, value.z));
}

float Vehicle_Handling_GetPercentSubmerged(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetPercentSubmerged();
}

void Vehicle_Handling_SetPercentSubmerged(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetPercentSubmerged(value);
}

float Vehicle_Handling_GetPercentSubmergedRatio(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetPercentSubmergedRatio();
}

void Vehicle_Handling_SetPercentSubmergedRatio(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetPercentSubmergedRatio(value);
}

float Vehicle_Handling_GetDriveBiasFront(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetDriveBiasFront();
}

void Vehicle_Handling_SetDriveBiasFront(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetDriveBiasFront(value);
}

float Vehicle_Handling_GetAcceleration(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetAcceleration();
}

void Vehicle_Handling_SetAcceleration(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetAcceleration(value);
}

uint32_t Vehicle_Handling_GetInitialDriveGears(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetInitialDriveGears();
}

void Vehicle_Handling_SetInitialDriveGears(alt::IVehicle* vehicle, uint32_t value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetInitialDriveGears(value);
}

float Vehicle_Handling_GetDriveInertia(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetDriveInertia();
}

void Vehicle_Handling_SetDriveInertia(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetDriveInertia(value);
}

float Vehicle_Handling_GetClutchChangeRateScaleUpShift(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetClutchChangeRateScaleUpShift();
}

void Vehicle_Handling_SetClutchChangeRateScaleUpShift(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetClutchChangeRateScaleUpShift(value);
}

float Vehicle_Handling_GetClutchChangeRateScaleDownShift(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetClutchChangeRateScaleDownShift();
}

void Vehicle_Handling_SetClutchChangeRateScaleDownShift(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetClutchChangeRateScaleDownShift(value);
}

float Vehicle_Handling_GetInitialDriveForce(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetInitialDriveForce();
}

void Vehicle_Handling_SetInitialDriveForce(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetInitialDriveForce(value);
}

float Vehicle_Handling_GetDriveMaxFlatVel(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetDriveMaxFlatVel();
}

void Vehicle_Handling_SetDriveMaxFlatVel(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetDriveMaxFlatVel(value);
}

float Vehicle_Handling_GetInitialDriveMaxFlatVel(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetInitialDriveMaxFlatVel();
}

void Vehicle_Handling_SetInitialDriveMaxFlatVel(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetInitialDriveMaxFlatVel(value);
}

float Vehicle_Handling_GetBrakeForce(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetBrakeForce();
}

void Vehicle_Handling_SetBrakeForce(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetBrakeForce(value);
}

float Vehicle_Handling_GetunkFloat4(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetunkFloat4();
}

void Vehicle_Handling_SetunkFloat4(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetunkFloat4(value);
}

float Vehicle_Handling_GetBrakeBiasFront(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetBrakeBiasFront();
}

void Vehicle_Handling_SetBrakeBiasFront(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetBrakeBiasFront(value);
}

float Vehicle_Handling_GetBrakeBiasRear(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetBrakeBiasRear();
}

void Vehicle_Handling_SetBrakeBiasRear(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetBrakeBiasRear(value);
}

float Vehicle_Handling_GetHandBrakeForce(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetHandBrakeForce();
}

void Vehicle_Handling_SetHandBrakeForce(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetHandBrakeForce(value);
}

float Vehicle_Handling_GetSteeringLock(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetSteeringLock();
}

void Vehicle_Handling_SetSteeringLock(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetSteeringLock(value);
}

float Vehicle_Handling_GetSteeringLockRatio(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetSteeringLockRatio();
}

void Vehicle_Handling_SetSteeringLockRatio(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetSteeringLockRatio(value);
}

float Vehicle_Handling_GetTractionCurveMax(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetTractionCurveMax();
}

void Vehicle_Handling_SetTractionCurveMax(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetTractionCurveMax(value);
}

float Vehicle_Handling_GetTractionCurveMaxRatio(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetTractionCurveMaxRatio();
}

void Vehicle_Handling_SetTractionCurveMaxRatio(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetTractionCurveMaxRatio(value);
}

float Vehicle_Handling_GetTractionCurveMin(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetTractionCurveMin();
}

void Vehicle_Handling_SetTractionCurveMin(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetTractionCurveMin(value);
}

float Vehicle_Handling_GetTractionCurveMinRatio(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetTractionCurveMinRatio();
}

void Vehicle_Handling_SetTractionCurveMinRatio(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetTractionCurveMinRatio(value);
}

float Vehicle_Handling_GetTractionCurveLateral(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetTractionCurveLateral();
}

void Vehicle_Handling_SetTractionCurveLateral(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetTractionCurveLateral(value);
}

float Vehicle_Handling_GetTractionCurveLateralRatio(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetTractionCurveLateralRatio();
}

void Vehicle_Handling_SetTractionCurveLateralRatio(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetTractionCurveLateralRatio(value);
}

float Vehicle_Handling_GetTractionSpringDeltaMax(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetTractionSpringDeltaMax();
}

void Vehicle_Handling_SetTractionSpringDeltaMax(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetTractionSpringDeltaMax(value);
}

float Vehicle_Handling_GetTractionSpringDeltaMaxRatio(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetTractionSpringDeltaMaxRatio();
}

void Vehicle_Handling_SetTractionSpringDeltaMaxRatio(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetTractionSpringDeltaMaxRatio(value);
}

float Vehicle_Handling_GetLowSpeedTractionLossMult(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetLowSpeedTractionLossMult();
}

void Vehicle_Handling_SetLowSpeedTractionLossMult(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetLowSpeedTractionLossMult(value);
}

float Vehicle_Handling_GetCamberStiffness(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetCamberStiffness();
}

void Vehicle_Handling_SetCamberStiffness(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetCamberStiffness(value);
}

float Vehicle_Handling_GetTractionBiasFront(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetTractionBiasFront();
}

void Vehicle_Handling_SetTractionBiasFront(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetTractionBiasFront(value);
}

float Vehicle_Handling_GetTractionBiasRear(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetTractionBiasRear();
}

void Vehicle_Handling_SetTractionBiasRear(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetTractionBiasRear(value);
}

float Vehicle_Handling_GetTractionLossMult(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetTractionLossMult();
}

void Vehicle_Handling_SetTractionLossMult(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetTractionLossMult(value);
}

float Vehicle_Handling_GetSuspensionForce(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetSuspensionForce();
}

void Vehicle_Handling_SetSuspensionForce(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetSuspensionForce(value);
}

float Vehicle_Handling_GetSuspensionCompDamp(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetSuspensionCompDamp();
}

void Vehicle_Handling_SetSuspensionCompDamp(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetSuspensionCompDamp(value);
}

float Vehicle_Handling_GetSuspensionReboundDamp(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetSuspensionReboundDamp();
}

void Vehicle_Handling_SetSuspensionReboundDamp(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetSuspensionReboundDamp(value);
}

float Vehicle_Handling_GetSuspensionUpperLimit(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetSuspensionUpperLimit();
}

void Vehicle_Handling_SetSuspensionUpperLimit(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetSuspensionUpperLimit(value);
}

float Vehicle_Handling_GetSuspensionLowerLimit(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetSuspensionLowerLimit();
}

void Vehicle_Handling_SetSuspensionLowerLimit(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetSuspensionLowerLimit(value);
}

float Vehicle_Handling_GetSuspensionRaise(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetSuspensionRaise();
}

void Vehicle_Handling_SetSuspensionRaise(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetSuspensionRaise(value);
}

float Vehicle_Handling_GetSuspensionBiasFront(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetSuspensionBiasFront();
}

void Vehicle_Handling_SetSuspensionBiasFront(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetSuspensionBiasFront(value);
}

float Vehicle_Handling_GetSuspensionBiasRear(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetSuspensionBiasRear();
}

void Vehicle_Handling_SetSuspensionBiasRear(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetSuspensionBiasRear(value);
}

float Vehicle_Handling_GetAntiRollBarForce(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetAntiRollBarForce();
}

void Vehicle_Handling_SetAntiRollBarForce(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetAntiRollBarForce(value);
}

float Vehicle_Handling_GetAntiRollBarBiasFront(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetAntiRollBarBiasFront();
}

void Vehicle_Handling_SetAntiRollBarBiasFront(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetAntiRollBarBiasFront(value);
}

float Vehicle_Handling_GetAntiRollBarBiasRear(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetAntiRollBarBiasRear();
}

void Vehicle_Handling_SetAntiRollBarBiasRear(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetAntiRollBarBiasRear(value);
}

float Vehicle_Handling_GetRollCentreHeightFront(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetRollCentreHeightFront();
}

void Vehicle_Handling_SetRollCentreHeightFront(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetRollCentreHeightFront(value);
}

float Vehicle_Handling_GetRollCentreHeightRear(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetRollCentreHeightRear();
}

void Vehicle_Handling_SetRollCentreHeightRear(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetRollCentreHeightRear(value);
}

float Vehicle_Handling_GetCollisionDamageMult(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetCollisionDamageMult();
}

void Vehicle_Handling_SetCollisionDamageMult(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetCollisionDamageMult(value);
}

float Vehicle_Handling_GetWeaponDamageMult(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetWeaponDamageMult();
}

void Vehicle_Handling_SetWeaponDamageMult(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetWeaponDamageMult(value);
}

float Vehicle_Handling_GetDeformationDamageMult(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetDeformationDamageMult();
}

void Vehicle_Handling_SetDeformationDamageMult(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetDeformationDamageMult(value);
}

float Vehicle_Handling_GetEngineDamageMult(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetEngineDamageMult();
}

void Vehicle_Handling_SetEngineDamageMult(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetEngineDamageMult(value);
}

float Vehicle_Handling_GetPetrolTankVolume(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetPetrolTankVolume();
}

void Vehicle_Handling_SetPetrolTankVolume(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetPetrolTankVolume(value);
}

float Vehicle_Handling_GetOilVolume(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetOilVolume();
}

void Vehicle_Handling_SetOilVolume(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetOilVolume(value);
}

float Vehicle_Handling_GetunkFloat5(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetunkFloat5();
}

void Vehicle_Handling_SetunkFloat5(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetunkFloat5(value);
}

float Vehicle_Handling_GetSeatOffsetDistX(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetSeatOffsetDistX();
}

void Vehicle_Handling_SetSeatOffsetDistX(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetSeatOffsetDistX(value);
}

float Vehicle_Handling_GetSeatOffsetDistY(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetSeatOffsetDistY();
}

void Vehicle_Handling_SetSeatOffsetDistY(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetSeatOffsetDistY(value);
}

float Vehicle_Handling_GetSeatOffsetDistZ(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetSeatOffsetDistZ();
}

void Vehicle_Handling_SetSeatOffsetDistZ(alt::IVehicle* vehicle, float value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetSeatOffsetDistZ(value);
}

uint32_t Vehicle_Handling_GetMonetaryValue(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetMonetaryValue();
}

void Vehicle_Handling_SetMonetaryValue(alt::IVehicle* vehicle, uint32_t value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetMonetaryValue(value);
}

uint32_t Vehicle_Handling_GetModelFlags(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetModelFlags();
}

void Vehicle_Handling_SetModelFlags(alt::IVehicle* vehicle, uint32_t value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetModelFlags(value);
}

uint32_t Vehicle_Handling_GetHandlingFlags(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetHandlingFlags();
}

void Vehicle_Handling_SetHandlingFlags(alt::IVehicle* vehicle, uint32_t value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetHandlingFlags(value);
}

uint32_t Vehicle_Handling_GetDamageFlags(alt::IVehicle* vehicle) {
    return vehicle->GetHandling()->GetDamageFlags();
}

void Vehicle_Handling_SetDamageFlags(alt::IVehicle* vehicle, uint32_t value) {
    vehicle->ReplaceHandling();
    vehicle->GetHandling()->SetDamageFlags(value);
}

#endif

CAPI_END()