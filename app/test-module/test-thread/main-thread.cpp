#include <chrono>

#include "EventFdMutex.h"
#include "Logger.h"
#include "WorkerThread.h"

using namespace common;

int main() {
  Logger::Instance().SetLogLevel(INFO);

  LOG_DEBUG("GGWP THIS IS DEBUG");
  LOG_INFO("GGWP THIS IS INFO");

  int x = 33;
  int y = 234;

  WorkerThread thread("haha", [&] {
    std::cout << "check here outside bool value is nothing" << std::endl;
    std::cout << "outside variable x + y = " << (x + y) << std::endl;
  });
  thread.Start();

  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  return 0;
}
