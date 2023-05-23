#include "local_vehicle.h"


#ifdef ALT_CLIENT_API
alt::IWorldObject* LocalVehicle_GetWorldObject(alt::ILocalVehicle* localVehicle)
{
    return dynamic_cast<alt::IWorldObject*>(localVehicle);
}

uint32_t LocalVehicle_GetID(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetID();
}

uint32_t LocalVehicle_GetModel(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetModel();
}

void LocalVehicle_SetModel(alt::ILocalVehicle* localVehicle, uint32_t model)
{
    localVehicle->SetModel(model);
}

void LocalVehicle_GetRotation(alt::ILocalVehicle* localVehicle, rotation_t& rot)
{
    auto localVehicleRotation = localVehicle->GetRotation();
    rot.roll = localVehicleRotation.roll;
    rot.pitch = localVehicleRotation.pitch;
    rot.yaw = localVehicleRotation.yaw;
}

void LocalVehicle_SetRotation(alt::ILocalVehicle* localVehicle, rotation_t rot)
{
    alt::Rotation localVehicleRot;
    localVehicleRot.roll = rot.roll;
    localVehicleRot.pitch = rot.pitch;
    localVehicleRot.yaw = rot.yaw;
    localVehicle->SetRotation(localVehicleRot);
}

uint32_t LocalVehicle_GetStreamingDistance(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetStreamingDistance();
}

void LocalVehicle_SetVisible(alt::ILocalVehicle* localVehicle, uint8_t toggle)
{
    localVehicle->SetVisible(toggle);
}

uint8_t LocalVehicle_IsVisible(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->IsVisible();
}

uint32_t LocalVehicle_GetScriptID(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetScriptID();
}

uint32_t LocalVehicle_GetRemoteID(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetRemoteID();
}

uint8_t LocalVehicle_IsRemote(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->IsRemote();
}

uint8_t LocalVehicle_IsStreamedIn(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->IsStreamedIn();
}

uint16_t LocalVehicle_GetCurrentGear(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetCurrentGear();
}

float LocalVehicle_GetWheelSpeed(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetWheelSpeed();
}

float LocalVehicle_GetCurrentRPM(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetCurrentRPM();
}

uint8_t LocalVehicle_GetWheelsCount(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetWheelsCount();
}

void LocalVehicle_GetSpeedVector(alt::ILocalVehicle* localVehicle, vector3_t& vector)
{
    auto speedVector = localVehicle->GetSpeedVector();
    vector.x = speedVector[0];
    vector.y = speedVector[1];
    vector.z = speedVector[2];
}

uint16_t LocalVehicle_GetMaxGear(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetMaxGear();
}

void LocalVehicle_SetCurrentGear(alt::ILocalVehicle* localVehicle, uint16_t currentGear)
{
    localVehicle->SetCurrentGear(currentGear);
}

void LocalVehicle_SetMaxGear(alt::ILocalVehicle* localVehicle, uint16_t gearMax)
{
    localVehicle->SetMaxGear(gearMax);
}

void LocalVehicle_SetCurrentRPM(alt::ILocalVehicle* localVehicle, float rpm)
{
    localVehicle->SetCurrentRPM(rpm);
}

uint8_t LocalVehicle_IsEngineOn(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->IsEngineOn();
}

uint8_t LocalVehicle_GetLockState(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetLockState();
}

int32_t LocalVehicle_GetPetrolTankHealth(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetPetrolTankHealth();
}

uint8_t LocalVehicle_IsHandlingModified(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->IsHandlingModified();
}

void LocalVehicle_ResetHandling(alt::ILocalVehicle* localVehicle)
{
    localVehicle->ResetHandling();
}

void LocalVehicle_ReplaceHandling(alt::ILocalVehicle* localVehicle)
{
    localVehicle->ReplaceHandling();
}

void LocalVehicle_ToggleExtra(alt::ILocalVehicle* localVehicle, uint8_t extraID, uint8_t state)
{
    localVehicle->ToggleExtra(extraID, state);
}

uint8_t LocalVehicle_GetLightsIndicator(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetLightsIndicator();
}

void LocalVehicle_SetLightsIndicator(alt::ILocalVehicle* localVehicle, uint8_t lightsIndicatorFlag)
{
    localVehicle->SetLightsIndicator(lightsIndicatorFlag);
}

uint8_t LocalVehicle_GetSeatCount(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetSeatCount();
}

uint8_t LocalVehicle_GetOccupiedSeatsCount(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetOccupiedSeatsCount();
}

void LocalVehicle_ToggleTaxiLight(alt::ILocalVehicle* localVehicle, uint8_t state)
{
    localVehicle->ToggleTaxiLight(state);
}

uint8_t LocalVehicle_IsTaxiLightOn(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->IsTaxiLightOn();
}

float LocalVehicle_GetWheelCamber(alt::ILocalVehicle* localVehicle, uint8_t wheel)
{
    return localVehicle->GetWheelCamber(wheel);
}

void LocalVehicle_SetWheelCamber(alt::ILocalVehicle* localVehicle, uint8_t wheel, float value)
{
    localVehicle->SetWheelCamber(wheel, value);
}

float LocalVehicle_GetWheelTrackWidth(alt::ILocalVehicle* localVehicle, uint8_t wheel)
{
    return localVehicle->GetWheelTrackWidth(wheel);
}

void LocalVehicle_SetWheelTrackWidth(alt::ILocalVehicle* localVehicle, uint8_t wheel, float value)
{
    localVehicle->SetWheelTrackWidth(wheel, value);
}

float LocalVehicle_GetWheelHeight(alt::ILocalVehicle* localVehicle, uint8_t wheel)
{
    return localVehicle->GetWheelHeight(wheel);
}

void LocalVehicle_SetWheelHeight(alt::ILocalVehicle* localVehicle, uint8_t wheel, float value)
{
    localVehicle->SetWheelHeight(wheel, value);
}

float LocalVehicle_GetWheelTyreRadius(alt::ILocalVehicle* localVehicle, uint8_t wheel)
{
    return localVehicle->GetWheelTyreRadius(wheel);
}

void LocalVehicle_SetWheelTyreRadius(alt::ILocalVehicle* localVehicle, uint8_t wheel, float value)
{
    localVehicle->SetWheelTyreRadius(wheel, value);
}

float LocalVehicle_GetWheelRimRadius(alt::ILocalVehicle* localVehicle, uint8_t wheel)
{
    return localVehicle->GetWheelRimRadius(wheel);
}

void LocalVehicle_SetWheelRimRadius(alt::ILocalVehicle* localVehicle, uint8_t wheel, float value)
{
    localVehicle->SetWheelRimRadius(wheel, value);
}

float LocalVehicle_GetWheelTyreWidth(alt::ILocalVehicle* localVehicle, uint8_t wheel)
{
    return localVehicle->GetWheelTyreWidth(wheel);
}

void LocalVehicle_SetWheelTyreWidth(alt::ILocalVehicle* localVehicle, uint8_t wheel, float value)
{
    localVehicle->SetWheelTyreWidth(wheel, value);
}

uint32_t LocalVehicle_GetWheelSurfaceMaterial(alt::ILocalVehicle* localVehicle, uint8_t wheel)
{
    return localVehicle->GetWheelSurfaceMaterial(wheel);
}

float LocalVehicle_GetEngineTemperature(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetEngineTemperature();
}

void LocalVehicle_SetEngineTemperature(alt::ILocalVehicle* localVehicle, float value)
{
    localVehicle->SetEngineTemperature(value);
}

float LocalVehicle_GetFuelLevel(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetFuelLevel();
}

void LocalVehicle_SetFuelLevel(alt::ILocalVehicle* localVehicle, float value)
{
    localVehicle->SetFuelLevel(value);
}

float LocalVehicle_GetOilLevel(alt::ILocalVehicle* localVehicle)
{
    return localVehicle->GetOilLevel();
}

void LocalVehicle_SetOilLevel(alt::ILocalVehicle* localVehicle, float value)
{
    localVehicle->SetOilLevel(value);
}

uint32_t LocalVehicle_Handling_GetHandlingNameHash(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetHandlingNameHash();
}

float LocalVehicle_Handling_GetMass(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetMass();
}

void LocalVehicle_Handling_SetMass(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetMass(value);
}

float LocalVehicle_Handling_GetInitialDragCoeff(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetInitialDragCoeff();
}

void LocalVehicle_Handling_SetInitialDragCoeff(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetInitialDragCoeff(value);
}

float LocalVehicle_Handling_GetDownforceModifier(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetDownforceModifier();
}

void LocalVehicle_Handling_SetDownforceModifier(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetDownforceModifier(value);
}

float LocalVehicle_Handling_GetunkFloat1(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetunkFloat1();
}

void LocalVehicle_Handling_SetunkFloat1(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetunkFloat1(value);
}

float LocalVehicle_Handling_GetunkFloat2(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetunkFloat2();
}

void LocalVehicle_Handling_SetunkFloat2(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetunkFloat2(value);
}

void LocalVehicle_Handling_GetCentreOfMassOffset(alt::ILocalVehicle* localVehicle, vector3_t& offset) {
    auto vector = localVehicle->GetHandling()->GetCentreOfMassOffset();
    offset.x = vector[0];
    offset.y = vector[1];
    offset.z = vector[2];
}

void LocalVehicle_Handling_SetCentreOfMassOffset(alt::ILocalVehicle* localVehicle, vector3_t value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetCentreOfMassOffset(alt::Vector3f(value.x, value.y, value.z));
}

void LocalVehicle_Handling_GetInertiaMultiplier(alt::ILocalVehicle* localVehicle, vector3_t& offset) {
    auto vector = localVehicle->GetHandling()->GetInertiaMultiplier();
    offset.x = vector[0];
    offset.y = vector[1];
    offset.z = vector[2];
}

void LocalVehicle_Handling_SetInertiaMultiplier(alt::ILocalVehicle* localVehicle, vector3_t value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetInertiaMultiplier(alt::Vector3f(value.x, value.y, value.z));
}

float LocalVehicle_Handling_GetPercentSubmerged(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetPercentSubmerged();
}

void LocalVehicle_Handling_SetPercentSubmerged(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetPercentSubmerged(value);
}

float LocalVehicle_Handling_GetPercentSubmergedRatio(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetPercentSubmergedRatio();
}

void LocalVehicle_Handling_SetPercentSubmergedRatio(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetPercentSubmergedRatio(value);
}

float LocalVehicle_Handling_GetDriveBiasFront(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetDriveBiasFront();
}

void LocalVehicle_Handling_SetDriveBiasFront(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetDriveBiasFront(value);
}

float LocalVehicle_Handling_GetAcceleration(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetAcceleration();
}

void LocalVehicle_Handling_SetAcceleration(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetAcceleration(value);
}

uint32_t LocalVehicle_Handling_GetInitialDriveGears(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetInitialDriveGears();
}

void LocalVehicle_Handling_SetInitialDriveGears(alt::ILocalVehicle* localVehicle, uint32_t value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetInitialDriveGears(value);
}

float LocalVehicle_Handling_GetDriveInertia(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetDriveInertia();
}

void LocalVehicle_Handling_SetDriveInertia(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetDriveInertia(value);
}

float LocalVehicle_Handling_GetClutchChangeRateScaleUpShift(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetClutchChangeRateScaleUpShift();
}

void LocalVehicle_Handling_SetClutchChangeRateScaleUpShift(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetClutchChangeRateScaleUpShift(value);
}

float LocalVehicle_Handling_GetClutchChangeRateScaleDownShift(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetClutchChangeRateScaleDownShift();
}

void LocalVehicle_Handling_SetClutchChangeRateScaleDownShift(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetClutchChangeRateScaleDownShift(value);
}

float LocalVehicle_Handling_GetInitialDriveForce(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetInitialDriveForce();
}

void LocalVehicle_Handling_SetInitialDriveForce(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetInitialDriveForce(value);
}

float LocalVehicle_Handling_GetDriveMaxFlatVel(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetDriveMaxFlatVel();
}

void LocalVehicle_Handling_SetDriveMaxFlatVel(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetDriveMaxFlatVel(value);
}

float LocalVehicle_Handling_GetInitialDriveMaxFlatVel(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetInitialDriveMaxFlatVel();
}

void LocalVehicle_Handling_SetInitialDriveMaxFlatVel(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetInitialDriveMaxFlatVel(value);
}

float LocalVehicle_Handling_GetBrakeForce(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetBrakeForce();
}

void LocalVehicle_Handling_SetBrakeForce(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetBrakeForce(value);
}

float LocalVehicle_Handling_GetunkFloat4(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetunkFloat4();
}

void LocalVehicle_Handling_SetunkFloat4(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetunkFloat4(value);
}

float LocalVehicle_Handling_GetBrakeBiasFront(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetBrakeBiasFront();
}

void LocalVehicle_Handling_SetBrakeBiasFront(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetBrakeBiasFront(value);
}

float LocalVehicle_Handling_GetBrakeBiasRear(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetBrakeBiasRear();
}

void LocalVehicle_Handling_SetBrakeBiasRear(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetBrakeBiasRear(value);
}

float LocalVehicle_Handling_GetHandBrakeForce(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetHandBrakeForce();
}

void LocalVehicle_Handling_SetHandBrakeForce(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetHandBrakeForce(value);
}

float LocalVehicle_Handling_GetSteeringLock(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetSteeringLock();
}

void LocalVehicle_Handling_SetSteeringLock(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetSteeringLock(value);
}

float LocalVehicle_Handling_GetSteeringLockRatio(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetSteeringLockRatio();
}

void LocalVehicle_Handling_SetSteeringLockRatio(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetSteeringLockRatio(value);
}

float LocalVehicle_Handling_GetTractionCurveMax(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetTractionCurveMax();
}

void LocalVehicle_Handling_SetTractionCurveMax(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetTractionCurveMax(value);
}

float LocalVehicle_Handling_GetTractionCurveMaxRatio(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetTractionCurveMaxRatio();
}

void LocalVehicle_Handling_SetTractionCurveMaxRatio(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetTractionCurveMaxRatio(value);
}

float LocalVehicle_Handling_GetTractionCurveMin(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetTractionCurveMin();
}

void LocalVehicle_Handling_SetTractionCurveMin(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetTractionCurveMin(value);
}

float LocalVehicle_Handling_GetTractionCurveMinRatio(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetTractionCurveMinRatio();
}

void LocalVehicle_Handling_SetTractionCurveMinRatio(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetTractionCurveMinRatio(value);
}

float LocalVehicle_Handling_GetTractionCurveLateral(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetTractionCurveLateral();
}

void LocalVehicle_Handling_SetTractionCurveLateral(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetTractionCurveLateral(value);
}

float LocalVehicle_Handling_GetTractionCurveLateralRatio(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetTractionCurveLateralRatio();
}

void LocalVehicle_Handling_SetTractionCurveLateralRatio(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetTractionCurveLateralRatio(value);
}

float LocalVehicle_Handling_GetTractionSpringDeltaMax(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetTractionSpringDeltaMax();
}

void LocalVehicle_Handling_SetTractionSpringDeltaMax(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetTractionSpringDeltaMax(value);
}

float LocalVehicle_Handling_GetTractionSpringDeltaMaxRatio(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetTractionSpringDeltaMaxRatio();
}

void LocalVehicle_Handling_SetTractionSpringDeltaMaxRatio(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetTractionSpringDeltaMaxRatio(value);
}

float LocalVehicle_Handling_GetLowSpeedTractionLossMult(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetLowSpeedTractionLossMult();
}

void LocalVehicle_Handling_SetLowSpeedTractionLossMult(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetLowSpeedTractionLossMult(value);
}

float LocalVehicle_Handling_GetCamberStiffness(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetCamberStiffness();
}

void LocalVehicle_Handling_SetCamberStiffness(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetCamberStiffness(value);
}

float LocalVehicle_Handling_GetTractionBiasFront(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetTractionBiasFront();
}

void LocalVehicle_Handling_SetTractionBiasFront(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetTractionBiasFront(value);
}

float LocalVehicle_Handling_GetTractionBiasRear(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetTractionBiasRear();
}

void LocalVehicle_Handling_SetTractionBiasRear(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetTractionBiasRear(value);
}

float LocalVehicle_Handling_GetTractionLossMult(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetTractionLossMult();
}

void LocalVehicle_Handling_SetTractionLossMult(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetTractionLossMult(value);
}

float LocalVehicle_Handling_GetSuspensionForce(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetSuspensionForce();
}

void LocalVehicle_Handling_SetSuspensionForce(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetSuspensionForce(value);
}

float LocalVehicle_Handling_GetSuspensionCompDamp(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetSuspensionCompDamp();
}

void LocalVehicle_Handling_SetSuspensionCompDamp(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetSuspensionCompDamp(value);
}

float LocalVehicle_Handling_GetSuspensionReboundDamp(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetSuspensionReboundDamp();
}

void LocalVehicle_Handling_SetSuspensionReboundDamp(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetSuspensionReboundDamp(value);
}

float LocalVehicle_Handling_GetSuspensionUpperLimit(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetSuspensionUpperLimit();
}

void LocalVehicle_Handling_SetSuspensionUpperLimit(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetSuspensionUpperLimit(value);
}

float LocalVehicle_Handling_GetSuspensionLowerLimit(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetSuspensionLowerLimit();
}

void LocalVehicle_Handling_SetSuspensionLowerLimit(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetSuspensionLowerLimit(value);
}

float LocalVehicle_Handling_GetSuspensionRaise(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetSuspensionRaise();
}

void LocalVehicle_Handling_SetSuspensionRaise(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetSuspensionRaise(value);
}

float LocalVehicle_Handling_GetSuspensionBiasFront(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetSuspensionBiasFront();
}

void LocalVehicle_Handling_SetSuspensionBiasFront(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetSuspensionBiasFront(value);
}

float LocalVehicle_Handling_GetSuspensionBiasRear(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetSuspensionBiasRear();
}

void LocalVehicle_Handling_SetSuspensionBiasRear(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetSuspensionBiasRear(value);
}

float LocalVehicle_Handling_GetAntiRollBarForce(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetAntiRollBarForce();
}

void LocalVehicle_Handling_SetAntiRollBarForce(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetAntiRollBarForce(value);
}

float LocalVehicle_Handling_GetAntiRollBarBiasFront(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetAntiRollBarBiasFront();
}

void LocalVehicle_Handling_SetAntiRollBarBiasFront(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetAntiRollBarBiasFront(value);
}

float LocalVehicle_Handling_GetAntiRollBarBiasRear(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetAntiRollBarBiasRear();
}

void LocalVehicle_Handling_SetAntiRollBarBiasRear(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetAntiRollBarBiasRear(value);
}

float LocalVehicle_Handling_GetRollCentreHeightFront(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetRollCentreHeightFront();
}

void LocalVehicle_Handling_SetRollCentreHeightFront(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetRollCentreHeightFront(value);
}

float LocalVehicle_Handling_GetRollCentreHeightRear(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetRollCentreHeightRear();
}

void LocalVehicle_Handling_SetRollCentreHeightRear(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetRollCentreHeightRear(value);
}

float LocalVehicle_Handling_GetCollisionDamageMult(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetCollisionDamageMult();
}

void LocalVehicle_Handling_SetCollisionDamageMult(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetCollisionDamageMult(value);
}

float LocalVehicle_Handling_GetWeaponDamageMult(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetWeaponDamageMult();
}

void LocalVehicle_Handling_SetWeaponDamageMult(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetWeaponDamageMult(value);
}

float LocalVehicle_Handling_GetDeformationDamageMult(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetDeformationDamageMult();
}

void LocalVehicle_Handling_SetDeformationDamageMult(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetDeformationDamageMult(value);
}

float LocalVehicle_Handling_GetEngineDamageMult(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetEngineDamageMult();
}

void LocalVehicle_Handling_SetEngineDamageMult(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetEngineDamageMult(value);
}

float LocalVehicle_Handling_GetPetrolTankVolume(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetPetrolTankVolume();
}

void LocalVehicle_Handling_SetPetrolTankVolume(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetPetrolTankVolume(value);
}

float LocalVehicle_Handling_GetOilVolume(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetOilVolume();
}

void LocalVehicle_Handling_SetOilVolume(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetOilVolume(value);
}

float LocalVehicle_Handling_GetunkFloat5(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetunkFloat5();
}

void LocalVehicle_Handling_SetunkFloat5(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetunkFloat5(value);
}

float LocalVehicle_Handling_GetSeatOffsetDistX(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetSeatOffsetDistX();
}

void LocalVehicle_Handling_SetSeatOffsetDistX(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetSeatOffsetDistX(value);
}

float LocalVehicle_Handling_GetSeatOffsetDistY(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetSeatOffsetDistY();
}

void LocalVehicle_Handling_SetSeatOffsetDistY(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetSeatOffsetDistY(value);
}

float LocalVehicle_Handling_GetSeatOffsetDistZ(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetSeatOffsetDistZ();
}

void LocalVehicle_Handling_SetSeatOffsetDistZ(alt::ILocalVehicle* localVehicle, float value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetSeatOffsetDistZ(value);
}

uint32_t LocalVehicle_Handling_GetMonetaryValue(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetMonetaryValue();
}

void LocalVehicle_Handling_SetMonetaryValue(alt::ILocalVehicle* localVehicle, uint32_t value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetMonetaryValue(value);
}

uint32_t LocalVehicle_Handling_GetModelFlags(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetModelFlags();
}

void LocalVehicle_Handling_SetModelFlags(alt::ILocalVehicle* localVehicle, uint32_t value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetModelFlags(value);
}

uint32_t LocalVehicle_Handling_GetHandlingFlags(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetHandlingFlags();
}

void LocalVehicle_Handling_SetHandlingFlags(alt::ILocalVehicle* localVehicle, uint32_t value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetHandlingFlags(value);
}

uint32_t LocalVehicle_Handling_GetDamageFlags(alt::ILocalVehicle* localVehicle) {
    return localVehicle->GetHandling()->GetDamageFlags();
}

void LocalVehicle_Handling_SetDamageFlags(alt::ILocalVehicle* localVehicle, uint32_t value) {
    localVehicle->ReplaceHandling();
    localVehicle->GetHandling()->SetDamageFlags(value);
}
#endif
