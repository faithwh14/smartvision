#include "WorkerThread.h"

#include <iostream>

#ifdef __linux__
#include <pthread.h>
#endif

namespace common {

WorkerThread::WorkerThread(std::string name, ThreadFunc func)
    : m_name(name), m_func(std::move(func)) {}

WorkerThread::~WorkerThread() {
  Stop();
}

void WorkerThread::Start() {
  if (m_running) {
    return;
  }

  m_running = true;
  m_thread = std::thread([this]() {
    SetName(m_name);
    std::cout << "check here inside bool value is: " << m_running.load() << std::endl;
    m_func();
  });
}

void WorkerThread::Stop() {
  if (m_running) {
    m_running = false;
  }

  if (m_thread.joinable()) {
    m_thread.join();
  }
}

bool WorkerThread::IsRunning() const {
  return m_running;
}

void WorkerThread::SetName(const std::string& name) {
#ifdef __linux__
  pthread_setname_np(pthread_self(), name.substr(0, 15).c_str());
#else
  (void)name;
#endif
}

}  // namespace common
