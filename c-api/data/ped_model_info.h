#pragma once

#include "cpp-sdk/ICore.h"

struct ClrPedModelInfo {
    char* name = nullptr;
    uint32_t hash;

	alt::BoneInfo* bones;
    uint32_t boneSize;

    ClrPedModelInfo() = default;

    ClrPedModelInfo(alt::PedModelInfo info) :
            hash(info.hash) {
        name = new char[info.name.length() + 1];
        strcpy(name, info.name.c_str());

        auto pedModelBones = info.bones;
        boneSize = pedModelBones.size();
        bones = new alt::BoneInfo[boneSize];
        for (auto i = 0; i < boneSize; i++) {
            bones[i] = pedModelBones[i];
        }
    }

    ~ClrPedModelInfo() {
        delete[] name;
    }
};