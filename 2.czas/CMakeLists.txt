cmake_minimum_required(VERSION 3.23)
project(2_czas)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(2_czas
        czas.cpp
        czas.h
        czastest.cpp)