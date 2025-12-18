project(foo_example VERSION 1.0 LANGUAGES CXX)

add_executable(foo_example src/main.cpp)

target_link_libraries(foo_example PRIVATE foo)