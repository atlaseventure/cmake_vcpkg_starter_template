cmake_minimum_required(VERSION 3.20)

project(foo VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/${VCPKG_TARGET_TRIPLET};${CMAKE_PREFIX_PATH}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Enable testing at top level
enable_testing()
include(CTest)

add_subdirectory(foo)
add_subdirectory(examples)
add_subdirectory(tests)