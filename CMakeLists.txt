cmake_minimum_required(VERSION 3.30)
project(lab8 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab8 main.c
        include/images.h
        include/io.h
        src/io.c
        include/colors.h
        include/calculations.h
        src/calculations.c)
