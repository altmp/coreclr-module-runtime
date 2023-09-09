#include "virtual_entity.h"

#include "../utils/strings.h"
#include "../utils/uint.h"
#include "../mvalue.h"
#include "../utils/macros.h"

CAPI_START()

uint32_t VirtualEntity_GetID(alt::IVirtualEntity* virtualEntity)
{
    return virtualEntity->GetID();
}

alt::IVirtualEntityGroup* VirtualEntity_GetGroup(alt::IVirtualEntity* virtualEntity)
{
    return virtualEntity->GetGroup();
}

uint8_t VirtualEntity_HasStreamSyncedMetaData(alt::IVirtualEntity* virtualEntity, const char* key)
{
    return virtualEntity->HasStreamSyncedMetaData(key);
}

alt::MValueConst* VirtualEntity_GetStreamSyncedMetaData(alt::IVirtualEntity* virtualEntity, const char* key)
{
    return AllocMValue(virtualEntity->GetStreamSyncedMetaData(key));
}

alt::IWorldObject* VirtualEntity_GetWorldObject(alt::IVirtualEntity* virtualEntity)
{
    return dynamic_cast<alt::IWorldObject*>(virtualEntity);
}

uint32_t VirtualEntity_GetStreamingDistance(alt::IVirtualEntity* virtualEntity)
{
    return virtualEntity->GetStreamingDistance();
}

void VirtualEntity_SetVisible(alt::IVirtualEntity* virtualEntity, uint8_t toggle)
{
    virtualEntity->SetVisible(toggle);
}

uint8_t VirtualEntity_IsVisible(alt::IVirtualEntity* virtualEntity)
{
    return virtualEntity->IsVisible();
}

#ifdef ALT_CLIENT_API
uint8_t VirtualEntity_IsStreamedIn(alt::IVirtualEntity* virtualEntity)
{
    return virtualEntity->IsStreamedIn();
}
#endif


#ifdef ALT_SERVER_API
void VirtualEntity_SetStreamSyncedMetaData(alt::IVirtualEntity* virtualEntity, const char* key, alt::MValueConst* val)
{
    if (val == nullptr) return;
    virtualEntity->SetStreamSyncedMetaData(key, val->get()->Clone());
}

void VirtualEntity_DeleteStreamSyncedMetaData(alt::IVirtualEntity* virtualEntity, const char* key)
{
    virtualEntity->DeleteStreamSyncedMetaData(key);
}

void VirtualEntity_SetMultipleStreamSyncedMetaData(alt::IVirtualEntity* virtualEntity, const char* keys[],
    alt::MValueConst* values[], uint64_t size)
{
    std::unordered_map<std::string, alt::MValue> data = {};

    for (uint64_t i = 0; i < size; i++) {
        data[keys[i]] = values[i]->get()->Clone();
    }

    virtualEntity->SetMultipleStreamSyncedMetaData(data);
}

#endif

CAPI_END()