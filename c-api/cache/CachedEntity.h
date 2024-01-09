#pragma once

#include <cpp-sdk/CRefCountable.h>
#include <cpp-sdk/ICore.h>
#include <cpp-sdk/objects/IBaseObject.h>
#include <cpp-sdk/types/MValue.h>

#include "CachedWorldObject.h"

namespace cache
{
    class CachedEntity : public virtual CachedWorldObject, public virtual CachedBaseObject, public virtual alt::IEntity
    {
    public:
        CachedEntity(IEntity* base) : CachedBaseObject(base), CachedWorldObject(base),
                                      _networkOwner(base->GetNetworkOwner()),
                                      _model(base->GetModel()),
                                      _rotation(base->GetRotation()),
                                      _visible(base->GetVisible()),
                                      _frozen(base->IsFrozen()),
#ifdef ALT_SERVER_API
                                      _streamed(base->GetStreamed()),
                                      _collision(base->HasCollision()),
                                      _timestamp(base->GetTimestamp()),
                                      _streamingDistance(base->GetStreamingDistance())
#elif ALT_CLIENT_API
                                      _scriptId(base->GetScriptID()),
                                      _syncInfo(base->GetSyncInfo()),
                                      _remoteId(base->GetRemoteID()),
                                      _isRemote(base->IsRemote())
#endif
        {
            auto syncedKeys = base->GetSyncedMetaDataKeys();
            for (const auto& key : syncedKeys)
            {
                _syncedMetaData[key] = base->GetSyncedMetaData(key);
            }

            auto streamSyncedKeys = base->GetStreamSyncedMetaDataKeys();
            for (const auto& key : streamSyncedKeys)
            {
                _streamSyncedMetaData[key] = base->GetStreamSyncedMetaData(key);
            }
        }

        uint16_t GetSyncID() const override { return static_cast<uint16_t>(_id)/*only temp*/; }

        alt::IPlayer* _networkOwner;

        alt::IPlayer* GetNetworkOwner() const override
        {
            return _networkOwner;
        }

        uint32_t _model;

        uint32_t GetModel() const override
        {
            return _model;
        }

        alt::Rotation _rotation;

        alt::Rotation GetRotation() const override
        {
            return _rotation;
        }

        void SetRotation(alt::Rotation rot) override
        {
        }

        std::unordered_map<std::string, alt::MValueConst> _syncedMetaData = {};

        bool HasSyncedMetaData(const std::string& key) const override
        {
            return _syncedMetaData.find(key) != _syncedMetaData.end();
        }

        alt::MValueConst GetSyncedMetaData(const std::string& key) const override
        {
            const auto find = _syncedMetaData.find(key);
            if (find == _syncedMetaData.end()) return alt::ICore::Instance().CreateMValueNil();
            return find->second;
        }

        std::vector<std::string> GetSyncedMetaDataKeys() const override
        {
            std::vector<std::string> keys(_syncedMetaData.size());
            for (const auto& kv : _syncedMetaData)
            {
                keys.push_back(kv.first);
            }

            return keys;
        }

        std::unordered_map<std::string, alt::MValueConst> _streamSyncedMetaData = {};

        bool HasStreamSyncedMetaData(const std::string& key) const override
        {
            return _streamSyncedMetaData.find(key) != _streamSyncedMetaData.end();
        }

        alt::MValueConst GetStreamSyncedMetaData(const std::string& key) const override
        {
            const auto find = _streamSyncedMetaData.find(key);
            if (find == _streamSyncedMetaData.end()) return alt::ICore::Instance().CreateMValueNil();
            return find->second;
        }

        std::vector<std::string> GetStreamSyncedMetaDataKeys() const override
        {
            std::vector<std::string> keys(_streamSyncedMetaData.size());
            for (const auto& kv : _streamSyncedMetaData)
            {
                keys.push_back(kv.first);
            }

            return keys;
        }

        bool _visible;

        bool GetVisible() const override
        {
            return _visible;
        }
        bool _frozen;

        bool IsFrozen() const override
        {
            return _frozen;
        }

        void SetFrozen(bool state) override
        {
        }

#ifdef ALT_SERVER_API
        void SetNetworkOwner(alt::IPlayer* player, bool disableMigration) override
        {
        }

        void SetSyncedMetaData(const std::string& key, alt::MValue val) override
        {
        }

        void DeleteSyncedMetaData(const std::string& key) override
        {
        }

        void SetStreamSyncedMetaData(const std::string& key, alt::MValue val) override
        {
        }

        void DeleteStreamSyncedMetaData(const std::string& key) override
        {
        }

        void SetVisible(bool toggle) override
        {
        }

        void AttachToEntity(IEntity* entity, uint16_t otherBoneId, uint16_t myBoneId, alt::Position position,
                            alt::Rotation rotation, bool collision, bool noFixedRotation) override
        {
        }

        void AttachToEntity(IEntity* entity, const std::string& otherBoneName, const std::string& myBoneName,
                            alt::Position position, alt::Rotation rotation, bool collision,
                            bool noFixedRotation) override
        {
        }

        void Detach() override
        {
        }

        void SetStreamed(bool toggle) override
        {
        }

        bool _streamed;

        bool GetStreamed() const override
        {
            return _streamed;
        }

        bool _collision;

        bool HasCollision() const override
        {
            return _collision;
        }

        void SetCollision(bool state) override
        {
        }

        uint32_t _timestamp;

        uint32_t GetTimestamp() const override
        {
            return _timestamp;
        }

        uint32_t _streamingDistance;
        uint32_t GetStreamingDistance() const override
        {
            return _streamingDistance;
        }

        void SetMultipleStreamSyncedMetaData(const std::unordered_map<std::string, alt::MValue>& values) override {}

        void SetStreamingDistance(uint32_t streamingDistance) override {}
#endif


#ifdef ALT_CLIENT_API
        uint32_t _scriptId;
        uint32_t GetScriptID() const override {
            return _scriptId;
        }

        alt::SyncInfo _syncInfo;
        alt::SyncInfo GetSyncInfo() const override {
            return _syncInfo;
        }

        uint32_t _remoteId;
        uint32_t GetRemoteID() const override {
            return _remoteId;
        }

        bool _isRemote;
        bool IsRemote() const override {
            return _isRemote;
        }
#endif
    };
} // namespace alt
