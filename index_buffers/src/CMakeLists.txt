add_executable(index_buffers main.cpp
                           ${learn_opengl_SOURCE_DIR}/src/glfw_wrapper.cpp
                           ${learn_opengl_SOURCE_DIR}/src/glew_wrapper.cpp
                           ${learn_opengl_SOURCE_DIR}/src/gl_wrapper.cpp)
target_include_directories(index_buffers PRIVATE ${learn_opengl_SOURCE_DIR}/src)
target_link_libraries(index_buffers PRIVATE GL fmt::fmt glfw GLEW::glew_s)