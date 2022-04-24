#pragma once
#include "../../cpp-sdk/SDK.h"

#ifdef ALTV_CSHARP_SHARED
    #define EXPORT_CLIENT extern "C"
#else
    #define EXPORT_CLIENT EXPORT
#endif

#define EXPORT_SERVER EXPORT
#define EXPORT_SHARED EXPORT
#define NO_GC