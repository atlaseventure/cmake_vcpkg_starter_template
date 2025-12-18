project(my_project_tests VERSION 1.0 LANGUAGES CXX)

# Find Catch2
find_package(Catch2 3 CONFIG REQUIRED)

# Create test executable
add_executable(foo_tests
    src/test_foo.cpp
)

# Link libraries
target_link_libraries(foo_tests 
    PRIVATE 
        foo
        Catch2::Catch2WithMain
)

# Discover tests
include(Catch)
catch_discover_tests(foo_tests)
