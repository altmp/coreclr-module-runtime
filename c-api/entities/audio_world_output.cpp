#include "audio_world_output.h"

#include "../utils/macros.h"

CAPI_START()

uint32_t AudioWorldOutput_GetID(alt::IAudioWorldOutput* audioWorldOutput)
{
    return audioWorldOutput->GetID();
}

#ifdef ALT_CLIENT_API
alt::IAudioOutput* AudioWorldOutput_GetAudioOutputObject(alt::IAudioWorldOutput* audioWorldOutput)
{
    return dynamic_cast<alt::IAudioOutput*>(audioWorldOutput);
}

void AudioWorldOutput_SetPosition(alt::IAudioWorldOutput* audioWorldOutput, alt::Position pos)
{
    audioWorldOutput->SetPosition(pos);
}

alt::Position AudioWorldOutput_GetPosition(alt::IAudioWorldOutput* audioWorldOutput)
{
    return audioWorldOutput->GetPosition();
}
#endif

CAPI_END()