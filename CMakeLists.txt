cmake_minimum_required(VERSION 3.26)
project(laba23 C)

set(CMAKE_C_STANDARD 99)

add_executable(laba23 main.c
        matrix.c
        matrix.h
        operations.c
        operations.h
        gauss.c
        gauss.h
        exp.c
        exp.h
        inverse.c
        inverse.h
)
