#include "RtspClient.h"

namespace rv {

RtspClient::RtspClient() {
  m_pipeline = gst_element_factory_make("pipeline", "pipeline");
}

RtspClient::~RtspClient() {}

void RtspClient::BuildPipeline() {
  GstElement* src = gst_element_factory_make("rtph264src", "src");
  //   g_object_set(src, "argument1", "value1");

  GstElement* convert = gst_element_factory_make("videoconvert", "convert");
  GstElement* scale = gst_element_factory_make("videoscale", "scale");
  GstElement* appsink = gst_element_factory_make("appsink", "appsink");

  gst_bin_add_many(GST_BIN(m_pipeline), src, convert, scale, appsink);
}

}  // namespace rv
