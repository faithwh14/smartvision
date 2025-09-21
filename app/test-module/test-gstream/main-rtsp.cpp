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
  client.BuildPipeline();
  client.Run();

  return 0;
}
