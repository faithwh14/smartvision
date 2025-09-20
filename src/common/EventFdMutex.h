#pragma once

#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <unistd.h>

namespace common {

int CreateEvent();

bool SetEvent(int efd);

bool ResetEvent(int efd);

int WaitEvent(int efd);

int WaitMultipleEvent(int efds[], int count);

int CloseEvent(int efd);

}  // namespace common
