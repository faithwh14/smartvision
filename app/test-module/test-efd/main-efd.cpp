#include <EventFdMutex.h>
#include <Logger.h>

#include <iostream>
#include <string>

using namespace common;

int main() {
  Logger::Instance().SetLogLevel(DEBUG);
  LOG_DEBUG("Check one two three");

  int efd = CreateEvent();
  int efd1 = CreateEvent();

  if (!SetEvent(efd)) {
    LOG_ERROR("Failed to set event");
  } else {
    LOG_INFO("Successfully set event");
  }

  if (!ResetEvent(efd)) {
    LOG_ERROR("Failed to reset event");
  } else {
    LOG_INFO("Successfully reset event");
  }

  LOG_DEBUG("TRY SET EVENT AGAIN");

  if (!SetEvent(efd)) {
    LOG_ERROR("Failed to set event");
  } else {
    LOG_INFO("Successfully set event");
  }

  int ret = WaitEvent(efd);

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  if (!SetEvent(efd)) {
    LOG_ERROR("Failed to set event0");
  } else {
    LOG_INFO("Successfully set event0");
  }
  if (!SetEvent(efd1)) {
    LOG_ERROR("Failed to set event1");
  } else {
    LOG_INFO("Successfully set event1");
  }

  int fds[2] = {efd, efd1};
  int ret1 = WaitMultipleEvent(fds, 2);
  if (ret1 != -1) {
    // LOG_WARN("Successfully wait multiple event: " + std::to_string(ret));
    std::cout << "check ret value is: " << ret1 << std::endl;
  } else {
    LOG_ERROR("Failed to wait multiple event");
  }
  int ret2 = WaitMultipleEvent(fds, 2);
  if (ret2 != -1) {
    // LOG_WARN("Successfully wait multiple event: " + std::to_string(ret));
    std::cout << "check ret1 value is: " << ret2 << std::endl;
  } else {
    LOG_ERROR("Failed to wait multiple event");
  }

  CloseEvent(efd);
  CloseEvent(efd1);

  std::cout << "End Here" << std::endl;

  return 0;
}
