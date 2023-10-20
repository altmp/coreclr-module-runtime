#include "audioFilter.h"

#include "../utils/macros.h"

CAPI_START()

uint32_t AudioFilter_GetID(alt::IAudioFilter* audioFilter)
{
    return audioFilter->GetID();
}

#ifdef ALT_CLIENT_API
alt::IBaseObject* AudioFilter_GetBaseObject(alt::IAudioFilter* audioFilter)
{
    return dynamic_cast<alt::IBaseObject*>(audioFilter);
}

uint32_t AudioFilter_GetAudCategory(alt::IAudioFilter* audioFilter)
{
    return audioFilter->GetAudCategory();
}

void AudioFilter_SetAudCategory(alt::IAudioFilter* audioFilter, uint32_t category)
{
    audioFilter->SetAudCategory(category);
}

uint32_t AudioFilter_GetHash(alt::IAudioFilter* audioFilter)
{
    return audioFilter->GetHash();
}

uint32_t AudioFilter_AddRotateEffect(alt::IAudioFilter* audioFilter, float rate, int priority)
{
    return audioFilter->AddRotateEffect(rate, priority);
}

uint32_t AudioFilter_AddVolumeEffect(alt::IAudioFilter* audioFilter, float volume, int priority)
{
    return audioFilter->AddVolumeEffect(volume, priority);
}

uint32_t AudioFilter_AddPeakeqEffect(alt::IAudioFilter* audioFilter, int lBand, float bandwidth, float q, float center,
    float gain, int priority)
{
    return audioFilter->AddPeakeqEffect(lBand, bandwidth, q, center, gain, priority);
}

uint32_t AudioFilter_AddDampEffect(alt::IAudioFilter* audioFilter, float target, float quiet, float rate, float gain,
    float delay, int priority)
{
    return audioFilter->AddDampEffect(target, quiet, rate, gain, delay, priority);
}

uint32_t AudioFilter_AddAutowahEffect(alt::IAudioFilter* audioFilter, float dryMix, float wetMix, float feedback,
    float rate, float range, float freq, int priority)
{
    return audioFilter->AddAutowahEffect(dryMix, wetMix, feedback, rate, range, freq, priority);
}

uint32_t AudioFilter_AddPhaserEffect(alt::IAudioFilter* audioFilter, float dryMix, float wetMix, float feedback,
    float rate, float range, float freq, int priority)
{
    return audioFilter->AddPhaserEffect(dryMix, wetMix, feedback, rate, range, freq, priority);
}

uint32_t AudioFilter_AddChorusEffect(alt::IAudioFilter* audioFilter, float dryMix, float wetMix, float feedback,
    float minSweep, float maxSweep, float rate, int priority)
{
    return audioFilter->AddChorusEffect(dryMix, wetMix, feedback, minSweep, maxSweep, rate, priority);
}

uint32_t AudioFilter_AddDistortionEffect(alt::IAudioFilter* audioFilter, float drive, float dryMix, float wetMix,
    float feedback, float volume, int priority)
{
    return audioFilter->AddDistortionEffect(drive, dryMix, wetMix, feedback, volume, priority);
}

uint32_t AudioFilter_AddCompressor2Effect(alt::IAudioFilter* audioFilter, float gain, float threshold, float ratio,
    float attack, float release, int priority)
{
    return audioFilter->AddCompressor2Effect(gain, threshold, ratio, attack, release, priority);
}

uint32_t AudioFilter_AddBqfEffect(alt::IAudioFilter* audioFilter, int lFilter, float center, float gain,
    float bandwidth, float q, float s, int priority)
{
    return audioFilter->AddBqfEffect(lFilter, center, gain, bandwidth, q, s, priority);
}

uint32_t AudioFilter_AddEcho4Effect(alt::IAudioFilter* audioFilter, float dryMix, float wetMix, float feedback,
    float delay, int priority)
{
    return audioFilter->AddEcho4Effect(dryMix, wetMix, feedback, delay, priority);
}

uint32_t AudioFilter_AddPitchshiftEffect(alt::IAudioFilter* audioFilter, float pitchShift, float semitones,
    long lFFTsize, long lOsamp, int priority)
{
    return audioFilter->AddPitchshiftEffect(pitchShift, semitones, lFFTsize, lOsamp, priority);
}

uint32_t AudioFilter_AddFreeverbEffect(alt::IAudioFilter* audioFilter, float dryMix, float wetMix, float roomSize,
    float damp, float width, uint32_t lMode, int priority)
{
    return audioFilter->AddFreeverbEffect(dryMix, wetMix, roomSize, damp, width, lMode, priority);
}

uint8_t AudioFilter_RemoveEffect(alt::IAudioFilter* audioFilter, uint32_t hfxHandler)
{
    return audioFilter->RemoveEffect(hfxHandler);
}
#endif

CAPI_END()