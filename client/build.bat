@echo off

:: Build project
IF NOT EXIST build\ (
    mkdir build
)

IF NOT EXIST build\coreclr-client-module (
    mkdir build\coreclr-client-module
)

cmake . -Bcmake-build-release -DDYNAMIC_BUILD=1
cmake --build cmake-build-release --config RelWithDebInfo
copy .\cmake-build-release\RelWithDebInfo\altv-client-csharp.dll .\build\coreclr-client-module\coreclr-client-module.dll
copy .\cmake-build-release\RelWithDebInfo\altv-client-csharp.pdb .\build\coreclr-client-module\coreclr-client-module.pdb
