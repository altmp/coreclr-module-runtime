#include "player.h"

#include "../utils/strings.h"
#include "../utils/uint.h"
#include "../mvalue.h"
#include "../utils/macros.h"

CAPI_START()

uint32_t Player_GetID(alt::IPlayer* player) {
    return player->GetID();
}

alt::IEntity* Player_GetEntity(alt::IPlayer* player) {
    return dynamic_cast<alt::IEntity*>(player);
}


const char* Player_GetName(alt::IPlayer* player, int32_t& size) {
    return AllocateString(player->GetName(), size);
}


uint16_t Player_GetHealth(alt::IPlayer* player) {
    return player->GetHealth();
}

uint16_t Player_GetMaxHealth(alt::IPlayer* player) {
    return player->GetMaxHealth();
}


void Player_GetCurrentWeaponComponents(alt::IPlayer* player, uint32_t*& weaponComponents, uint32_t& size) {
    auto currWeaponComponents = player->GetCurrentWeaponComponents();
    size = currWeaponComponents.size();
    auto valuesArr = new uint32_t[size];
    for (auto i = 0; i < size; i++) {
        valuesArr[i] = currWeaponComponents[i];
    }
    weaponComponents = valuesArr;
}

uint32_t Player_GetCurrentWeapon(alt::IPlayer* player) {
    return player->GetCurrentWeapon();
}

uint8_t Player_IsDead(alt::IPlayer* player) {
    return player->IsDead();
}

uint8_t Player_IsJumping(alt::IPlayer* player) {
    return player->IsJumping();
}

uint8_t Player_IsInRagdoll(alt::IPlayer* player) {
    return player->IsInRagdoll();
}

uint8_t Player_IsAiming(alt::IPlayer* player) {
    return player->IsAiming();
}

uint8_t Player_IsShooting(alt::IPlayer* player) {
    return player->IsShooting();
}

uint8_t Player_IsReloading(alt::IPlayer* player) {
    return player->IsReloading();
}


uint16_t Player_GetArmor(alt::IPlayer* player) {
    return player->GetArmour();
}

uint16_t Player_GetMaxArmor(alt::IPlayer* player) {
    return player->GetMaxArmour();
}


float Player_GetMoveSpeed(alt::IPlayer* player) {
    return player->GetMoveSpeed();
}


void Player_GetAimPos(alt::IPlayer* player, position_t &aimPosition) {
    auto playerAimPosition = player->GetAimPos();
    aimPosition.x = playerAimPosition.x;
    aimPosition.y = playerAimPosition.y;
    aimPosition.z = playerAimPosition.z;
}

void Player_GetHeadRotation(alt::IPlayer* player, rotation_t &headRotation) {
    auto playerHeadRotation = player->GetHeadRotation();
    headRotation.roll = playerHeadRotation.roll;
    headRotation.pitch = playerHeadRotation.pitch;
    headRotation.yaw = playerHeadRotation.yaw;
}


uint8_t Player_IsInVehicle(alt::IPlayer* player) {
    return player->IsInVehicle();
}

alt::IVehicle* Player_GetVehicle(alt::IPlayer* player) {
    return player->GetVehicle();
}

uint8_t Player_GetVehicleID(alt::IPlayer* player, uint16_t& id) {
    auto vehicle = player->GetVehicle();
    if (vehicle == nullptr) return false;
    id = vehicle->GetID();
    return true;
}

uint8_t Player_GetSeat(alt::IPlayer* player) {
    return player->GetSeat();
}


void* Player_GetEntityAimingAt(alt::IPlayer* player, alt::IBaseObject::Type &type) {
    auto entity = player->GetEntityAimingAt();
    if (entity != nullptr) {
        type = entity->GetType();
        switch (type) {
            case alt::IBaseObject::Type::PLAYER:
                return dynamic_cast<alt::IPlayer*>(entity);
            case alt::IBaseObject::Type::VEHICLE:
                return dynamic_cast<alt::IVehicle*>(entity);
            case alt::IBaseObject::Type::PED:
                return dynamic_cast<alt::IPed*>(entity);
            default:
                return nullptr;
        }
    }
    return nullptr;
}

void Player_GetEntityAimOffset(alt::IPlayer* player, position_t &position) {
    auto offset = player->GetEntityAimOffset();
    position.x = offset.x;
    position.y = offset.y;
    position.z = offset.z;
}


uint8_t Player_IsFlashlightActive(alt::IPlayer* player) {
    return player->IsFlashlightActive();
}

uint8_t Player_IsSpawned(alt::IPlayer* player) {
    return player->IsSpawned();
}

uint32_t Player_GetCurrentAnimationDict(alt::IPlayer* player) {
    return player->GetCurrentAnimationDict();
}

uint32_t Player_GetCurrentAnimationName(alt::IPlayer* player) {
    return player->GetCurrentAnimationName();
}

float Player_GetForwardSpeed(alt::IPlayer* player) {
    return player->GetForwardSpeed();
}

float Player_GetStrafeSpeed(alt::IPlayer* player) {
    return player->GetStrafeSpeed();
}

uint8_t Player_IsEnteringVehicle(alt::IPlayer* player)
{
    return player->IsEnteringVehicle();
}

uint8_t Player_IsLeavingVehicle(alt::IPlayer* player)
{
    return player->IsLeavingVehicle();
}

uint8_t Player_IsOnLadder(alt::IPlayer* player)
{
    return player->IsOnLadder();
}

uint8_t Player_IsInMelee(alt::IPlayer* player)
{
    return player->IsInMelee();
}

uint8_t Player_IsInCover(alt::IPlayer* player)
{
    return player->IsInCover();
}

uint8_t Player_IsParachuting(alt::IPlayer* player)
{
    return player->IsParachuting();
}

#ifdef ALT_SERVER_API
alt::MValueConst* Player_GetLocalMetaData(alt::IPlayer* player, const char* key) {
    return AllocMValue(player->GetLocalMetaData(key));
}

void Player_SetLocalMetaData(alt::IPlayer* player, const char* key, alt::MValueConst* val) {
    if (val == nullptr) return;
    player->SetLocalMetaData(key, val->get()->Clone());
}

uint8_t Player_HasLocalMetaData(alt::IPlayer* player, const char* key) {
    return player->HasLocalMetaData(key);
}

void Player_DeleteLocalMetaData(alt::IPlayer* player, const char* key) {
    player->DeleteLocalMetaData(key);
}


uint8_t Player_IsConnected(alt::IPlayer* player) {
    return player->IsConnected();
}

void Player_Spawn(alt::IPlayer* player, alt::Position pos, uint32_t delayMs) {
    player->Spawn(pos, delayMs);
}

void Player_Despawn(alt::IPlayer* player) {
    player->Despawn();
}

void Player_SetModel(alt::IPlayer* player, uint32_t model) {
    player->SetModel(model);
}


uint64_t Player_GetSocialID(alt::IPlayer* player) {
    return player->GetSocialID();
}

uint64_t Player_GetHwidHash(alt::IPlayer* player) {
    return player->GetHwidHash();
}

uint64_t Player_GetHwidExHash(alt::IPlayer* player) {
    return player->GetHwidExHash();
}

const char* Player_GetAuthToken(alt::IPlayer* player, int32_t& size) {
    return AllocateString(player->GetAuthToken(), size);
}


void Player_SetHealth(alt::IPlayer* player, uint16_t health) {
    player->SetHealth(health);
}

void Player_SetMaxHealth(alt::IPlayer* player, uint16_t maxHealth) {
    player->SetMaxHealth(maxHealth);
}


void Player_SetDateTime(alt::IPlayer* player, int day, int month, int year, int hour, int minute, int second) {
    player->SetDateTime(day, month, year, hour, minute, second);
}

void Player_SetWeather(alt::IPlayer* player, uint32_t weather) {
    player->SetWeather(weather);
}


void Player_GiveWeapon(alt::IPlayer* player, uint32_t weapon, int32_t ammo, uint8_t selectWeapon) {
    player->GiveWeapon(weapon, ammo, selectWeapon);
}

uint8_t Player_RemoveWeapon(alt::IPlayer* player, uint32_t weapon) {
    return player->RemoveWeapon(weapon);
}

void Player_RemoveAllWeapons(alt::IPlayer* player, uint8_t removeAllAmmo) {
    player->RemoveAllWeapons(removeAllAmmo);
}

void Player_AddWeaponComponent(alt::IPlayer* player, uint32_t weapon, uint32_t component) {
    player->AddWeaponComponent(weapon, component);
}

void Player_RemoveWeaponComponent(alt::IPlayer* player, uint32_t weapon, uint32_t component) {
    player->RemoveWeaponComponent(weapon, component);
}

uint8_t Player_HasWeaponComponent(alt::IPlayer* player, uint32_t weapon, uint32_t component) {
    return player->HasWeaponComponent(weapon, component);
}


void Player_SetWeaponTintIndex(alt::IPlayer* player, uint32_t weapon, uint8_t tintIndex) {
    player->SetWeaponTintIndex(weapon, tintIndex);
}

uint8_t Player_GetWeaponTintIndex(alt::IPlayer* player, uint32_t weapon) {
    return player->GetWeaponTintIndex(weapon);
}

uint8_t Player_GetCurrentWeaponTintIndex(alt::IPlayer* player) {
    return player->GetCurrentWeaponTintIndex();
}


void Player_SetCurrentWeapon(alt::IPlayer* player, uint32_t weapon) {
    player->SetCurrentWeapon(weapon);
}

uint64_t Player_GetWeaponCount(alt::IPlayer* player) {
    return player->GetWeapons().size();
}

uint8_t Player_HasWeapon(alt::IPlayer* player, uint32_t weapon)
{
    return player->HasWeapon(weapon);
}

void Player_GetWeapons(alt::IPlayer* player, weapon_t*& weapons, uint32_t& size) {
    auto playerWeapons = player->GetWeapons();
    size = playerWeapons.size();
    auto weaponsArr = new weapon_t[size];

    for (auto i = 0; i < size; i++) {
        auto playerWeapon = playerWeapons[i];

        weapon_t weapon;
        weapon.hash = playerWeapon.hash;
        weapon.tintIndex = playerWeapon.tintIndex;

        weapon.componentsCount = playerWeapon.components.size();

        if (weapon.componentsCount > 0) {
            weapon.components = new uint32_t[weapon.componentsCount];

            auto j = 0;
            for (auto component : playerWeapon.components) {
                weapon.components[j++] = component;
                if (j == weapon.componentsCount) break;
            }
        } else {
            weapon.components = nullptr;
        }

        weaponsArr[i] = weapon;
    }

    weapons = weaponsArr;
}


void Player_SetArmor(alt::IPlayer* player, uint16_t armor) {
    player->SetArmour(armor);
}

void Player_SetMaxArmor(alt::IPlayer* player, uint16_t armor) {
    player->SetMaxArmour(armor);
}


void Player_Kick(alt::IPlayer* player, const char* reason) {
    player->Kick(reason);
}


uint32_t Player_GetPing(alt::IPlayer* player) {
    return player->GetPing();
}

const char* Player_GetIP(alt::IPlayer* player, int32_t& size) {
    return AllocateString(player->GetIP(), size);
}


void Player_ClearBloodDamage(alt::IPlayer* player) {
    player->ClearBloodDamage();
}


void Player_GetClothes(alt::IPlayer* player, uint8_t component, cloth_t& cloth) {
    auto clothes = player->GetClothes(component);
    cloth.drawable = clothes.drawableId;
    cloth.texture = clothes.textureId;
    cloth.palette = clothes.textureId;
}

uint8_t Player_SetClothes(alt::IPlayer* player, uint8_t component, uint16_t drawable, uint8_t texture, uint8_t palette) {
    return player->SetClothes(component, drawable, texture, palette);
}

void Player_GetDlcClothes(alt::IPlayer* player, uint8_t component, dlccloth_t& cloth) {
    auto clothes = player->GetDlcClothes(component);
    cloth.dlc = clothes.dlc;
    cloth.drawable = clothes.drawableId;
    cloth.texture = clothes.textureId;
    cloth.palette = clothes.textureId;
}

uint8_t Player_SetDlcClothes(alt::IPlayer* player, uint8_t component, uint16_t drawable, uint8_t texture, uint8_t palette, uint32_t dlc) {
    return player->SetDlcClothes(component, drawable, texture, palette, dlc);
}

uint8_t Player_ClearClothes(alt::IPlayer* player, uint8_t component)
{
    return player->ClearClothes(component);
}

void Player_GetProps(alt::IPlayer* player, uint8_t component, prop_t& prop) {
    auto props = player->GetProps(component);
    prop.drawable = props.drawableId;
    prop.texture = props.textureId;
}

uint8_t Player_SetProps(alt::IPlayer* player, uint8_t component, uint16_t drawable, uint8_t texture) {
    return player->SetProps(component, drawable, texture);
}

void Player_GetDlcProps(alt::IPlayer* player, uint8_t component, dlcprop_t& prop) {
    auto props = player->GetDlcProps(component);
    prop.dlc = props.dlc;
    prop.drawable = props.drawableId;
    prop.texture = props.textureId;
}

uint8_t Player_SetDlcProps(alt::IPlayer* player, uint8_t component, uint16_t drawable, uint8_t texture, uint32_t dlc) {
    return player->SetDlcProps(component, drawable, texture, dlc);
}

void Player_ClearProps(alt::IPlayer* player, uint8_t component) {
    player->ClearProps(component);
}


uint8_t Player_IsEntityInStreamingRange(alt::IPlayer* player, alt::IEntity* entity) {
    return player->IsEntityInStreamingRange(entity->GetSyncID());
}

uint8_t Player_GetInvincible(alt::IPlayer* player) {
    return player->GetInvincible();
}

void Player_SetInvincible(alt::IPlayer* player, uint8_t state) {
    player->SetInvincible(state);
}


void Player_SetIntoVehicle(alt::IPlayer* player, alt::IVehicle* vehicle, uint8_t seat) {
    player->SetIntoVehicle(vehicle, seat);
}


uint8_t Player_IsSuperJumpEnabled(alt::IPlayer* player) {
    return player->IsSuperJumpEnabled();
}

uint8_t Player_IsCrouching(alt::IPlayer* player) {
    return player->IsCrouching();
}

uint8_t Player_IsStealthy(alt::IPlayer* player) {
    return player->IsStealthy();
}


void Player_PlayAmbientSpeech(alt::IPlayer* player, const char* speechName, const char* speechParam, uint32_t speechDictHash) {
    player->PlayAmbientSpeech(speechName, speechParam, speechDictHash);
}


uint8_t Player_SetHeadOverlay(alt::IPlayer* player, uint8_t overlayID, uint8_t index, float opacity) {
    return player->SetHeadOverlay(overlayID, index, opacity);
}

uint8_t Player_RemoveHeadOverlay(alt::IPlayer* player, uint8_t overlayID) {
    return player->RemoveHeadOverlay(overlayID);
}

uint8_t Player_SetHeadOverlayColor(alt::IPlayer* player, uint8_t overlayID, uint8_t colorType, uint8_t colorIndex, uint8_t secondColorIndex) {
    return player->SetHeadOverlayColor(overlayID, colorType, colorIndex, secondColorIndex);
}

void Player_GetHeadOverlay(alt::IPlayer* player, uint8_t overlayID, head_overlay_t &headOverlay) {
    auto playerHeadOverlay = player->GetHeadOverlay(overlayID);
    headOverlay.index = playerHeadOverlay.index;
    headOverlay.opacity = playerHeadOverlay.opacity;
    headOverlay.colorType = playerHeadOverlay.colorType;
    headOverlay.colorIndex = playerHeadOverlay.colorIndex;
    headOverlay.secondColorIndex = playerHeadOverlay.secondColorIndex;
}


uint8_t Player_SetFaceFeature(alt::IPlayer* player, uint8_t index, float scale) {
    return player->SetFaceFeature(index, scale);
}

float Player_GetFaceFeatureScale(alt::IPlayer* player, uint8_t index) {
    return player->GetFaceFeatureScale(index);
}

uint8_t Player_RemoveFaceFeature(alt::IPlayer* player, uint8_t index) {
    return player->RemoveFaceFeature(index);
}


uint8_t Player_SetHeadBlendPaletteColor(alt::IPlayer* player, uint8_t id, uint8_t red, uint8_t green, uint8_t blue) {
    return player->SetHeadBlendPaletteColor(id, red, green, blue);
}

void Player_GetHeadBlendPaletteColor(alt::IPlayer* player, uint8_t id, rgba_t &headBlendPaletteColor) {
    auto playerHeadBlendPaletteColor = player->GetHeadBlendPaletteColor(id);
    headBlendPaletteColor.r = playerHeadBlendPaletteColor.r;
    headBlendPaletteColor.g = playerHeadBlendPaletteColor.g;
    headBlendPaletteColor.b = playerHeadBlendPaletteColor.b;
    headBlendPaletteColor.a= playerHeadBlendPaletteColor.a;
}

void Player_SetHeadBlendData(alt::IPlayer* player, uint32_t shapeFirstID, uint32_t shapeSecondID, uint32_t shapeThirdID,
                             uint32_t skinFirstID, uint32_t skinSecondID, uint32_t skinThirdID,
                             float shapeMix, float skinMix, float thirdMix) {
    player->SetHeadBlendData(shapeFirstID, shapeSecondID, shapeThirdID, skinFirstID, skinSecondID, skinThirdID, shapeMix, skinMix, thirdMix);
}

void Player_RemoveHeadBlendData(alt::IPlayer* player)
{
    player->RemoveHeadBlendData();
}

void Player_GetHeadBlendData(alt::IPlayer* player, head_blend_data_t &headBlendData) {
    auto playerHeadBlendData = player->GetHeadBlendData();
    headBlendData.shapeFirstID = playerHeadBlendData.shapeFirstID;
    headBlendData.shapeSecondID = playerHeadBlendData.shapeSecondID;
    headBlendData.shapeThirdID = playerHeadBlendData.shapeThirdID;
    headBlendData.skinFirstID = playerHeadBlendData.skinFirstID;
    headBlendData.skinSecondID = playerHeadBlendData.skinSecondID;
    headBlendData.skinThirdID = playerHeadBlendData.skinThirdID;
    headBlendData.shapeMix = playerHeadBlendData.shapeMix;
    headBlendData.skinMix = playerHeadBlendData.skinMix;
    headBlendData.thirdMix = playerHeadBlendData.thirdMix;
}


uint8_t Player_SetEyeColor(alt::IPlayer* player, uint16_t eyeColor) {
    return player->SetEyeColor(eyeColor);
}

uint16_t Player_GetEyeColor(alt::IPlayer* player) {
    return player->GetEyeColor();
}

void Player_SetHairColor(alt::IPlayer* player, uint8_t hairColor) {
    player->SetHairColor(hairColor);
}

uint8_t Player_GetHairColor(alt::IPlayer* player) {
    return player->GetHairColor();
}

void Player_SetHairHighlightColor(alt::IPlayer* player, uint8_t hairHighlightColor) {
    player->SetHairHighlightColor(hairHighlightColor);
}

uint8_t Player_GetHairHighlightColor(alt::IPlayer* player) {
    return player->GetHairHighlightColor();
}

int64_t Player_GetDiscordId(alt::IPlayer* player) {
    return player->GetDiscordId();
}

uint32_t Player_GetInteriorLocation(alt::IPlayer* player) {
    return player->GetInteriorLocation();
}

uint32_t Player_GetLastDamagedBodyPart(alt::IPlayer* player) {
    return player->GetLastDamagedBodyPart();
}

void Player_SetLastDamagedBodyPart(alt::IPlayer* player, uint32_t bodyPart) {
    player->SetLastDamagedBodyPart(bodyPart);
}

void Player_SetSendNames(alt::IPlayer* player, uint8_t state) {
    player->SetSendNames(state);
}

uint8_t Player_GetSendNames(alt::IPlayer* player){
    return player->GetSendNames();
}

void Player_PlayAnimation(alt::IPlayer* player, const char* animDict, const char* animName, float blendInSpeed,
    float blendOutSpeed, int duration, int flags, float playbackRate, uint8_t lockX, uint8_t lockY, uint8_t lockZ)
{
    player->PlayAnimation(animDict, animName, blendInSpeed, blendOutSpeed, duration, flags, playbackRate, lockX, lockY, lockZ);
}

void Player_ClearTasks(alt::IPlayer* player)
{
    player->ClearTasks();
}

const char* Player_GetSocialClubName(alt::IPlayer* player, int32_t& size)
{
    return AllocateString(player->GetSocialClubName(), size);
}

void Player_SetAmmo(alt::IPlayer* player, uint32_t ammoHash, uint16_t ammo)
{
    player->SetAmmo(ammoHash, ammo);
}

uint16_t Player_GetAmmo(alt::IPlayer* player, uint32_t ammoHash)
{
    return player->GetAmmo(ammoHash);
}

void Player_SetWeaponAmmo(alt::IPlayer* player, uint32_t weaponHash, uint16_t ammo)
{
    player->SetWeaponAmmo(weaponHash, ammo);
}

uint16_t Player_GetWeaponAmmo(alt::IPlayer* player, uint32_t weaponHash)
{
    return player->GetWeaponAmmo(weaponHash);
}

void Player_SetAmmoSpecialType(alt::IPlayer* player, uint32_t ammoHash, uint32_t ammoSpecialType)
{
    player->SetAmmoSpecialType(ammoHash, (alt::AmmoSpecialType)ammoSpecialType);
}

uint32_t Player_GetAmmoSpecialType(alt::IPlayer* player, uint32_t ammoHash)
{
    return (uint32_t)player->GetAmmoSpecialType(ammoHash);
}

void Player_SetAmmoFlags(alt::IPlayer* player, uint32_t ammoHash, uint8_t infiniteAmmo, uint8_t addSmokeOnExplosion, uint8_t fuse,
    uint8_t fixedAfterExplosion)
{
    player->SetAmmoFlags(ammoHash,
        {
            static_cast<bool>(infiniteAmmo),
            static_cast<bool>(addSmokeOnExplosion),
            static_cast<bool>(fuse),
            static_cast<bool>(fixedAfterExplosion)
        });
}

ClrAmmoFlags* Player_GetAmmoFlags(alt::IPlayer* player, uint32_t ammoHash)
{
    return new ClrAmmoFlags(player->GetAmmoFlags(ammoHash));
}

void Player_DeallocAmmoFlags(ClrAmmoFlags* ammoFlags)
{
    delete ammoFlags;
}

void Player_SetAmmoMax(alt::IPlayer* player, uint32_t ammoHash, int32_t ammoMax)
{
    player->SetAmmoMax(ammoHash, ammoMax);
}

int32_t Player_GetAmmoMax(alt::IPlayer* player, uint32_t ammoHash)
{
    return player->GetAmmoMax(ammoHash);
}

void Player_SetAmmoMax50(alt::IPlayer* player, uint32_t ammoHash, int32_t ammoMax50)
{
    player->SetAmmoMax50(ammoHash, ammoMax50);
}

int32_t Player_GetAmmoMax50(alt::IPlayer* player, uint32_t ammoHash)
{
    return player->GetAmmoMax50(ammoHash);
}

void Player_SetAmmoMax100(alt::IPlayer* player, uint32_t ammoHash, int32_t ammoMax100)
{
    player->SetAmmoMax100(ammoHash, ammoMax100);
}

int32_t Player_GetAmmoMax100(alt::IPlayer* player, uint32_t ammoHash)
{
    return player->GetAmmoMax100(ammoHash);
}

void Player_AddDecoration(alt::IPlayer* player, uint32_t collection, uint32_t overlay, uint8_t count)
{
    player->AddDecoration(collection, overlay, count);
}

void Player_RemoveDecoration(alt::IPlayer* player, uint32_t collection, uint32_t overlay)
{
    player->RemoveDecoration(collection, overlay);
}

void Player_ClearDecorations(alt::IPlayer* player)
{
    player->ClearDecorations();
}

ClrDecoration** Player_GetDecorations(alt::IPlayer* player, uint64_t& size)
{
    auto decorations = player->GetDecorations();
    size = decorations.size();
    auto out = new ClrDecoration*[size];
    for (auto i = 0; i < size; i++) {
        out[i] = new ClrDecoration(decorations[i]);
    }

    return out;
}

void Player_DeallocDecoration(ClrDecoration** decoInfo) {
    delete[] decoInfo;
}

void Player_PlayScenario(alt::IPlayer* player, const char* name)
{
    player->PlayScenario(name);
}

uint8_t Player_IsNetworkOwnershipDisabled(alt::IPlayer* player)
{
    return player->IsNetworkOwnershipDisabled();
}

void Player_SetNetworkOwnershipDisabled(alt::IPlayer* player, uint8_t state)
{
    player->SetNetworkOwnershipDisabled(state);
}

const char* Player_GetCloudID(alt::IPlayer* player, int32_t& size)
{
    return AllocateString(player->GetCloudID(), size);
}

uint8_t Player_GetCloudAuthResult(alt::IPlayer* player)
{
    return static_cast<uint8_t>(player->GetCloudAuthResult());
}

const char* Player_GetBloodDamageBase64(alt::IPlayer* player, int32_t& size)
{
    return AllocateString(player->GetBloodDamageBase64(), size);
}

void Player_SetBloodDamageBase64(alt::IPlayer* player, const char* bloodDamage)
{
    player->SetBloodDamageBase64(bloodDamage);
}

void Player_RemoveHeadBlendPaletteColor(alt::IPlayer* player)
{
    player->RemoveHeadBlendPaletteColor();
}

#endif

#if ALT_CLIENT_API

uint8_t Player_IsTalking(alt::IPlayer* player) {
    return player->IsTalking();
}


float Player_GetMicLevel(alt::IPlayer* player) {
    return player->GetMicLevel();
}


float Player_GetNonSpatialVolume(alt::IPlayer* player) {
    return player->GetNonSpatialVolume();
}

void Player_SetNonSpatialVolume(alt::IPlayer* player, float value) {
    player->SetNonSpatialVolume(value);
}

float Player_GetSpatialVolume(alt::IPlayer* player) {
    return player->GetSpatialVolume();
}

void Player_SetSpatialVolume(alt::IPlayer* player, float value) {
    player->SetSpatialVolume(value);
}

alt::ILocalPlayer* Player_GetLocal() {
    return alt::ICore::Instance().GetLocalPlayer();
}

uint32_t LocalPlayer_GetID(alt::ILocalPlayer* player) {
    return player->GetID();
}

alt::IPlayer* LocalPlayer_GetPlayer(alt::ILocalPlayer* localPlayer) {
    return dynamic_cast<alt::IPlayer*>(localPlayer);
}

uint16_t LocalPlayer_GetCurrentAmmo(alt::ILocalPlayer* localPlayer) {
    return localPlayer->GetCurrentAmmo();
}

uint32_t LocalPlayer_GetCurrentWeaponHash(alt::ILocalPlayer* localPlayer) {
    const auto data = localPlayer->GetCurrentWeaponData();
    if (!data)
    {
        return 0;
    }
    return data->GetNameHash();
}

uint16_t LocalPlayer_GetWeaponAmmo(alt::ILocalPlayer* localPlayer, uint32_t weaponHash) {
    return localPlayer->GetWeaponAmmo(weaponHash);
}

uint8_t LocalPlayer_HasWeapon(alt::ILocalPlayer* localPlayer, uint32_t weaponHash) {
    return localPlayer->HasWeapon(weaponHash);
}

void LocalPlayer_GetWeapons(alt::ILocalPlayer* localPlayer, const uint32_t*& weapons, uint32_t& size) {
    auto arr = localPlayer->GetWeapons();
    std::vector<uint32_t> hashes {};
    for (auto crr : arr)
    {
        hashes.push_back(crr.hash);
    }
    weapons = AllocateUInt32Array(hashes, size);
}

void LocalPlayer_GetWeaponComponents(alt::ILocalPlayer* localPlayer, uint32_t weaponHash, const uint32_t*& weaponComponents, uint32_t& size) {
    auto arr = localPlayer->GetWeaponComponents(weaponHash);
    weaponComponents = AllocateUInt32Array(arr, size);
}

float LocalPlayer_GetStamina(alt::ILocalPlayer* localPlayer)
{
    return localPlayer->GetStamina();
}

void LocalPlayer_SetStamina(alt::ILocalPlayer* localPlayer, float stamina)
{
    localPlayer->SetStamina(stamina);
}

float LocalPlayer_GetMaxStamina(alt::ILocalPlayer* localplayer)
{
    return localplayer->GetMaxStamina();
}

void LocalPlayer_SetMaxStamina(alt::ILocalPlayer* localPlayer, float stamina)
{
    localPlayer->SetMaxStamina(stamina);
}

void Player_AddFilter(alt::IPlayer* player, alt::IAudioFilter* filter)
{
    player->AddFilter(filter);
}

void Player_RemoveFilter(alt::IPlayer* player)
{
    player->RemoveFilter();
}

alt::IAudioFilter* Player_GetFilter(alt::IPlayer* player)
{
    return player->GetFilter();
}

const char* Player_GetTaskData(alt::IPlayer* player, int32_t& size)
{
    return AllocateString(player->GetTaskData(), size);
}

#endif

CAPI_END()