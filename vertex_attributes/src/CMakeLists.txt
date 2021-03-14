add_executable(vertex_attributes main.cpp
                           ${learn_opengl_SOURCE_DIR}/src/glfw_wrapper.cpp
                           ${learn_opengl_SOURCE_DIR}/src/glew_wrapper.cpp)
target_include_directories(vertex_attributes PRIVATE ${learn_opengl_SOURCE_DIR}/src)
target_link_libraries(vertex_attributes PRIVATE GL fmt::fmt glfw GLEW::glew_s)