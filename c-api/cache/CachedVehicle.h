#pragma once

#include <cpp-sdk/CRefCountable.h>
#include <cpp-sdk/ICore.h>
#include <cpp-sdk/objects/IBaseObject.h>
#include <cpp-sdk/types/MValue.h>

#include "CachedEntity.h"

namespace cache
{
    class CachedVehicle : public virtual CachedEntity, public virtual CachedWorldObject, public virtual CachedBaseObject, public virtual alt::IVehicle
    {

    public:

    	CachedVehicle(IVehicle* base) : CachedBaseObject(base),
										CachedWorldObject(base),
										CachedEntity(base),
										_isEngineOn(base->IsEngineOn()),
    									_lockState(base->GetLockState()),
										_petrolTankHealth(base->GetPetrolTankHealth()),
										_wheelsCount(base->GetWheelsCount()),
    									_steeringAngle(base->GetSteeringAngle()),
#ifdef ALT_SERVER_API
										_dirtLevel(base->GetDirtLevel()),
										_isNeonActive(base->IsNeonActive()),
										_neonColor(base->GetNeonColor()),
										_livery(base->GetLivery()),
										_roofLivery(base->GetRoofLivery()),
										_appearanceDataBase64(base->GetAppearanceDataBase64()),
										_isHandbrakeActive(base->IsHandbrakeActive()),
										_headlightColor(base->GetHeadlightColor()),
										_radioStationIndex(base->GetRadioStationIndex()),
										_isSirenActive(base->IsSirenActive()),
										_isDaylightOn(base->IsDaylightOn()),
										_isNightlightOn(base->IsNightlightOn()),
										_roofState(base->GetRoofState()),
										_isFlamethrowerActive(base->IsFlamethrowerActive()),
										_lightsMultiplier(base->GetLightsMultiplier()),
										_gameStateBase64(base->GetGameStateBase64()),
										_engineHealth(base->GetEngineHealth()),
										_repairsCount(base->GetRepairsCount()),
										_bodyHealth(base->GetBodyHealth()),
										_bodyAdditionalHealth(base->GetBodyAdditionalHealth()),
										_healthDataBase64(base->GetHealthDataBase64()),
										_hasArmoredWindows(base->HasArmoredWindows()),
										_damageDataBase64(base->GetDamageDataBase64()),
										_isManualEngineControl(base->IsManualEngineControl()),
										_scriptDataBase64(base->GetScriptDataBase64()),
										_velocity(base->GetVelocity()),
										_driver(base->GetDriver()),
										_isDestroyed(base->IsDestroyed()),
										_modKitsCount(base->GetModKitsCount()),
										_modKit(base->GetModKit()),
										_isPrimaryColorRGB(base->IsPrimaryColorRGB()),
										_primaryColor(base->GetPrimaryColor()),
										_primaryColorRGB(base->GetPrimaryColorRGB()),
										_isSecondaryColorRGB(base->IsSecondaryColorRGB()),
										_secondaryColor(base->GetSecondaryColor()),
										_secondaryColorRGB(base->GetSecondaryColorRGB()),
										_pearlColor(base->GetPearlColor()),
										_wheelColor(base->GetWheelColor()),
										_interiorColor(base->GetInteriorColor()),
										_dashboardColor(base->GetDashboardColor()),
										_isTireSmokeColorCustom(base->IsTireSmokeColorCustom()),
										_tireSmokeColor(base->GetTireSmokeColor()),
										_wheelType(base->GetWheelType()),
										_wheelVariation(base->GetWheelVariation()),
										_rearWheelVariation(base->GetRearWheelVariation()),
										_customTires(base->GetCustomTires()),
										_specialDarkness(base->GetSpecialDarkness()),
										_numberplateIndex(base->GetNumberplateIndex()),
										_numberplateText(base->GetNumberplateText()),
										_windowTint(base->GetWindowTint()),
										_attached(base->GetAttached()),
										_attachedTo(base->GetAttachedTo()),
										_isDriftMode(base->IsDriftMode()),
										_isTrainMissionTrain(base->IsTrainMissionTrain()),
										_trainTrackId(base->GetTrainTrackId()),
										_trainEngineId(base->GetTrainEngineId()),
										_trainConfigIndex(base->GetTrainConfigIndex()),
										_trainDistanceFromEngine(base->GetTrainDistanceFromEngine()),
										_isTrainEngine(base->IsTrainEngine()),
										_isTrainCaboose(base->IsTrainCaboose()),
										_trainDirection(base->GetTrainDirection()),
										_hasTrainPassengerCarriages(base->HasTrainPassengerCarriages()),
										_trainRenderDerailed(base->GetTrainRenderDerailed()),
										_trainForceDoorsOpen(base->GetTrainForceDoorsOpen()),
										_trainCruiseSpeed(base->GetTrainCruiseSpeed()),
										_trainCarriageConfigIndex(base->GetTrainCarriageConfigIndex()),
										_trainLinkedToBackwardId(base->GetTrainLinkedToBackwardId()),
										_trainLinkedToForwardId(base->GetTrainLinkedToForwardId()),
										_trainUnk1(base->GetTrainUnk1()),
										_trainUnk2(base->GetTrainUnk2()),
										_trainUnk3(base->GetTrainUnk3()),
										_isBoatAnchorActive(base->IsBoatAnchorActive()),
										_lightState(base->GetLightState()),
										_hasTimedExplosion(base->HasTimedExplosion()),
										_timedExplosionCulprit(base->GetTimedExplosionCulprit()),
										_timedExplosionTime(base->GetTimedExplosionTime()),
										_isTowingDisabled(base->IsTowingDisabled()),
										_rocketRefuelSpeed(base->GetRocketRefuelSpeed()),
										_counterMeasureCount(base->GetCounterMeasureCount()),
										_scriptMaxSpeed(base->GetScriptMaxSpeed()),
										_hybridExtraActive(base->GetHybridExtraActive()),
										_hybridExtraState(base->GetHybridExtraState()),
										_wheelBurst(base->GetWheelsCount(), false),
										_wheelDetached(base->GetWheelsCount(), false),
										_wheelOnFire(base->GetWheelsCount(), false),
										_wheelHealth(base->GetWheelsCount(), 0.0f),
										_wheelHasTire(base->GetWheelsCount(), false),
    									_quaternion(base->GetQuaternion()),
    									_isHornActive(base->IsHornActive()),
    									_accelerationLevel(base->GetAccelerationLevel()),
    									_brakeLevel(base->GetBrakeLevel())
#else
    									_wheelSpeed(base->GetWheelSpeed()),
										_currentGear(base->GetCurrentGear()),
										_currentRPM(base->GetCurrentRPM()),
										_speedVector(base->GetSpeedVector()),
										_maxGear(base->GetMaxGear()),
										_isHandingModified(base->IsHandlingModified()),
										_lightsIndicator(base->GetLightsIndicator()),
										_seatCount(base->GetSeatCount()),
										_occupiedSeatsCount(base->GetOccupiedSeatsCount()),
										_taxiLight(base->IsTaxiLightOn()),
										_wheelCambers(base->GetWheelsCount(), 0.0f),
										_wheelTrackWidths(base->GetWheelsCount(), 0.0f),
										_wheelHeights(base->GetWheelsCount(), 0.0f),
										_wheelTyreRadiuses(base->GetWheelsCount(), 0.0f),
										_wheelTyreWidths(base->GetWheelsCount(), 0.0f),
    									_wheelSurfaceMaterials(base->GetWheelsCount(), 0u),
										_engineTemperature(base->GetEngineTemperature()),
										_fuelLevel(base->GetFuelLevel()),
										_oilLevel(base->GetOilLevel()),
										_lightState(base->GetEngineLightState()),
										_absLightState(base->GetAbsLightState()),
										_petrolLightState(base->GetPetrolLightState()),
										_oilLightState(base->GetOilLightState()),
										_batteryLightState(base->GetBatteryLightState()),
    									_suspensionHeight(base->GetSuspensionHeight())

#endif
    	{
    		auto wheels = base->GetWheelsCount();
    		for (uint8_t i = 0; i < wheels; i++) {
#ifdef ALT_CLIENT_API
    			_wheelCambers[i] = base->GetWheelCamber(i);
    			_wheelTrackWidths[i] = base->GetWheelTrackWidth(i);
    			_wheelHeights[i] = base->GetWheelHeight(i);
    			_wheelTyreRadiuses[i] = base->GetWheelTyreRadius(i);
    			_wheelTyreWidths[i] = base->GetWheelTyreWidth(i);
    			_wheelSurfaceMaterials[i] = base->GetWheelSurfaceMaterial(i);
#elif ALT_SERVER_API
    			_wheelBurst[i] = base->IsWheelBurst(i);
    			_wheelHasTire[i] = base->DoesWheelHasTire(i);
    			_wheelDetached[i] = base->IsWheelDetached(i);
    			_wheelOnFire[i] = base->IsWheelOnFire(i);
    			_wheelHealth[i] = base->GetWheelHealth(i);
#endif
    		}
    	}

        void SetMultipleMetaData(const std::unordered_map<std::string, alt::MValue>& values) override {};

        alt::IPlayer* _driver;
        alt::IPlayer* GetDriver() const override {
			return _driver;
		}

        bool _isDestroyed;
        bool IsDestroyed() const override {
			return _isDestroyed;
		}

        uint8_t GetMod(uint8_t category) const override {
	        return 0;
        }
        uint8_t GetModsCount(uint8_t category) const override {
	        return 0;
        }
        uint8_t _modKitsCount;
        uint8_t GetModKitsCount() const override {
			return _modKitsCount;
		}

        uint8_t _modKit;
        uint8_t GetModKit() const override {
			return _modKit;
		}

        bool _isPrimaryColorRGB;
        bool IsPrimaryColorRGB() const override {
			return _isPrimaryColorRGB;
		}

        uint8_t _primaryColor;
        uint8_t GetPrimaryColor() const override {
			return _primaryColor;
		}

        alt::RGBA _primaryColorRGB;
        alt::RGBA GetPrimaryColorRGB() const override {
			return _primaryColorRGB;
		}

        bool _isSecondaryColorRGB;
        bool IsSecondaryColorRGB() const override {
			return _isSecondaryColorRGB;
		}

        uint8_t _secondaryColor;
        uint8_t GetSecondaryColor() const override {
			return _secondaryColor;
		}

        alt::RGBA _secondaryColorRGB;
        alt::RGBA GetSecondaryColorRGB() const override {
			return _secondaryColorRGB;
		}

        uint8_t _pearlColor;
        uint8_t GetPearlColor() const override {
			return _pearlColor;
		}

        uint8_t _wheelColor;
        uint8_t GetWheelColor() const override {
			return _wheelColor;
		}

        uint8_t _interiorColor;
        uint8_t GetInteriorColor() const override {
			return _interiorColor;
		}

        uint8_t _dashboardColor;
        uint8_t GetDashboardColor() const override {
			return _dashboardColor;
		}

        bool _isTireSmokeColorCustom;
        bool IsTireSmokeColorCustom() const override {
			return _isTireSmokeColorCustom;
		}

        alt::RGBA _tireSmokeColor;
        alt::RGBA GetTireSmokeColor() const override {
			return _tireSmokeColor;
		}

        uint8_t _wheelType;
        uint8_t GetWheelType() const override {
			return _wheelType;
		}

        uint8_t _wheelVariation;
        uint8_t GetWheelVariation() const override {
			return _wheelVariation;
		}

        uint8_t _rearWheelVariation;
        uint8_t GetRearWheelVariation() const override {
			return _rearWheelVariation;
		}

        bool _customTires;
        bool GetCustomTires() const override {
			return _customTires;
		}

        uint8_t _specialDarkness;
        uint8_t GetSpecialDarkness() const override {
			return _specialDarkness;
		}

        uint32_t _numberplateIndex;
        uint32_t GetNumberplateIndex() const override {
			return _numberplateIndex;
		}

        std::string _numberplateText;
        std::string GetNumberplateText() const override {
			return _numberplateText;
		}

        uint8_t _windowTint;
        uint8_t GetWindowTint() const override {
			return _windowTint;
		}

        uint8_t _dirtLevel;
        uint8_t GetDirtLevel() const override {
			return _dirtLevel;
		}

        bool IsExtraOn(uint8_t extraID) const override {
	        return false;
        }
        bool _isNeonActive;
        bool IsNeonActive() const override {
			return _isNeonActive;
		}

        void GetNeonActive(bool* left, bool* right, bool* front, bool* back) const override {}
        alt::RGBA _neonColor;
        alt::RGBA GetNeonColor() const override {
			return _neonColor;
		}

        uint8_t _livery;
        uint8_t GetLivery() const override {
			return _livery;
		}

        uint8_t _roofLivery;
        uint8_t GetRoofLivery() const override {
			return _roofLivery;
		}

        std::string _appearanceDataBase64;
        std::string GetAppearanceDataBase64() const override {
			return _appearanceDataBase64;
		}

        bool _isEngineOn;
        bool IsEngineOn() const override {
			return _isEngineOn;
		}

        bool _isHandbrakeActive;
        bool IsHandbrakeActive() const override {
			return _isHandbrakeActive;
		}

        uint8_t _headlightColor;
        uint8_t GetHeadlightColor() const override {
			return _headlightColor;
		}

        uint32_t _radioStationIndex;
        uint32_t GetRadioStationIndex() const override {
			return _radioStationIndex;
		}

        bool _isSirenActive;
        bool IsSirenActive() const override {
			return _isSirenActive;
		}

        uint8_t _lockState;
        uint8_t GetLockState() const override {
			return _lockState;
		}

        uint8_t GetDoorState(uint8_t doorId) const override {
	        return 0;
        }
        bool IsWindowOpened(uint8_t windowId) const override {
	        return false;
        }
        bool _isDaylightOn;
        bool IsDaylightOn() const override {
			return _isDaylightOn;
		}

        bool _isNightlightOn;
        bool IsNightlightOn() const override {
			return _isNightlightOn;
		}

        uint8_t _roofState;
        uint8_t GetRoofState() const override {
			return _roofState;
		}

        bool _isFlamethrowerActive;
        bool IsFlamethrowerActive() const override {
			return _isFlamethrowerActive;
		}

        float _lightsMultiplier;
        float GetLightsMultiplier() const override {
			return _lightsMultiplier;
		}

        std::string _gameStateBase64;
        std::string GetGameStateBase64() const override {
			return _gameStateBase64;
		}

        int32_t _engineHealth;
        int32_t GetEngineHealth() const override {
			return _engineHealth;
		}

        int32_t _petrolTankHealth;
        int32_t GetPetrolTankHealth() const override {
			return _petrolTankHealth;
		}

        uint8_t _wheelsCount;
        uint8_t GetWheelsCount() const override {
			return _wheelsCount;
		}

    	uint8_t _steeringAngle;
        float GetSteeringAngle() const override
        {
        	return _steeringAngle;
        }

        std::vector<bool> _wheelBurst;
        bool IsWheelBurst(uint8_t wheelId) override {
        	return _wheelBurst.size() <= wheelId ? false : _wheelBurst[wheelId];
        }

    	std::vector<bool> _wheelHasTire;
        bool DoesWheelHasTire(uint8_t wheelId) override {
        	return _wheelHasTire.size() <= wheelId ? false : _wheelHasTire[wheelId];
        }

    	std::vector<bool> _wheelDetached;
        bool IsWheelDetached(uint8_t wheelId) override {
        	return _wheelDetached.size() <= wheelId ? false : _wheelDetached[wheelId];
        }

    	std::vector<bool> _wheelOnFire;
        bool IsWheelOnFire(uint8_t wheelId) override {
        	return _wheelOnFire.size() <= wheelId ? false : _wheelOnFire[wheelId];
        }

    	std::vector<float> _wheelHealth;
        float GetWheelHealth(uint8_t wheelId) override {
        	return _wheelHealth.size() <= wheelId ? 0.0f : _wheelHealth[wheelId];
        }

        uint8_t _repairsCount;
        uint8_t GetRepairsCount() const override {
			return _repairsCount;
		}

        uint32_t _bodyHealth;
        uint32_t GetBodyHealth() const override {
			return _bodyHealth;
		}

        uint32_t _bodyAdditionalHealth;
        uint32_t GetBodyAdditionalHealth() const override {
			return _bodyAdditionalHealth;
		}

        std::string _healthDataBase64;
        std::string GetHealthDataBase64() const override {
			return _healthDataBase64;
		}

        uint8_t GetPartDamageLevel(uint8_t partId) override {
	        return 0;
        }
        uint8_t GetPartBulletHoles(uint8_t partId) override {
	        return 0;
        }
        bool IsLightDamaged(uint8_t lightId) override {
	        return false;
        }
        bool IsWindowDamaged(uint8_t windowId) override {
	        return false;
        }
        bool IsSpecialLightDamaged(uint8_t specialLightId) override {
	        return false;
        }
        bool _hasArmoredWindows;
        bool HasArmoredWindows() const override {
			return _hasArmoredWindows;
		}

        float GetArmoredWindowHealth(uint8_t windowId) override {
	        return 0;
        }
        uint8_t GetArmoredWindowShootCount(uint8_t windowId) override {
	        return 0;
        }
        uint8_t GetBumperDamageLevel(uint8_t bumperId) override {
	        return 0;
        }
        std::string _damageDataBase64;
        std::string GetDamageDataBase64() const override {
			return _damageDataBase64;
		}

        bool _isManualEngineControl;
        bool IsManualEngineControl() const override {
			return _isManualEngineControl;
		}

        std::string _scriptDataBase64;
        std::string GetScriptDataBase64() const override {
			return _scriptDataBase64;
		}

        void ToggleExtra(uint8_t extraID, bool state) override {}
        alt::Vector3f _velocity;
        alt::Vector3f GetVelocity() const override {
			return _velocity;
		}

#ifdef ALT_SERVER_API
        void SetFixed() override {}
        bool SetMod(uint8_t category, uint8_t id) override {
	        return false;
        }
        bool SetModKit(uint8_t id) override {
	        return false;
        }
        void SetPrimaryColor(uint8_t color) override {}
        void SetPrimaryColorRGB(alt::RGBA color) override {}
        void SetSecondaryColor(uint8_t color) override {}
        void SetSecondaryColorRGB(alt::RGBA color) override {}
        void SetPearlColor(uint8_t color) override {}
        void SetWheelColor(uint8_t color) override {}
        void SetInteriorColor(uint8_t color) override {}
        void SetDashboardColor(uint8_t color) override {}
        void SetTireSmokeColor(alt::RGBA color) override {}
        void SetWheels(uint8_t type, uint8_t variation) override {}
        void SetRearWheels(uint8_t variation) override {}
        void SetCustomTires(bool state) override {}
        void SetSpecialDarkness(uint8_t value) override {}
        void SetNumberplateIndex(uint32_t index) override {}
        void SetNumberplateText(const std::string& text) override {}
        void SetWindowTint(uint8_t tint) override {}
        void SetDirtLevel(uint8_t level) override {}
        void SetNeonActive(bool left, bool right, bool front, bool back) override {}
        void SetNeonColor(alt::RGBA color) override {}
        void SetLivery(uint8_t livery) override {}
        void SetRoofLivery(uint8_t roofLivery) override {}
        void LoadAppearanceDataFromBase64(const std::string& base64) override {}
        void SetEngineOn(bool state) override {}
        void SetHeadlightColor(uint8_t color) override {}
        void SetRadioStationIndex(uint32_t stationIndex) override {}
        void SetSirenActive(bool state) override {}
        void SetLockState(uint8_t state) override {}
        void SetDoorState(uint8_t doorId, uint8_t state) override {}
        void SetWindowOpened(uint8_t windowId, bool state) override {}
        void SetRoofState(uint8_t state) override {}
        void SetLightsMultiplier(float multiplier) override {}
        void SetEngineHealth(int32_t health) override {}
        void SetPetrolTankHealth(int32_t health) override {}
        void SetWheelBurst(uint8_t wheelId, bool state) override {}
        void SetWheelHasTire(uint8_t wheelId, bool state) override {}
        void SetWheelDetached(uint8_t wheelId, bool state) override {}
        void SetWheelOnFire(uint8_t wheelId, bool state) override {}
        void SetWheelHealth(uint8_t wheelId, float health) override {}
        void SetWheelFixed(uint8_t wheelId) override {}
        void SetBodyHealth(uint32_t health) override {}
        void SetBodyAdditionalHealth(uint32_t health) override {}
        void SetPartDamageLevel(uint8_t partId, uint8_t damage) override {}
        void SetPartBulletHoles(uint8_t partId, uint8_t shootsCount) override {}
        void SetLightDamaged(uint8_t lightId, bool isDamaged) override {}
        void SetWindowDamaged(uint8_t windowId, bool isDamaged) override {}
        void SetSpecialLightDamaged(uint8_t specialLightId, bool isDamaged) override {}
        void SetArmoredWindowHealth(uint8_t windowId, float health) override {}
        void SetArmoredWindowShootCount(uint8_t windowId, uint8_t count) override {}
        void SetBumperDamageLevel(uint8_t bumperId, uint8_t damageLevel) override {}
        void SetManualEngineControl(bool state) override {}
        void LoadDamageDataFromBase64(const std::string& base64) override {}
        void LoadScriptDataFromBase64(const std::string& base64) override {}
        void LoadGameStateFromBase64(const std::string& base64) override {}
        void LoadHealthDataFromBase64(const std::string& base64) override {}
        IVehicle* _attached;
        IVehicle* GetAttached() const override {
			return _attached;
		}

        IVehicle* _attachedTo;
        IVehicle* GetAttachedTo() const override {
			return _attachedTo;
		}

        bool _isDriftMode;
        bool IsDriftMode() const override {
			return _isDriftMode;
		}

        void SetDriftMode(bool state) override {}
        bool _isTrainMissionTrain;
        bool IsTrainMissionTrain() const override {
			return _isTrainMissionTrain;
		}

        void SetTrainMissionTrain(bool value) override {}
        int8_t _trainTrackId;
        int8_t GetTrainTrackId() const override {
			return _trainTrackId;
		}

        void SetTrainTrackId(int8_t trackId) override {}
        IVehicle* _trainEngineId;
        IVehicle* GetTrainEngineId() const override {
			return _trainEngineId;
		}

        void SetTrainEngineId(IVehicle* vehicle) override {}
        int8_t _trainConfigIndex;
        int8_t GetTrainConfigIndex() const override {
			return _trainConfigIndex;
		}

        void SetTrainConfigIndex(int8_t trainConfigIndex) override {}
        float _trainDistanceFromEngine;
        float GetTrainDistanceFromEngine() const override {
			return _trainDistanceFromEngine;
		}

        void SetTrainDistanceFromEngine(float distanceFromEngine) override {}
        bool _isTrainEngine;
        bool IsTrainEngine() const override {
			return _isTrainEngine;
		}

        void SetTrainIsEngine(bool isEngine) override {}
        bool _isTrainCaboose;
        bool IsTrainCaboose() const override {
			return _isTrainCaboose;
		}

        void SetTrainIsCaboose(bool isCaboose) override {}
        bool _trainDirection;
        bool GetTrainDirection() const override {
			return _trainDirection;
		}

        void SetTrainDirection(bool direction) override {}
        bool _hasTrainPassengerCarriages;
        bool HasTrainPassengerCarriages() const override {
			return _hasTrainPassengerCarriages;
		}

        void SetTrainHasPassengerCarriages(bool hasPassengerCarriages) override {}
        bool _trainRenderDerailed;
        bool GetTrainRenderDerailed() const override {
			return _trainRenderDerailed;
		}

        void SetTrainRenderDerailed(bool renderDerailed) override {}
        bool _trainForceDoorsOpen;
        bool GetTrainForceDoorsOpen() const override {
			return _trainForceDoorsOpen;
		}

        void SetTrainForceDoorsOpen(bool forceDoorsOpen) override {}
        float _trainCruiseSpeed;
        float GetTrainCruiseSpeed() const override {
			return _trainCruiseSpeed;
		}

        void SetTrainCruiseSpeed(float cruiseSpeed) override {}
        int8_t _trainCarriageConfigIndex;
        int8_t GetTrainCarriageConfigIndex() const override {
			return _trainCarriageConfigIndex;
		}

        void SetTrainCarriageConfigIndex(int8_t carriageConfigIndex) override {}
        IVehicle* _trainLinkedToBackwardId;
        IVehicle* GetTrainLinkedToBackwardId() const override {
			return _trainLinkedToBackwardId;
		}

        void SetTrainLinkedToBackwardId(IVehicle* vehicle) override {}
        IVehicle* _trainLinkedToForwardId;
        IVehicle* GetTrainLinkedToForwardId() const override {
			return _trainLinkedToForwardId;
		}

        void SetTrainLinkedToForwardId(IVehicle* vehicle) override {}
        void SetTrainUnk1(bool unk1) override {}
        bool _trainUnk1;
        bool GetTrainUnk1() const override {
			return _trainUnk1;
		}

        void SetTrainUnk2(bool unk2) override {}
        bool _trainUnk2;
        bool GetTrainUnk2() const override {
			return _trainUnk2;
		}

        void SetTrainUnk3(bool unk3) override {}
        bool _trainUnk3;
        bool GetTrainUnk3() const override {
			return _trainUnk3;
		}

        bool _isBoatAnchorActive;
        bool IsBoatAnchorActive() const override {
			return _isBoatAnchorActive;
		}

        void SetBoatAnchorActive(bool state) override {}
        bool SetSearchLight(bool state, IEntity* spottedEntity) override {
	        return false;
        }
        uint8_t _lightState;
        uint8_t GetLightState() const override {
			return _lightState;
		}

        void SetLightState(uint8_t state) override {}
        bool _hasTimedExplosion;
        bool HasTimedExplosion() const override {
			return _hasTimedExplosion;
		}

        alt::IPlayer* _timedExplosionCulprit;
        alt::IPlayer* GetTimedExplosionCulprit() const override {
			return _timedExplosionCulprit;
		}

        uint32_t _timedExplosionTime;
        uint32_t GetTimedExplosionTime() const override {
			return _timedExplosionTime;
		}

        void SetTimedExplosion(bool state, alt::IPlayer* culprit, uint32_t time) override {}
        bool _isTowingDisabled;
        bool IsTowingDisabled() const override {
			return _isTowingDisabled;
		}

        void SetDisableTowing(bool state) override {}
        float _rocketRefuelSpeed;
        float GetRocketRefuelSpeed() const override {
			return _rocketRefuelSpeed;
		}

        void SetRocketRefuelSpeed(float rocketRefuelSpeed) override {}
        uint32_t _counterMeasureCount;
        uint32_t GetCounterMeasureCount() const override {
			return _counterMeasureCount;
		}

        void SetCounterMeasureCount(uint32_t counterMeasureCount) override {}
        float _scriptMaxSpeed;
        float GetScriptMaxSpeed() const override {
			return _scriptMaxSpeed;
		}

        void SetScriptMaxSpeed(float scriptMaxSpeed) override {}
        int32_t GetWeaponCapacity(uint8_t index) const override {
	        return 0;
        }
        void SetWeaponCapacity(uint8_t index, int32_t state) override {}
        bool _hybridExtraActive;
        bool GetHybridExtraActive() const override {
			return _hybridExtraActive;
		}

        void SetHybridExtraActive(bool state) override {}
        uint8_t _hybridExtraState;
        uint8_t GetHybridExtraState() const override {
			return _hybridExtraState;
		}

        void SetHybridExtraState(uint8_t state) override {}

    	alt::Quaternion _quaternion;
        alt::Quaternion GetQuaternion() const override
        {
	        return _quaternion;
        }
        void SetQuaternion(alt::Quaternion quaternion) override {}

    	bool _isHornActive;
        bool IsHornActive() const override
        {
	        return _isHornActive;
        }

    	float _accelerationLevel;
        float GetAccelerationLevel() const override
        {
	        return _accelerationLevel;
        }

    	float _brakeLevel;
        float GetBrakeLevel() const override
        {
	        return _brakeLevel;
        }

	    void SetBadge(uint32_t textureDictionary, uint32_t texture, alt::VehicleBadgePosition positions[4]) override {}
#endif
#ifdef ALT_CLIENT_API
    	float _wheelSpeed;
        float GetWheelSpeed() const override {
	        return _wheelSpeed;
        }

    	uint16_t _currentGear;
        uint16_t GetCurrentGear() const override {
	        return _currentGear;
        }
        void SetCurrentGear(uint16_t currentGear) override {}

        void SetCurrentRPM(float rpm) override {}

    	float _currentRPM;
        float GetCurrentRPM() const override {
	        return _currentRPM;
        }

    	alt::Vector3f _speedVector;
        alt::Vector3f GetSpeedVector() const override {
	        return _speedVector;
        }

    	uint16_t _maxGear;
        uint16_t GetMaxGear() const override {
	        return _maxGear;
        }
        void SetMaxGear(uint16_t gearMax) override {}

    	bool _isHandingModified;
        bool IsHandlingModified() const override {
	        return _isHandingModified;
        }

        std::shared_ptr<alt::IHandlingData> GetHandling() const override {
	        return nullptr;
        }
        void ResetHandling() override {}
        void ReplaceHandling() override {}

    	uint8_t _lightsIndicator;
        uint8_t GetLightsIndicator() const override {
	        return _lightsIndicator;
        }
        void SetLightsIndicator(uint8_t lightsIndicatorFlag) override {}

    	uint8_t _seatCount;
        uint8_t GetSeatCount() const override {
	        return _seatCount;
        }

    	uint8_t _occupiedSeatsCount;
        uint8_t GetOccupiedSeatsCount() const override {
	        return _occupiedSeatsCount;
        }

    	bool _taxiLight;
        bool IsTaxiLightOn() const override {
	        return _taxiLight;
        }
        void ToggleTaxiLight(bool state) override {}

    	std::vector<float> _wheelCambers;
        float GetWheelCamber(uint8_t wheel) const override {
	        return _wheelCambers.size() <= wheel ? 0 : _wheelCambers[wheel];
        }
        void SetWheelCamber(uint8_t wheel, float value) override {}

    	std::vector<float> _wheelTrackWidths;
        float GetWheelTrackWidth(uint8_t wheel) const override {
        	return _wheelTrackWidths.size() <= wheel ? 0 : _wheelTrackWidths[wheel];
        }
        void SetWheelTrackWidth(uint8_t wheel, float value) override {}

    	std::vector<float> _wheelHeights;
        float GetWheelHeight(uint8_t wheel) const override {
	        return _wheelHeights.size() <= wheel ? 0 : _wheelHeights[wheel];
        }
        void SetWheelHeight(uint8_t wheel, float value) override {}

    	std::vector<float> _wheelTyreRadiuses;
        float GetWheelTyreRadius(uint8_t wheel) const override {
        	return _wheelTyreRadiuses.size() <= wheel ? 0 : _wheelTyreRadiuses[wheel];
        }
        void SetWheelTyreRadius(uint8_t wheel, float value) override {}

    	std::vector<float> _wheelRimRadiuses;
        float GetWheelRimRadius(uint8_t wheel) const override {
        	return _wheelRimRadiuses.size() <= wheel ? 0 : _wheelRimRadiuses[wheel];
        }
        void SetWheelRimRadius(uint8_t wheel, float value) override {}

    	std::vector<float> _wheelTyreWidths;
        float GetWheelTyreWidth(uint8_t wheel) const override {
        	return _wheelTyreWidths.size() <= wheel ? 0 : _wheelTyreWidths[wheel];
        }
        void SetWheelTyreWidth(uint8_t wheel, float value) override {}

    	std::vector<uint32_t> _wheelSurfaceMaterials;
        uint32_t GetWheelSurfaceMaterial(uint8_t wheel) const override {
        	return _wheelSurfaceMaterials.size() <= wheel ? 0 : _wheelSurfaceMaterials[wheel];
        }

    	float _engineTemperature;
        float GetEngineTemperature() const override {
	        return _engineTemperature;
        }
        void SetEngineTemperature(float value) override {}

    	float _fuelLevel;
        float GetFuelLevel() const override {
	        return _fuelLevel;
        }
        void SetFuelLevel(float value) override {}

    	float _oilLevel;
        float GetOilLevel() const override {
	        return _oilLevel;
        }
        void SetOilLevel(float value) override {}

    	bool _lightState;
        bool GetEngineLightState() const override {
	        return _lightState;
        }
        void SetEngineLightState(bool state) override {}

    	bool _absLightState;
        bool GetAbsLightState() const override {
	        return _absLightState;
        }
        void SetAbsLightState(bool state) override {}

    	bool _petrolLightState;
        bool GetPetrolLightState() const override {
	        return _petrolLightState;
        }
        void SetPetrolLightState(bool state) override {}

    	bool _oilLightState;
        bool GetOilLightState() const override {
	        return _oilLightState;
        }
        void SetOilLightState(bool state) override {}

    	bool _batteryLightState;
        bool GetBatteryLightState() const override {
	        return _batteryLightState;
        }
        void SetBatteryLightState(bool state) override {}

        void ResetDashboardLights() override {}

    	float _suspensionHeight;
        float GetSuspensionHeight() const override
        {
	        return _suspensionHeight;
        }
        void SetSuspensionHeight(float value) override {}

        void SetSteeringAngle(float value) override {}
#endif

    };
} // namespace alt
