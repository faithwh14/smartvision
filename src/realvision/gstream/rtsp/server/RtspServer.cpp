#include "RtspServer.h"

namespace rv {

RtspServer::RtspServer(const RtspConfig& config) : m_config(config) {
  m_server = gst_rtsp_server_new();
  m_mount = gst_rtsp_server_get_mount_points(m_server);
  m_factory = gst_rtsp_media_factory_new();
}

RtspServer::~RtspServer() {}

void RtspServer::Init() {
  gst_rtsp_mount_points_add_factory(m_mount, m_config.URi, m_factory);

  // Unref mount piont here?

  gst_rtsp_server_attach(m_server, nullptr);
}

}  // namespace rv
