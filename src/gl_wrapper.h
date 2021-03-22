#ifndef __GL_WRAPPER_H__
#define __GL_WRAPPER_H__

#include <string>

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

#endif // __GL_WRAPPER_H__