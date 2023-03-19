#pragma once

#include "cpp-sdk/ICore.h"

struct ClrBoneInfo
{
    uint16_t id;
    uint16_t index;
    char name[256];

    ClrBoneInfo() = default;
    ClrBoneInfo(alt::BoneInfo info) : id(info.id), index(info.index), name() {
        std::copy(info.name.begin(), info.name.size() >= 255 ? info.name.begin() + 255 : info.name.end(), name);
        name[std::min((int) info.name.size(), 255)] = '\0';
    }
};