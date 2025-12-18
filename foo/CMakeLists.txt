project(foo VERSION 1.0 LANGUAGES CXX)

# Create library
add_library(foo STATIC
    src/foo.cpp
)

# Find fmt package
find_package(fmt CONFIG REQUIRED)

# Link fmt library
target_link_libraries(foo PUBLIC fmt::fmt)

# Set include directories
target_include_directories(foo 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

