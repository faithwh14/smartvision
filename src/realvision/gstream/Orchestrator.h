#pragma once

#include <map>
#include <memory>
#include <string>

#include "rtsp/client/RtspClient.h"

namespace rv {

class Orchestrator {
 public:
  Orchestrator();
  ~Orchestrator();

  void AddRtspClient(std::string id, std::unique_ptr<RtspClient> client);

 private:
  std::map<std::string, std::unique_ptr<RtspClient>> m_rtspClients;
};

}  // namespace rv
