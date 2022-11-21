#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "../data/types.h"
#include "../data/cloth.h"
#include "../data/head_overlay.h"
#include "../utils/export.h"
#include "c-api/cache/CachedBaseObject.h"
#include "c-api/cache/CachedPlayer.h"
#include "c-api/cache/CachedVehicle.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_SHARED void BaseObject_SetMetaData(alt::IBaseObject* baseObject, const char* key, alt::MValueConst* value);
EXPORT_SHARED uint8_t BaseObject_HasMetaData(alt::IBaseObject* baseObject, const char* key);
EXPORT_SHARED void BaseObject_DeleteMetaData(alt::IBaseObject* baseObject, const char* key);
EXPORT_SHARED alt::MValueConst* BaseObject_GetMetaData(alt::IBaseObject* baseObject, const char* key);
EXPORT_SHARED void* BaseObject_TryCache(alt::IBaseObject* baseObject);
EXPORT_SHARED void BaseObject_DestructCache(alt::IBaseObject* baseObject);

EXPORT_SHARED uint8_t BaseObject_GetType(alt::IBaseObject* baseObject);