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

EXPORT_SHARED uint32_t AudioAttachedOutput_GetID(alt::IAudioAttachedOutput* audioAttachedOutput);

EXPORT_CLIENT alt::IAudioOutput* AudioAttachedOutput_GetAudioOutputObject(alt::IAudioAttachedOutput* audioAttachedOutput);

EXPORT_CLIENT void AudioAttachedOutput_SetEntity(alt::IAudioAttachedOutput* audioAttachedOutput, alt::IWorldObject* entity);
EXPORT_CLIENT alt::IWorldObject* AudioAttachedOutput_GetEntity(alt::IAudioAttachedOutput* audioAttachedOutput);
