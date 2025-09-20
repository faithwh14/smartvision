#pragma once

#include <atomic>
#include <functional>
#include <string>
#include <thread>

namespace common {

class WorkerThread {
 public:
  using ThreadFunc = std::function<void()>;

  WorkerThread(std::string name, ThreadFunc func);
  ~WorkerThread();

  void Start();
  void Stop();

  bool IsRunning() const;

 private:
  void SetName(const std::string& name);

  std::string m_name;
  std::thread m_thread;
  std::atomic<bool> m_running{false};
  ThreadFunc m_func;
};

}  // namespace common
