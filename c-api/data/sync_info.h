#pragma once

typedef struct {
    uint8_t active;
    uint32_t receivedTick;
    uint32_t fullyReceivedTick;
    uint32_t sendTick;
    uint32_t ackedSendTick;
    uint16_t propertyCount;
    uint8_t componentCount;
    uint32_t* propertyUpdateCount;
    uint32_t** propertyUpdateTicks;
} sync_info_t;