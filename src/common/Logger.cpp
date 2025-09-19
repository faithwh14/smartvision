#include "Logger.h"

namespace common {

Logger::Logger() {
  m_color_map = {{DEBUG, "\033[36m"}, {INFO, "\033[32m"}, {WARN, "\033[33m"}, {ERROR, "\033[31m"}};

  m_level_map = {
      {DEBUG, "[DEBUG]:  "}, {INFO, "[INFO]:  "}, {WARN, "[WARN]:  "}, {ERROR, "[ERROR]:  "}};

  m_rank = DEBUG;  // default = debug
}

Logger::~Logger() = default;

Logger& Logger::Instance() {
  static Logger instance;
  return instance;
}

void Logger::SetLogLevel(LOG_LEVEL level) {
  m_rank = static_cast<int>(level);
}

void Logger::Log(LOG_LEVEL level, const char* message) {
  if (static_cast<int>(level) < m_rank) {
    return;
  }
  std::cout << m_color_map[level] << m_level_map[level] << m_end_color << message << std::endl;
}

}  // namespace common
