cmake_minimum_required(VERSION 3.8)
project(proc)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Stack.c Stack.h CPU.c CPU.h Commands.h)
add_executable(proc ${SOURCE_FILES})