# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(AsmDecoder VERSION 1.0)

# C++ standard Configuration
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set build type to Release by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

# Enable debug symbols for Debug build
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Werror")

# Enable optimizations for Release build
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Werror")

# Set the output directory for the executable
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    make_directory(${CMAKE_BINARY_DIR}/build/debug)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/debug)
else()
    make_directory(${CMAKE_BINARY_DIR}/build/release)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/release)
endif()

# Include the subdirectory containing our libs
add_subdirectory(src)

