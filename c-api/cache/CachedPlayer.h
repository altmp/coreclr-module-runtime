#pragma once

#include <cpp-sdk/CRefCountable.h>
#include <cpp-sdk/ICore.h>
#include <cpp-sdk/objects/IBaseObject.h>
#include <cpp-sdk/types/MValue.h>

#include "CachedEntity.h"

namespace cache
{
    class CachedPlayer : public virtual CachedEntity, public virtual CachedWorldObject, public virtual CachedBaseObject, public virtual alt::IPlayer
    {
    public:

        CachedPlayer(IPlayer* base) : CachedBaseObject(base), CachedWorldObject(base), CachedEntity(base),
                                      _name(base->GetName()),
                                      _health(base->GetHealth()),
                                      _maxHealth(base->GetMaxHealth()),
    	                              _currentWeaponTintIndex(base->GetCurrentWeaponTintIndex()),
                                      _currentWeapon(base->GetCurrentWeapon()),
                                      _dead(base->IsDead()),
                                      _jumping(base->IsJumping()),
                                      _inRagdoll(base->IsInRagdoll()),
                                      _aiming(base->IsAiming()),
                                      _shooting(base->IsShooting()),
                                      _reloading(base->IsReloading()),
                                      _enteringVehicle(base->IsEnteringVehicle()),
                                      _leavingVehicle(base->IsLeavingVehicle()),
                                      _onLadder(base->IsOnLadder()),
                                      _inMelee(base->IsInMelee()),
                                      _inCover(base->IsInCover()),
                                      _armour(base->GetArmour()),
                                      _maxArmour(base->GetMaxArmour()),
                                      _moveSpeed(base->GetMoveSpeed()),
                                      _aimPos(base->GetAimPos()),
                                      _headRotation(base->GetHeadRotation()),
                                      _inVehicle(base->IsInVehicle()),
                                      _vehicle(base->GetVehicle()),
                                      _seat(base->GetSeat()),
                                      _entityAimingAt(base->GetEntityAimingAt()),
                                      _entityAimOffset(base->GetEntityAimOffset()),
                                      _flashlightActive(base->IsFlashlightActive()),
                                      _currentAnimationDict(base->GetCurrentAnimationDict()),
                                      _currentAnimationName(base->GetCurrentAnimationName()),
                                      _spawned(base->IsSpawned()),
                                      _forwardSpeed(base->GetForwardSpeed()),
                                      _strafeSpeed(base->GetStrafeSpeed()),
                                      _parachuting(base->IsParachuting()),
#ifdef ALT_SERVER_API
										_superJumpEnabled(base->IsSuperJumpEnabled()),
										_crouching(base->IsCrouching()),
										_stealthy(base->IsStealthy()),
										_connected(base->IsConnected()),
										_ping(base->GetPing()),
										_iP(base->GetIP()),
										_socialID(base->GetSocialID()),
										_hwidHash(base->GetHwidHash()),
										_hwidExHash(base->GetHwidExHash()),
										_authToken(base->GetAuthToken()),
										_discordId(base->GetDiscordId()),
										_invincible(base->GetInvincible()),
										_headBlendData(base->GetHeadBlendData()),
										_eyeColor(base->GetEyeColor()),
										_hairColor(base->GetHairColor()),
										_hairHighlightColor(base->GetHairHighlightColor()),
										_interiorLocation(base->GetInteriorLocation()),
										_lastDamagedBodyPart(base->GetLastDamagedBodyPart()),
    									_sendNames(base->GetSendNames()),
										_clothes(12, { 0, 0, 0 }),
										_dlcClothes(12, { 0, 0, 0, 0 }),
										_props(13, { 0, 0 }),
										_dlcProps(13, { 0, 0, 0 }),
										_headOverlays(13, { 0, 0, 0, 0, 0 }),
										_faceFeatures(20, 0.0f),
										_socialClubName(base->GetSocialClubName()),
    									_cloudID(base->GetCloudID()),
    									_cloudAuthResult(base->GetCloudAuthResult()),
										_bloodDamageBase64(base->GetBloodDamageBase64())
#elif ALT_CLIENT_API
                                      _talking(base->IsTalking()),
                                      _micLevel(base->GetMicLevel()),
                                      _spatialVolume(base->GetSpatialVolume()),
                                      _nonSpatialVolume(base->GetNonSpatialVolume())
#endif
        {
#ifdef ALT_SERVER_API
	        for (uint8_t i = 0; i < 12; i++) {
		        _clothes[i] = base->GetClothes(i);
		        _dlcClothes[i] = base->GetDlcClothes(i);
	        }
        	for (uint8_t i = 0; i < 13; i++) {
        		_props[i] = base->GetProps(i);
        		_dlcProps[i] = base->GetDlcProps(i);
        	}
        	for (uint8_t i = 0; i < 13; i++) {
        		_headOverlays[i] = base->GetHeadOverlay(i);
        	}
        	for (uint8_t i = 0; i < 20; i++) {
        		_faceFeatures[i] = base->GetFaceFeatureScale(i);
        	}
#endif
        }


        void SetMultipleMetaData(const std::unordered_map<std::string, alt::MValue>& values) override {};

    	std::string _name;
    	std::string GetName() const override {
    		return _name;
    	}

        uint16_t _health;
        uint16_t GetHealth() const override {
			return _health;
		}

        uint16_t _maxHealth;
        uint16_t GetMaxHealth() const override {
			return _maxHealth;
		}

        bool HasWeaponComponent(uint32_t weapon, uint32_t component) const override {
	        return false;
        }

        std::vector<unsigned> GetCurrentWeaponComponents() const override {
			return {};
		}

        uint8_t GetWeaponTintIndex(uint32_t weapon) const override {
	        return 0;
        }

        uint8_t _currentWeaponTintIndex;
        uint8_t GetCurrentWeaponTintIndex() const override {
			return _currentWeaponTintIndex;
		}

        uint32_t _currentWeapon;
        uint32_t GetCurrentWeapon() const override {
			return _currentWeapon;
		}

        bool _dead;
        bool IsDead() const override {
			return _dead;
		}

        bool _jumping;
        bool IsJumping() const override {
			return _jumping;
		}

        bool _inRagdoll;
        bool IsInRagdoll() const override {
			return _inRagdoll;
		}

        bool _aiming;
        bool IsAiming() const override {
			return _aiming;
		}

        bool _shooting;
        bool IsShooting() const override {
			return _shooting;
        }

    	bool _reloading;
    	bool IsReloading() const override {
    		return _reloading;
    	}

    	bool _enteringVehicle;
    	bool IsEnteringVehicle() const override {
    		return _enteringVehicle;
    	}

    	bool _leavingVehicle;
    	bool IsLeavingVehicle() const override {
    		return _leavingVehicle;
    	}

    	bool _onLadder;
    	bool IsOnLadder() const override {
    		return _onLadder;
    	}

    	bool _inMelee;
    	bool IsInMelee() const override {
    		return _inMelee;
    	}

    	bool _inCover;
    	bool IsInCover() const override {
    		return _inCover;
    	}

        uint16_t _armour;
        uint16_t GetArmour() const override {
			return _armour;
		}

        uint16_t _maxArmour;
        uint16_t GetMaxArmour() const override {
			return _maxArmour;
		}

        float _moveSpeed;
        float GetMoveSpeed() const override {
			return _moveSpeed;
		}

        alt::Position _aimPos;
        alt::Position GetAimPos() const override {
			return _aimPos;
		}

        alt::Rotation _headRotation;
        alt::Rotation GetHeadRotation() const override {
			return _headRotation;
		}

        bool _inVehicle;
        bool IsInVehicle() const override {
			return _inVehicle;
		}

        alt::IVehicle* _vehicle;
        alt::IVehicle* GetVehicle() const override {
			return _vehicle;
		}

        uint8_t _seat;
        uint8_t GetSeat() const override {
			return _seat;
		}

        IEntity* _entityAimingAt;
        IEntity* GetEntityAimingAt() const override {
			return _entityAimingAt;
		}

        alt::Position _entityAimOffset;
        alt::Position GetEntityAimOffset() const override {
			return _entityAimOffset;
		}

        bool _flashlightActive;
        bool IsFlashlightActive() const override {
			return _flashlightActive;
		}

        bool _superJumpEnabled;
        bool IsSuperJumpEnabled() const override {
			return _superJumpEnabled;
		}

        bool _crouching;
        bool IsCrouching() const override {
			return _crouching;
		}

        bool _stealthy;
        bool IsStealthy() const override {
			return _stealthy;
		}

        uint32_t _currentAnimationDict;
        uint32_t GetCurrentAnimationDict() const override {
			return _currentAnimationDict;
		}

        uint32_t _currentAnimationName;
        uint32_t GetCurrentAnimationName() const override {
			return _currentAnimationName;
		}

        bool _spawned;
        bool IsSpawned() const override {
			return _spawned;
		}

        float _forwardSpeed;
        float GetForwardSpeed() const override {
			return _forwardSpeed;
		}

        float _strafeSpeed;
        float GetStrafeSpeed() const override {
			return _strafeSpeed;
        }

    	bool _parachuting;
    	bool IsParachuting() const override {
    		return _parachuting;
    	}
#ifdef ALT_SERVER_API
        bool _connected;
        bool IsConnected() const override {
			return _connected;
		}

        uint32_t _ping;
        uint32_t GetPing() const override {
			return _ping;
		}

        std::string _iP;
        std::string GetIP() const override {
			return _iP;
		}

        uint64_t _socialID;
        uint64_t GetSocialID() const override {
			return _socialID;
		}

        uint64_t _hwidHash;
        uint64_t GetHwidHash() const override {
			return _hwidHash;
		}

        uint64_t _hwidExHash;
        uint64_t GetHwidExHash() const override {
			return _hwidExHash;
		}

        std::string _authToken;
        std::string GetAuthToken() const override {
			return _authToken;
		}

        int64_t _discordId;
        int64_t GetDiscordId() const override {
			return _discordId;
		}

        void Spawn(alt::Position pos, uint32_t delayMs) override {}
        void Despawn() override {}
        void SetModel(uint32_t model) override {}
        void SetArmour(uint16_t armor) override {}
        void SetMaxArmour(uint16_t armor) override {}
        void SetCurrentWeapon(uint32_t weapon) override {}
        void SetWeaponTintIndex(uint32_t weapon, uint8_t tintIndex) override {}
        void AddWeaponComponent(uint32_t weapon, uint32_t component) override {}
        void RemoveWeaponComponent(uint32_t weapon, uint32_t component) override {}
        void ClearBloodDamage() override {}
        void SetHealth(uint16_t health) override {}
        void SetMaxHealth(uint16_t health) override {}
        void GiveWeapon(uint32_t weapon, int32_t ammo, bool selectWeapon) override {}
        bool RemoveWeapon(uint32_t weapon) override {
	        return false;
        }
        void RemoveAllWeapons(bool removeAllAmmo) override {}
        void SetDateTime(int day, int month, int year, int hour, int minute, int second) override {}
        void SetWeather(uint32_t weather) override {}
        void Kick(const std::string& reason) override {}

    	std::vector<alt::Cloth> _clothes = {};
        alt::Cloth GetClothes(uint8_t component) const override {
        	if (_clothes.size() <= component) return { 0, 0, 0 };
        	return _clothes[component];
        }
        bool SetClothes(uint8_t component, uint16_t drawable, uint8_t texture, uint8_t palette) override {
	        return false;
        }

        bool ClearClothes(uint8_t component) override {
	        return false;
        }

        std::vector<alt::DlcCloth> _dlcClothes = {};
    	alt::DlcCloth GetDlcClothes(uint8_t component) const override {
    		if (_dlcClothes.size() <= component) return { 0, 0, 0, 0 };
    		return _dlcClothes[component];
        }
        bool SetDlcClothes(uint8_t component, uint16_t drawable, uint8_t texture, uint8_t palette, uint32_t dlc) override {
	        return false;
        }
    	std::vector<alt::Prop> _props = {};
    	alt::Prop GetProps(uint8_t component) const override {
    		if (_props.size() <= component) return { 0, 0 };
    		return _props[component];
        }
        bool SetProps(uint8_t component, uint16_t drawable, uint8_t texture) override {
	        return false;
        }
    	std::vector<alt::DlcProp> _dlcProps = {};
    	alt::DlcProp GetDlcProps(uint8_t component) const override {
    		if (_dlcProps.size() <= component) return { 0, 0, 0 };
    		return _dlcProps[component];
        }
        bool SetDlcProps(uint8_t component, uint8_t drawable, uint8_t texture, uint32_t dlc) override {
	        return false;
        }
        void ClearProps(uint8_t component) override {}
        bool IsEntityInStreamingRange(uint16_t entityId) override {
	        return false;
        }
        void SetInvincible(bool toggle) override {}
        bool _invincible;
        bool GetInvincible() const override {
			return _invincible;
		}

        void SetIntoVehicle(alt::IVehicle* vehicle, uint8_t seat) override {}
        void PlayAmbientSpeech(const std::string& speechName, const std::string& speechParam, uint32_t speechDictHash) override {}
        bool SetHeadOverlay(uint8_t overlayID, uint8_t index, float opacity) override {
	        return false;
        }
        bool RemoveHeadOverlay(uint8_t overlayID) override {
	        return false;
        }
        bool SetHeadOverlayColor(uint8_t overlayID, uint8_t colorType, uint8_t colorIndex, uint8_t secondColorIndex) override {
	        return false;
        }
    	std::vector<alt::HeadOverlay> _headOverlays = {};
        alt::HeadOverlay GetHeadOverlay(uint8_t overlayID) const override {
        	if (_headOverlays.size() <= overlayID) return { 0, 0, 0, 0, 0 };
        	return _headOverlays[overlayID];
        }
        bool SetFaceFeature(uint8_t index, float scale) override {
	        return false;
        }
    	std::vector<float> _faceFeatures = {};
        float GetFaceFeatureScale(uint8_t index) const override {
        	return _faceFeatures.size() <= index ? 0 : _faceFeatures[index];
        }
        bool RemoveFaceFeature(uint8_t index) override {
			return false;
        }
        bool SetHeadBlendPaletteColor(uint8_t id, uint8_t red, uint8_t green, uint8_t blue) override {
	        return false;
        }
        alt::RGBA GetHeadBlendPaletteColor(uint8_t id) const override {
	        return { 0, 0, 0, 0 };
        }
        void SetHeadBlendData(uint32_t shapeFirstID, uint32_t shapeSecondID, uint32_t shapeThirdID, uint32_t skinFirstID, uint32_t skinSecondID, uint32_t skinThirdID, float shapeMix,
            float skinMix, float thirdMix) override {}

        void RemoveHeadBlendData() override {}

        alt::HeadBlendData _headBlendData;
        alt::HeadBlendData GetHeadBlendData() const override {
			return _headBlendData;
		}

        bool SetEyeColor(int16_t eyeColor) override {
	        return false;
        }
        int16_t _eyeColor;
        int16_t GetEyeColor() const override {
			return _eyeColor;
		}

        void SetHairColor(uint8_t hairColor) override {}
        uint8_t _hairColor;
        uint8_t GetHairColor() const override {
			return _hairColor;
		}

        void SetHairHighlightColor(uint8_t hairHighlightColor) override {}
        uint8_t _hairHighlightColor;
        uint8_t GetHairHighlightColor() const override {
			return _hairHighlightColor;
		}

        std::vector<alt::Weapon> GetWeapons() const override {
			return {};
		}

    	std::unordered_map<std::string, alt::MValue> _localMetaData = {};

    	bool HasLocalMetaData(const std::string& key) const override {
    		return _localMetaData.find(key) != _localMetaData.end();
    	}

    	alt::MValueConst GetLocalMetaData(const std::string& key) const override {
    		const auto find = _localMetaData.find(key);
    		if (find == _localMetaData.end()) return alt::ICore::Instance().CreateMValueNil();
    		return find->second;
    	}

    	std::vector<std::string> GetLocalMetaDataKeys() const override {
    		std::vector<std::string> keys(_localMetaData.size());
    		for(const auto &kv : _localMetaData) {
    			keys.push_back(kv.first);
    		}

    		return keys;
    	}

        void SetLocalMetaData(const std::string& key, alt::MValue val) override {}
    	void DeleteLocalMetaData(const std::string& key) override {}

        uint32_t _interiorLocation;
        uint32_t GetInteriorLocation() const override {
			return _interiorLocation;
		}

        uint32_t _lastDamagedBodyPart;
        uint32_t GetLastDamagedBodyPart() const override {
			return _lastDamagedBodyPart;
		}

        void SetLastDamagedBodyPart(uint32_t bodyPart) override {}

        void SetSendNames(bool state) override {}
        bool _sendNames;
        bool GetSendNames() const override {
			return _sendNames;
		}

    	void PlayAnimation(const std::string& animDict, const std::string& animName, float blendInSpeed, float blendOutSpeed, int duration, int flags, float playbackRate, bool lockX, bool lockY, bool lockZ) override {}
    	void ClearTasks() override {}

    	std::string _socialClubName;
    	std::string GetSocialClubName() const override {
    		return _socialClubName;
    	}

    	std::vector<std::pair<IEntity*, int32_t>> GetStreamedEntities() const override { return {}; }

    	uint16_t GetAmmo(uint32_t ammoHash) const override {
    		return 0;
    	}

        void SetAmmo(uint32_t ammoHash, uint16_t ammo) override {}
        void SetWeaponAmmo(uint32_t weaponHash, uint16_t ammo) override {}

        uint16_t GetWeaponAmmo(uint32_t weaponHash) const override {
    		return 0;
    	}

        bool HasWeapon(uint32_t weapon) const override
    	{
    		return false;
    	}

        void SetAmmoSpecialType(uint32_t ammoHash, alt::AmmoSpecialType ammoSpecialType) override {}
    	alt::AmmoSpecialType GetAmmoSpecialType(uint32_t ammoHash) const override
    	{
        	return {};
    	}
        void SetAmmoFlags(uint32_t ammoHash, alt::AmmoFlags ammoFlags) override {}
    	alt::AmmoFlags GetAmmoFlags(uint32_t ammoHash) const override
        {
        	return {};
        }
        void SetAmmoMax(uint32_t ammoHash, int32_t ammoMax) override {}
    	int32_t GetAmmoMax(uint32_t ammoHash) const override
        {
        	return 0;
        }
        void SetAmmoMax50(uint32_t ammoHash, int32_t ammoMax50) override {}
    	int32_t GetAmmoMax50(uint32_t ammoHash) const override
        {
        	return 0;
        }
        void SetAmmoMax100(uint32_t ammoHash, int32_t ammoMax100) override {}
        int32_t GetAmmoMax100(uint32_t ammoHash) const override
        {
	        return 0;
        }

        void AddDecoration(uint32_t collection, uint32_t overlay, uint8_t count = 1) override {}
        void RemoveDecoration(uint32_t collection, uint32_t overlay) override {}
        void ClearDecorations() override {}
    	std::vector<alt::CDecoration> GetDecorations() const override
    	{
    		return {};
    	}

    	void PlayScenario(const std::string& name) override {}

        bool IsNetworkOwnershipDisabled() const override
    	{
    		return false;
    	}
    	void SetNetworkOwnershipDisabled(bool disabled) override {}

    	std::string _cloudID;
    	std::string GetCloudID() const override {
    		return _cloudID;
    	}

        alt::CloudAuthResult _cloudAuthResult;
    	alt::CloudAuthResult GetCloudAuthResult() const override {
    		return _cloudAuthResult;
    	}

    	std::string _bloodDamageBase64;
    	std::string GetBloodDamageBase64() const override {
    		return _bloodDamageBase64;
    	}
        void SetBloodDamageBase64(const std::string& _base64) override {}

    	void RemoveHeadBlendPaletteColor() override {}
#endif


#ifdef ALT_CLIENT_API
    	bool _talking;
        bool IsTalking() const override {
	        return _talking;
        }
    	float _micLevel;
        float GetMicLevel() const override {
	        return _micLevel;
        }
    	float _spatialVolume;
        float GetSpatialVolume() const override {
	        return _spatialVolume;
        }
        void SetSpatialVolume(float volume) override {}
    	float _nonSpatialVolume;
        float GetNonSpatialVolume() const override {
	        return _nonSpatialVolume;
        }
        void SetNonSpatialVolume(float volume) override {}

        void AddFilter(alt::IAudioFilter* filter) override {}
        void RemoveFilter() override {}
        alt::IAudioFilter* GetFilter() const override { return nullptr; }

        std::string _taskData;
        std::string GetTaskData() const override {
            return _taskData;
        }

#endif

    };
} // namespace alt