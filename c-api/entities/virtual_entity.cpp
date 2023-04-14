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

alt::IWorldObject* VirtualEntity_GetWorldObject(alt::IVirtualEntity* virtualEntity)
{
    return dynamic_cast<alt::IWorldObject*>(virtualEntity);
}

uint32_t VirtualEntity_GetStreamingDistance(alt::IVirtualEntity* virtualEntity)
{
    return virtualEntity->GetStreamingDistance();
}


#ifdef ALT_CLIENT_API
uint32_t VirtualEntity_GetRemoteID(alt::IVirtualEntity* virtualEntity)
{
    return virtualEntity->GetRemoteID();
}

uint8_t VirtualEntity_IsRemote(alt::IVirtualEntity* virtualEntity)
{
    return virtualEntity->IsRemote();
}

uint8_t VirtualEntity_IsStreamedIn(alt::IVirtualEntity* virtualEntity)
{
    return virtualEntity->IsStreamedIn();
}

#endif


#ifdef ALT_SERVER_API
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