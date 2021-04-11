add_executable(dealing_with_errors main.cpp
                           ${learn_opengl_SOURCE_DIR}/src/glfw_wrapper.cpp
                           ${learn_opengl_SOURCE_DIR}/src/glew_wrapper.cpp
                           ${learn_opengl_SOURCE_DIR}/src/gl_wrapper.cpp)
target_include_directories(dealing_with_errors PRIVATE ${learn_opengl_SOURCE_DIR}/src)
target_link_libraries(dealing_with_errors PRIVATE GL fmt::fmt glfw GLEW::glew_s)