add_executable(shader2 main.cpp
                           ${learn_opengl_SOURCE_DIR}/src/glfw_wrapper.cpp
                           ${learn_opengl_SOURCE_DIR}/src/glew_wrapper.cpp
                           ${learn_opengl_SOURCE_DIR}/src/gl_wrapper.cpp)
target_include_directories(shader2 PRIVATE ${learn_opengl_SOURCE_DIR}/src)
target_link_libraries(shader2 PRIVATE GL fmt::fmt glfw GLEW::glew_s)