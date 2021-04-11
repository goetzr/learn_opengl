#include <exception>

#include <GL/glew.h>

#include "glew_wrapper.h"
#include "glfw_wrapper.h"
#include "log.h"
#include "gl_wrapper.h"

#include <iostream>
#include <filesystem>

using namespace std;

int main(int argc, char** argv) {
  bool has_error = false;

  try {
    InitGlfw();
    auto window = CreateWindow("Index Buffers", 640, 430);
    glfwMakeContextCurrent(window);

    InitGlew();

    float positions[] = {
      -0.5f, -0.5f,
       0.5f, -0.5f,
       0.5f,  0.5f,
      -0.5f,  0.5f
    };

    unsigned int indices[] = {
      0, 1, 2,
      2, 3, 0
    };

    unsigned buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), static_cast<void const*>(0));

    unsigned ibo; // index buffer object
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    auto prog_src = ParseShader("../res/shaders/Basic.shader");
    auto shader = CreateShader(prog_src.vertexSource, prog_src.fragmentSource);
    glUseProgram(shader);

    while (!glfwWindowShouldClose(window)) {
      glClear(GL_COLOR_BUFFER_BIT);

      glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

      glfwSwapBuffers(window);

      glfwPollEvents();
    }

    glDeleteProgram(shader);
  } catch (exception& e) {
    has_error = true;
    error(e.what());
  }

  glfwTerminate();
  return has_error ? 1 : 0;
}