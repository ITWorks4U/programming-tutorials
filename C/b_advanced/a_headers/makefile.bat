::  builder for Windows
@echo off
setlocal

::  --------------
::  settings
::  --------------
set EXECUTABLE=header_example.exe
set SOURCE=src/main.c src/math_functions.c
set HEADER_REF=-Iheader
set COMPILER=gcc.exe
set FLAGS=-Wall -o

if "%1" == "" goto help_function
if not "%2" == "" goto help_function
if "%1" == "build" goto build_app
if "%1" == "clean" goto clean_up

::  for any other single argument
goto help_function

::  --------------
::  functions
::  --------------
:help_function
echo "usage: makefile.bat [build | clean]"
echo build = build the libary
echo clean = removes the libary
goto :eof

:build_app
%COMPILER% %SOURCE% %HEADER_REF% %FLAGS% %EXECUTABLE%
goto :eof

:clean_up
del %EXECUTABLE% 2>&1>nul
goto :eof

endlocal