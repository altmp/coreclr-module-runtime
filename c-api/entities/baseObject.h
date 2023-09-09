#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "../utils/export.h"
#include "../cache/CachedBaseObject.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_SHARED void BaseObject_SetMetaData(alt::IBaseObject* baseObject, const char* key, alt::MValueConst* value);
EXPORT_SHARED void BaseObject_SetMultipleMetaData(alt::IBaseObject* baseObject, const char* keys[], alt::MValueConst* values[], uint64_t size);
EXPORT_SHARED uint8_t BaseObject_HasMetaData(alt::IBaseObject* baseObject, const char* key);
EXPORT_SHARED void BaseObject_DeleteMetaData(alt::IBaseObject* baseObject, const char* key);
EXPORT_SHARED alt::MValueConst* BaseObject_GetMetaData(alt::IBaseObject* baseObject, const char* key);
EXPORT_SHARED void* BaseObject_TryCache(alt::IBaseObject* baseObject);
EXPORT_SHARED void BaseObject_DestructCache(alt::IBaseObject* baseObject);

EXPORT_SHARED uint8_t BaseObject_GetType(alt::IBaseObject* baseObject);

EXPORT_SHARED uint8_t BaseObject_HasSyncedMetaData(alt::IBaseObject* baseObject, const char* key);
EXPORT_SHARED alt::MValueConst* BaseObject_GetSyncedMetaData(alt::IBaseObject* baseObject, const char* key);

EXPORT_SERVER void BaseObject_SetSyncedMetaData(alt::IBaseObject* baseObject, const char* key, alt::MValueConst* val);
EXPORT_SERVER void BaseObject_SetMultipleSyncedMetaData(alt::IBaseObject* baseObject, const char* keys[], alt::MValueConst* values[], uint64_t size);
EXPORT_SERVER void BaseObject_DeleteSyncedMetaData(alt::IBaseObject* baseObject, const char* key);

EXPORT_CLIENT uint32_t BaseObject_GetRemoteID(alt::IBaseObject* baseObject);
EXPORT_CLIENT uint8_t BaseObject_IsRemote(alt::IBaseObject* baseObject);