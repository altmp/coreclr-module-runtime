#pragma once

#include "cpp-sdk/ICore.h"

struct ClrAmmoFlags
{
    uint8_t infiniteAmmo;
    uint8_t addSmokeOnExplosion;
    uint8_t fuse;
    uint8_t fixedAfterExplosion;

    ClrAmmoFlags() = default;

    ClrAmmoFlags(alt::AmmoFlags info) : infiniteAmmo(info.infiniteAmmo),
                                        addSmokeOnExplosion(info.addSmokeOnExplosion),
                                        fuse(info.fuse),
                                        fixedAfterExplosion(info.fixedAfterExplosion)
    {
    }
};
