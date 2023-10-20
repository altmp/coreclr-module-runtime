#include "marker.h"

#include "../utils/macros.h"

CAPI_START()

alt::IWorldObject* Marker_GetWorldObject(alt::IMarker* marker)
{
    return dynamic_cast<alt::IWorldObject*>(marker);
}

uint32_t Marker_GetID(alt::IMarker* marker)
{
    return marker->GetID();
}

uint32_t Marker_IsGlobal(alt::IMarker* marker)
{
    return marker->IsGlobal();
}

alt::IPlayer* Marker_GetTarget(alt::IMarker* marker)
{
    return marker->GetTarget();
}

void Marker_GetColor(alt::IMarker* marker, rgba_t& color)
{
    auto markerColor = marker->GetColor();
    color.r = markerColor.r;
    color.g = markerColor.g;
    color.b = markerColor.b;
    color.a = markerColor.a;
}

void Marker_SetColor(alt::IMarker* marker, rgba_t color)
{
    alt::RGBA rgba;
    rgba.r = color.r;
    rgba.g = color.g;
    rgba.b = color.b;
    rgba.a = color.a;
    marker->SetColor(rgba);
}

uint8_t Marker_IsVisible(alt::IMarker* marker)
{
    return marker->IsVisible();
}

void Marker_SetVisible(alt::IMarker* marker, uint8_t visible)
{
    marker->SetVisible(visible);
}

uint8_t Marker_GetMarkerType(alt::IMarker* marker)
{
    return (uint8_t)marker->GetMarkerType();
}

void Marker_SetMarkerType(alt::IMarker* marker, uint8_t type)
{
    marker->SetMarkerType((alt::IMarker::MarkerType)type);
}

void Marker_GetScale(alt::IMarker* marker, position_t& scale)
{
    auto markerScale = marker->GetScale();
    scale.x = markerScale.x;
    scale.y = markerScale.y;
    scale.z = markerScale.z;
}

void Marker_SetScale(alt::IMarker* marker, position_t scale)
{
    alt::Position markerScale;
    markerScale.x = scale.x;
    markerScale.y = scale.y;
    markerScale.z = scale.z;
    marker->SetScale(markerScale);
}

void Marker_GetRotation(alt::IMarker* marker, rotation_t& rot)
{
    auto markerRotation = marker->GetRotation();
    rot.roll = markerRotation.roll;
    rot.pitch = markerRotation.pitch;
    rot.yaw = markerRotation.yaw;
}

void Marker_SetRotation(alt::IMarker* marker, rotation_t rot)
{
    alt::Rotation markerRot;
    markerRot.roll = rot.roll;
    markerRot.pitch = rot.pitch;
    markerRot.yaw = rot.yaw;
    marker->SetRotation(markerRot);
}

void Marker_GetDirection(alt::IMarker* marker, position_t& dir)
{
    auto markerDirection = marker->GetDirection();
    dir.x = markerDirection.x;
    dir.y = markerDirection.y;
    dir.z = markerDirection.z;
}

void Marker_SetDirection(alt::IMarker* marker, position_t dir)
{
    alt::Position markerDir;
    markerDir.x = dir.x;
    markerDir.y = dir.y;
    markerDir.z = dir.z;
    marker->SetScale(markerDir);
}

uint32_t Marker_GetStreamingDistance(alt::IMarker* marker)
{
    return marker->GetStreamingDistance();
}

uint8_t Marker_IsFaceCamera(alt::IMarker* marker)
{
    return marker->IsFaceCamera();
}

void Marker_SetFaceCamera(alt::IMarker* marker, uint8_t faceCamera)
{
    marker->SetFaceCamera(faceCamera);
}

uint8_t Marker_IsRotating(alt::IMarker* marker)
{
    return marker->IsRotating();
}

void Marker_SetRotating(alt::IMarker* marker, uint8_t rotating)
{
    marker->SetRotating(rotating);
}

uint8_t Marker_IsBobUpDown(alt::IMarker* marker)
{
    return marker->IsBobUpDown();
}

void Marker_SetBobUpDown(alt::IMarker* marker, uint8_t bobUpDown)
{
    marker->SetBobUpDown(bobUpDown);
}

#ifdef ALT_CLIENT_API
uint8_t Marker_IsStreamedIn(alt::IMarker* marker)
{
    return marker->IsStreamedIn();
}
#endif

CAPI_END()