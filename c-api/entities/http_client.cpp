#include "http_client.h"

#include "../utils/macros.h"
#include "../utils/strings.h"

CAPI_START()

uint32_t HttpClient_GetID(alt::IHttpClient* httpClient)
{
    return httpClient->GetID();
}

#ifdef ALT_CLIENT_API

alt::IBaseObject* HttpClient_GetBaseObject(alt::IHttpClient* httpClient) {
    return dynamic_cast<alt::IBaseObject*>(httpClient);
}

void HttpClient_SetExtraHeader(alt::IHttpClient* httpClient, const char* key, const char* value) {
    httpClient->SetExtraHeader(key, value);
}

void MarshalStringDict(alt::IMValueDict* map, const char**& keys, const char**& values, int32_t& size) {
    size = map->GetSize();
    keys = new const char*[size];
    values = new const char*[size];

    auto i = 0;
    for(auto it = map->Begin(); it != map->End(); ++it)
    {
        auto key = it->first;
        auto value = std::dynamic_pointer_cast<const alt::IMValueString>(it->second)->Value();

        auto keyStr = key.c_str();
        auto keySize = key.size();
        auto allocKey = new char[keySize + 1];
        for (auto j = 0; j < keySize; j++) allocKey[j] = keyStr[j];
        allocKey[keySize] = '\0';
        keys[i] = allocKey;

        auto valueStr = value.c_str();
        auto valueSize = value.size();
        auto allocValue = new char[valueSize + 1];
        for (auto j = 0; j < valueSize; j++) allocValue[j] = valueStr[j];
        allocValue[valueSize] = '\0';
        values[i] = allocValue;
        i++;
    }
}

void HttpClient_GetExtraHeaders(alt::IHttpClient* httpClient, const char**& keys, const char**& values, int32_t& size) {
    auto map = httpClient->GetExtraHeaders();
    MarshalStringDict(map.get(), keys, values, size);
}

void InvokeCallback(const alt::IHttpClient::HttpResponse response, const void* ptr) {
    const char** keys;
    const char** values;
    int32_t size;
    MarshalStringDict(response.headers.get(), keys, values, size);
    auto delegate = (HttpResponseDelegate_t) ptr;
    delegate(response.statusCode, response.body.c_str(), keys, values, size);
}

void HttpClient_Get(alt::IHttpClient* httpClient, const char* url, /** ClientEvents.HttpResponseModuleDelegate */ HttpResponseDelegate_t callback) {
    httpClient->Get(InvokeCallback, url, (void *) callback);
}

void HttpClient_Head(alt::IHttpClient* httpClient, const char* url, /** ClientEvents.HttpResponseModuleDelegate */ HttpResponseDelegate_t callback) {
    httpClient->Head(InvokeCallback, url, (void *) callback);
}
void HttpClient_Connect(alt::IHttpClient* httpClient, const char* url, const char* body, /** ClientEvents.HttpResponseModuleDelegate */ HttpResponseDelegate_t callback) {
    httpClient->Connect(InvokeCallback, url, body, (void *) callback);
}

void HttpClient_Delete(alt::IHttpClient* httpClient, const char* url, const char* body, /** ClientEvents.HttpResponseModuleDelegate */ HttpResponseDelegate_t callback) {
    httpClient->Delete(InvokeCallback, url, body, (void *) callback);
}

void HttpClient_Options(alt::IHttpClient* httpClient, const char* url, const char* body, /** ClientEvents.HttpResponseModuleDelegate */ HttpResponseDelegate_t callback) {
    httpClient->Options(InvokeCallback, url, body, (void *) callback);
}

void HttpClient_Patch(alt::IHttpClient* httpClient, const char* url, const char* body, /** ClientEvents.HttpResponseModuleDelegate */ HttpResponseDelegate_t callback) {
    httpClient->Patch(InvokeCallback, url, body, (void *) callback);
}

void HttpClient_Post(alt::IHttpClient* httpClient, const char* url, const char* body, /** ClientEvents.HttpResponseModuleDelegate */ HttpResponseDelegate_t callback) {
    httpClient->Post(InvokeCallback, url, body, (void *) callback);
}

void HttpClient_Put(alt::IHttpClient* httpClient, const char* url, const char* body, /** ClientEvents.HttpResponseModuleDelegate */ HttpResponseDelegate_t callback) {
    httpClient->Put(InvokeCallback, url, body, (void *) callback);
}

void HttpClient_Trace(alt::IHttpClient* httpClient, const char* url, const char* body, /** ClientEvents.HttpResponseModuleDelegate */ HttpResponseDelegate_t callback) {
    httpClient->Trace(InvokeCallback, url, body, (void *) callback);
}
#endif

CAPI_END()