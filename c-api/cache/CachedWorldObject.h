#pragma once

#include <cpp-sdk/CRefCountable.h>
#include <cpp-sdk/ICore.h>
#include <cpp-sdk/objects/IBaseObject.h>
#include <cpp-sdk/types/MValue.h>

#include "CachedBaseObject.h"

namespace cache
{
    class CachedWorldObject : public virtual CachedBaseObject, public virtual alt::IWorldObject
    {
        alt::Position _position;
        int32_t _dimension;
    public:

        CachedWorldObject(IWorldObject* base) : CachedBaseObject(base),
            _position(base->GetPosition()),
            _dimension(base->GetDimension()) {
        }
        
        alt::Position GetPosition() const override {
            return _position;
        }
        
        void SetPosition(alt::Position pos) override {
        }
        
        int32_t GetDimension() const override {
            return _dimension;
        }
        
        void SetDimension(int32_t dimension) override {
        }


    };
} // namespace alt
