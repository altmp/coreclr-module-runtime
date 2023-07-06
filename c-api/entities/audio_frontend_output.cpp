#include "audio_frontend_output.h"

uint32_t AudioFrontendOutput_GetID(alt::IAudioFrontendOutput* audioFrontendOutput)
{
    return audioFrontendOutput->GetID();
}

#ifdef ALT_CLIENT_API
alt::IAudioOutput* AudioFrontendOutput_GetAudioOutputObject(alt::IAudioFrontendOutput* audioFrontendOutput)
{
    return dynamic_cast<alt::IAudioOutput*>(audioFrontendOutput);
}
#endif
