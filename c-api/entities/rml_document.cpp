#include "rml_document.h"

#include "../utils/macros.h"
#include "../utils/strings.h"

CAPI_START()

uint32_t RmlDocument_GetID(alt::IRmlDocument* rmlDocument)
{
    return rmlDocument->GetID();
}

#ifdef ALT_CLIENT_API

alt::IRmlElement* RmlDocument_GetRmlElement(alt::IRmlDocument* rmlDocument) {
    return dynamic_cast<alt::IRmlElement*>(rmlDocument);
}

alt::IRmlElement* RmlDocument_GetBody(alt::IRmlDocument* rmlDocument) {
    return rmlDocument->GetBody();
}

const char* RmlDocument_GetSourceUrl(alt::IRmlDocument* rmlDocument, int32_t& size) {
    return AllocateString(rmlDocument->GetSourceUrl(), size);
}

uint8_t RmlDocument_IsModal(alt::IRmlDocument* rmlDocument) {
    return rmlDocument->IsModal();
}

uint8_t RmlDocument_IsVisible(alt::IRmlDocument* rmlDocument) {
    return rmlDocument->IsVisible();
}

const char* RmlDocument_GetTitle(alt::IRmlDocument* rmlDocument, int32_t& size) {
    return AllocateString(rmlDocument->GetTitle(), size);
}

void RmlDocument_SetTitle(alt::IRmlDocument* rmlDocument, const char* title) {
    rmlDocument->SetTitle(title);
}

alt::IRmlElement* RmlDocument_CreateElement(alt::IRmlDocument* rmlDocument, const char* tag, uint32_t& id) {
    auto element = rmlDocument->CreateElement(tag);

    if (!element) return nullptr;

    if (element != nullptr) {
        id = element->GetID();
    }
    return element;
}

alt::IRmlElement* RmlDocument_CreateTextNode(alt::IRmlDocument* rmlDocument, const char* text, uint32_t& id) {
    auto element = rmlDocument->CreateTextNode(text);

    if (!element) return nullptr;

    if (element != nullptr) {
        id = element->GetID();
    }
    return element;
}

void RmlDocument_Hide(alt::IRmlDocument* rmlDocument) {
    rmlDocument->Hide();
}

void RmlDocument_Show(alt::IRmlDocument* rmlDocument, uint8_t isModal, uint8_t focused) {
    rmlDocument->Show(isModal, focused);
}

void RmlDocument_Update(alt::IRmlDocument* rmlDocument) {
    rmlDocument->Update();
}
#endif

CAPI_END()