#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#pragma clang diagnostic ignored "-Wswitch"
#endif

#include "cpp-sdk/SDK.h"
#include "../data/types.h"
#include "../utils/export.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif

EXPORT_SERVER alt::IBaseObject* ConnectionInfo_GetBaseObject(alt::IConnectionInfo* connectionInfo);

EXPORT_SERVER uint32_t ConnectionInfo_GetID(alt::IConnectionInfo* connectionInfo);
EXPORT_SERVER const char* ConnectionInfo_GetName(alt::IConnectionInfo* connectionInfo, int32_t& size);
EXPORT_SERVER uint64_t ConnectionInfo_GetSocialId(alt::IConnectionInfo* connectionInfo);
EXPORT_SERVER const char* ConnectionInfo_GetSocialName(alt::IConnectionInfo* connectionInfo, int32_t& size);
EXPORT_SERVER uint64_t ConnectionInfo_GetHwIdHash(alt::IConnectionInfo* connectionInfo);
EXPORT_SERVER uint64_t ConnectionInfo_GetHwIdExHash(alt::IConnectionInfo* connectionInfo);
EXPORT_SERVER const char* ConnectionInfo_GetAuthToken(alt::IConnectionInfo* connectionInfo, int32_t& size);
EXPORT_SERVER uint8_t ConnectionInfo_GetIsDebug(alt::IConnectionInfo* connectionInfo);
EXPORT_SERVER const char* ConnectionInfo_GetBranch(alt::IConnectionInfo* connectionInfo, int32_t& size);
EXPORT_SERVER uint16_t ConnectionInfo_GetVersionMajor(alt::IConnectionInfo* connectionInfo);
EXPORT_SERVER uint16_t ConnectionInfo_GetVersionMinor(alt::IConnectionInfo* connectionInfo);
EXPORT_SERVER const char* ConnectionInfo_GetCdnUrl(alt::IConnectionInfo* connectionInfo, int32_t& size);
EXPORT_SERVER uint64_t ConnectionInfo_GetPasswordHash(alt::IConnectionInfo* connectionInfo);
EXPORT_SERVER const char* ConnectionInfo_GetIp(alt::IConnectionInfo* connectionInfo, int32_t& size);
EXPORT_SERVER int64_t ConnectionInfo_GetDiscordUserID(alt::IConnectionInfo* connectionInfo);
EXPORT_SERVER const char* ConnectionInfo_GetText(alt::IConnectionInfo* connectionInfo, int32_t& size);
EXPORT_SERVER void ConnectionInfo_SetText(alt::IConnectionInfo* connectionInfo, const char* text);

EXPORT_SERVER const char* ConnectionInfo_GetCloudID(alt::IConnectionInfo* connectionInfo, int32_t& size);
EXPORT_SERVER uint8_t ConnectionInfo_GetCloudAuthResult(alt::IConnectionInfo* connectionInfo);

EXPORT_SERVER void ConnectionInfo_Accept(alt::IConnectionInfo* connectionInfo, uint8_t sendNames);
EXPORT_SERVER void ConnectionInfo_Decline(alt::IConnectionInfo* connectionInfo, const char* reason);
EXPORT_SERVER uint8_t ConnectionInfo_IsAccepted(alt::IConnectionInfo* connectionInfo);
