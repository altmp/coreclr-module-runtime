#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include <string>
#include <vector>

const uint32_t* AllocateUInt32Array(std::vector<uint32_t> arr, uint32_t& size);