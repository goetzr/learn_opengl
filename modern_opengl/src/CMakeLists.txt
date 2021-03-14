add_executable(modern_opengl main.cpp
                           ${learn_opengl_SOURCE_DIR}/src/glfw_wrapper.cpp
                           ${learn_opengl_SOURCE_DIR}/src/glew_wrapper.cpp)
target_include_directories(modern_opengl PRIVATE ${learn_opengl_SOURCE_DIR}/src)
target_link_libraries(modern_opengl PRIVATE GL fmt::fmt glfw GLEW::glew_s)