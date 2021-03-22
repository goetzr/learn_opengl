add_executable(shader1 main.cpp
                           ${learn_opengl_SOURCE_DIR}/src/glfw_wrapper.cpp
                           ${learn_opengl_SOURCE_DIR}/src/glew_wrapper.cpp
                           ${learn_opengl_SOURCE_DIR}/src/gl_wrapper.cpp)
target_include_directories(shader1 PRIVATE ${learn_opengl_SOURCE_DIR}/src)
target_link_libraries(shader1 PRIVATE GL fmt::fmt glfw GLEW::glew_s)