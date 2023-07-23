#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "../utils/export.h"
#include "../data/types.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_CLIENT uint32_t Font_GetID(alt::IFont* font);

EXPORT_CLIENT alt::IBaseObject* Font_GetBaseObject(alt::IFont* font);