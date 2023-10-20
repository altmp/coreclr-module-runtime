//
// Created by Fabian Terhorst on 2019-02-23.
//

#include "resource.h"

#include "mvalue.h"
#include "data/config_node_data.h"
#include "utils/macros.h"
#include "utils/strings.h"

CAPI_START()

const char* Resource_GetName(alt::IResource* resource, int32_t& size) {
    return AllocateString(resource->GetName(), size);
}

const char* Resource_GetType(alt::IResource* resource, int32_t& size) {
    return AllocateString(resource->GetType(), size);
}

CSharpResourceImpl* Resource_GetCSharpImpl(alt::IResource* resource) {
    return (CSharpResourceImpl*) resource->GetImpl();
}
uint64_t Resource_GetExportsCount(alt::IResource* resource) {
    alt::IMValueDict* dict = resource->GetExports().get();
    if (dict == nullptr) return 0;
    return dict->GetSize();
}

void Resource_GetExports(alt::IResource* resource, const char* keys[],
                         alt::MValueConst* values[]) {
    auto dict = resource->GetExports();
    if (dict.get() == nullptr) {
        return;
    }
    uint64_t i = 0;
    for (auto next = dict->Begin(); next != dict->End(); ++next) {
        alt::MValueConst mValueElement = next->second;
        keys[i] = next->first.c_str();
        values[i] = &mValueElement;
    }
}

alt::MValueConst* Resource_GetExport(alt::IResource* resource, const char* key) {
    alt::IMValueDict* dict = resource->GetExports().get();
    if (dict == nullptr) return nullptr;
    auto value = dict->Get(key);
    if (value.get() == nullptr) {
        return nullptr;
    }
    return AllocMValue(value);
}

int Resource_GetDependenciesSize(alt::IResource* resource) {
    return resource->GetDependencies().size();
}

void Resource_GetDependencies(alt::IResource* resource, const char* dependencies[], int size) {

    if (resource->GetDependencies().size() != size) return;
    for (uint64_t i = 0, length = resource->GetDependencies().size(); i < length; i++) {
        dependencies[i] = resource->GetDependencies()[i].c_str();
    }
}

int Resource_GetDependantsSize(alt::IResource* resource) {
    return resource->GetDependants().size();
}

void Resource_GetDependants(alt::IResource* resource, const char* dependencies[], int size) {

    if (resource->GetDependants().size() != size) return;
    for (uint64_t i = 0, length = resource->GetDependants().size(); i < length; i++) {
        dependencies[i] = resource->GetDependants()[i].c_str();
    }
}

void Resource_SetExport(alt::ICore* core, alt::IResource* resource, const char* key, alt::MValueConst* val) {
    alt::MValueDict dict = resource->GetExports();
    if (dict.get() == nullptr) {
        dict = core->CreateMValueDict();
        resource->SetExports(dict);
    }
    dict->Set(key, val->get()->Clone());
}

void Resource_SetExports(alt::ICore* core, alt::IResource* resource, alt::MValueConst* val[], const char* keys[], int size) {
    alt::MValueDict dict = core->CreateMValueDict();
    for (int i = 0; i < size; i++) {
        dict->Set(keys[i], val[i]->get()->Clone());
    }
    resource->SetExports(dict);
}

uint8_t Resource_IsStarted(alt::IResource* resource) {
    return resource->IsStarted();
}

alt::IResource::Impl* Resource_GetImpl(alt::IResource* resource) {
    return resource->GetImpl();
}

ClrConfigNodeData* Resource_GetConfig(alt::IResource* resource) {
    return new ClrConfigNodeData(resource->GetConfig());
}

#ifdef ALT_SERVER_API
const char* Resource_GetPath(alt::IResource* resource, int32_t& size) {
    return AllocateString(resource->GetPath(), size);
}

const char* Resource_GetMain(alt::IResource* resource, int32_t& size) {
    return AllocateString(resource->GetMain(), size);
}

void Resource_Start(alt::IResource* resource) {
    resource->GetImpl()->Start();
}

void Resource_Stop(alt::IResource* resource) {
    resource->GetImpl()->Stop();
}
#endif

#ifdef ALT_CLIENT_API
uint8_t Resource_FileExists(alt::IResource* resource, const char* path) {
    auto pkg = resource->GetPackage();
    return pkg->FileExists(path);
}

void Resource_GetFile(alt::IResource* resource, const char* path, int* bufferSize, void** buffer) {
    auto pkg = resource->GetPackage();
    if(!pkg->FileExists(path)) return;
    alt::IPackage::File* pkgFile = pkg->OpenFile(path);
    uint64_t size = pkg->GetFileSize(pkgFile);

    std::string content(size, 0);
    pkg->ReadFile(pkgFile, content.data(), content.size());
    pkg->CloseFile(pkgFile);

    *bufferSize = static_cast<int>(content.size());
    *buffer = utils::get_clr_value(content.data(), size);
}

alt::ILocalStorage* Resource_GetLocalStorage(alt::IResource* resource) {
    return resource->GetLocalStorage();
}

#endif

CAPI_END()