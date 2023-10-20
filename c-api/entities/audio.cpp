#include "audio.h"
#include "../utils/strings.h"
#include "../utils/entity.h"
#include "../utils/macros.h"

CAPI_START()

uint32_t Audio_GetID(alt::IAudio* audio)
{
    return audio->GetID();
}

#ifdef ALT_CLIENT_API
alt::IBaseObject* Audio_GetBaseObject(alt::IAudio* audio) {
    return dynamic_cast<alt::IBaseObject*>(audio);
}

double Audio_GetCurrentTime(alt::IAudio* audio) {
    return audio->GetCurrentTime();
}

uint8_t Audio_GetLooped(alt::IAudio* audio) {
    return audio->IsLoop();
}

void Audio_SetLooped(alt::IAudio* audio, uint8_t value) {
    return audio->SetLoop(value);
}

double Audio_GetMaxTime(alt::IAudio* audio) {
    return audio->GetMaxTime();
}

uint8_t Audio_IsPlaying(alt::IAudio* audio) {
    return audio->IsPlaying();
}

const char* Audio_GetSource(alt::IAudio* audio, int32_t& size) {
    return AllocateString(audio->GetSource(), size);
}

void Audio_SetSource(alt::IAudio* audio, const char* value) {
    audio->SetSource(value);
}

float Audio_GetVolume(alt::IAudio* audio) {
    return audio->GetVolume();
}

void Audio_SetVolume(alt::IAudio* audio, float value) {
    audio->SetVolume(value);
}


void Audio_AddOutput(alt::IAudio* audio, alt::IAudioOutput* output) {
    audio->AddOutput(output);
}

void Audio_RemoveOutput(alt::IAudio* audio, alt::IAudioOutput* output) {
    audio->RemoveOutput(output);
}

void Audio_GetOutputs(alt::IAudio* audio, void**& entityArray, uint8_t*& entityTypesArray, uint32_t*& scriptIdArray, uint32_t& size) {
    auto outputs = audio->GetOutputs();
    size = outputs->GetSize();
    auto entityArr = new void*[size];
    auto entityTypeArr = new uint8_t[size];
    auto scriptIdArr = new uint32_t[size];

    for (auto i = 0; i < size; i++) {
        scriptIdArr[i] = 0;
        entityTypeArr[i] = 255;
        entityArr[i] = nullptr;

        auto mValue = outputs->Get(i);
        if (mValue->GetType() == alt::IMValue::Type::BASE_OBJECT) {
            auto baseObject = dynamic_cast<const alt::IMValueBaseObject*>(mValue.get())->Value();

            if (!baseObject) continue;

            auto entityPtr = Util_GetBaseObjectPointer(baseObject.get());
            if (entityPtr != nullptr) entityArr[i] = entityPtr;
        } else if (mValue->GetType() == alt::IMValue::Type::UINT) {
            auto valueRef = dynamic_cast<const alt::IMValueUInt*>(mValue.get())->Value();
            scriptIdArr[i] = valueRef;
        }
    }

    entityTypesArray = entityTypeArr;
    entityArray = entityArr;
    scriptIdArray = scriptIdArr;
}

void Audio_Pause(alt::IAudio* audio) {
    audio->Pause();
}

void Audio_Play(alt::IAudio* audio) {
    audio->Play();
}

void Audio_Reset(alt::IAudio* audio) {
    audio->Reset();
}

void Audio_Seek(alt::IAudio* audio, double time) {
    audio->Seek(time);
}
#endif

CAPI_END()