#include "checkpoint.h"

#include "../utils/macros.h"

CAPI_START()

uint32_t Checkpoint_GetID(alt::ICheckpoint* checkpoint)
{
    return checkpoint->GetID();
}

alt::IColShape* Checkpoint_GetColShape(alt::ICheckpoint* checkpoint) {
    return dynamic_cast<alt::IColShape*>(checkpoint);
}

uint8_t Checkpoint_GetCheckpointType(alt::ICheckpoint* checkpoint) {
    return checkpoint->GetCheckpointType();
}

void Checkpoint_SetCheckpointType(alt::ICheckpoint* checkpoint, uint8_t type) {
    checkpoint->SetCheckpointType(type);
}

float Checkpoint_GetHeight(alt::ICheckpoint* checkpoint) {
    return checkpoint->GetHeight();
}

void Checkpoint_SetHeight(alt::ICheckpoint* checkpoint, float height) {
    checkpoint->SetHeight(height);
}

float Checkpoint_GetRadius(alt::ICheckpoint* checkpoint) {
    return checkpoint->GetRadius();
}

void Checkpoint_SetRadius(alt::ICheckpoint* checkpoint, float radius) {
    checkpoint->SetRadius(radius);
}

void Checkpoint_GetColor(alt::ICheckpoint* checkpoint, rgba_t &color) {
    auto checkpointColor = checkpoint->GetColor();
    color.r = checkpointColor.r;
    color.g = checkpointColor.g;
    color.b = checkpointColor.b;
    color.a = checkpointColor.a;
}

void Checkpoint_SetColor(alt::ICheckpoint* checkpoint, rgba_t color) {
    alt::RGBA newColor;
    newColor.r = color.r;
    newColor.g = color.g;
    newColor.b = color.b;
    newColor.a = color.a;
    checkpoint->SetColor(newColor);
}

void Checkpoint_GetIconColor(alt::ICheckpoint* checkpoint, rgba_t& color)
{
    auto checkpointIconColor = checkpoint->GetIconColor();
    color.r = checkpointIconColor.r;
    color.g = checkpointIconColor.g;
    color.b = checkpointIconColor.b;
    color.a = checkpointIconColor.a;
}

void Checkpoint_SetIconColor(alt::ICheckpoint* checkpoint, rgba_t color)
{
    alt::RGBA newColor;
    newColor.r = color.r;
    newColor.g = color.g;
    newColor.b = color.b;
    newColor.a = color.a;
    checkpoint->SetIconColor(newColor);
}

void Checkpoint_GetNextPosition(alt::ICheckpoint* checkpoint, vector3_t &pos) {
    auto position = checkpoint->GetNextPosition();
    pos.x = position.x;
    pos.y = position.y;
    pos.z = position.z;
}

void Checkpoint_SetNextPosition(alt::ICheckpoint* checkpoint, vector3_t pos) {
    checkpoint->SetNextPosition({ pos.x, pos.y, pos.z });
}

uint32_t Checkpoint_GetStreamingDistance(alt::ICheckpoint* checkpoint)
{
    return checkpoint->GetStreamingDistance();
}

void Checkpoint_SetVisible(alt::ICheckpoint* checkpoint, uint8_t toggle)
{
    checkpoint->SetVisible(toggle);
}

uint8_t Checkpoint_IsVisible(alt::ICheckpoint* checkpoint)
{
    return checkpoint->IsVisible();
}

#ifdef ALT_CLIENT_API
uint8_t Checkpoint_IsStreamedIn(alt::ICheckpoint* checkpoint)
{
    return checkpoint->IsStreamedIn();
}

uint32_t Checkpoint_GetGameID(alt::ICheckpoint* checkpoint)
{
    return checkpoint->GetGameID();
}
#endif

CAPI_END()