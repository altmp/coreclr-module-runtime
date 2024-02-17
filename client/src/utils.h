#pragma once
#include <string>
#include <combaseapi.h>
#include "cpp-sdk/SDK.h"
#include <string>
#include <codecvt>
#include <future>
#include <Log.h>

EXTERN_C IMAGE_DOS_HEADER __ImageBase;

#ifdef _WIN32
#define STR(s) L##s
#else
#define STR(s) s
#endif


static const std::string base64_chars =
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";


static inline bool is_base64(unsigned char c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
}

namespace utils
{
#ifdef DEBUG_CLIENT
    inline std::wstring get_current_dll_path()
    {
        wchar_t strDLLPath[MAX_PATH];
        GetModuleFileName((HINSTANCE)&__ImageBase, strDLLPath, MAX_PATH);
        return {strDLLPath, strDLLPath + wcslen(strDLLPath)};
    }
#endif

    inline std::wstring string_to_wstring(const std::string& string)
    {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::wstring wide = converter.from_bytes(string);
        return wide;
    }

    inline std::string wstring_to_string(const std::wstring& string)
    {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::string narrow = converter.to_bytes(string);
        return narrow;
    }

    template<typename T>
    inline T* get_clr_string(const T* str) {
        size_t ulSize = (std::char_traits<T>::length(str) + 1) * sizeof(T);
        T* returnStr;
        returnStr = CoTaskMemAlloc(ulSize);
        std::char_traits<T>::copy(returnStr, str, ulSize);
        return returnStr;
    }
    
    template <typename T, typename... Args>
    T *get_clr_value(Args &&...args)
    {
        return new (static_cast<T*>(CoTaskMemAlloc(sizeof(T)))) T(std::forward<Args>(args)...);
    }

    template <typename T, typename Traits = std::char_traits<T>>
    T *get_clr_value(const T *str)
    {
        size_t size = (Traits::length(str) + 1) * sizeof(T);
        T *clr_str = static_cast<T *>(CoTaskMemAlloc(size));
        Traits::copy(clr_str, str, size);
        return clr_str;
    }

    template <typename T, typename Traits = std::char_traits<T>>
    T *get_clr_value(const T *str, int len)
    {
        size_t size = len * sizeof(T);
        T *clr_str = static_cast<T *>(CoTaskMemAlloc(size));
        Traits::copy(clr_str, str, size);
        return clr_str;
    }

    inline bool has_suffix(const std::string &str, const std::string &suffix)
    {
        return str.size() >= suffix.size() &&
               str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
    }

    inline bool has_prefix(const std::string &str, const std::string &prefix)
    {
        return str.compare(0, prefix.size(), prefix) == 0;
    }

    inline std::string& to_lower(std::string& str) {
        std::transform(str.begin(), str.end(), str.begin(), [](const unsigned char c){ return std::tolower(c); });
        return str;
    }
    
    inline alt::IHttpClient::HttpResponse download_file_sync(alt::IHttpClient* httpClient, const std::string& url) {
        auto attempt = 0;
        
        while (true)
        {
            if (++attempt > 5) throw std::runtime_error("Failed to download file " + url);
            
            std::promise<alt::IHttpClient::HttpResponse> promise;
            std::future<alt::IHttpClient::HttpResponse> future = promise.get_future();
    
            httpClient->Get([](alt::IHttpClient::HttpResponse response, const void* data) {
                const auto innerPromise = (std::promise<alt::IHttpClient::HttpResponse>*) data;
            
                if (response.statusCode != 200) {
                    std::stringstream ss;
                    ss << "HTTP " << response.statusCode << " " << response.body;
                    innerPromise->set_exception(std::make_exception_ptr(std::runtime_error(ss.str())));
                    return;
                }
            
                innerPromise->set_value(response);
            }, url, &promise);

            try {
                return future.get();
            } catch(const std::exception& e) {
                cs::Log::Warning << "Failed to download file " << url << ", attempt " << attempt << ": " << e.what() << cs::Log::Endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
    }


    inline std::vector<unsigned char> base64_decode(std::string const& encoded_string) {
        auto in_len = encoded_string.size();
        int i = 0;
        int j = 0;
        int in_ = 0;
        unsigned char char_array_4[4], char_array_3[3];
        std::vector<unsigned char> ret;

        while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
            char_array_4[i++] = encoded_string[in_]; in_++;
            if (i ==4) {
                for (i = 0; i <4; i++)
                    char_array_4[i] = base64_chars.find(char_array_4[i]);

                char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
                char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
                char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

                for (i = 0; (i < 3); i++)
                    ret.push_back(char_array_3[i]);
                i = 0;
            }
        }

        if (i) {
            for (j = i; j <4; j++)
                char_array_4[j] = 0;

            for (j = 0; j <4; j++)
                char_array_4[j] = base64_chars.find(char_array_4[j]);

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

            for (j = 0; (j < i - 1); j++) ret.push_back(char_array_3[j]);
        }

        return ret;
    }
}  // namespace utils