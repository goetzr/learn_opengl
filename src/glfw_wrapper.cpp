#include "glfw_wrapper.h"

#include <fmt/format.h>
#include <GLFW/glfw3.h>

#include "error.h"

void InitGlfw() {
  if (!glfwInit()) {
    auto err = GetError();
    throw GlfwError(fmt::format("Failed to initialized GLFW: {}. Error code = {}.", err.description, err.code));
  }
}

GLFWwindow* CreateWindow(char const* title, int width, int height) {
  auto w = glfwCreateWindow(width, height, title, nullptr, nullptr);
  if (w == nullptr) {
    auto err = GetError();
    throw GlfwError(fmt::format("Failed to create the window: {}. Error code = {}.", err.description, err.code));
  }
  return w;
}