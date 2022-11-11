#pragma once
#include <json.hpp>
#include "cpp-sdk/SDK.h"

class NuGet {
public:
    explicit NuGet(alt::IHttpClient* httpClient);
    ~NuGet() = default;

    std::vector<std::string> GetPackageVersions(const std::string& package);
    nlohmann::json GetCatalog(const std::string& package, const std::string& version);
    std::string DownloadPackage(const std::string& package, const std::string& version);
private:
    std::string GetIndexUrl(const std::string& type);
    alt::IHttpClient* _httpClient;
    nlohmann::json _serviceIndex;
};
