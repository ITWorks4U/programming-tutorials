::  for Windows only
::  use this batch file to build or clean up your application
::
::  It may happen, that on your machine this batch file won't create an
::  executable file. This may happen, if the system settings blocks a batch
::  file or else.
@echo off
setlocal

::  --------------
::  declarations
::  --------------
set COMPILER=gcc.exe
set SOURCES=src/main.c src/math_functions.c
set FLAGS=-Wall
set LINK=-Iheader
set OUTPUT=-o
set APPLICATION=math_tester.exe

::  --------------
::  some checks
::  --------------

::  check, if no argument or more than one argument is/are given
if "%1" == "" goto help_function
if not "%2" == "" goto help_function

::  check, if the first argument is "build" or "clean" only
::  every other argument calls the help function instead
if "%1" == "build" goto build_app
if "%1" == "clean" goto clean_up

::  for any other single argument
goto help_function

::  --------------
::  functions
::  --------------
:help_function
echo "usage: makefile.bat [build | clean]"
echo build = build the application
echo clean = removes the application
goto :eof

:build_app
%COMPILER% %FLAGS% %SOURCES% %LINK% %OUTPUT% %APPLICATION%
goto :eof

:clean_up
del %APPLICATION% 2>&1>nul
goto :eof

endlocal