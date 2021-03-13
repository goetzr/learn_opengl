add_executable(show_window main.cpp
                           ${learn_opengl_SOURCE_DIR}/src/glfw_wrapper.cpp)
target_include_directories(show_window PRIVATE ${learn_opengl_SOURCE_DIR}/src)
target_link_libraries(show_window PRIVATE GL fmt::fmt glfw)