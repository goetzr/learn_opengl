#include <exception>

#include <GL/glew.h>

#include "glew_wrapper.h"
#include "glfw_wrapper.h"
#include "log.h"

using namespace std;

int main(int argc, char** argv) {
  bool has_error = false;

  try {
    InitGlfw();
    auto window = CreateWindow("Modern OpenGL", 640, 430);
    glfwMakeContextCurrent(window);

    InitGlew();
    info("Using OpenGL version {}.", glGetString(GL_VERSION));

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