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

EXPORT_SHARED uint32_t AudioWorldOutput_GetID(alt::IAudioWorldOutput* audioWorldOutput);

EXPORT_CLIENT alt::IAudioOutput* AudioWorldOutput_GetAudioOutputObject(alt::IAudioWorldOutput* audioWorldOutput);

EXPORT_CLIENT void AudioWorldOutput_SetPosition(alt::IAudioWorldOutput* audioWorldOutput, alt::Position pos);
EXPORT_CLIENT alt::Position AudioWorldOutput_GetPosition(alt::IAudioWorldOutput* audioWorldOutput);
