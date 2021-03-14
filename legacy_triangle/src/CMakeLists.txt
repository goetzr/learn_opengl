add_executable(legacy_triangle main.cpp
                           ${learn_opengl_SOURCE_DIR}/src/glfw_wrapper.cpp)
target_include_directories(legacy_triangle PRIVATE ${learn_opengl_SOURCE_DIR}/src)
target_link_libraries(legacy_triangle PRIVATE GL fmt::fmt glfw)