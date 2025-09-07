#pragma once

#include <gst/app/app.h>
#include <gst/gst.h>

namespace rv {

class RtspClient {
 public:
  RtspClient();
  ~RtspClient();

  void BuildPipeline();

 private:
  GstElement* m_pipeline;
};

}  // namespace rv
