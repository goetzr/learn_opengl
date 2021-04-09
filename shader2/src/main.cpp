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
    auto window = CreateWindow("Shader 2", 640, 430);
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

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), static_cast<void const*>(0));

    auto prog_src = ParseShader("../res/shaders/Basic.shader");
    cout << filesystem::current_path() << endl;
    cout << prog_src.vertexSource << endl;
    cout << prog_src.fragmentSource << endl;
    auto shader = CreateShader(prog_src.vertexSource, prog_src.fragmentSource);
    glUseProgram(shader);

    while (!glfwWindowShouldClose(window)) {
      glClear(GL_COLOR_BUFFER_BIT);

      glDrawArrays(GL_TRIANGLES, 0, 3);

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