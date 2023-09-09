#pragma once

#include <cpp-sdk/CRefCountable.h>
#include <cpp-sdk/ICore.h>
#include <cpp-sdk/objects/IBaseObject.h>
#include <cpp-sdk/types/MValue.h>

#include "CachedEntity.h"

namespace cache
{
    class CachedObject : public virtual CachedEntity, public virtual CachedWorldObject, public virtual CachedBaseObject, public virtual alt::IObject
    {
    public:
        CachedObject(IObject* base) : CachedBaseObject(base),
                                                    CachedWorldObject(base),
                                                    CachedEntity(base),
                                                    _alpha(base->GetAlpha()),
                                                    _textureVariation(base->GetTextureVariation()),
                                                    _lodDistance(base->GetLodDistance())
        {

        }

        uint8_t _alpha;
        uint8_t GetAlpha() const override
        {
            return _alpha;
        }

        uint8_t _textureVariation;
        uint8_t GetTextureVariation() const override
        {
            return _textureVariation;
        }

        uint16_t _lodDistance;
        uint16_t GetLodDistance() const override
        {
            return _lodDistance;
        }

        void SetMultipleMetaData(const std::unordered_map<std::string, alt::MValue>& values) override {};

#ifdef ALT_SERVER_API
        void ActivatePhysics() override {}
        void PlaceOnGroundProperly() override {}
        void SetAlpha(uint8_t alpha) override {}
        void SetTextureVariation(uint8_t textureVariation) override {}
        void SetLodDistance(uint16_t lodDistance) override {}

        void SetMultipleSyncedMetaData(const std::unordered_map<std::string, alt::MValue>& values) override {}
        void SetMultipleStreamSyncedMetaData(const std::unordered_map<std::string, alt::MValue>& values) override {}
#endif

    };
}