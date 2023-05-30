cmake_minimum_required(VERSION 3.10.0)
project(custom_alloc VERSION 0.1.0)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17 REQUIRED)

# download GTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip # TODO use more recent version
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)


include_directories(./include)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

add_library(custom_alloc_lib ${SOURCES})

enable_testing()

add_executable(custom_alloc main.cpp )
target_link_libraries(custom_alloc custom_alloc_lib)

# enable GTest
target_link_libraries(
    custom_alloc
  GTest::gtest_main
)
include(GoogleTest)

# Create a test executable
add_executable(custom_alloc_tests ${TEST_SOURCES})
target_link_libraries(custom_alloc_tests custom_alloc_lib GTest::gtest_main)
gtest_discover_tests(custom_alloc_tests)
