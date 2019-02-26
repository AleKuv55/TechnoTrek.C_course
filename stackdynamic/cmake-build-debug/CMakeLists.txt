cmake_minimum_required(VERSION 3.8)
project(cmake_build_debug)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    cmake_install.cmake
    CMakeCache.txt
    Makefile
    stack2.cbp
    stack2.exe)

add_executable(cmake_build_debug ${SOURCE_FILES})