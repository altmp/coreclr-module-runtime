#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "data/types.h"
#include "data/invoker.h"
#include "utils/export.h"

#ifdef ALT_SERVER_API
#include <CSharpResourceImpl.h>
#elif ALT_CLIENT_API
#include "../client/src/runtime/CSharpResourceImpl.h"
#endif

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_CLIENT uint8_t Handling_GetByModelHash(alt::ICore* core, uint32_t modelHash, alt::IHandlingData*& handling);

EXPORT_CLIENT uint32_t Handling_GetHandlingNameHash(uint32_t modelHash);
EXPORT_CLIENT float Handling_GetMass(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetMass(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetInitialDragCoeff(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetInitialDragCoeff(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetDownforceModifier(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetDownforceModifier(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetunkFloat1(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetunkFloat1(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetunkFloat2(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetunkFloat2(uint32_t modelHash, float value);
EXPORT_CLIENT void Handling_GetCentreOfMassOffset(uint32_t modelHash, vector3_t& offset);
EXPORT_CLIENT void Handling_SetCentreOfMassOffset(uint32_t modelHash, vector3_t value);
EXPORT_CLIENT void Handling_GetInertiaMultiplier(uint32_t modelHash, vector3_t& offset);
EXPORT_CLIENT void Handling_SetInertiaMultiplier(uint32_t modelHash, vector3_t value);
EXPORT_CLIENT float Handling_GetPercentSubmerged(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetPercentSubmerged(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetPercentSubmergedRatio(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetPercentSubmergedRatio(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetDriveBiasFront(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetDriveBiasFront(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetAcceleration(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetAcceleration(uint32_t modelHash, float value);
EXPORT_CLIENT uint32_t Handling_GetInitialDriveGears(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetInitialDriveGears(uint32_t modelHash, uint32_t value);
EXPORT_CLIENT float Handling_GetDriveInertia(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetDriveInertia(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetClutchChangeRateScaleUpShift(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetClutchChangeRateScaleUpShift(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetClutchChangeRateScaleDownShift(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetClutchChangeRateScaleDownShift(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetInitialDriveForce(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetInitialDriveForce(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetDriveMaxFlatVel(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetDriveMaxFlatVel(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetInitialDriveMaxFlatVel(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetInitialDriveMaxFlatVel(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetBrakeForce(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetBrakeForce(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetunkFloat4(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetunkFloat4(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetBrakeBiasFront(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetBrakeBiasFront(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetBrakeBiasRear(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetBrakeBiasRear(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetHandBrakeForce(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetHandBrakeForce(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetSteeringLock(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetSteeringLock(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetSteeringLockRatio(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetSteeringLockRatio(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetTractionCurveMax(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetTractionCurveMax(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetTractionCurveMaxRatio(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetTractionCurveMaxRatio(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetTractionCurveMin(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetTractionCurveMin(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetTractionCurveMinRatio(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetTractionCurveMinRatio(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetTractionCurveLateral(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetTractionCurveLateral(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetTractionCurveLateralRatio(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetTractionCurveLateralRatio(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetTractionSpringDeltaMax(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetTractionSpringDeltaMax(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetTractionSpringDeltaMaxRatio(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetTractionSpringDeltaMaxRatio(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetLowSpeedTractionLossMult(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetLowSpeedTractionLossMult(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetCamberStiffness(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetCamberStiffness(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetTractionBiasFront(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetTractionBiasFront(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetTractionBiasRear(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetTractionBiasRear(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetTractionLossMult(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetTractionLossMult(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetSuspensionForce(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetSuspensionForce(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetSuspensionCompDamp(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetSuspensionCompDamp(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetSuspensionReboundDamp(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetSuspensionReboundDamp(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetSuspensionUpperLimit(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetSuspensionUpperLimit(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetSuspensionLowerLimit(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetSuspensionLowerLimit(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetSuspensionRaise(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetSuspensionRaise(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetSuspensionBiasFront(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetSuspensionBiasFront(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetSuspensionBiasRear(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetSuspensionBiasRear(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetAntiRollBarForce(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetAntiRollBarForce(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetAntiRollBarBiasFront(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetAntiRollBarBiasFront(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetAntiRollBarBiasRear(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetAntiRollBarBiasRear(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetRollCentreHeightFront(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetRollCentreHeightFront(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetRollCentreHeightRear(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetRollCentreHeightRear(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetCollisionDamageMult(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetCollisionDamageMult(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetWeaponDamageMult(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetWeaponDamageMult(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetDeformationDamageMult(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetDeformationDamageMult(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetEngineDamageMult(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetEngineDamageMult(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetPetrolTankVolume(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetPetrolTankVolume(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetOilVolume(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetOilVolume(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetunkFloat5(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetunkFloat5(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetSeatOffsetDistX(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetSeatOffsetDistX(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetSeatOffsetDistY(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetSeatOffsetDistY(uint32_t modelHash, float value);
EXPORT_CLIENT float Handling_GetSeatOffsetDistZ(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetSeatOffsetDistZ(uint32_t modelHash, float value);
EXPORT_CLIENT uint32_t Handling_GetMonetaryValue(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetMonetaryValue(uint32_t modelHash, uint32_t value);
EXPORT_CLIENT uint32_t Handling_GetModelFlags(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetModelFlags(uint32_t modelHash, uint32_t value);
EXPORT_CLIENT uint32_t Handling_GetHandlingFlags(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetHandlingFlags(uint32_t modelHash, uint32_t value);
EXPORT_CLIENT uint32_t Handling_GetDamageFlags(uint32_t modelHash);
EXPORT_CLIENT void Handling_SetDamageFlags(uint32_t modelHash, uint32_t value);