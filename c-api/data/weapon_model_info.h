#pragma once

#include "cpp-sdk/ICore.h"

struct ClrWeaponModelInfo {
    uint32_t hash = 0;
    char* name = nullptr;
    char* modelName = nullptr;
    uint32_t modelHash = 0;
    uint32_t ammoTypeHash = 0;
    char* ammoType = nullptr;
    char* ammoModelName = nullptr;
    uint32_t ammoModelHash = 0;
    int32_t defaultMaxAmmoMp = 0;
    int32_t skillAbove50MaxAmmoMp = 0;
    int32_t maxSkillMaxAmmoMp = 0;
    int32_t bonusMaxAmmoMp = 0;

    ClrWeaponModelInfo() = default;
    ClrWeaponModelInfo(alt::WeaponModelInfo info) :
                hash(info.hash),
                modelHash(info.modelHash),
                ammoTypeHash(info.ammoTypeHash),
                ammoModelHash(info.ammoModelHash),
                defaultMaxAmmoMp(info.defaultMaxAmmoMp),
                skillAbove50MaxAmmoMp(info.skillAbove50MaxAmmoMp),
                maxSkillMaxAmmoMp(info.maxSkillMaxAmmoMp),
                bonusMaxAmmoMp(info.bonusMaxAmmoMp)
    {
        name = new char[info.name.length() + 1];
        std::copy(info.name.begin(), info.name.end(), name);
        name[info.name.length()] = '\0';

        ammoType = new char[info.ammoType.length() + 1];
        std::copy(info.ammoType.begin(), info.ammoType.end(), ammoType);
        ammoType[info.ammoType.length()] = '\0';

        modelName = new char[info.model.length() + 1];
        std::copy(info.model.begin(), info.model.end(), modelName);
        modelName[info.model.length()] = '\0';

        ammoModelName = new char[info.ammoModelName.length() + 1];
        std::copy(info.ammoModelName.begin(), info.ammoModelName.end(), ammoModelName);
        ammoModelName[info.ammoModelName.length()] = '\0';
    }

    ~ClrWeaponModelInfo() {
        delete[] name;
        delete[] ammoType;
        delete[] modelName;
        delete[] ammoModelName;
    }
};
