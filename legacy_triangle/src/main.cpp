#include <exception>

#include "log.h"
#include "glfw_wrapper.h"

using namespace std;

int main(int argc, char** argv) {
  bool has_error = false;

  try {
    InitGlfw();
    auto window = CreateWindow("Legacy Triangle", 640, 430);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
      glClear(GL_COLOR_BUFFER_BIT);

      glBegin(GL_TRIANGLES);
      glVertex2f(-0.5f, -0.5f);
      glVertex2f(0.5f, -0.5f);
      glVertex2f(0.0f, 0.5f);
      glEnd();

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