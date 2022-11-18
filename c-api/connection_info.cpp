#include "connection_info.h"
#include "utils/strings.h"

#ifdef ALT_SERVER_API
void ConnectionInfo_Accept(alt::IConnectionInfo *connectionInfo, uint8_t sendNames) {
    connectionInfo->Accept(sendNames);
}

void ConnectionInfo_Decline(alt::IConnectionInfo *connectionInfo, const char* reason) {
    connectionInfo->Decline(reason);
}

const char* ConnectionInfo_GetName(alt::IConnectionInfo *connectionInfo, int32_t& size) {
    return AllocateString(connectionInfo->GetName(), size);
}

uint64_t ConnectionInfo_GetSocialId(alt::IConnectionInfo *connectionInfo) {
    return connectionInfo->GetSocialId();
}

uint64_t ConnectionInfo_GetHwIdHash(alt::IConnectionInfo *connectionInfo) {
    return connectionInfo->GetHwIdHash();
}

uint64_t ConnectionInfo_GetHwIdExHash(alt::IConnectionInfo *connectionInfo) {
    return connectionInfo->GetHwIdExHash();
}

const char* ConnectionInfo_GetAuthToken(alt::IConnectionInfo *connectionInfo, int32_t& size) {
    return AllocateString(connectionInfo->GetAuthToken(), size);
}

uint8_t ConnectionInfo_GetIsDebug(alt::IConnectionInfo *connectionInfo) {
    return connectionInfo->GetIsDebug();
}

const char* ConnectionInfo_GetBranch(alt::IConnectionInfo *connectionInfo, int32_t& size) {
    return AllocateString(connectionInfo->GetBranch(), size);
}

uint32_t ConnectionInfo_GetBuild(alt::IConnectionInfo *connectionInfo) {
    return connectionInfo->GetBuild();
}

const char* ConnectionInfo_GetCdnUrl(alt::IConnectionInfo *connectionInfo, int32_t& size) {
    return AllocateString(connectionInfo->GetCdnUrl(), size);
}

uint64_t ConnectionInfo_GetPasswordHash(alt::IConnectionInfo *connectionInfo) {
    return connectionInfo->GetPasswordHash();
}

const char* ConnectionInfo_GetIp(alt::IConnectionInfo *connectionInfo, int32_t& size) {
    return AllocateString(connectionInfo->GetIp(), size);
}

int64_t ConnectionInfo_GetDiscordUserID(alt::IConnectionInfo *connectionInfo) {
    return connectionInfo->GetDiscordUserID();
}
#endif