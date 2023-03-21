#pragma once

#include <cpp-sdk/CRefCountable.h>
#include <cpp-sdk/ICore.h>
#include <cpp-sdk/objects/IBaseObject.h>
#include <cpp-sdk/types/MValue.h>

#include "CachedEntity.h"

namespace cache
{
    class CachedPed : public virtual CachedEntity, public virtual CachedWorldObject, public virtual CachedBaseObject, public virtual alt::IPed
    {
    public:
        CachedPed(IPed* base): CachedBaseObject(base), CachedWorldObject(base), CachedEntity(base)
        {

        }
    };

}