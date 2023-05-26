cmake_minimum_required(VERSION 3.0.0)
project(custom_alloc VERSION 0.1.0)

include_directories(./include)

include(CTest)
enable_testing()

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(custom_alloc main.cpp ${SOURCES})

