#pragma once
#include "../../cpp-sdk/SDK.h"

#ifdef ALTV_CSHARP_SHARED
    #define EXPORT_CLIENT EXPORT
#else
    #define EXPORT_CLIENT extern "C"
#endif

#define EXPORT_SERVER EXPORT
#define EXPORT_SHARED EXPORT
#define NO_GC
