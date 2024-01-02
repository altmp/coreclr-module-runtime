#include "connection_info.h"

#include "../utils/macros.h"
#include "../utils/strings.h"
#include "../utils/uint.h"

CAPI_START()

#ifdef ALT_SERVER_API

alt::IBaseObject* ConnectionInfo_GetBaseObject(alt::IConnectionInfo* connectionInfo)
{
    return dynamic_cast<alt::IBaseObject*>(connectionInfo);
}

void ConnectionInfo_Accept(alt::IConnectionInfo* connectionInfo, uint8_t sendNames) {
    connectionInfo->Accept(sendNames);
}

void ConnectionInfo_Decline(alt::IConnectionInfo* connectionInfo, const char* reason) {
    connectionInfo->Decline(reason);
}

const char* ConnectionInfo_GetName(alt::IConnectionInfo* connectionInfo, int32_t& size) {
    return AllocateString(connectionInfo->GetName(), size);
}

uint64_t ConnectionInfo_GetSocialId(alt::IConnectionInfo* connectionInfo) {
    return connectionInfo->GetSocialId();
}

uint64_t ConnectionInfo_GetHwIdHash(alt::IConnectionInfo* connectionInfo) {
    return connectionInfo->GetHwIdHash();
}

uint64_t ConnectionInfo_GetHwIdExHash(alt::IConnectionInfo* connectionInfo) {
    return connectionInfo->GetHwIdExHash();
}

const char* ConnectionInfo_GetAuthToken(alt::IConnectionInfo* connectionInfo, int32_t& size) {
    return AllocateString(connectionInfo->GetAuthToken(), size);
}

uint8_t ConnectionInfo_GetIsDebug(alt::IConnectionInfo* connectionInfo) {
    return connectionInfo->GetIsDebug();
}

const char* ConnectionInfo_GetBranch(alt::IConnectionInfo* connectionInfo, int32_t& size) {
    return AllocateString(connectionInfo->GetBranch(), size);
}

uint16_t ConnectionInfo_GetVersionMajor(alt::IConnectionInfo* connectionInfo) {
    return connectionInfo->GetVersionMajor();
}

uint16_t ConnectionInfo_GetVersionMinor(alt::IConnectionInfo* connectionInfo) {
    return connectionInfo->GetVersionMinor();
}

const char* ConnectionInfo_GetCdnUrl(alt::IConnectionInfo* connectionInfo, int32_t& size) {
    return AllocateString(connectionInfo->GetCdnUrl(), size);
}

uint64_t ConnectionInfo_GetPasswordHash(alt::IConnectionInfo* connectionInfo) {
    return connectionInfo->GetPasswordHash();
}

const char* ConnectionInfo_GetIp(alt::IConnectionInfo* connectionInfo, int32_t& size) {
    return AllocateString(connectionInfo->GetIp(), size);
}

int64_t ConnectionInfo_GetDiscordUserID(alt::IConnectionInfo* connectionInfo) {
    return connectionInfo->GetDiscordUserID();
}

uint32_t ConnectionInfo_GetID(alt::IConnectionInfo* connectionInfo)
{
    return connectionInfo->GetID();
}

const char* ConnectionInfo_GetSocialName(alt::IConnectionInfo* connectionInfo, int32_t& size)
{
    return AllocateString(connectionInfo->GetSocialName(), size);
}

const char* ConnectionInfo_GetCloudID(alt::IConnectionInfo* connectionInfo, int32_t& size)
{
    return AllocateString(connectionInfo->GetCloudID(), size);
}

uint8_t ConnectionInfo_GetCloudAuthResult(alt::IConnectionInfo* connectionInfo)
{
    return static_cast<uint8_t>(connectionInfo->GetCloudAuthResult());
}

uint8_t ConnectionInfo_IsAccepted(alt::IConnectionInfo* connectionInfo)
{
    return connectionInfo->IsAccepted();
}

const char* ConnectionInfo_GetText(alt::IConnectionInfo* connectionInfo, int32_t& size)
{
    return AllocateString(connectionInfo->GetText(), size);
}

void ConnectionInfo_SetText(alt::IConnectionInfo* connectionInfo, const char* text)
{
    connectionInfo->SetText(text);
}
#endif

CAPI_END()