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
    auto window = CreateWindow("Vertex Attributes", 640, 430);
    glfwMakeContextCurrent(window);

    InitGlew();

    float positions[6] = {
      -0.5f, -0.5f,
       0.0f,  0.5f,
       0.5f, -0.5f
    };

    unsigned buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    while (!glfwWindowShouldClose(window)) {
      glClear(GL_COLOR_BUFFER_BIT);

      glDrawArrays(GL_TRIANGLES, 0, 3);

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