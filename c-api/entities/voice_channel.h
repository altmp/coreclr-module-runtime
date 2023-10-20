#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "../utils/export.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_SHARED uint32_t VoiceChannel_GetID(alt::IVoiceChannel* voiceChannel);

EXPORT_SERVER alt::IBaseObject* VoiceChannel_GetBaseObject(alt::IVoiceChannel* voiceChannel);

EXPORT_SERVER uint8_t VoiceChannel_IsSpatial(alt::IVoiceChannel* channel);
EXPORT_SERVER float VoiceChannel_GetMaxDistance(alt::IVoiceChannel* channel);

EXPORT_SERVER uint8_t VoiceChannel_HasPlayer(alt::IVoiceChannel* channel, alt::IPlayer* player);
EXPORT_SERVER void VoiceChannel_AddPlayer(alt::IVoiceChannel* channel, alt::IPlayer* player);
EXPORT_SERVER void VoiceChannel_RemovePlayer(alt::IVoiceChannel* channel, alt::IPlayer* player);

EXPORT_SERVER uint8_t VoiceChannel_IsPlayerMuted(alt::IVoiceChannel* channel, alt::IPlayer* player);
EXPORT_SERVER void VoiceChannel_MutePlayer(alt::IVoiceChannel* channel, alt::IPlayer* player);
EXPORT_SERVER void VoiceChannel_UnmutePlayer(alt::IVoiceChannel* channel, alt::IPlayer* player);

EXPORT_SERVER alt::IPlayer** VoiceChannel_GetPlayers(alt::IVoiceChannel* channel, uint64_t& size);
EXPORT_SERVER uint64_t VoiceChannel_GetPlayerCount(alt::IVoiceChannel* channel);

EXPORT_SERVER uint32_t VoiceChannel_GetFilter(alt::IVoiceChannel* channel);
EXPORT_SERVER void VoiceChannel_SetFilter(alt::IVoiceChannel* channel, uint32_t filter);

EXPORT_SERVER int32_t VoiceChannel_GetPriority(alt::IVoiceChannel* channel);
EXPORT_SERVER void VoiceChannel_SetPriority(alt::IVoiceChannel* channel, int32_t priority);
