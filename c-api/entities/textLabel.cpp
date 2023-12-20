#include "textLabel.h"

#include "../utils/macros.h"
#include "../utils/strings.h"

CAPI_START()

uint32_t TextLabel_GetID(alt::ITextLabel* textLabel)
{
    return textLabel->GetID();
}

alt::IWorldObject* TextLabel_GetWorldObject(alt::ITextLabel* textLabel)
{
    return dynamic_cast<alt::IWorldObject*>(textLabel);
}

uint8_t TextLabel_IsGlobal(alt::ITextLabel* textLabel)
{
    return textLabel->IsGlobal();
}

alt::IPlayer* TextLabel_GetTarget(alt::ITextLabel* textLabel)
{
    return textLabel->GetTarget();
}

void TextLabel_GetColor(alt::ITextLabel* textLabel, rgba_t& color)
{
    auto textLabelColor = textLabel->GetColor();
    color.r = textLabelColor.r;
    color.g = textLabelColor.g;
    color.b = textLabelColor.b;
    color.a = textLabelColor.a;
}

void TextLabel_SetColor(alt::ITextLabel* textLabel, rgba_t color)
{
    alt::RGBA textLabelColor;
    textLabelColor.r = color.r;
    textLabelColor.g = color.g;
    textLabelColor.b = color.b;
    textLabelColor.a = color.a;
    textLabel->SetColor(textLabelColor);
}

void TextLabel_GetOutlineColor(alt::ITextLabel* textLabel, rgba_t& color)
{
    auto outlineColor = textLabel->GetOutlineColor();
    color.r = outlineColor.r;
    color.g = outlineColor.g;
    color.b = outlineColor.b;
    color.a = outlineColor.a;
}

void TextLabel_SetOutlineColor(alt::ITextLabel* textLabel, rgba_t color)
{
    alt::RGBA outlineColor;
    outlineColor.r = color.r;
    outlineColor.g = color.g;
    outlineColor.b = color.b;
    outlineColor.a = color.a;
    textLabel->SetOutlineColor(outlineColor);
}

float TextLabel_GetOutlineWidth(alt::ITextLabel* textLabel)
{
    return textLabel->GetOutlineWidth();
}

void TextLabel_SetOutlineWidth(alt::ITextLabel* textLabel, float width)
{
    textLabel->SetOutlineWidth(width);
}

float TextLabel_GetFontSize(alt::ITextLabel* textLabel)
{
    return textLabel->GetFontSize();
}

void TextLabel_SetFontSize(alt::ITextLabel* textLabel, float size)
{
    textLabel->SetFontSize(size);
}

uint8_t TextLabel_GetAlign(alt::ITextLabel* textLabel)
{
    return static_cast<uint8_t>(textLabel->GetAlign());
}

void TextLabel_SetAlign(alt::ITextLabel* textLabel, uint8_t align)
{
    textLabel->SetAlign(static_cast<alt::ITextLabel::Alignment>(align));
}

const char* TextLabel_GetText(alt::ITextLabel* textLabel, int32_t& size)
{
    return AllocateString(textLabel->GetText(), size);
}

void TextLabel_SetText(alt::ITextLabel* textLabel, const char* text)
{
    textLabel->SetText(text);
}

const char* TextLabel_GetFont(alt::ITextLabel* textLabel, int32_t& size)
{
    return AllocateString(textLabel->GetFont(), size);
}

void TextLabel_SetFont(alt::ITextLabel* textLabel, const char* font)
{
    textLabel->SetFont(font);
}

uint8_t TextLabel_IsVisible(alt::ITextLabel* textLabel)
{
    return textLabel->IsVisible();
}

void TextLabel_SetVisible(alt::ITextLabel* textLabel, uint8_t visible)
{
    textLabel->SetVisible(visible);
}

float TextLabel_GetScale(alt::ITextLabel* textLabel)
{
    return textLabel->GetScale();
}

void TextLabel_SetScale(alt::ITextLabel* textLabel, float scale)
{
    textLabel->SetScale(scale);
}

void TextLabel_GetRotation(alt::ITextLabel* textLabel, rotation_t& rot)
{
    auto textLabelRot = textLabel->GetRotation();
    rot.roll = textLabelRot.roll;
    rot.pitch = textLabelRot.pitch;
    rot.yaw = textLabelRot.yaw;
}

void TextLabel_SetRotation(alt::ITextLabel* textLabel, rotation_t rot)
{
    alt::Rotation textLabelRot;
    textLabelRot.roll = rot.roll;
    textLabelRot.pitch = rot.pitch;
    textLabelRot.yaw = rot.yaw;
    textLabel->SetRotation(textLabelRot);
}

uint32_t TextLabel_GetStreamingDistance(alt::ITextLabel* textLabel)
{
    return textLabel->GetStreamingDistance();
}

uint8_t TextLabel_IsFacingCamera(alt::ITextLabel* textLabel)
{
    return textLabel->IsFacingCamera();
}

void TextLabel_SetFaceCamera(alt::ITextLabel* textLabel, uint8_t faceCamera)
{
    textLabel->SetFaceCamera(faceCamera);
}

#ifdef ALT_CLIENT_API
uint8_t TextLabel_IsStreamedIn(alt::ITextLabel* textLabel)
{
    return textLabel->IsStreamedIn();
}
#endif

CAPI_END()