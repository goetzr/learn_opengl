#include "gl_wrapper.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <fmt/format.h>
#include <GL/glew.h>

#include "error.h"

using namespace std;

unsigned CompileShader(ShaderType type, std::string const& source) {
  unsigned shader = glCreateShader((int)type);
  auto src = source.c_str();
  GLCall(glShaderSource(shader, 1, &src, nullptr));
  GLCall(glCompileShader(shader));

  int result;
  GLCall(glGetShaderiv(shader, GL_COMPILE_STATUS, &result));
  if (result == GL_FALSE) {
    int length;
    GLCall(glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length));
    char* msg = static_cast<char*>(alloca(length));
    GLCall(glGetShaderInfoLog(shader, length, &length, msg));
    GLCall(glDeleteShader(shader));
    throw GlError(fmt::format("Failed to compile the {} shader: {}.", ToString(type), msg));
  }

  return shader;
}

unsigned CreateShader(std::string const& vertexShader, std::string const& fragmentShader) {
  unsigned program = glCreateProgram();
  unsigned vs = CompileShader(ShaderType::kVertex, vertexShader);
  unsigned fs = CompileShader(ShaderType::kFragment, fragmentShader);

  GLCall(glAttachShader(program, vs));
  GLCall(glAttachShader(program, fs));
  GLCall(glLinkProgram(program));
  GLCall(glValidateProgram(program));

  GLCall(glDeleteShader(vs));
  GLCall(glDeleteShader(fs));

  return program;
}

ShaderProgramSource ParseShader(std::string const& file_path) {
  ifstream stream(file_path);

  enum class ShaderType {
    NONE = -1, VERTEX = 0, FRAGMENT = 1
  };

  string line;
  stringstream ss[2];
  ShaderType type = ShaderType::NONE;
  while (getline(stream, line)) {
    if (line.find("#shader") != string::npos) {
      if (line.find("vertex") != string::npos) {
        type = ShaderType::VERTEX;
      } else if (line.find("fragment") != string::npos) {
        type = ShaderType::FRAGMENT;
      }
    } else {
      ss[static_cast<size_t>(type)] << line << '\n';
    }
  }

  return { ss[0].str(), ss[1].str() };
}

void ClearGlErrors() {
  while (glGetError() != GL_NO_ERROR);
}

bool LogGlCall(char const* function, char const* file, int line) {
  for (auto err = glGetError(); err != GL_NO_ERROR; err = glGetError()) {
    cerr << "[OpenGL Error] (" << err << "): " << function << ' ' << file << ':' << line << endl;
    return false;
  }
  return true;
}