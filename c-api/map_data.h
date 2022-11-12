#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "utils/export.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_CLIENT void MapData_SetFScrollSpeed(uint32_t id, float value);
EXPORT_CLIENT float MapData_GetFScrollSpeed(uint32_t id);
EXPORT_CLIENT void MapData_SetFZoomScale(uint32_t id, float value);
EXPORT_CLIENT float MapData_GetFZoomScale(uint32_t id);
EXPORT_CLIENT void MapData_SetFZoomSpeed(uint32_t id, float value);
EXPORT_CLIENT float MapData_GetFZoomSpeed(uint32_t id);
EXPORT_CLIENT void MapData_SetVTilesX(uint32_t id, float value);
EXPORT_CLIENT float MapData_GetVTilesX(uint32_t id);
EXPORT_CLIENT void MapData_SetVTilesY(uint32_t id, float value);
EXPORT_CLIENT float MapData_GetVTilesY(uint32_t id);
