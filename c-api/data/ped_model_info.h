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

struct ClrPedModelInfo {
    char* name = nullptr;
    uint32_t hash = 0;
        
    ClrBoneInfo* bones = nullptr;
    uint32_t boneSize = 0;

    ClrPedModelInfo() = default;
    ClrPedModelInfo(alt::PedModelInfo info) : hash(info.hash) {
        name = new char[info.name.length() + 1];
        std::copy(info.name.begin(), info.name.end(), name);
        name[info.name.length()] = '\0';

        const auto pedModelBones = info.bones;
        boneSize = pedModelBones.size();
        bones = new ClrBoneInfo[boneSize];
        for (uint32_t i = 0; i < boneSize; i++) {
            bones[i] = ClrBoneInfo(pedModelBones[i]);
        }
    }

    ~ClrPedModelInfo() {
        delete[] name;
        delete[] bones;
    }
};