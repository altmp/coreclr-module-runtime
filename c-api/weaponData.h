#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "../../cpp-sdk/SDK.h"
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

#ifdef __cplusplus
extern "C"
{
#endif
    
EXPORT_CLIENT uint32_t WeaponData_GetNameHash(alt::IWeaponData* weaponData);
EXPORT_CLIENT uint32_t WeaponData_GetModelHash(alt::IWeaponData* weaponData);
EXPORT_CLIENT float WeaponData_GetRecoilShakeAmplitude(alt::IWeaponData* weaponData);
EXPORT_CLIENT float WeaponData_GetRecoilAccuracyMax(alt::IWeaponData* weaponData);
EXPORT_CLIENT float WeaponData_GetRecoilAccuracyToAllowHeadshotPlayer(alt::IWeaponData* weaponData);
EXPORT_CLIENT float WeaponData_GetRecoilRecoveryRate(alt::IWeaponData* weaponData);
EXPORT_CLIENT float WeaponData_GetAnimReloadRate(alt::IWeaponData* weaponData);
EXPORT_CLIENT float WeaponData_GetVehicleReloadTime(alt::IWeaponData* weaponData);
EXPORT_CLIENT float WeaponData_GetLockOnRange(alt::IWeaponData* weaponData);
EXPORT_CLIENT float WeaponData_GetAccuracySpread(alt::IWeaponData* weaponData);
EXPORT_CLIENT float WeaponData_GetRange(alt::IWeaponData* weaponData);
EXPORT_CLIENT float WeaponData_GetDamage(alt::IWeaponData* weaponData);
EXPORT_CLIENT uint32_t WeaponData_GetClipSize(alt::IWeaponData* weaponData);
EXPORT_CLIENT float WeaponData_GetTimeBetweenShots(alt::IWeaponData* weaponData);
EXPORT_CLIENT float WeaponData_GetHeadshotDamageModifier(alt::IWeaponData* weaponData);
EXPORT_CLIENT void WeaponData_SetRecoilShakeAmplitude(alt::IWeaponData* weaponData, float val);
EXPORT_CLIENT void WeaponData_SetRecoilAccuracyMax(alt::IWeaponData* weaponData, float val);
EXPORT_CLIENT void WeaponData_SetRecoilAccuracyToAllowHeadshotPlayer(alt::IWeaponData* weaponData, float val);
EXPORT_CLIENT void WeaponData_SetRecoilRecoveryRate(alt::IWeaponData* weaponData, float val);
EXPORT_CLIENT void WeaponData_SetAnimReloadRate(alt::IWeaponData* weaponData, float val);
EXPORT_CLIENT void WeaponData_SetVehicleReloadTime(alt::IWeaponData* weaponData, float val);
EXPORT_CLIENT void WeaponData_SetLockOnRange(alt::IWeaponData* weaponData, float val);
EXPORT_CLIENT void WeaponData_SetAccuracySpread(alt::IWeaponData* weaponData, float val);
EXPORT_CLIENT void WeaponData_SetRange(alt::IWeaponData* weaponData, float val);
EXPORT_CLIENT void WeaponData_SetDamage(alt::IWeaponData* weaponData, float val);
EXPORT_CLIENT void WeaponData_SetHeadshotDamageModifier(alt::IWeaponData* weaponData, float val);
EXPORT_CLIENT void WeaponData_Dispose(alt::IWeaponData* weaponData);
EXPORT_CLIENT uint8_t WeaponData_GetByWeaponHash(alt::ICore* core, uint32_t modelHash, alt::IWeaponData*& weaponData);

#ifdef __cplusplus
}
#endif
