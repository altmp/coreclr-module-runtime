#pragma once
#include "cpp-sdk/SDK.h"

#define EXPORT_CLIENT
#define EXPORT_SHARED

#ifdef ALT_SERVER_API
#define EXPORT_SERVER EXPORT
#else 
#define EXPORT_SERVER
#endif

#define NO_GC
#define ONLY_MANUAL
