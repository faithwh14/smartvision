#include <iostream>

#include "Logger.h"

using namespace common;

int main() {
  std::cout << "Hello World" << std::endl;

  Logger::Instance().SetLogLevel(DEBUG);

  LOG_DEBUG("CHECKING DEBUG HERE");
  LOG_INFO("CHECKING INFO HERE");
  LOG_WARN("CHECKING WARN HERE");
  LOG_ERROR("CHECKING ERROR HERE");

  return 0;
}
