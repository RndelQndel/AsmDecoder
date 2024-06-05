# CMakeLists.txt
project(ArmDecoder)
# cmake version
cmake_minimum_required(VERSION 3.10)

# set Source files
set(BUILD_SRC_LISTS
    main.cpp
    elf.cpp
)

# add executable
add_executable(ArmDecoder ${BUILD_SRC_LISTS})

# set properties
message(STATUS "CMAKE_RUNTIME_OUTPUT_DIRECTORY: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set_target_properties(ArmDecoder PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# set include directories
target_include_directories(ArmDecoder PRIVATE ${CMAKE_SOURCE_DIR}/include)

# current build type flags
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Release build flags: ${CMAKE_CXX_FLAGS_RELEASE}")
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Debug build flags: ${CMAKE_CXX_FLAGS_DEBUG}")
elseif(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
    message(STATUS "MinSizeRel build flags: ${CMAKE_CXX_FLAGS_MINSIZEREL}")
elseif(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    message(STATUS "RelWithDebInfo build flags: ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
else()
    message(WARNING "Unknown build type: ${CMAKE_BUILD_TYPE}")
endif()