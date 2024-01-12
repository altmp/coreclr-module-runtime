#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "../data/types.h"
#include "../utils/export.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_SHARED uint32_t TextLabel_GetID(alt::ITextLabel* textLabel);
EXPORT_SHARED alt::IWorldObject* TextLabel_GetWorldObject(alt::ITextLabel* textLabel);

EXPORT_SHARED uint8_t TextLabel_IsGlobal(alt::ITextLabel* textLabel);
EXPORT_SHARED alt::IPlayer* TextLabel_GetTarget(alt::ITextLabel* textLabel);
EXPORT_SHARED void TextLabel_GetColor(alt::ITextLabel* textLabel, rgba_t& color);
EXPORT_SHARED void TextLabel_SetColor(alt::ITextLabel* textLabel, rgba_t color);


EXPORT_SHARED void TextLabel_GetOutlineColor(alt::ITextLabel* textLabel, rgba_t& color);
EXPORT_SHARED void TextLabel_SetOutlineColor(alt::ITextLabel* textLabel, rgba_t color);

EXPORT_SHARED float TextLabel_GetOutlineWidth(alt::ITextLabel* textLabel);
EXPORT_SHARED void TextLabel_SetOutlineWidth(alt::ITextLabel* textLabel, float width);

EXPORT_SHARED float TextLabel_GetFontSize(alt::ITextLabel* textLabel);
EXPORT_SHARED void TextLabel_SetFontSize(alt::ITextLabel* textLabel, float size);

EXPORT_SHARED uint8_t TextLabel_GetAlign(alt::ITextLabel* textLabel);
EXPORT_SHARED void TextLabel_SetAlign(alt::ITextLabel* textLabel, uint8_t align);

EXPORT_SHARED const char* TextLabel_GetText(alt::ITextLabel* textLabel, int32_t& size);
EXPORT_SHARED void TextLabel_SetText(alt::ITextLabel* textLabel, const char* text);

EXPORT_SHARED const char* TextLabel_GetFont(alt::ITextLabel* textLabel, int32_t& size);
EXPORT_SHARED void TextLabel_SetFont(alt::ITextLabel* textLabel, const char* font);

EXPORT_SHARED uint8_t TextLabel_IsVisible(alt::ITextLabel* textLabel);
EXPORT_SHARED void TextLabel_SetVisible(alt::ITextLabel* textLabel, uint8_t visible);
EXPORT_SHARED float TextLabel_GetScale(alt::ITextLabel* textLabel);
EXPORT_SHARED void TextLabel_SetScale(alt::ITextLabel* textLabel, float scale);
EXPORT_SHARED void TextLabel_GetRotation(alt::ITextLabel* textLabel, rotation_t& rot);
EXPORT_SHARED void TextLabel_SetRotation(alt::ITextLabel* textLabel, rotation_t rot);

EXPORT_CLIENT uint8_t TextLabel_IsStreamedIn(alt::ITextLabel* textLabel);
EXPORT_SHARED uint32_t TextLabel_GetStreamingDistance(alt::ITextLabel* textLabel);

EXPORT_SHARED uint8_t TextLabel_IsFacingCamera(alt::ITextLabel* textLabel);
EXPORT_SHARED void TextLabel_SetFaceCamera(alt::ITextLabel* textLabel, uint8_t faceCamera);