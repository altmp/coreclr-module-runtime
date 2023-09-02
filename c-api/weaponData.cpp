#include "weaponData.h"

#include "utils/macros.h"

CAPI_START()

#ifdef ALT_CLIENT_API

uint32_t WeaponData_GetNameHash(uint32_t weaponHash) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    return weaponData->GetNameHash();
}

uint32_t WeaponData_GetModelHash(uint32_t weaponHash) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    return weaponData->GetModelHash();
}

float WeaponData_GetRecoilShakeAmplitude(uint32_t weaponHash) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    return weaponData->GetRecoilShakeAmplitude();
}

float WeaponData_GetRecoilAccuracyMax(uint32_t weaponHash) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    return weaponData->GetRecoilAccuracyMax();
}

float WeaponData_GetRecoilAccuracyToAllowHeadshotPlayer(uint32_t weaponHash) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    return weaponData->GetRecoilAccuracyToAllowHeadshotPlayer();
}

float WeaponData_GetRecoilRecoveryRate(uint32_t weaponHash) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    return weaponData->GetRecoilRecoveryRate();
}

float WeaponData_GetAnimReloadRate(uint32_t weaponHash) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    return weaponData->GetAnimReloadRate();
}

float WeaponData_GetVehicleReloadTime(uint32_t weaponHash) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    return weaponData->GetVehicleReloadTime();
}

float WeaponData_GetLockOnRange(uint32_t weaponHash) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    return weaponData->GetLockOnRange();
}

float WeaponData_GetAccuracySpread(uint32_t weaponHash) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    return weaponData->GetAccuracySpread();
}

float WeaponData_GetRange(uint32_t weaponHash) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    return weaponData->GetRange();
}

float WeaponData_GetDamage(uint32_t weaponHash) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    return weaponData->GetDamage();
}

uint32_t WeaponData_GetClipSize(uint32_t weaponHash) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    return weaponData->GetClipSize();
}

float WeaponData_GetTimeBetweenShots(uint32_t weaponHash) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    return weaponData->GetTimeBetweenShots();
}

float WeaponData_GetHeadshotDamageModifier(uint32_t weaponHash) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    return weaponData->GetHeadshotDamageModifier();
}

float WeaponData_GetPlayerDamageModifier(uint32_t weaponHash) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    return weaponData->GetPlayerDamageModifier();
}

void WeaponData_SetRecoilShakeAmplitude(uint32_t weaponHash, float val) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    weaponData->SetRecoilShakeAmplitude(val);
}

void WeaponData_SetRecoilAccuracyMax(uint32_t weaponHash, float val) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    weaponData->SetRecoilAccuracyMax(val);
}

void WeaponData_SetRecoilAccuracyToAllowHeadshotPlayer(uint32_t weaponHash, float val) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    weaponData->SetRecoilAccuracyToAllowHeadshotPlayer(val);
}

void WeaponData_SetRecoilRecoveryRate(uint32_t weaponHash, float val) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    weaponData->SetRecoilRecoveryRate(val);
}

void WeaponData_SetAnimReloadRate(uint32_t weaponHash, float val) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    weaponData->SetAnimReloadRate(val);
}

void WeaponData_SetVehicleReloadTime(uint32_t weaponHash, float val) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    weaponData->SetVehicleReloadTime(val);
}

void WeaponData_SetLockOnRange(uint32_t weaponHash, float val) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    weaponData->SetLockOnRange(val);
}

void WeaponData_SetAccuracySpread(uint32_t weaponHash, float val) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    weaponData->SetAccuracySpread(val);
}

void WeaponData_SetRange(uint32_t weaponHash, float val) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    weaponData->SetRange(val);
}

void WeaponData_SetDamage(uint32_t weaponHash, float val) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    weaponData->SetDamage(val);
}

void WeaponData_SetHeadshotDamageModifier(uint32_t weaponHash, float val) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    weaponData->SetHeadshotDamageModifier(val);
}

void WeaponData_SetPlayerDamageModifier(uint32_t weaponHash, float val) {
    auto weaponData = alt::ICore::Instance().GetWeaponData(weaponHash);
    weaponData->SetPlayerDamageModifier(val);
}

#endif

CAPI_END()