#include "textLabel.h"

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

uint8_t TextLabel_GetVisible(alt::ITextLabel* textLabel)
{
    return textLabel->GetVisible();
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

#ifdef ALT_CLIENT_API
uint8_t TextLabel_IsRemote(alt::ITextLabel* textLabel)
{
    return textLabel->IsRemote();
}

uint32_t TextLabel_GetRemoteID(alt::ITextLabel* textLabel)
{
    return textLabel->GetRemoteID();
}
#endif