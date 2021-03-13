#include <exception>

#include "log.h"
#include "glfw_wrapper.h"

using namespace std;

int main(int argc, char** argv) {
  bool has_error = false;

  try {
    InitGlfw();
    auto window = CreateWindow("Show Window", 640, 430);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
      glClear(GL_COLOR_BUFFER_BIT);

      glfwSwapBuffers(window);

      glfwPollEvents();
    }
  } catch (exception& e) {
    has_error = true;
    error(e.what());
  }

  glfwTerminate();
  return has_error ? 1 : 0;
}