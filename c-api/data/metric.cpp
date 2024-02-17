#include "metric.h"

#include "../utils/strings.h"

#ifdef ALT_SERVER_API
void Metric_SetValue(alt::Metric* metric, uint64_t value)
{
    metric->SetValue(value);
}

uint64_t Metric_GetValue(alt::Metric* metric)
{
    return metric->value;
}

const char* Metric_GetName(alt::Metric* metric, int32_t& size)
{
    return AllocateString(metric->name, size);
}

void Metric_Begin(alt::Metric* metric)
{
    metric->Begin();
}

void Metric_End(alt::Metric* metric)
{
    metric->End();
}

void Metric_End2(alt::Metric* metric)
{
    metric->End2();
}

void Metric_Add(alt::Metric* metric, uint64_t value)
{
    metric->Add(value);
}

void Metric_Inc(alt::Metric* metric)
{
    metric->Inc();
}
#endif
