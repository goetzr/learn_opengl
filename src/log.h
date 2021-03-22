#ifndef __OPENGL_LOG_H__
#define __OPENGL_LOG_H__

#include <utility>

#include <fmt/format.h>

enum class LogLevel : unsigned char { kInfo, kError };

template<LogLevel>
struct LogLevelToString;

template<LogLevel level>
constexpr char const* LogLevelToString_v = LogLevelToString<level>::value;

template<>
struct LogLevelToString<LogLevel::kInfo> {
  static constexpr char const* value = "INFO";
};

template<>
struct LogLevelToString<LogLevel::kError> {
  static constexpr char const* value = "ERROR";
};

template<LogLevel level>
void log(char const* msg) {
  if constexpr (level == LogLevel::kError)
    fmt::print(stderr, "{}: {}\n", LogLevelToString_v<level>, msg);
  else
    fmt::print("{}: {}\n", LogLevelToString_v<level>, msg);
}

template<LogLevel level, typename... Ts>
void log(char const* fmt, Ts&&... args) {
  auto msg = fmt::format(fmt, std::forward<Ts>(args)...);
  if constexpr (level == LogLevel::kError)
    fmt::print(stderr, "{}: {}\n", LogLevelToString_v<level>, msg.c_str());
  else
    fmt::print("{}: {}\n", LogLevelToString_v<level>, msg.c_str());
}

inline void info(char const* msg) {
  log<LogLevel::kInfo>(msg);
}

template<typename T, typename... Ts>
inline void info(char const* fmt, T&& first, Ts&&... rest) {
  log<LogLevel::kInfo>(fmt, std::forward<T>(first), std::forward<Ts>(rest)...);
}

inline void error(char const* msg) {
  log<LogLevel::kError>(msg);
}

template<typename T, typename... Ts>
inline void error(char const* fmt, T&& first, Ts&&... rest) {
  log<LogLevel::kError>(fmt, std::forward<T>(first), std::forward<Ts>(rest)...);
}

#endif // __OPENGL_LOG_H__