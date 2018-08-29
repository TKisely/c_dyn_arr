cmake_minimum_required(VERSION 3.10)
project(dynamicArray C)

set(CMAKE_C_STANDARD 99)

add_executable(dynamicArray main.c dynamicArray.h dynamicString.h)