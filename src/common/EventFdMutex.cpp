#include "EventFdMutex.h"

namespace common {

int CreateEvent() {
  return eventfd(0, EFD_NONBLOCK | EFD_SEMAPHORE);
}

bool SetEvent(int efd) {
  uint64_t value = 1;
  return write(efd, &value, sizeof(value)) == sizeof(value);
}

bool ResetEvent(int efd) {
  uint64_t value;
  ssize_t n = read(efd, &value, sizeof(value));
  return n == sizeof(value);
}

int WaitEvent(int efd) {
  int epfd = epoll_create1(0);

  epoll_event ev{};
  ev.events = EPOLLIN;
  ev.data.fd = efd;
  epoll_ctl(epfd, EPOLL_CTL_ADD, efd, &ev);

  epoll_event events[1];
  int nfds = epoll_wait(epfd, events, 1, -1);

  if (nfds > 0 && (events[0].events & EPOLLIN)) {
    uint64_t val;
    read(efd, &val, sizeof(val));
    return static_cast<int>(val);
  }
  return -1;
}

int WaitMultipleEvent(int efds[], int count) {
  int epfd = epoll_create1(0);

  for (int i = 0; i < count; i++) {
    epoll_event ev{};
    ev.events = EPOLLIN;
    ev.data.u32 = i;
    epoll_ctl(epfd, EPOLL_CTL_ADD, efds[i], &ev);
  }

  epoll_event events[16];
  int nfds = epoll_wait(epfd, events, 16, -1);

  for (int n = 0; n < nfds; ++n) {
    int idx = events[n].data.u32;
    uint64_t val;
    read(efds[idx], &val, sizeof(val));
    return idx + 1;
  }

  return -1;
}

int CloseEvent(int efd) {
  return close(efd);
}

}  // namespace common