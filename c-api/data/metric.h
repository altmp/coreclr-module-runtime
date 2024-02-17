#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "../utils/export.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_SERVER void Metric_SetValue(alt::Metric* metric, uint64_t value);
EXPORT_SERVER uint64_t Metric_GetValue(alt::Metric* metric);
EXPORT_SERVER void Metric_Begin(alt::Metric* metric);
EXPORT_SERVER void Metric_End(alt::Metric* metric);
EXPORT_SERVER void Metric_End2(alt::Metric* metric);
EXPORT_SERVER const char* Metric_GetName(alt::Metric* metric, int32_t& size);
EXPORT_SERVER void Metric_Add(alt::Metric* metric, uint64_t value);
EXPORT_SERVER void Metric_Inc(alt::Metric* metric);
