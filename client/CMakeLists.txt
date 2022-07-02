cmake_minimum_required (VERSION 3.8)

set(TARGET_NAME altv-client-csharp)

project(${TARGET_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CSHARP_MODULE_DEFS 
    # Compliation
    -DCXX_COMPILER_ID="${CMAKE_CXX_COMPILER_ID}"
    -D_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING

    # Platform
    -DUNICODE
    -D_UNICODE

    # alt:V
    -DALT_CLIENT
    -DALT_CLIENT_API

    # Debug
#   -DDEBUG_CLIENT
)

file(GLOB_RECURSE PROJECT_SOURCE_FILES "src/*.h" "src/*.cpp")
file(GLOB_RECURSE CAPI_FILES "../c-api/*.h" "../c-api/*.cpp")

if(WIN32 AND (MSVC OR CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    add_definitions(/MP)
endif()

if(DYNAMIC_BUILD)
    set(SDK_PROJECT_NAME csharp-alt-sdk)
    include(../cpp-sdk/CMakeLists.txt)
    
    add_library(${TARGET_NAME} SHARED "${PROJECT_SOURCE_FILES}" "${CAPI_FILES}")
    target_compile_definitions(${PROJECT_NAME} PRIVATE 
        ${CSHARP_MODULE_DEFS}
        -DALTV_CSHARP_SHARED
    )
    include_directories(${TARGET_NAME} PRIVATE "src" "thirdparty" "..")
    add_dependencies(${TARGET_NAME} csharp-alt-sdk)
else()
    add_library(${TARGET_NAME}-static STATIC "${PROJECT_SOURCE_FILES}" "${CAPI_FILES}")
    target_compile_definitions(${PROJECT_NAME}-static PRIVATE 
        ${CSHARP_MODULE_DEFS}
    )
    include_directories(${TARGET_NAME}-static PRIVATE "src" "thirdparty" ${ALTV_CSHARP_CPP_SDK})
    # add_dependencies(${TARGET_NAME}-static csharp-alt-sdk)
endif()
