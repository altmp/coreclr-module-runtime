#pragma once

#include <cpp-sdk/CRefCountable.h>
#include <cpp-sdk/ICore.h>
#include <cpp-sdk/objects/IBaseObject.h>
#include <cpp-sdk/types/MValue.h>

#include "CachedEntity.h"

namespace cache
{
    class CachedPed : public virtual CachedEntity, public virtual CachedWorldObject, public virtual CachedBaseObject,
                      public virtual alt::IPed
    {
    public:
        CachedPed(IPed* base): CachedBaseObject(base),
                               CachedWorldObject(base),
                               CachedEntity(base),
                               _health(base->GetHealth()),
                               _maxHealth(base->GetMaxHealth()),
                               _armour(base->GetArmour()),
                               _currentWeapon(base->GetCurrentWeapon())
        {
        }

        void SetMultipleMetaData(const std::unordered_map<std::string, alt::MValue>& values) override {};

        uint16_t _health;

        uint16_t GetHealth() const override
        {
            return _health;
        }

        uint16_t _maxHealth;

        uint16_t GetMaxHealth() const override
        {
            return _maxHealth;
        }

        uint16_t _armour;

        uint16_t GetArmour() const override
        {
            return _armour;
        }

        uint32_t _currentWeapon;

        uint32_t GetCurrentWeapon() const override
        {
            return _currentWeapon;
        }

#ifdef ALT_SERVER_API
        void SetHealth(uint16_t health) override
        {
        }

        void SetMaxHealth(uint16_t health) override
        {
        }

        void SetArmour(uint16_t health) override
        {
        }

        void SetCurrentWeapon(uint32_t weapon) override
        {
        }

        void SetMultipleSyncedMetaData(const std::unordered_map<std::string, alt::MValue>& values) override {}
        void SetMultipleStreamSyncedMetaData(const std::unordered_map<std::string, alt::MValue>& values) override {}
#endif
    };
}
