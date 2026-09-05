# minimal version for cmake, e. g. 4.0+
cmake_minimum_required(VERSION 4.0)

# set C standard version
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# project name => C: tells Cmake, that this is a project for C only
project(SimpleProject C)

# set a target name, because we are lazy >:-)
# NOTE: for Windows only the name without file extension is good enough
#       for any other OS, an extension can be used, but this is not necessary
set(TARGET application)

# also set a variable for the source file;
# not necesseary, but... Why not? :o)
set(SOURCES src/main.c src/math_functions.c)

# add to the target the source file(s)
add_executable(${TARGET} ${SOURCES})

# since this project also requires a header, this must be defined here
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/header)

# add compiler and linker flags

# compiler warnings (-Wall ---OR--- -Wextra ---OR--- -Wpedantic)
target_compile_options(${TARGET} PRIVATE -Wall)

# only for UNIX systems, like Linux, macOS, chromeOS, ...
# on a Windows system this doesn't trigger
if(UNIX)
    target_link_libraries(${TARGET} PRIVATE m)
endif()