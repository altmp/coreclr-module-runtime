#include "virtual_entitiy_group.h"

#include "../utils/strings.h"
#include "../utils/uint.h"

uint32_t VirtualEntityGroup_GetID(alt::IVirtualEntityGroup* virtualEntityGroup)
{
    return virtualEntityGroup->GetID();
}

uint32_t VirtualEntityGroup_GetStreamingRangeLimit(alt::IVirtualEntityGroup* virtualEntityGroup)
{
    return virtualEntityGroup->GetStreamingRangeLimit();
}
alt::IBaseObject* VirtualEntityGroup_GetBaseObject(alt::IVirtualEntityGroup* virtualEntityGroup)
{
    return dynamic_cast<alt::IBaseObject*>(virtualEntityGroup);
}