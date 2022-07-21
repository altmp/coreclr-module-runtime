//
// Created by doxoh on 21.07.2022.
//

#include "uint.h"
#include "cpp-sdk/types/Array.h"

const uint32_t* AllocateUInt32Array(std::vector<uint32_t> arr, uint32_t& size) {
    size = arr.size();
    auto out = new uint32_t[size];

    std::copy(arr.begin(), arr.end(), out);

    return out;
} 