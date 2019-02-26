cmake_minimum_required(VERSION 3.8)
project(openclosefiles)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Header.h Onegin.c)
add_executable(openclosefiles ${SOURCE_FILES})