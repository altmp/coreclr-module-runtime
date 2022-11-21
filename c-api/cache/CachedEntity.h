﻿#pragma once

#include <cpp-sdk/CRefCountable.h>
#include <cpp-sdk/ICore.h>
#include <cpp-sdk/objects/IBaseObject.h>
#include <cpp-sdk/types/MValue.h>

#include "CachedWorldObject.h"

namespace cache
{
    class CachedEntity : public virtual CachedWorldObject, public virtual CachedBaseObject, public virtual alt::IEntity {
    public:
        CachedEntity(IEntity* base) : CachedBaseObject(base), CachedWorldObject(base), _id(base->GetID()),
                                      _networkOwner(base->GetNetworkOwner()),
                                      _model(base->GetModel()),
                                      _rotation(base->GetRotation()),
                                      _visible(base->GetVisible()),
#ifdef ALT_SERVER_API
                                      _streamed(base->GetStreamed()),
    								  _frozen(base->IsFrozen()),
    								  _collision(base->HasCollision())
#elif ALT_CLIENT_API
                                      _scriptId(base->GetScriptGuid())
#endif
        {
            auto syncedKeys = base->GetSyncedMetaDataKeys();
            for (const auto& key : syncedKeys) {
                _syncedMetaData[key] = base->GetSyncedMetaData(key);
            }
            
            auto streamSyncedKeys = base->GetStreamSyncedMetaDataKeys();
            for (const auto& key : streamSyncedKeys) {
                _streamSyncedMetaData[key] = base->GetStreamSyncedMetaData(key);
            }
        }

        uint16_t _id;
        uint16_t GetID() const override {
            return _id;
        }

        alt::IPlayer* _networkOwner;
        alt::IPlayer* GetNetworkOwner() const override {
            return _networkOwner;
        }

        uint32_t _model;
        uint32_t GetModel() const override {
            return _model;
        }

        alt::Rotation _rotation;
        alt::Rotation GetRotation() const override {
            return _rotation;
        }

        void SetRotation(alt::Rotation rot) override {}

        std::unordered_map<std::string, alt::MValueConst> _syncedMetaData = {};
        
        bool HasSyncedMetaData(const std::string& key) const override {
            return _syncedMetaData.find(key) != _syncedMetaData.end();
        }
        
        alt::MValueConst GetSyncedMetaData(const std::string& key) const override {
            const auto find = _syncedMetaData.find(key);
            if (find == _syncedMetaData.end()) return alt::ICore::Instance().CreateMValueNil();
            return find->second;
        }
        
        std::vector<std::string> GetSyncedMetaDataKeys() const override {
            std::vector<std::string> keys(_syncedMetaData.size());
            for(const auto &kv : _syncedMetaData) {
                keys.push_back(kv.first);  
            }

            return keys;
        }

        std::unordered_map<std::string, alt::MValueConst> _streamSyncedMetaData = {};
        
        bool HasStreamSyncedMetaData(const std::string& key) const override {
            return _streamSyncedMetaData.find(key) != _streamSyncedMetaData.end();
        }
        
        alt::MValueConst GetStreamSyncedMetaData(const std::string& key) const override {
            const auto find = _streamSyncedMetaData.find(key);
            if (find == _streamSyncedMetaData.end()) return alt::ICore::Instance().CreateMValueNil();
            return find->second;
        }
        
        std::vector<std::string> GetStreamSyncedMetaDataKeys() const override {
            std::vector<std::string> keys(_streamSyncedMetaData.size());
            for(const auto &kv : _streamSyncedMetaData) {
                keys.push_back(kv.first);  
            }

            return keys;
        }
        
        bool _visible;
        bool GetVisible() const override {
            return _visible;
        }

#ifdef ALT_SERVER_API
        void SetNetworkOwner(alt::IPlayer* player, bool disableMigration) override {}
        void SetSyncedMetaData(const std::string& key, alt::MValue val) override {}
        void DeleteSyncedMetaData(const std::string& key) override {}
        void SetStreamSyncedMetaData(const std::string& key, alt::MValue val) override {}
        void DeleteStreamSyncedMetaData(const std::string& key) override {}
        void SetVisible(bool toggle) override {}
        void AttachToEntity(IEntity* entity, int16_t otherBoneIndex, int16_t myBoneIndex, alt::Position position, alt::Rotation rotation, bool collision, bool noFixedRotation) override {}
        void AttachToEntity(IEntity* entity, const std::string& otherBoneName, const std::string& myBoneName, alt::Position position, alt::Rotation rotation, bool collision,
            bool noFixedRotation) override {}
        void Detach() override {}
        void SetStreamed(bool toggle) override {}
        bool _streamed;
        bool GetStreamed() const override {
			return _streamed;
		}

        bool _frozen;
        bool IsFrozen() const override {
			return _frozen;
		}

        void SetFrozen(bool state) override {}
        bool _collision;
        bool HasCollision() const override {
			return _collision;
		}

        void SetCollision(bool state) override {}
#endif


#ifdef ALT_CLIENT_API
        int32_t _scriptId;
        int32_t GetScriptGuid() const override {
            return _scriptId;
        }
#endif
    };
} // namespace alt