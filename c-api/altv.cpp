#include "altv.h"

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

using alt::Array;

void FreeUIntArray(alt::Array<uint32_t>* array) {
    array->~Array<uint32_t>();
}

/*void FreeStringViewArray(alt::Array<std::stringView>* array) {
    array->~Array<std::stringView>();
}*/

/*void FreeStringArray(alt::Array<std::string>* array) {
    array->~Array<std::string>();
}*/

/*void FreeMValueArray(alt::Array<alt::MValue>* array) {
    array->~Array<alt::MValue>();
}*/

/*void FreePlayerPointerArray(alt::Array<alt::IPlayer*>* array) {
    array->~Array<alt::IPlayer*>();
}*/

void FreeCharArray(char charArray[]) {
    delete[] charArray;
}

void FreeUInt32Array(uint32_t uInt32Array[]) {
    delete[] uInt32Array;
}

void FreeUInt8Array(uint8_t uInt8Array[]) {
    delete[] uInt8Array;
}

void FreeVoidPointerArray(void* voidPointerArray[]) {
    delete[] voidPointerArray;
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
    return AllocateString("", 0);
#endif
}

#ifdef ALT_CLIENT_API
void FreeRmlElementArray(alt::IRmlElement** rmlElementArray) {
    delete[] rmlElementArray;
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
