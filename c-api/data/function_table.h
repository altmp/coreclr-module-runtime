#pragma once
#include <cstdint>

typedef struct {
    uint32_t size;
    uint64_t* hashes;
    void** pointers; 
} function_table_t;