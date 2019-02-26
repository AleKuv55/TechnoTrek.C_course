cmake_minimum_required(VERSION 3.9)
project(CALCULATOR C)

set(CMAKE_C_STANDARD 99)

add_executable(CALCULATOR main.c Stack.h Stack.c Stackint.c Stackint.h)