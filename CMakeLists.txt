cmake_minimum_required(VERSION 3.19)
project(learn_opengl)

set(CMAKE_CXX_STANDARD           20)
set(CMAKE_CXX_STANDARD_REQUIRED  TRUE)
set(CMAKE_CXX_EXTENSIONS         FALSE)

find_package(fmt REQUIRED CONFIG)
find_package(glfw3 REQUIRED CONFIG)

add_subdirectory(show_window)