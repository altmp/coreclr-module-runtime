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

EXPORT_SHARED uint16_t Ped_GetID(alt::IPed* ped);
EXPORT_SHARED alt::IEntity* Ped_GetEntity(alt::IPed* ped);

EXPORT_SERVER void Ped_AttachToEntity(alt::IPed* ped, alt::IEntity* entity, int16_t otherBone, int16_t ownBone, position_t pos, rotation_t rot, uint8_t collision, uint8_t noFixedRot);
EXPORT_SERVER void Ped_AttachToEntity_BoneString(alt::IPed* ped, alt::IEntity* entity, const char* otherBone, const char* ownBone, position_t pos, rotation_t rot, uint8_t collision, uint8_t noFixedRot);
EXPORT_SERVER void Ped_Detach(alt::IPed* ped);