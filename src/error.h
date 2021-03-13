#ifndef __OPENGL_ERROR_H__
#define __OPENGL_ERROR_H__

#include <exception>
#include <string>

class GlfwError : public std::exception {
 public:
  explicit GlfwError(std::string const& msg) : msg_(msg) {}
  char const* what() const noexcept override { return msg_.c_str(); }

 private:
  std::string msg_;
};

#endif // __OPENGL_ERROR_H__