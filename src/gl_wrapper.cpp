#include "gl_wrapper.h"

#include <fstream>
#include <sstream>
#include <string>

#include <fmt/format.h>
#include <GL/glew.h>

#include "error.h"

using namespace std;

unsigned CompileShader(ShaderType type, std::string const& source) {
  unsigned shader = glCreateShader((int)type);
  auto src = source.c_str();
  glShaderSource(shader, 1, &src, nullptr);
  glCompileShader(shader);

  int result;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
  if (result == GL_FALSE) {
    int length;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
    char* msg = static_cast<char*>(alloca(length));
    glGetShaderInfoLog(shader, length, &length, msg);
    glDeleteShader(shader);
    throw GlError(fmt::format("Failed to compile the {} shader: {}.", ToString(type), msg));
  }

  return shader;
}

unsigned CreateShader(std::string const& vertexShader, std::string const& fragmentShader) {
  unsigned program = glCreateProgram();
  unsigned vs = CompileShader(ShaderType::kVertex, vertexShader);
  unsigned fs = CompileShader(ShaderType::kFragment, fragmentShader);

  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);
  glValidateProgram(program);

  glDeleteShader(vs);
  glDeleteShader(fs);

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