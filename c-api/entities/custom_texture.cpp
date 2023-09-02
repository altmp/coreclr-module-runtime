#include "custom_texture.h"

#include "../utils/macros.h"

CAPI_START()

#ifdef ALT_CLIENT_API
uint32_t CustomTexture_GetID(alt::ICustomTexture* costumTexture)
{
    return costumTexture->GetID();
}

alt::IBaseObject* CustomTexture_GetBaseObject(alt::ICustomTexture* costumTexture)
{
    return dynamic_cast<alt::IBaseObject*>(costumTexture);
}
#endif

CAPI_END()