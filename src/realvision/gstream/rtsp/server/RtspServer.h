#pragma once

#include <gst/rtsp-server/rtsp-server.h>

#include <string>

namespace rv {

struct RtspConfig {
  const char* URi;
};

class RtspServer {
 public:
  RtspServer(const RtspConfig& config);
  ~RtspServer();

  void Init();

 private:
  GstRTSPServer* m_server;
  GstRTSPMediaFactory* m_factory;
  GstRTSPMountPoints* m_mount;

  const RtspConfig& m_config;
};

}  // namespace rv