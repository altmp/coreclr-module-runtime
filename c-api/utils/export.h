#pragma once
#include "../../cpp-sdk/SDK.h"

#ifdef ALTV_CSHARP_SHARED
    #define EXPORT_CLIENT EXPORT
    #define EXPORT_SHARED EXPORT
#else
    #define EXPORT_CLIENT extern "C"
    #define EXPORT_SHARED extern "C"
#endif

#define EXPORT_SERVER EXPORT
#define NO_GC
