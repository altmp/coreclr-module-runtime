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

EXPORT_SHARED uint32_t AudioOutput_GetID(alt::IAudioOutput* audioOutput);

EXPORT_CLIENT alt::IBaseObject* AudioOutput_GetBaseObject(alt::IAudioOutput* audioOutput);

EXPORT_CLIENT void AudioOutput_SetVolume(alt::IAudioOutput* audioOutput, float vol);
EXPORT_CLIENT float AudioOutput_GetVolume(alt::IAudioOutput* audioOutput);

EXPORT_CLIENT void AudioOutput_SetMuted(alt::IAudioOutput* audioOutput, uint8_t toggle);
EXPORT_CLIENT uint8_t AudioOutput_IsMuted(alt::IAudioOutput* audioOutput);

EXPORT_CLIENT uint32_t AudioOutput_GetCategory(alt::IAudioOutput* audioOutput);

EXPORT_CLIENT alt::IBaseObject* AudioOutput_GetOwner(alt::IAudioOutput* audioOutput);

EXPORT_CLIENT void AudioOutput_AddFilter(alt::IAudioOutput* audioOutput, alt::IAudioFilter* filter);
EXPORT_CLIENT void AudioOutput_RemoveFilter(alt::IAudioOutput* audioOutput);
EXPORT_CLIENT alt::IAudioFilter* AudioOutput_GetFilter(alt::IAudioOutput* audioOutput);
