@echo off

(
  echo #pragma once
  echo.
  echo #define CSHARP_VERSION "%GITHUB_REF_NAME%"
) > version.h.tmp

if not exist version.h goto rename

fc version.h version.h.tmp > nul
if errorlevel 1 goto remove

del version.h.tmp
goto end

:remove
del version.h
:rename
move version.h.tmp version.h

:end