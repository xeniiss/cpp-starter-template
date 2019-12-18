# CMake version
cmake_minimum_required(VERSION 3.8.2)

# include cmake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project(starter-template VERSION 0.1.0)

# set output directories
set(DEFAULT_CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# set enable output of compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)
include_directories(thirdparty/doctest/doctest)

# import compile options
include(cmake/compile_options.cmake)

# default build type - Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory(src)
add_subdirectory(thirdparty)
add_subdirectory(test)