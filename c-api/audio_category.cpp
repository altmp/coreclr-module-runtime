#include "audio_category.h"

#include "utils/macros.h"
#include "utils/strings.h"

CAPI_START()

#ifdef ALT_CLIENT_API

const char* AudioCategory_GetName(const char* name, int32_t& size) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);    
    return AllocateString(audioCategory->GetName(), size);
}

float AudioCategory_GetVolume(const char* name) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    return audioCategory->GetVolume(); 
}

float AudioCategory_GetDistanceRolloffScale(const char* name) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    return audioCategory->GetDistanceRolloffScale(); 
}

float AudioCategory_GetPlateauRolloffScale(const char* name) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    return audioCategory->GetPlateauRolloffScale(); 
}

float AudioCategory_GetOcclusionDamping(const char* name) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    return audioCategory->GetOcclusionDamping(); 
}

float AudioCategory_GetEnvironmentalFilterDamping(const char* name) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    return audioCategory->GetEnvironmentalFilterDamping(); 
}

float AudioCategory_GetSourceReverbDamping(const char* name) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    return audioCategory->GetSourceReverbDamping(); 
}

float AudioCategory_GetDistanceReverbDamping(const char* name) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    return audioCategory->GetDistanceReverbDamping(); 
}

float AudioCategory_GetInteriorReverbDamping(const char* name) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    return audioCategory->GetInteriorReverbDamping(); 
}

float AudioCategory_GetEnvironmentalLoudness(const char* name) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    return audioCategory->GetEnvironmentalLoudness(); 
}

float AudioCategory_GetUnderwaterWetLevel(const char* name) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    return audioCategory->GetUnderwaterWetLevel(); 
}

float AudioCategory_GetStonedWetLevel(const char* name) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    return audioCategory->GetStonedWetLevel(); 
}

int16_t AudioCategory_GetPitch(const char* name) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    return audioCategory->GetPitch(); 
}

int16_t AudioCategory_GetLowPassFilterCutoff(const char* name) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    return audioCategory->GetLowPassFilterCutoff(); 
}

int16_t AudioCategory_GetHighPassFilterCutoff(const char* name) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    return audioCategory->GetHighPassFilterCutoff(); 
}

void AudioCategory_SetVolume(const char* name, float value) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    audioCategory->SetVolume(value); 
}

void AudioCategory_SetDistanceRolloffScale(const char* name, float value) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    audioCategory->SetDistanceRolloffScale(value); 
}

void AudioCategory_SetPlateauRolloffScale(const char* name, float value) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    audioCategory->SetPlateauRolloffScale(value); 
}

void AudioCategory_SetOcclusionDamping(const char* name, float value) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    audioCategory->SetOcclusionDamping(value); 
}

void AudioCategory_SetEnvironmentalFilterDamping(const char* name, float value) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    audioCategory->SetEnvironmentalFilterDamping(value); 
}

void AudioCategory_SetSourceReverbDamping(const char* name, float value) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    audioCategory->SetSourceReverbDamping(value); 
}

void AudioCategory_SetDistanceReverbDamping(const char* name, float value) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    audioCategory->SetDistanceReverbDamping(value); 
}

void AudioCategory_SetInteriorReverbDamping(const char* name, float value) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    audioCategory->SetInteriorReverbDamping(value); 
}

void AudioCategory_SetEnvironmentalLoudness(const char* name, float value) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    audioCategory->SetEnvironmentalLoudness(value); 
}

void AudioCategory_SetUnderwaterWetLevel(const char* name, float value) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    audioCategory->SetUnderwaterWetLevel(value); 
}

void AudioCategory_SetStonedWetLevel(const char* name, float value) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    audioCategory->SetStonedWetLevel(value); 
}

void AudioCategory_SetPitch(const char* name, int16_t value) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    audioCategory->SetPitch(value); 
}

void AudioCategory_SetLowPassFilterCutoff(const char* name, int16_t value) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    audioCategory->SetLowPassFilterCutoff(value); 
}

void AudioCategory_SetHighPassFilterCutoff(const char* name, int16_t value) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    audioCategory->SetHighPassFilterCutoff(value); 
}

void AudioCategory_Reset(const char* name) {
    auto audioCategory = alt::ICore::Instance().GetAudioCategory(name);
    audioCategory->Reset(); 
}

#endif

CAPI_END()