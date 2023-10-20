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

EXPORT_CLIENT uint32_t CustomTexture_GetID(alt::ICustomTexture* costumTexture);

EXPORT_CLIENT alt::IBaseObject* CustomTexture_GetBaseObject(alt::ICustomTexture* costumTexture);