cmake_minimum_required(VERSION 3.2)
project(antgrep)
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR})

add_executable(antgrep main.cpp recursive_search.cpp )
install(TARGETS antgrep DESTINATION bin)