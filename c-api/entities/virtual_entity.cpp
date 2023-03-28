#include "virtual_entity.h"

#include "../utils/strings.h"
#include "../utils/uint.h"

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
    return new alt::MValueConst(virtualEntity->GetStreamSyncedMetaData(key));
}

alt::IBaseObject* VirtualEntity_GetBaseObject(alt::IVirtualEntity* virtualEntity)
{
    return dynamic_cast<alt::IBaseObject*>(virtualEntity);
}

#ifdef ALT_CLIENT_API
uint32_t VirtualEntity_GetRemoteID(alt::IVirtualEntity* virtualEntity)
{
    return virtualEntity->GetRemoteID();
}

#endif

#ifdef ALT_SERVER_API
uint32_t VirtualEntity_GetStreamingDistance(alt::IVirtualEntity* virtualEntity)
{
    return virtualEntity->GetStreamingDistance();
}

void VirtualEntity_SetStreamSyncedMetaData(alt::IVirtualEntity* virtualEntity, const char* key, alt::MValueConst* val)
{
    if (val == nullptr) return;
    virtualEntity->SetStreamSyncedMetaData(key, val->Get()->Clone());
}

void VirtualEntity_DeleteStreamSyncedMetaData(alt::IVirtualEntity* virtualEntity, const char* key)
{
    virtualEntity->DeleteStreamSyncedMetaData(key);
}
#endif
