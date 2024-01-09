#include "altv.h"

#include "data/sync_info.h"
#include "data/types.h"
#include "utils/macros.h"
#include "version/version.h"
#if defined ALTV_CSHARP_SHARED || defined ALT_SERVER_API
#include "cpp-sdk/version/version.h"
#endif

#ifdef ALT_CLIENT_API
#include "utils.h"
#include <filesystem>
#endif

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wempty-body"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif

CAPI_START()

void FreeUIntArray(std::vector<uint32_t>* array) {
    array->clear();
}

void FreeCharArray(char charArray[]) {
    delete[] charArray;
}

void FreeUInt32Array(uint32_t uInt32Array[]) {
    delete[] uInt32Array;
}

void FreeUInt8Array(uint8_t uInt8Array[]) {
    delete[] uInt8Array;
}

void FreeVector2Array(vector2_t* vector2Array)
{
    delete[] vector2Array;
}

void FreeVoidPointerArray(void* voidPointerArray[]) {
    delete[] voidPointerArray;
}

void FreeWeaponTArray(weapon_t* weaponArray, uint32_t size) {
    for (int i = 0; i < size; i++) if (weaponArray[i].componentsCount > 0) delete[] weaponArray[i].components;
    delete[] weaponArray;
}

void FreeSyncInfo(sync_info_t syncInfo) {
    if (syncInfo.componentCount > 0)
    {
        for (int i = 0; i < syncInfo.componentCount; ++i)
        {
            delete[]syncInfo.propertyUpdateTicks[i];
        }
        delete[] syncInfo.propertyUpdateTicks;
    }
}

void FreeString(const char* string) {
    delete[] string;
}

void FreeStringArray(const char** stringArray, uint32_t size) {
    for (int i = 0; i < size; i++) delete[] stringArray[i];
    delete[] stringArray;
}

void FreeResourceArray(alt::IResource** resourceArray) {
    delete[] resourceArray;
}

void FreePlayerArray(alt::IPlayer** playerArray) {
    delete[] playerArray;
}

void FreeBlipArray(alt::IBlip** blipArray)
{
    delete[] blipArray;
}

void FreeVehicleArray(alt::IVehicle** vehicleArray)
{
    delete[] vehicleArray;
}

void FreePedArray(alt::IPed** pedArray)
{
    delete[] pedArray;
}

void FreeNetworkObjectArray(alt::IObject** networkObjectArray)
{
    delete[] networkObjectArray;
}

void FreeColShapeArray(alt::IColShape** colShapeArray)
{
    delete[] colShapeArray;
}

void FreeMarkerArray(alt::IMarker** markerArray)
{
    delete[] markerArray;
}

void FreeTextLabelArray(alt::ITextLabel** textLabelArray)
{
    delete[] textLabelArray;
}

void FreeCheckpointArray(alt::ICheckpoint** checkPointArray)
{
    delete[] checkPointArray;
}

void FreeVirtualEntityArray(alt::IVirtualEntity** virtualEntityArray)
{
    delete[] virtualEntityArray;
}

void FreeVirtualEntityGroupArray(alt::IVirtualEntityGroup** virtualEntityGroupArray)
{
    delete[] virtualEntityGroupArray;
}

void FreeConnectionInfoArray(alt::IConnectionInfo** connectionInfoArray)
{
    delete[] connectionInfoArray;
}

void FreeLocalObjectArray(alt::ILocalObject** objectArray) {
    delete[] objectArray;
}

void FreeAudioArray(alt::IAudio** audioArray)
{
    delete[] audioArray;
}

void FreeAudioOutputArray(alt::IAudioOutput** audioOutputArray)
{
    delete[] audioOutputArray;
}

void FreeMValueConstArray(alt::MValueConst** mValueConstArray) {
    delete[] mValueConstArray;
}

const char* GetVersionStatic(int32_t &size) {
    return AllocateString(alt::ICore::Instance().GetVersion(), size);
}

const char* GetBranchStatic(int32_t &size) {
    return AllocateString(alt::ICore::Instance().GetBranch(), size);
}

uint8_t IsDebugStatic() {
    return alt::ICore::Instance().IsDebug();
}

const char* GetCApiVersion(int32_t &size) {
    return AllocateString(CSHARP_VERSION, size);
}

const char* GetSDKVersion(int32_t &size) {
#ifdef ALT_SDK_VERSION
    return AllocateString(ALT_SDK_VERSION, size);
#else
    return AllocateString("", size);
#endif
}

#ifdef ALT_CLIENT_API
void FreeRmlElementArray(alt::IRmlElement** rmlElementArray) {
    delete[] rmlElementArray;
}

void FreeLocalVehicleArray(alt::ILocalVehicle** localVehicleArray)
{
    delete[] localVehicleArray;
}

void FreeLocalPedArray(alt::ILocalPed** localPedArray)
{
    delete[] localPedArray;
}

void* Win_GetTaskDialog() {
    char *pValue;
    size_t len;
    if (_dupenv_s(&pValue, &len, "windir")) return nullptr;
    const std::string platform = sizeof(size_t) == 4 ? "x86" : "amd64";
    const std::string prefix = platform + "_microsoft.windows.common-controls_6595b64144ccf1df_6.";
    const std::filesystem::path winDir(pValue);
    for (auto& dirEntry : std::filesystem::directory_iterator(winDir / "WinSxS")) {
        auto filename = dirEntry.path().filename().string();
        if (!dirEntry.is_directory() || !utils::has_prefix(filename, prefix)) continue;
        auto path = (dirEntry.path() / "comctl32.dll").string();
        auto lib = LoadLibraryEx(utils::string_to_wstring(path).c_str(), nullptr, 0);
        return (void*) GetProcAddress(lib, "TaskDialogIndirect");
    }

    return nullptr;
}

#endif

CAPI_END()