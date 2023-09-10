#pragma once

#include <cpp-sdk/CRefCountable.h>
#include <cpp-sdk/ICore.h>
#include <cpp-sdk/objects/IBaseObject.h>
#include <cpp-sdk/types/MValue.h>

namespace cache
{
    class CachedBaseObject : public virtual alt::IBaseObject
    {
        Type _type;

    public:
        ~CachedBaseObject() override
        {
        };

        CachedBaseObject(IBaseObject* base) : _type(base->GetType())
        {
            auto keys = base->GetMetaDataKeys();
            for (const auto& key : keys)
            {
                _metaData[key] = base->GetMetaData(key);
            }
        }

        Type GetType() const override
        {
            return _type;
        }

        std::unordered_map<std::string, alt::MValueConst> _metaData = {};

        bool HasMetaData(const std::string& key) const override
        {
            return _metaData.find(key) != _metaData.end();
        }

        alt::MValueConst GetMetaData(const std::string& key) const override
        {
            const auto find = _metaData.find(key);
            if (find == _metaData.end()) return alt::ICore::Instance().CreateMValueNil();
            return find->second;
        }

        std::vector<std::string> GetMetaDataKeys() const override
        {
            std::vector<std::string> keys(_metaData.size());
            for (const auto& kv : _metaData)
            {
                keys.push_back(kv.first);
            }

            return keys;
        }

        void SetMetaData(const std::string& key, alt::MValue val) override
        {
        }

        void DeleteMetaData(const std::string& key) override
        {
        }

        bool IsRemoved() const
        {
            return false;
        }

        void SetMultipleMetaData(const std::unordered_map<std::string, alt::MValue>& values) override {}

#ifdef ALT_SERVER_API
        void SetMultipleSyncedMetaData(const std::unordered_map<std::string, alt::MValue>& values) override {}
        void SetSyncedMetaData(const std::string& key, alt::MValue val) override {}
        void DeleteSyncedMetaData(const std::string& key) override {}
#endif

    };
} // namespace alt
