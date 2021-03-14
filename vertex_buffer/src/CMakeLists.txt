add_executable(vertex_buffer main.cpp
                           ${learn_opengl_SOURCE_DIR}/src/glfw_wrapper.cpp
                           ${learn_opengl_SOURCE_DIR}/src/glew_wrapper.cpp)
target_include_directories(vertex_buffer PRIVATE ${learn_opengl_SOURCE_DIR}/src)
target_link_libraries(vertex_buffer PRIVATE GL fmt::fmt glfw GLEW::glew_s)