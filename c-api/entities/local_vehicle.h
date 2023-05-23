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

EXPORT_CLIENT alt::IWorldObject* LocalVehicle_GetWorldObject(alt::ILocalVehicle* localVehicle);

EXPORT_CLIENT uint32_t LocalVehicle_GetID(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT uint32_t LocalVehicle_GetModel(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_SetModel(alt::ILocalVehicle* localVehicle, uint32_t model);
EXPORT_CLIENT void LocalVehicle_GetRotation(alt::ILocalVehicle* localVehicle, rotation_t& rot);
EXPORT_CLIENT void LocalVehicle_SetRotation(alt::ILocalVehicle* localVehicle, rotation_t rot);

EXPORT_CLIENT uint32_t LocalVehicle_GetStreamingDistance(alt::ILocalVehicle* localVehicle);

EXPORT_CLIENT void LocalVehicle_SetVisible(alt::ILocalVehicle* localVehicle, uint8_t toggle);
EXPORT_CLIENT uint8_t LocalVehicle_IsVisible(alt::ILocalVehicle* localVehicle);

EXPORT_CLIENT uint32_t LocalVehicle_GetScriptID(alt::ILocalVehicle* localVehicle);

EXPORT_CLIENT uint32_t LocalVehicle_GetRemoteID(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT uint8_t LocalVehicle_IsRemote(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT uint8_t LocalVehicle_IsStreamedIn(alt::ILocalVehicle* localVehicle);

EXPORT_CLIENT uint16_t LocalVehicle_GetCurrentGear(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT float LocalVehicle_GetWheelSpeed(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT float LocalVehicle_GetCurrentRPM(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT uint8_t LocalVehicle_GetWheelsCount(alt::ILocalVehicle* localVehicle);

EXPORT_CLIENT void LocalVehicle_GetSpeedVector(alt::ILocalVehicle* localVehicle, vector3_t& vector);
EXPORT_CLIENT uint16_t LocalVehicle_GetMaxGear(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_SetCurrentGear(alt::ILocalVehicle* localVehicle, uint16_t currentGear);
EXPORT_CLIENT void LocalVehicle_SetMaxGear(alt::ILocalVehicle* localVehicle, uint16_t gearMax);
EXPORT_CLIENT void LocalVehicle_SetCurrentRPM(alt::ILocalVehicle* localVehicle, float rpm);

EXPORT_CLIENT uint8_t LocalVehicle_IsEngineOn(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT uint8_t LocalVehicle_GetLockState(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT int32_t LocalVehicle_GetPetrolTankHealth(alt::ILocalVehicle* localVehicle);

EXPORT_CLIENT uint8_t LocalVehicle_IsHandlingModified(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_ResetHandling(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_ReplaceHandling(alt::ILocalVehicle* localVehicle);

EXPORT_CLIENT void LocalVehicle_ToggleExtra(alt::ILocalVehicle* localVehicle, uint8_t extraID, uint8_t state);
EXPORT_CLIENT uint8_t LocalVehicle_GetLightsIndicator(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_SetLightsIndicator(alt::ILocalVehicle* localVehicle, uint8_t lightsIndicatorFlag);

EXPORT_CLIENT uint8_t LocalVehicle_GetSeatCount(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT uint8_t LocalVehicle_GetOccupiedSeatsCount(alt::ILocalVehicle* localVehicle);

EXPORT_CLIENT void LocalVehicle_ToggleTaxiLight(alt::ILocalVehicle* localVehicle, uint8_t state);
EXPORT_CLIENT uint8_t LocalVehicle_IsTaxiLightOn(alt::ILocalVehicle* localVehicle);

EXPORT_CLIENT float LocalVehicle_GetWheelCamber(alt::ILocalVehicle* localVehicle, uint8_t wheel);
EXPORT_CLIENT void LocalVehicle_SetWheelCamber(alt::ILocalVehicle* localVehicle, uint8_t wheel, float value);
EXPORT_CLIENT float LocalVehicle_GetWheelTrackWidth(alt::ILocalVehicle* localVehicle, uint8_t wheel);
EXPORT_CLIENT void LocalVehicle_SetWheelTrackWidth(alt::ILocalVehicle* localVehicle, uint8_t wheel, float value);
EXPORT_CLIENT float LocalVehicle_GetWheelHeight(alt::ILocalVehicle* localVehicle, uint8_t wheel);
EXPORT_CLIENT void LocalVehicle_SetWheelHeight(alt::ILocalVehicle* localVehicle, uint8_t wheel, float value);
EXPORT_CLIENT float LocalVehicle_GetWheelTyreRadius(alt::ILocalVehicle* localVehicle, uint8_t wheel);
EXPORT_CLIENT void LocalVehicle_SetWheelTyreRadius(alt::ILocalVehicle* localVehicle, uint8_t wheel, float value);
EXPORT_CLIENT float LocalVehicle_GetWheelRimRadius(alt::ILocalVehicle* localVehicle, uint8_t wheel);
EXPORT_CLIENT void LocalVehicle_SetWheelRimRadius(alt::ILocalVehicle* localVehicle, uint8_t wheel, float value);
EXPORT_CLIENT float LocalVehicle_GetWheelTyreWidth(alt::ILocalVehicle* localVehicle, uint8_t wheel);
EXPORT_CLIENT void LocalVehicle_SetWheelTyreWidth(alt::ILocalVehicle* localVehicle, uint8_t wheel, float value);
EXPORT_CLIENT uint32_t LocalVehicle_GetWheelSurfaceMaterial(alt::ILocalVehicle* localVehicle, uint8_t wheel);

EXPORT_CLIENT float LocalVehicle_GetEngineTemperature(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_SetEngineTemperature(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_GetFuelLevel(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_SetFuelLevel(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_GetOilLevel(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_SetOilLevel(alt::ILocalVehicle* localVehicle, float value);


EXPORT_CLIENT uint32_t LocalVehicle_Handling_GetHandlingNameHash(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT float LocalVehicle_Handling_GetMass(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetMass(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetInitialDragCoeff(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetInitialDragCoeff(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetDownforceModifier(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetDownforceModifier(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetunkFloat1(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetunkFloat1(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetunkFloat2(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetunkFloat2(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT void LocalVehicle_Handling_GetCentreOfMassOffset(alt::ILocalVehicle* localVehicle, vector3_t& offset);
EXPORT_CLIENT void LocalVehicle_Handling_SetCentreOfMassOffset(alt::ILocalVehicle* localVehicle, vector3_t value);
EXPORT_CLIENT void LocalVehicle_Handling_GetInertiaMultiplier(alt::ILocalVehicle* localVehicle, vector3_t& offset);
EXPORT_CLIENT void LocalVehicle_Handling_SetInertiaMultiplier(alt::ILocalVehicle* localVehicle, vector3_t value);
EXPORT_CLIENT float LocalVehicle_Handling_GetPercentSubmerged(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetPercentSubmerged(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetPercentSubmergedRatio(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetPercentSubmergedRatio(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetDriveBiasFront(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetDriveBiasFront(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetAcceleration(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetAcceleration(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT uint32_t LocalVehicle_Handling_GetInitialDriveGears(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetInitialDriveGears(alt::ILocalVehicle* localVehicle, uint32_t value);
EXPORT_CLIENT float LocalVehicle_Handling_GetDriveInertia(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetDriveInertia(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetClutchChangeRateScaleUpShift(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetClutchChangeRateScaleUpShift(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetClutchChangeRateScaleDownShift(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetClutchChangeRateScaleDownShift(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetInitialDriveForce(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetInitialDriveForce(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetDriveMaxFlatVel(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetDriveMaxFlatVel(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetInitialDriveMaxFlatVel(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetInitialDriveMaxFlatVel(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetBrakeForce(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetBrakeForce(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetunkFloat4(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetunkFloat4(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetBrakeBiasFront(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetBrakeBiasFront(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetBrakeBiasRear(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetBrakeBiasRear(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetHandBrakeForce(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetHandBrakeForce(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetSteeringLock(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetSteeringLock(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetSteeringLockRatio(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetSteeringLockRatio(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetTractionCurveMax(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetTractionCurveMax(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetTractionCurveMaxRatio(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetTractionCurveMaxRatio(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetTractionCurveMin(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetTractionCurveMin(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetTractionCurveMinRatio(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetTractionCurveMinRatio(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetTractionCurveLateral(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetTractionCurveLateral(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetTractionCurveLateralRatio(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetTractionCurveLateralRatio(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetTractionSpringDeltaMax(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetTractionSpringDeltaMax(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetTractionSpringDeltaMaxRatio(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetTractionSpringDeltaMaxRatio(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetLowSpeedTractionLossMult(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetLowSpeedTractionLossMult(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetCamberStiffness(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetCamberStiffness(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetTractionBiasFront(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetTractionBiasFront(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetTractionBiasRear(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetTractionBiasRear(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetTractionLossMult(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetTractionLossMult(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetSuspensionForce(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetSuspensionForce(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetSuspensionCompDamp(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetSuspensionCompDamp(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetSuspensionReboundDamp(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetSuspensionReboundDamp(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetSuspensionUpperLimit(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetSuspensionUpperLimit(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetSuspensionLowerLimit(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetSuspensionLowerLimit(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetSuspensionRaise(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetSuspensionRaise(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetSuspensionBiasFront(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetSuspensionBiasFront(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetSuspensionBiasRear(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetSuspensionBiasRear(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetAntiRollBarForce(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetAntiRollBarForce(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetAntiRollBarBiasFront(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetAntiRollBarBiasFront(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetAntiRollBarBiasRear(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetAntiRollBarBiasRear(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetRollCentreHeightFront(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetRollCentreHeightFront(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetRollCentreHeightRear(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetRollCentreHeightRear(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetCollisionDamageMult(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetCollisionDamageMult(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetWeaponDamageMult(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetWeaponDamageMult(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetDeformationDamageMult(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetDeformationDamageMult(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetEngineDamageMult(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetEngineDamageMult(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetPetrolTankVolume(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetPetrolTankVolume(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetOilVolume(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetOilVolume(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetunkFloat5(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetunkFloat5(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetSeatOffsetDistX(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetSeatOffsetDistX(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetSeatOffsetDistY(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetSeatOffsetDistY(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT float LocalVehicle_Handling_GetSeatOffsetDistZ(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetSeatOffsetDistZ(alt::ILocalVehicle* localVehicle, float value);
EXPORT_CLIENT uint32_t LocalVehicle_Handling_GetMonetaryValue(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetMonetaryValue(alt::ILocalVehicle* localVehicle, uint32_t value);
EXPORT_CLIENT uint32_t LocalVehicle_Handling_GetModelFlags(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetModelFlags(alt::ILocalVehicle* localVehicle, uint32_t value);
EXPORT_CLIENT uint32_t LocalVehicle_Handling_GetHandlingFlags(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetHandlingFlags(alt::ILocalVehicle* localVehicle, uint32_t value);
EXPORT_CLIENT uint32_t LocalVehicle_Handling_GetDamageFlags(alt::ILocalVehicle* localVehicle);
EXPORT_CLIENT void LocalVehicle_Handling_SetDamageFlags(alt::ILocalVehicle* localVehicle, uint32_t value);
