#include "audio_frontend_output.h"

#include "../utils/macros.h"

CAPI_START()

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

CAPI_END()