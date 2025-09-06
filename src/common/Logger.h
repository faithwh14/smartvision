#pragma once

#include <iostream>
#include <sstream>
#include <thread>

namespace common {

class Logger {
public:
  Logger();
  ~Logger();

  const Logger(Logger &) = delete;
};

} // namespace common
