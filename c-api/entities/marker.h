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

EXPORT_SHARED alt::IWorldObject* Marker_GetWorldObject(alt::IMarker* marker);

EXPORT_SHARED uint32_t Marker_GetID(alt::IMarker* marker);

EXPORT_SHARED uint32_t Marker_IsGlobal(alt::IMarker* marker);
EXPORT_SHARED alt::IPlayer* Marker_GetTarget(alt::IMarker* marker);

EXPORT_SHARED void Marker_GetColor(alt::IMarker* marker, rgba_t& color);
EXPORT_SHARED void Marker_SetColor(alt::IMarker* marker, rgba_t color);

EXPORT_SHARED uint8_t Marker_IsVisible(alt::IMarker* marker);
EXPORT_SHARED void Marker_SetVisible(alt::IMarker* marker, uint8_t visible);

EXPORT_SHARED uint8_t Marker_GetMarkerType(alt::IMarker* marker);
EXPORT_SHARED void Marker_SetMarkerType(alt::IMarker* marker, uint8_t type);

EXPORT_SHARED void Marker_GetScale(alt::IMarker* marker, position_t& scale);
EXPORT_SHARED void Marker_SetScale(alt::IMarker* marker, position_t scale);

EXPORT_SHARED void Marker_GetRotation(alt::IMarker* marker, rotation_t& rot);
EXPORT_SHARED void Marker_SetRotation(alt::IMarker* marker, rotation_t rot);

EXPORT_SHARED void Marker_GetDirection(alt::IMarker* marker, position_t& dir);
EXPORT_SHARED void Marker_SetDirection(alt::IMarker* marker, position_t dir);

EXPORT_SHARED uint32_t Marker_GetStreamingDistance(alt::IMarker* marker);
EXPORT_CLIENT uint8_t Marker_IsStreamedIn(alt::IMarker* marker);

EXPORT_CLIENT uint8_t Marker_IsRemote(alt::IMarker* marker);
EXPORT_CLIENT uint32_t Marker_GetRemoteID(alt::IMarker* marker);
