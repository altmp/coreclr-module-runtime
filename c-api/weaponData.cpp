#include "weaponData.h"

#ifdef ALT_CLIENT_API

uint32_t WeaponData_GetNameHash(alt::IWeaponData* weaponData) {
    return weaponData->GetNameHash();
}

uint32_t WeaponData_GetModelHash(alt::IWeaponData* weaponData) {
    return weaponData->GetModelHash();
}

float WeaponData_GetRecoilShakeAmplitude(alt::IWeaponData* weaponData) {
    return weaponData->GetRecoilShakeAmplitude();
}

float WeaponData_GetRecoilAccuracyMax(alt::IWeaponData* weaponData) {
    return weaponData->GetRecoilAccuracyMax();
}

float WeaponData_GetRecoilAccuracyToAllowHeadshotPlayer(alt::IWeaponData* weaponData) {
    return weaponData->GetRecoilAccuracyToAllowHeadshotPlayer();
}

float WeaponData_GetRecoilRecoveryRate(alt::IWeaponData* weaponData) {
    return weaponData->GetRecoilRecoveryRate();
}

float WeaponData_GetAnimReloadRate(alt::IWeaponData* weaponData) {
    return weaponData->GetAnimReloadRate();
}

float WeaponData_GetVehicleReloadTime(alt::IWeaponData* weaponData) {
    return weaponData->GetVehicleReloadTime();
}

float WeaponData_GetLockOnRange(alt::IWeaponData* weaponData) {
    return weaponData->GetLockOnRange();
}

float WeaponData_GetAccuracySpread(alt::IWeaponData* weaponData) {
    return weaponData->GetAccuracySpread();
}

float WeaponData_GetRange(alt::IWeaponData* weaponData) {
    return weaponData->GetRange();
}

float WeaponData_GetDamage(alt::IWeaponData* weaponData) {
    return weaponData->GetDamage();
}

uint32_t WeaponData_GetClipSize(alt::IWeaponData* weaponData) {
    return weaponData->GetClipSize();
}

float WeaponData_GetTimeBetweenShots(alt::IWeaponData* weaponData) {
    return weaponData->GetTimeBetweenShots();
}

float WeaponData_GetHeadshotDamageModifier(alt::IWeaponData* weaponData) {
    return weaponData->GetHeadshotDamageModifier();
}

float WeaponData_GetPlayerDamageModifier(alt::IWeaponData* weaponData) {
    return weaponData->GetPlayerDamageModifier();
}

void WeaponData_SetRecoilShakeAmplitude(alt::IWeaponData* weaponData, float val) {
    weaponData->SetRecoilShakeAmplitude(val);
}

void WeaponData_SetRecoilAccuracyMax(alt::IWeaponData* weaponData, float val) {
    weaponData->SetRecoilAccuracyMax(val);
}

void WeaponData_SetRecoilAccuracyToAllowHeadshotPlayer(alt::IWeaponData* weaponData, float val) {
    weaponData->SetRecoilAccuracyToAllowHeadshotPlayer(val);
}

void WeaponData_SetRecoilRecoveryRate(alt::IWeaponData* weaponData, float val) {
    weaponData->SetRecoilRecoveryRate(val);
}

void WeaponData_SetAnimReloadRate(alt::IWeaponData* weaponData, float val) {
    weaponData->SetAnimReloadRate(val);
}

void WeaponData_SetVehicleReloadTime(alt::IWeaponData* weaponData, float val) {
    weaponData->SetVehicleReloadTime(val);
}

void WeaponData_SetLockOnRange(alt::IWeaponData* weaponData, float val) {
    weaponData->SetLockOnRange(val);
}

void WeaponData_SetAccuracySpread(alt::IWeaponData* weaponData, float val) {
    weaponData->SetAccuracySpread(val);
}

void WeaponData_SetRange(alt::IWeaponData* weaponData, float val) {
    weaponData->SetRange(val);
}

void WeaponData_SetDamage(alt::IWeaponData* weaponData, float val) {
    weaponData->SetDamage(val);
}

void WeaponData_SetHeadshotDamageModifier(alt::IWeaponData* weaponData, float val) {
    weaponData->SetHeadshotDamageModifier(val);
}

void WeaponData_SetPlayerDamageModifier(alt::IWeaponData* weaponData, float val) {
    weaponData->SetPlayerDamageModifier(val);
}

uint8_t WeaponData_GetByWeaponHash(alt::ICore* core, uint32_t modelHash, alt::IWeaponData*& weaponData) {
    auto data = core->GetWeaponData(modelHash);
    if (!data) return false;
    weaponData = data.get();
    return true;
}

#endif