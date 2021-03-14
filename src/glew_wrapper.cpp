#include "glew_wrapper.h"

#include <fmt/format.h>
#include <GL/glew.h>

#include "error.h"

void InitGlew() {
  auto code = glewInit();
  if (code != GLEW_OK)
    throw GlewError(fmt::format("Failed to initialize GLEW: {}. Error code = {}.", glewGetErrorString(code), code));
}