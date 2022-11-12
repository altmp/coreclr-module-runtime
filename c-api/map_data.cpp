#include "./map_data.h"
#include "./utils/strings.h"

#ifdef ALT_CLIENT_API
void MapData_SetFScrollSpeed(uint32_t id, float value) {
    auto mapData = alt::ICore::Instance().GetMapData(zoomDataId);
    mapData->SetScrollSpeed(value);
}

float MapData_GetFScrollSpeed(uint32_t id) {
    auto mapData = alt::ICore::Instance().GetMapData(zoomDataId);
    return mapData->GetScrollSpeed();
}

void MapData_SetFZoomScale(uint32_t id, float value) {
    auto mapData = alt::ICore::Instance().GetMapData(zoomDataId);
    mapData->SetZoomScale(value);
}

float MapData_GetFZoomScale(uint32_t id) {
    auto mapData = alt::ICore::Instance().GetMapData(zoomDataId);
    return mapData->GetZoomScale();
}

void MapData_SetFZoomSpeed(uint32_t id, float value) {
    auto mapData = alt::ICore::Instance().GetMapData(zoomDataId);
    mapData->SetZoomSpeed(value);
}

float MapData_GetFZoomSpeed(uint32_t id) {
    auto mapData = alt::ICore::Instance().GetMapData(zoomDataId);
    return mapData->GetZoomSpeed();
}

void MapData_SetVTilesX(uint32_t id, float value) {
    auto mapData = alt::ICore::Instance().GetMapData(zoomDataId);
    mapData->SetTilesCountX(value);
}

float MapData_GetVTilesX(uint32_t id) {
    auto mapData = alt::ICore::Instance().GetMapData(zoomDataId);
    return mapData->GetTilesCountX();
}

void MapData_SetVTilesY(uint32_t id, float value) {
    auto mapData = alt::ICore::Instance().GetMapData(zoomDataId);
    mapData->SetTilesCountY(value);
}

float MapData_GetVTilesY(uint32_t id) {
    auto mapData = alt::ICore::Instance().GetMapData(zoomDataId);
    return mapData->GetTilesCountY();
}
#endif