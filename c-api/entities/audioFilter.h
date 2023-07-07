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

EXPORT_SHARED uint32_t AudioFilter_GetID(alt::IAudioFilter* audioFilter);
EXPORT_CLIENT alt::IBaseObject* AudioFilter_GetBaseObject(alt::IAudioFilter* audioFilter);

EXPORT_CLIENT uint32_t AudioFilter_GetHash(alt::IAudioFilter* audioFilter);

EXPORT_CLIENT uint32_t AudioFilter_GetAudCategory(alt::IAudioFilter* audioFilter);
EXPORT_CLIENT void AudioFilter_SetAudCategory(alt::IAudioFilter* audioFilter, uint32_t category);

EXPORT_CLIENT uint32_t AudioFilter_AddRotateEffect(alt::IAudioFilter* audioFilter, float rate, int priority);
EXPORT_CLIENT uint32_t AudioFilter_AddVolumeEffect(alt::IAudioFilter* audioFilter, float volume, int priority);
EXPORT_CLIENT uint32_t AudioFilter_AddPeakeqEffect(alt::IAudioFilter* audioFilter, int lBand, float bandwidth, float q, float center, float gain, int priority);
EXPORT_CLIENT uint32_t AudioFilter_AddDampEffect(alt::IAudioFilter* audioFilter, float target, float quiet, float rate, float gain, float delay, int priority);
EXPORT_CLIENT uint32_t AudioFilter_AddAutowahEffect(alt::IAudioFilter* audioFilter, float dryMix, float wetMix, float feedback, float rate, float range, float freq, int priority);
EXPORT_CLIENT uint32_t AudioFilter_AddPhaserEffect(alt::IAudioFilter* audioFilter, float dryMix, float wetMix, float feedback, float rate, float range, float freq, int priority);
EXPORT_CLIENT uint32_t AudioFilter_AddChorusEffect(alt::IAudioFilter* audioFilter, float dryMix, float wetMix, float feedback, float minSweep, float maxSweep, float rate, int priority);
EXPORT_CLIENT uint32_t AudioFilter_AddDistortionEffect(alt::IAudioFilter* audioFilter, float drive, float dryMix, float wetMix, float feedback, float volume, int priority);
EXPORT_CLIENT uint32_t AudioFilter_AddCompressor2Effect(alt::IAudioFilter* audioFilter, float gain, float threshold, float ratio, float attack, float release, int priority);
EXPORT_CLIENT uint32_t AudioFilter_AddBqfEffect(alt::IAudioFilter* audioFilter, int lFilter, float center, float gain, float bandwidth, float q, float s, int priority);
EXPORT_CLIENT uint32_t AudioFilter_AddEcho4Effect(alt::IAudioFilter* audioFilter, float dryMix, float wetMix, float feedback, float delay, int priority);
EXPORT_CLIENT uint32_t AudioFilter_AddPitchshiftEffect(alt::IAudioFilter* audioFilter, float pitchShift, float semitones, long lFFTsize, long lOsamp, int priority);
EXPORT_CLIENT uint32_t AudioFilter_AddFreeverbEffect(alt::IAudioFilter* audioFilter, float dryMix, float wetMix, float roomSize, float damp, float width, uint32_t lMode, int priority);

EXPORT_CLIENT uint8_t AudioFilter_RemoveEffect(alt::IAudioFilter* audioFilter, uint32_t hfxHandler);
