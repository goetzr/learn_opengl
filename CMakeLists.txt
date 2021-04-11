cmake_minimum_required(VERSION 3.19)
project(learn_opengl)

set(CMAKE_CXX_STANDARD           20)
set(CMAKE_CXX_STANDARD_REQUIRED  TRUE)
set(CMAKE_CXX_EXTENSIONS         FALSE)

find_package(fmt REQUIRED CONFIG)
find_package(glfw3 REQUIRED CONFIG)
find_package(GLEW REQUIRED CONFIG)

add_subdirectory(show_window)
add_subdirectory(legacy_triangle)
add_subdirectory(modern_opengl)
add_subdirectory(vertex_buffer)
add_subdirectory(vertex_attributes)
add_subdirectory(shader1)
add_subdirectory(shader2)
add_subdirectory(index_buffers)