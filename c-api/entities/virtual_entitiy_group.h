#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "../data/types.h"
#include "../utils/export.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_CLIENT alt::IBaseObject* VirtualEntityGroup_GetBaseObject(alt::IVirtualEntityGroup* virtualEntityGroup);

EXPORT_SHARED uint32_t VirtualEntityGroup_GetID(alt::IVirtualEntityGroup* virtualEntityGroup);
EXPORT_SHARED uint32_t VirtualEntityGroup_GetStreamingRangeLimit(alt::IVirtualEntityGroup* virtualEntityGroup);