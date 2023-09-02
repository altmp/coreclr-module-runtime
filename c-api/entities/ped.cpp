#include "ped.h"

#include "../utils/macros.h"
#include "../utils/strings.h"
#include "../utils/uint.h"

CAPI_START()

uint16_t Ped_GetID(alt::IPed* ped) {
    return ped->GetID();
}

alt::IEntity* Ped_GetEntity(alt::IPed* ped) {
    return dynamic_cast<alt::IEntity*>(ped);
}

uint16_t Ped_GetHealth(alt::IPed* ped) {
    return ped->GetHealth();
}

uint16_t Ped_GetMaxHealth(alt::IPed* ped) {
    return ped->GetMaxHealth();
}

uint16_t Ped_GetArmour(alt::IPed* ped) {
    return ped->GetArmour();
}

uint32_t Ped_GetCurrentWeapon(alt::IPed* ped) {
    return ped->GetCurrentWeapon();
}

#ifdef ALT_SERVER_API

void Ped_SetHealth(alt::IPed* ped, uint16_t health) {
    ped->SetHealth(health);
}

void Ped_SetMaxHealth(alt::IPed* ped, uint16_t maxHealth) {
    ped->SetMaxHealth(maxHealth);
}

void Ped_SetArmour(alt::IPed* ped, uint16_t armor) {
    ped->SetArmour(armor);
}

void Ped_SetCurrentWeapon(alt::IPed* ped, uint32_t weapon) {
    ped->SetCurrentWeapon(weapon);
}


#endif

#if ALT_CLIENT_API

#endif

CAPI_END()