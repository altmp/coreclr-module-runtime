#pragma once
#include "cpp-sdk/SDK.h"

typedef struct {
    float x;
    float y;
    float z;
} vector3_t;

typedef struct {
    float x;
    float y;
} vector2_t;

typedef struct {
    uint32_t componentsCount;
    uint32_t hash;
    uint8_t tintIndex;
    uint32_t* components;
} weapon_t;

typedef struct {
    float x;
    float y;
    float z;
} position_t;

typedef struct {
    float roll;
    float pitch;
    float yaw;
} rotation_t;

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} rgba_t;

typedef struct
{
    uint8_t active;
    uint8_t alpha;
    float size;
    int16_t boneIndex;
    vector3_t offset;
    vector3_t direction;
    vector3_t side;
} vehicleBadgePosition_t;