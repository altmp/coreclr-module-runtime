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
    
EXPORT_CLIENT uint32_t WeaponData_GetNameHash(uint32_t weaponHash);
EXPORT_CLIENT uint32_t WeaponData_GetModelHash(uint32_t weaponHash);
EXPORT_CLIENT float WeaponData_GetRecoilShakeAmplitude(uint32_t weaponHash);
EXPORT_CLIENT float WeaponData_GetRecoilAccuracyMax(uint32_t weaponHash);
EXPORT_CLIENT float WeaponData_GetRecoilAccuracyToAllowHeadshotPlayer(uint32_t weaponHash);
EXPORT_CLIENT float WeaponData_GetRecoilRecoveryRate(uint32_t weaponHash);
EXPORT_CLIENT float WeaponData_GetAnimReloadRate(uint32_t weaponHash);
EXPORT_CLIENT float WeaponData_GetVehicleReloadTime(uint32_t weaponHash);
EXPORT_CLIENT float WeaponData_GetLockOnRange(uint32_t weaponHash);
EXPORT_CLIENT float WeaponData_GetAccuracySpread(uint32_t weaponHash);
EXPORT_CLIENT float WeaponData_GetRange(uint32_t weaponHash);
EXPORT_CLIENT float WeaponData_GetDamage(uint32_t weaponHash);
EXPORT_CLIENT uint32_t WeaponData_GetClipSize(uint32_t weaponHash);
EXPORT_CLIENT float WeaponData_GetTimeBetweenShots(uint32_t weaponHash);
EXPORT_CLIENT float WeaponData_GetHeadshotDamageModifier(uint32_t weaponHash);
EXPORT_CLIENT float WeaponData_GetPlayerDamageModifier(uint32_t weaponHash);
EXPORT_CLIENT void WeaponData_SetRecoilShakeAmplitude(uint32_t weaponHash, float val);
EXPORT_CLIENT void WeaponData_SetRecoilAccuracyMax(uint32_t weaponHash, float val);
EXPORT_CLIENT void WeaponData_SetRecoilAccuracyToAllowHeadshotPlayer(uint32_t weaponHash, float val);
EXPORT_CLIENT void WeaponData_SetRecoilRecoveryRate(uint32_t weaponHash, float val);
EXPORT_CLIENT void WeaponData_SetAnimReloadRate(uint32_t weaponHash, float val);
EXPORT_CLIENT void WeaponData_SetVehicleReloadTime(uint32_t weaponHash, float val);
EXPORT_CLIENT void WeaponData_SetLockOnRange(uint32_t weaponHash, float val);
EXPORT_CLIENT void WeaponData_SetAccuracySpread(uint32_t weaponHash, float val);
EXPORT_CLIENT void WeaponData_SetRange(uint32_t weaponHash, float val);
EXPORT_CLIENT void WeaponData_SetDamage(uint32_t weaponHash, float val);
EXPORT_CLIENT void WeaponData_SetHeadshotDamageModifier(uint32_t weaponHash, float val);
EXPORT_CLIENT void WeaponData_SetPlayerDamageModifier(uint32_t weaponHash, float val);