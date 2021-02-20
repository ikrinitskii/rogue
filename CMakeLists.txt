cmake_minimum_required(VERSION 3.17)
project(rogue)

set(CMAKE_CXX_STANDARD 17)

add_library(array2d STATIC array2d.cpp)

add_executable(rogue main.cpp)
add_dependencies(rogue array2d)

target_link_libraries(rogue -lncurses array2d)