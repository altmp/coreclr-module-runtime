#include "audio_attached_output.h"

#include "../utils/macros.h"

CAPI_START()

uint32_t AudioAttachedOutput_GetID(alt::IAudioAttachedOutput* audioAttachedOutput)
{
    return audioAttachedOutput->GetID();
}

#ifdef ALT_CLIENT_API
alt::IAudioOutput* AudioAttachedOutput_GetAudioOutputObject(alt::IAudioAttachedOutput* audioAttachedOutput)
{
    return dynamic_cast<alt::IAudioOutput*>(audioAttachedOutput);
}

void AudioAttachedOutput_SetEntity(alt::IAudioAttachedOutput* audioAttachedOutput, alt::IWorldObject* entity)
{
    audioAttachedOutput->SetEntity(entity);
}

alt::IWorldObject* AudioAttachedOutput_GetEntity(alt::IAudioAttachedOutput* audioAttachedOutput, alt::IBaseObject::Type& type)
{
    auto entity = audioAttachedOutput->GetEntity();
    type = entity->GetType();
    return entity;
}
#endif

CAPI_END()