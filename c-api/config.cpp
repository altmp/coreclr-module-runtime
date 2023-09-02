#include "config.h"

#include "utils/macros.h"

CAPI_START()

void Config_Delete(ClrConfigNodeData* node) {
    delete node;
}

CAPI_END()