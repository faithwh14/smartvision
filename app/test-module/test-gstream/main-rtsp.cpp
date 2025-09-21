#include "EventFdMutex.h"
#include "Logger.h"
#include "WorkerThread.h"
#include "gstream/rtsp/client/RtspClient.h"

using namespace common;
using namespace rv;

int main(int argc, char* argv[]) {
  Logger::Instance().SetLogLevel(INFO);

  LOG_DEBUG("TEST DEBUG");
  LOG_INFO("TEST INFO");

  RtspClient client("rtsp://user:pass@ip:port/stream");
  client.SetFrameCallback([](cv::Mat frame) {
    std::cout << "Do nothing about this frame: " << frame.rows << " x " << frame.cols << std::endl;
  });
  client.BuildPipeline();
  client.Run();

  return 0;
}
