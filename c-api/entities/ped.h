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

EXPORT_SHARED uint32_t Ped_GetID(alt::IPed* ped);
EXPORT_SHARED alt::IEntity* Ped_GetEntity(alt::IPed* ped);

EXPORT_SHARED uint16_t Ped_GetHealth(alt::IPed* ped);
EXPORT_SHARED uint16_t Ped_GetMaxHealth(alt::IPed* ped);
EXPORT_SHARED uint16_t Ped_GetArmour(alt::IPed* ped);
EXPORT_SHARED uint32_t Ped_GetCurrentWeapon(alt::IPed* ped);

EXPORT_SERVER void Ped_SetHealth(alt::IPed* ped, uint16_t health);
EXPORT_SERVER void Ped_SetMaxHealth(alt::IPed* ped, uint16_t maxHealth);
EXPORT_SERVER void Ped_SetArmour(alt::IPed* ped, uint16_t armor);
EXPORT_SERVER void Ped_SetCurrentWeapon(alt::IPed* ped, uint32_t weapon);