#include "virtual_entitiy_group.h"

#include "../utils/macros.h"
#include "../utils/strings.h"
#include "../utils/uint.h"

CAPI_START()

uint32_t VirtualEntityGroup_GetID(alt::IVirtualEntityGroup* virtualEntityGroup)
{
    return virtualEntityGroup->GetID();
}

uint32_t VirtualEntityGroup_GetMaxEntitiesInStream(alt::IVirtualEntityGroup* virtualEntityGroup)
{
    return virtualEntityGroup->GetMaxEntitiesInStream();
}
alt::IBaseObject* VirtualEntityGroup_GetBaseObject(alt::IVirtualEntityGroup* virtualEntityGroup)
{
    return dynamic_cast<alt::IBaseObject*>(virtualEntityGroup);
}

CAPI_END()