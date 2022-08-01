#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "data/types.h"
#include "data/invoker.h"
#include "utils/export.h"

#ifdef ALT_SERVER_API
#include <CSharpResourceImpl.h>
#elif ALT_CLIENT_API
#include "../client/src/runtime/CSharpResourceImpl.h"
#endif

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#ifdef __cplusplus
extern "C"
{
#endif
    
EXPORT_SHARED uint8_t Object_GetAlpha(alt::IObject* object);
EXPORT_SHARED void Object_SetAlpha(alt::IObject* object, uint8_t alpha);
EXPORT_SHARED void Object_ResetAlpha(alt::IObject* object);

EXPORT_SHARED uint8_t Object_IsDynamic(alt::IObject* object);
EXPORT_SHARED void Object_SetDynamic(alt::IObject* object, uint8_t dynamic);

EXPORT_SHARED uint16_t Object_GetLodDistance(alt::IObject* object);
EXPORT_SHARED void Object_SetLodDistance(alt::IObject* object, uint16_t distance);

EXPORT_SHARED uint8_t Object_HasGravity(alt::IObject* object);
EXPORT_SHARED void Object_ToggleGravity(alt::IObject* object, uint8_t toggle);

EXPORT_SHARED uint8_t Object_IsOnFire(alt::IObject* object);
EXPORT_SHARED uint32_t Object_StartFire(alt::IObject* object);
EXPORT_SHARED void Object_StopFire(alt::IObject* object);

EXPORT_CLIENT uint8_t Object_IsRemote(alt::IObject* object);

#ifdef __cplusplus
}
#endif
