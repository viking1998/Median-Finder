cmake_minimum_required(VERSION 3.20)

include(Dart)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_subdirectory(test)

set(Headers
    include/median_finder.h)

set(Sources
    src/median_finder.cpp)

add_library(median_finder STATIC ${Sources} ${Headers})