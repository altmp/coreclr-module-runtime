#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "../utils/export.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif


EXPORT_SHARED uint32_t AudioFrontendOutput_GetID(alt::IAudioFrontendOutput* audioFrontendOutput);

EXPORT_CLIENT alt::IAudioOutput* AudioFrontendOutput_GetAudioOutputObject(alt::IAudioFrontendOutput* audioFrontendOutput);
