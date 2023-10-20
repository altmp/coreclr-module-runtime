#include "audio_output.h"
#include "../utils/strings.h"
#include "../utils/entity.h"
#include "../utils/macros.h"

CAPI_START()

uint32_t AudioOutput_GetID(alt::IAudioOutput* audioOutput)
{
    return audioOutput->GetID();
}

#ifdef ALT_CLIENT_API

alt::IBaseObject* AudioOutput_GetBaseObject(alt::IAudioOutput* audioOutput)
{
    return dynamic_cast<alt::IBaseObject*>(audioOutput);
}

void AudioOutput_SetVolume(alt::IAudioOutput* audioOutput, float vol)
{
    audioOutput->SetVolume(vol);
}

float AudioOutput_GetVolume(alt::IAudioOutput* audioOutput)
{
    return audioOutput->GetVolume();
}

void AudioOutput_SetMuted(alt::IAudioOutput* audioOutput, uint8_t toggle)
{
    audioOutput->SetMuted(toggle);
}

uint8_t AudioOutput_IsMuted(alt::IAudioOutput* audioOutput)
{
    return audioOutput->IsMuted();
}

uint32_t AudioOutput_GetCategory(alt::IAudioOutput* audioOutput)
{
    return audioOutput->GetCategory();
}

alt::IBaseObject* AudioOutput_GetOwner(alt::IAudioOutput* audioOutput)
{
    return audioOutput->GetOwner();
}

void AudioOutput_AddFilter(alt::IAudioOutput* audioOutput, alt::IAudioFilter* filter)
{
    audioOutput->AddFilter(filter);
}

void AudioOutput_RemoveFilter(alt::IAudioOutput* audioOutput)
{
    audioOutput->RemoveFilter();
}

alt::IAudioFilter* AudioOutput_GetFilter(alt::IAudioOutput* audioOutput)
{
    return audioOutput->GetFilter();
}
#endif

CAPI_END()
