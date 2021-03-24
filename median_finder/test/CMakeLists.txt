cmake_minimum_required(VERSION 3.20)

include(Dart)

set(CMAKE_CXX_STANDARD 14)

set(Sources
    median_finder_tests.cpp)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

add_executable(median_finder_tests ${Sources})
target_link_libraries(median_finder_tests PUBLIC
    gtest_main
    median_finder)

add_test(
    NAME MedianFinderTests
    COMMAND median_finder_tests
)