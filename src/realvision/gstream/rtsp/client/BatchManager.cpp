#include "BatchManager.h"

namespace rv {

BatchManager::BatchManager(int batch_size) : m_batch_size(batch_size) {}

BatchManager::~BatchManager() {}

void BatchManager::Init() {
  m_fd = CreateEvent();
}

void BatchManager::Start() {
  m_thread = std::thread(&BatchManager::WorkerLoop, this);
}

void BatchManager::Stop() {}

int BatchManager::BatchSize() const {
  return m_batch_size;
}

void BatchManager::PushFrame(std::string id, cv::Mat frame) {
  m_batchFrames.push_back(frame.clone());
  (void)SetEvent(m_fd);
}

void BatchManager::SetCallback(BatchCB cb) {
  std::lock_guard<std::mutex> lk(m_mtx);
  m_cb = cb;
}

void BatchManager::TryInferCallback() {
  std::vector<cv::Mat> frames;
  std::lock_guard<std::mutex> lk(m_mtx);

  frames.swap(m_batchFrames);
  if (m_cb) {
    m_cb(frames);
  }
}

void BatchManager::WorkerLoop() {
  while (true) {
    if (WaitEvent(m_fd)) {
      TryInferCallback();
      ResetEvent(m_fd);
    }
  }
}

}  // namespace rv