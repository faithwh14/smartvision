#pragma once

#include <functional>
#include <opencv2/opencv.hpp>
#include <thread>

#include "EventFdMutex.h"
#include "Logger.h"
#include "WorkerThread.h"

using namespace common;

namespace rv {

class BatchManager {
 public:
  using BatchCB = std::function<void(std::vector<cv::Mat>)>;

  BatchManager(int batch_size);
  ~BatchManager();

  void Init();
  void Start();
  void Stop();

  int BatchSize() const;

  void PushFrame(std::string id, cv::Mat frame);

  void SetCallback(BatchCB cb);

 private:
  void TryInferCallback();
  void WorkerLoop();

  int m_batch_size;
  std::thread m_thread;

  std::vector<cv::Mat> m_batchFrames;
  BatchCB m_cb;
  std::mutex m_mtx;

  int m_fd;
};

}  // namespace rv
