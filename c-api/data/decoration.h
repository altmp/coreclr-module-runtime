#pragma once

#include "cpp-sdk/ICore.h"

struct ClrDecoration
{
    uint32_t collection;
    uint32_t overlay;
    uint8_t count;

    ClrDecoration() = default;

    ClrDecoration(alt::CDecoration info) : collection(info.collection),
                                           overlay(info.overlay),
                                           count(info.count)
    {
    }
};
