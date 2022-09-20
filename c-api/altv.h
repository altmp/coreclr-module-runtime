#pragma once

#include "utils/export.h"
#include "utils/strings.h"
#include "cpp-sdk/SDK.h"

EXPORT_SHARED void FreeUIntArray(alt::Array<uint32_t> *array);
//EXPORT void FreePlayerPointerArray(alt::Array<alt::IPlayer*> *array);
//EXPORT void FreeStringViewArray(alt::Array<std::stringView> *array);
//EXPORT void FreeStringArray(alt::Array<std::string>* array);
/*EXPORT void FreeMValueArray(alt::Array<alt::MValue> *array);*/
EXPORT_SHARED void FreeCharArray(char charArray[]);
EXPORT_SHARED void FreeUInt32Array(/** nint */ uint32_t* uInt32Array);
EXPORT_SHARED void FreeUInt8Array(/** nint */ uint8_t* uInt8Array);
EXPORT_SHARED void FreeVoidPointerArray(/** nint */void** voidPointerArray);
EXPORT_SHARED void FreeString(const char* string);
EXPORT_SHARED void FreeStringArray(const char** stringArray, uint32_t size);
EXPORT_SHARED void FreeResourceArray(alt::IResource** resourceArray);
EXPORT_SHARED void FreeObjectArray(alt::IObject** objectArray);
EXPORT_SHARED void FreeMValueConstArray(alt::MValueConst** mvalueConstArray);
EXPORT_SHARED const char* GetVersionStatic(int32_t &size);
EXPORT_SHARED const char* GetBranchStatic(int32_t &size);
EXPORT_SHARED uint8_t IsDebugStatic();
EXPORT_SHARED const char* GetCApiVersion(int32_t &size);
EXPORT_SHARED const char* GetSDKVersion(int32_t &size);

EXPORT_CLIENT void FreeRmlElementArray(alt::IRmlElement** rmlElementArray);
EXPORT_CLIENT void* Win_GetTaskDialog();
