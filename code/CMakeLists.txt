cmake_minimum_required(VERSION 3.10.0)
project(project5 VERSION 0.1.0 LANGUAGES C CXX)

if (MSVC)
    add_compile_options(/W3)
    add_compile_options(/std:c++20)
    add_compile_options(/EHsc)
    add_compile_options(/utf-8)
else()
    add_compile_options(-Wall)
    add_compile_options(-std=c++20)
    add_compile_options(-fexceptions)
    add_compile_options(-O3)
endif()

add_executable(project5
    program.cpp
    work.cpp
    computations.cpp
)
