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
EXPORT_SHARED uint8_t TextLabel_IsVisible(alt::ITextLabel* textLabel);
EXPORT_SHARED void TextLabel_SetVisible(alt::ITextLabel* textLabel, uint8_t visible);
EXPORT_SHARED float TextLabel_GetScale(alt::ITextLabel* textLabel);
EXPORT_SHARED void TextLabel_SetScale(alt::ITextLabel* textLabel, float scale);
EXPORT_SHARED void TextLabel_GetRotation(alt::ITextLabel* textLabel, rotation_t& rot);
EXPORT_SHARED void TextLabel_SetRotation(alt::ITextLabel* textLabel, rotation_t rot);

EXPORT_CLIENT uint8_t TextLabel_IsRemote(alt::ITextLabel* textLabel);
EXPORT_CLIENT uint32_t TextLabel_GetRemoteID(alt::ITextLabel* textLabel);

EXPORT_CLIENT uint8_t TextLabel_IsStreamedIn(alt::ITextLabel* textLabel);
EXPORT_SHARED uint32_t TextLabel_GetStreamingDistance(alt::ITextLabel* textLabel);