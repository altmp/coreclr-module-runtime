#include "local_ped.h"

#include "../utils/macros.h"

#ifdef ALT_CLIENT_API

CAPI_START()

alt::IPed* LocalPed_GetPed(alt::ILocalPed* localPed)
{
    return dynamic_cast<alt::IPed*>(localPed);
}

uint32_t LocalPed_GetID(alt::ILocalPed* localPed)
{
    return localPed->GetID();
}

void LocalPed_SetModel(alt::ILocalPed* localPed, uint32_t model)
{
    localPed->SetModel(model);
}

uint32_t LocalPed_GetStreamingDistance(alt::ILocalPed* localPed)
{
    return localPed->GetStreamingDistance();
}

void LocalPed_SetVisible(alt::ILocalPed* localPed, uint8_t toggle)
{
    localPed->SetVisible(toggle);
}

uint8_t LocalPed_IsVisible(alt::ILocalPed* localPed)
{
    return localPed->IsVisible();
}

uint32_t LocalPed_GetScriptID(alt::ILocalPed* localPed)
{
    return localPed->GetScriptID();
}

uint8_t LocalPed_IsStreamedIn(alt::ILocalPed* localPed)
{
    return localPed->IsStreamedIn();
}
#endif

CAPI_END()