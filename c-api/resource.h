#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "data/config_node_data.h"
#include "utils/export.h"

#if ALT_SERVER_API
#include <CSharpResourceImpl.h>
#elif ALT_CLIENT_API
#include "../client/src/runtime/CSharpResourceImpl.h"
#endif

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_SHARED const char* Resource_GetName(alt::IResource* resource, int32_t& size);
EXPORT_SHARED const char* Resource_GetType(alt::IResource* resource, int32_t& size);

EXPORT_SHARED CSharpResourceImpl* Resource_GetCSharpImpl(alt::IResource* resource);
    
EXPORT_SHARED uint64_t Resource_GetExportsCount(alt::IResource* resource);
EXPORT_SHARED void Resource_GetExports(alt::IResource* resource, const char* keys[], alt::MValueConst* values[]);
EXPORT_SHARED alt::MValueConst* Resource_GetExport(alt::IResource* resource, const char* key);
EXPORT_SHARED int Resource_GetDependenciesSize(alt::IResource* resource);
EXPORT_SHARED void Resource_GetDependencies(alt::IResource* resource, const char* dependencies[], int size);
EXPORT_SHARED int Resource_GetDependantsSize(alt::IResource* resource);
EXPORT_SHARED void Resource_GetDependants(alt::IResource* resource, const char* dependencies[], int size);
EXPORT_SHARED void Resource_SetExport(alt::ICore* core, alt::IResource* resource, const char* key, alt::MValueConst* val);
EXPORT_SHARED void Resource_SetExports(alt::ICore* core, alt::IResource* resource, alt::MValueConst* val[], const char* keys[], int size);
EXPORT_SHARED uint8_t Resource_IsStarted(alt::IResource* resource);
EXPORT_SHARED alt::IResource::Impl* Resource_GetImpl(alt::IResource* resource);

EXPORT_SERVER const char* Resource_GetPath(alt::IResource* resource, int32_t& size);
EXPORT_SERVER const char* Resource_GetMain(alt::IResource* resource, int32_t& size);
EXPORT_SERVER void Resource_Start(alt::IResource* resource);
EXPORT_SERVER void Resource_Stop(alt::IResource* resource);
EXPORT_SERVER ClrConfigNodeData* Resource_GetConfig(alt::IResource* resource);

EXPORT_CLIENT void Resource_GetFile(alt::IResource* resource, const char* path, int* bufferSize, void** buffer);
EXPORT_CLIENT bool Resource_FileExists(alt::IResource* resource, const char* path);
EXPORT_CLIENT alt::ILocalStorage* Resource_GetLocalStorage(alt::IResource* resource);
