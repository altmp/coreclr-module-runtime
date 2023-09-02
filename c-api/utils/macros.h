#pragma once

#ifdef ALT_CLIENT_API

#ifdef __clang__

// clang and bang
#define CAPI_START() _Pragma("clang optimize off")
#define CAPI_END()  _Pragma("clang optimize on")

#else

// msvc i pososi
#define CAPI_START() __pragma(optimize("", off))
#define CAPI_END()  __pragma(optimize("", on))

#endif

#else

#define CAPI_START()
#define CAPI_END()

#endif