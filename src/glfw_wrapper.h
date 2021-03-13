#ifndef __OPENGL_GLFW_WRAPPER_H__
#define __OPENGL_GLFW_WRAPPER_H__

#include <tuple>
#include <string>

#include <GLFW/glfw3.h>

struct GlfwErrorInfo {
  GlfwErrorInfo(int err_code, std::string const& err_desc) : code(err_code), description(err_desc) {}

  int code;
  std::string description;
};

inline GlfwErrorInfo GetError() {
  char const* desc;
  auto code = glfwGetError(&desc);
  return GlfwErrorInfo(code, desc);
}

void InitGlfw();
GLFWwindow* CreateWindow(char const* title, int width, int height);

#endif // __OPENGL_GLFW_WRAPPER_H__