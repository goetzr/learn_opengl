#ifndef __GL_WRAPPER_H__
#define __GL_WRAPPER_H__

#include <string>

#include <signal.h>

#include <GL/glew.h>

enum class ShaderType {
  kVertex = GL_VERTEX_SHADER,
  kFragment = GL_FRAGMENT_SHADER
};

inline char const* ToString(ShaderType type) {
  switch (type) {
    case ShaderType::kVertex:
      return "vertex";
    case ShaderType::kFragment:
      return "fragment";
    default:
      return "unknown";
  };
}

unsigned CompileShader(ShaderType type, std::string const& source);
unsigned CreateShader(std::string const& vertexShader, std::string const& fragmentShader);

struct ShaderProgramSource {
  std::string vertexSource;
  std::string fragmentSource;
};
ShaderProgramSource ParseShader(std::string const& path);

#define ASSERT(x) if (!(x)) raise(SIGTRAP);
#define GLCall(x) ClearGlErrors();\
  x;\
  ASSERT(LogGlCall(#x, __FILE__, __LINE__))

void ClearGlErrors();
bool LogGlCall(char const* function, char const* file, int line);

#endif // __GL_WRAPPER_H__