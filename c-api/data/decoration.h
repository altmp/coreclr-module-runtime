#pragma once

#include "cpp-sdk/ICore.h"

struct ClrDecoration
{
    uint32_t collection;
    uint32_t overlay;

    ClrDecoration() = default;

    ClrDecoration(alt::CDecoration info) : collection(info.collection),
                                           overlay(info.overlay)
    {
    }
};
