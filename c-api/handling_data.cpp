#include "handling_data.h"

#include "utils/macros.h"

CAPI_START()

#ifdef ALT_CLIENT_API
uint32_t Handling_GetHandlingNameHash(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetHandlingNameHash();
}

float Handling_GetMass(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetMass();
}

void Handling_SetMass(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetMass(value);
}

float Handling_GetInitialDragCoeff(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetInitialDragCoeff();
}

void Handling_SetInitialDragCoeff(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetInitialDragCoeff(value);
}

float Handling_GetDownforceModifier(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetDownforceModifier();
}

void Handling_SetDownforceModifier(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetDownforceModifier(value);
}

float Handling_GetunkFloat1(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetunkFloat1();
}

void Handling_SetunkFloat1(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetunkFloat1(value);
}

float Handling_GetunkFloat2(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetunkFloat2();
}

void Handling_SetunkFloat2(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetunkFloat2(value);
}

void Handling_GetCentreOfMassOffset(uint32_t modelHash, vector3_t& offset) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    auto vector = handling->GetCentreOfMassOffset();
    offset.x = vector[0];
    offset.y = vector[1];
    offset.z = vector[2];
}

void Handling_SetCentreOfMassOffset(uint32_t modelHash, vector3_t value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetCentreOfMassOffset(alt::Vector3f(value.x, value.y, value.z));
}

void Handling_GetInertiaMultiplier(uint32_t modelHash, vector3_t& offset) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    auto vector = handling->GetInertiaMultiplier();
    offset.x = vector[0];
    offset.y = vector[1];
    offset.z = vector[2];
}

void Handling_SetInertiaMultiplier(uint32_t modelHash, vector3_t value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetInertiaMultiplier(alt::Vector3f(value.x, value.y, value.z));
}

float Handling_GetPercentSubmerged(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetPercentSubmerged();
}

void Handling_SetPercentSubmerged(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetPercentSubmerged(value);
}

float Handling_GetPercentSubmergedRatio(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetPercentSubmergedRatio();
}

void Handling_SetPercentSubmergedRatio(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetPercentSubmergedRatio(value);
}

float Handling_GetDriveBiasFront(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetDriveBiasFront();
}

void Handling_SetDriveBiasFront(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetDriveBiasFront(value);
}

float Handling_GetAcceleration(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetAcceleration();
}

void Handling_SetAcceleration(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetAcceleration(value);
}

uint32_t Handling_GetInitialDriveGears(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetInitialDriveGears();
}

void Handling_SetInitialDriveGears(uint32_t modelHash, uint32_t value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetInitialDriveGears(value);
}

float Handling_GetDriveInertia(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetDriveInertia();
}

void Handling_SetDriveInertia(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetDriveInertia(value);
}

float Handling_GetClutchChangeRateScaleUpShift(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetClutchChangeRateScaleUpShift();
}

void Handling_SetClutchChangeRateScaleUpShift(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetClutchChangeRateScaleUpShift(value);
}

float Handling_GetClutchChangeRateScaleDownShift(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetClutchChangeRateScaleDownShift();
}

void Handling_SetClutchChangeRateScaleDownShift(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetClutchChangeRateScaleDownShift(value);
}

float Handling_GetInitialDriveForce(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetInitialDriveForce();
}

void Handling_SetInitialDriveForce(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetInitialDriveForce(value);
}

float Handling_GetDriveMaxFlatVel(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetDriveMaxFlatVel();
}

void Handling_SetDriveMaxFlatVel(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetDriveMaxFlatVel(value);
}

float Handling_GetInitialDriveMaxFlatVel(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetInitialDriveMaxFlatVel();
}

void Handling_SetInitialDriveMaxFlatVel(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetInitialDriveMaxFlatVel(value);
}

float Handling_GetBrakeForce(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetBrakeForce();
}

void Handling_SetBrakeForce(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetBrakeForce(value);
}

float Handling_GetunkFloat4(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetunkFloat4();
}

void Handling_SetunkFloat4(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetunkFloat4(value);
}

float Handling_GetBrakeBiasFront(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetBrakeBiasFront();
}

void Handling_SetBrakeBiasFront(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetBrakeBiasFront(value);
}

float Handling_GetBrakeBiasRear(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetBrakeBiasRear();
}

void Handling_SetBrakeBiasRear(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetBrakeBiasRear(value);
}

float Handling_GetHandBrakeForce(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetHandBrakeForce();
}

void Handling_SetHandBrakeForce(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetHandBrakeForce(value);
}

float Handling_GetSteeringLock(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetSteeringLock();
}

void Handling_SetSteeringLock(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetSteeringLock(value);
}

float Handling_GetSteeringLockRatio(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetSteeringLockRatio();
}

void Handling_SetSteeringLockRatio(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetSteeringLockRatio(value);
}

float Handling_GetTractionCurveMax(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetTractionCurveMax();
}

void Handling_SetTractionCurveMax(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetTractionCurveMax(value);
}

float Handling_GetTractionCurveMaxRatio(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetTractionCurveMaxRatio();
}

void Handling_SetTractionCurveMaxRatio(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetTractionCurveMaxRatio(value);
}

float Handling_GetTractionCurveMin(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetTractionCurveMin();
}

void Handling_SetTractionCurveMin(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetTractionCurveMin(value);
}

float Handling_GetTractionCurveMinRatio(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetTractionCurveMinRatio();
}

void Handling_SetTractionCurveMinRatio(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetTractionCurveMinRatio(value);
}

float Handling_GetTractionCurveLateral(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetTractionCurveLateral();
}

void Handling_SetTractionCurveLateral(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetTractionCurveLateral(value);
}

float Handling_GetTractionCurveLateralRatio(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetTractionCurveLateralRatio();
}

void Handling_SetTractionCurveLateralRatio(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetTractionCurveLateralRatio(value);
}

float Handling_GetTractionSpringDeltaMax(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetTractionSpringDeltaMax();
}

void Handling_SetTractionSpringDeltaMax(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetTractionSpringDeltaMax(value);
}

float Handling_GetTractionSpringDeltaMaxRatio(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetTractionSpringDeltaMaxRatio();
}

void Handling_SetTractionSpringDeltaMaxRatio(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetTractionSpringDeltaMaxRatio(value);
}

float Handling_GetLowSpeedTractionLossMult(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetLowSpeedTractionLossMult();
}

void Handling_SetLowSpeedTractionLossMult(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetLowSpeedTractionLossMult(value);
}

float Handling_GetCamberStiffness(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetCamberStiffness();
}

void Handling_SetCamberStiffness(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetCamberStiffness(value);
}

float Handling_GetTractionBiasFront(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetTractionBiasFront();
}

void Handling_SetTractionBiasFront(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetTractionBiasFront(value);
}

float Handling_GetTractionBiasRear(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetTractionBiasRear();
}

void Handling_SetTractionBiasRear(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetTractionBiasRear(value);
}

float Handling_GetTractionLossMult(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetTractionLossMult();
}

void Handling_SetTractionLossMult(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetTractionLossMult(value);
}

float Handling_GetSuspensionForce(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetSuspensionForce();
}

void Handling_SetSuspensionForce(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetSuspensionForce(value);
}

float Handling_GetSuspensionCompDamp(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetSuspensionCompDamp();
}

void Handling_SetSuspensionCompDamp(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetSuspensionCompDamp(value);
}

float Handling_GetSuspensionReboundDamp(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetSuspensionReboundDamp();
}

void Handling_SetSuspensionReboundDamp(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetSuspensionReboundDamp(value);
}

float Handling_GetSuspensionUpperLimit(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetSuspensionUpperLimit();
}

void Handling_SetSuspensionUpperLimit(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetSuspensionUpperLimit(value);
}

float Handling_GetSuspensionLowerLimit(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetSuspensionLowerLimit();
}

void Handling_SetSuspensionLowerLimit(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetSuspensionLowerLimit(value);
}

float Handling_GetSuspensionRaise(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetSuspensionRaise();
}

void Handling_SetSuspensionRaise(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetSuspensionRaise(value);
}

float Handling_GetSuspensionBiasFront(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetSuspensionBiasFront();
}

void Handling_SetSuspensionBiasFront(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetSuspensionBiasFront(value);
}

float Handling_GetSuspensionBiasRear(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetSuspensionBiasRear();
}

void Handling_SetSuspensionBiasRear(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetSuspensionBiasRear(value);
}

float Handling_GetAntiRollBarForce(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetAntiRollBarForce();
}

void Handling_SetAntiRollBarForce(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetAntiRollBarForce(value);
}

float Handling_GetAntiRollBarBiasFront(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetAntiRollBarBiasFront();
}

void Handling_SetAntiRollBarBiasFront(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetAntiRollBarBiasFront(value);
}

float Handling_GetAntiRollBarBiasRear(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetAntiRollBarBiasRear();
}

void Handling_SetAntiRollBarBiasRear(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetAntiRollBarBiasRear(value);
}

float Handling_GetRollCentreHeightFront(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetRollCentreHeightFront();
}

void Handling_SetRollCentreHeightFront(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetRollCentreHeightFront(value);
}

float Handling_GetRollCentreHeightRear(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetRollCentreHeightRear();
}

void Handling_SetRollCentreHeightRear(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetRollCentreHeightRear(value);
}

float Handling_GetCollisionDamageMult(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetCollisionDamageMult();
}

void Handling_SetCollisionDamageMult(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetCollisionDamageMult(value);
}

float Handling_GetWeaponDamageMult(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetWeaponDamageMult();
}

void Handling_SetWeaponDamageMult(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetWeaponDamageMult(value);
}

float Handling_GetDeformationDamageMult(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetDeformationDamageMult();
}

void Handling_SetDeformationDamageMult(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetDeformationDamageMult(value);
}

float Handling_GetEngineDamageMult(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetEngineDamageMult();
}

void Handling_SetEngineDamageMult(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetEngineDamageMult(value);
}

float Handling_GetPetrolTankVolume(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetPetrolTankVolume();
}

void Handling_SetPetrolTankVolume(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetPetrolTankVolume(value);
}

float Handling_GetOilVolume(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetOilVolume();
}

void Handling_SetOilVolume(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetOilVolume(value);
}

float Handling_GetunkFloat5(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetunkFloat5();
}

void Handling_SetunkFloat5(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetunkFloat5(value);
}

float Handling_GetSeatOffsetDistX(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetSeatOffsetDistX();
}

void Handling_SetSeatOffsetDistX(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetSeatOffsetDistX(value);
}

float Handling_GetSeatOffsetDistY(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetSeatOffsetDistY();
}

void Handling_SetSeatOffsetDistY(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetSeatOffsetDistY(value);
}

float Handling_GetSeatOffsetDistZ(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetSeatOffsetDistZ();
}

void Handling_SetSeatOffsetDistZ(uint32_t modelHash, float value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetSeatOffsetDistZ(value);
}

uint32_t Handling_GetMonetaryValue(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetMonetaryValue();
}

void Handling_SetMonetaryValue(uint32_t modelHash, uint32_t value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetMonetaryValue(value);
}

uint32_t Handling_GetModelFlags(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetModelFlags();
}

void Handling_SetModelFlags(uint32_t modelHash, uint32_t value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetModelFlags(value);
}

uint32_t Handling_GetHandlingFlags(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetHandlingFlags();
}

void Handling_SetHandlingFlags(uint32_t modelHash, uint32_t value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetHandlingFlags(value);
}

uint32_t Handling_GetDamageFlags(uint32_t modelHash) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    return handling->GetDamageFlags();
}

void Handling_SetDamageFlags(uint32_t modelHash, uint32_t value) {
    auto handling = alt::ICore::Instance().GetHandlingData(modelHash);
    handling->SetDamageFlags(value);
}
#endif

CAPI_END()