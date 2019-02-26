cmake_minimum_required(VERSION 3.8)
project(Assembler)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c Commands.h)
add_executable(Assembler ${SOURCE_FILES})