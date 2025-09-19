#pragma once

#include <iostream>
#include <map>
#include <memory>

namespace common {

enum LOG_LEVEL {
  DEBUG,
  INFO,
  WARN,
  ERROR
};

class Logger {
 public:
  static Logger& Instance();

  Logger(const Logger&) = delete;
  Logger& operator=(const Logger&) = delete;

  void SetLogLevel(LOG_LEVEL level);
  void Log(LOG_LEVEL level, const char* message);

 private:
  Logger();
  ~Logger();

  int m_rank;
  const char* m_end_color = "\033[0m";
  std::map<LOG_LEVEL, const char*> m_color_map;
  std::map<LOG_LEVEL, const char*> m_level_map;
};

#define LOG_DEBUG(msg) common::Logger::Instance().Log(common::DEBUG, msg)
#define LOG_INFO(msg) common::Logger::Instance().Log(common::INFO, msg)
#define LOG_WARN(msg) common::Logger::Instance().Log(common::WARN, msg)
#define LOG_ERROR(msg) common::Logger::Instance().Log(common::ERROR, msg)

}  // namespace common
