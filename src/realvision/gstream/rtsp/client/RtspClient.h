#pragma once

#include <gst/app/app.h>
#include <gst/app/gstappsink.h>
#include <gst/gst.h>

#include <functional>
#include <opencv2/opencv.hpp>

namespace rv {

class RtspClient {
 public:
  using FrameCB = std::function<void(cv::Mat)>;

  explicit RtspClient(const std::string& uri);
  ~RtspClient();

  void BuildPipeline();
  void Run();

  void SetFrameCallback(FrameCB frame_cb);

 private:
  GstElement* m_pipeline = nullptr;
  std::string m_uri;
  FrameCB m_frame_cb;

  static GstFlowReturn on_new_sample(GstAppSink* sink, gpointer user_data);
};

}  // namespace rv
