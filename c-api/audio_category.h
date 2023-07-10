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


EXPORT_CLIENT const char* AudioCategory_GetName(const char* name, int32_t& size);

EXPORT_CLIENT float AudioCategory_GetVolume(const char* name);
EXPORT_CLIENT float AudioCategory_GetDistanceRolloffScale(const char* name);
EXPORT_CLIENT float AudioCategory_GetPlateauRolloffScale(const char* name);
EXPORT_CLIENT float AudioCategory_GetOcclusionDamping(const char* name);
EXPORT_CLIENT float AudioCategory_GetEnvironmentalFilterDamping(const char* name);
EXPORT_CLIENT float AudioCategory_GetSourceReverbDamping(const char* name);
EXPORT_CLIENT float AudioCategory_GetDistanceReverbDamping(const char* name);
EXPORT_CLIENT float AudioCategory_GetInteriorReverbDamping(const char* name);
EXPORT_CLIENT float AudioCategory_GetEnvironmentalLoudness(const char* name);
EXPORT_CLIENT float AudioCategory_GetUnderwaterWetLevel(const char* name);
EXPORT_CLIENT float AudioCategory_GetStonedWetLevel(const char* name);
EXPORT_CLIENT int16_t AudioCategory_GetPitch(const char* name);
EXPORT_CLIENT int16_t AudioCategory_GetLowPassFilterCutoff(const char* name);
EXPORT_CLIENT int16_t AudioCategory_GetHighPassFilterCutoff(const char* name);

EXPORT_CLIENT void AudioCategory_SetVolume(const char* name, float value);
EXPORT_CLIENT void AudioCategory_SetDistanceRolloffScale(const char* name, float value);
EXPORT_CLIENT void AudioCategory_SetPlateauRolloffScale(const char* name, float value);
EXPORT_CLIENT void AudioCategory_SetOcclusionDamping(const char* name, float value);
EXPORT_CLIENT void AudioCategory_SetEnvironmentalFilterDamping(const char* name, float value);
EXPORT_CLIENT void AudioCategory_SetSourceReverbDamping(const char* name, float value);
EXPORT_CLIENT void AudioCategory_SetDistanceReverbDamping(const char* name, float value);
EXPORT_CLIENT void AudioCategory_SetInteriorReverbDamping(const char* name, float value);
EXPORT_CLIENT void AudioCategory_SetEnvironmentalLoudness(const char* name, float value);
EXPORT_CLIENT void AudioCategory_SetUnderwaterWetLevel(const char* name, float value);
EXPORT_CLIENT void AudioCategory_SetStonedWetLevel(const char* name, float value);
EXPORT_CLIENT void AudioCategory_SetPitch(const char* name, int16_t value);
EXPORT_CLIENT void AudioCategory_SetLowPassFilterCutoff(const char* name, int16_t value);
EXPORT_CLIENT void AudioCategory_SetHighPassFilterCutoff(const char* name, int16_t value);

EXPORT_CLIENT void AudioCategory_Reset(const char* name);