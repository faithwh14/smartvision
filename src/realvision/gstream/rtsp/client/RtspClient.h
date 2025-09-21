#pragma once

#include <gst/app/app.h>
#include <gst/app/gstappsink.h>
#include <gst/gst.h>

#include <opencv2/opencv.hpp>

namespace rv {

class RtspClient {
 public:
  explicit RtspClient(const std::string& uri);
  ~RtspClient();

  void BuildPipeline();
  void Run();

 private:
  GstElement* m_pipeline = nullptr;
  std::string m_uri;

  static GstFlowReturn on_new_sample(GstAppSink* sink, gpointer user_data);
};

}  // namespace rv
