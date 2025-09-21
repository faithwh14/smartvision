#include "RtspClient.h"

#include <iostream>

namespace rv {

RtspClient::RtspClient(const std::string& uri) : m_uri(uri) {
  gst_init(nullptr, nullptr);
}

RtspClient::~RtspClient() {
  std::cout << "This is rtsp client destructor" << std::endl;
}

void RtspClient::BuildPipeline() {
  m_pipeline = GST_ELEMENT(gst_pipeline_new("rtsp-pipeline"));

  GstElement* src = gst_element_factory_make("rtspsrc", "src");
  GstElement* depay = gst_element_factory_make("rtph264depay", "depay");
  GstElement* parse = gst_element_factory_make("h264parse", "parse");
  GstElement* decode = gst_element_factory_make("avdec_h264", "decode");
  GstElement* convert = gst_element_factory_make("videoconvert", "convert");
  GstElement* sink = gst_element_factory_make("appsink", "appsink");

  if (!m_pipeline || !src || !depay || !parse || !decode || !convert || !sink) {
    g_printerr("Failed to create elements\n");
    return;
  }

  g_object_set(src, "location", m_uri.c_str(), nullptr);

  g_object_set(sink, "emit-signals", TRUE, "sync", FALSE, nullptr);

  g_signal_connect(sink, "new-sample", G_CALLBACK(RtspClient::on_new_sample), this);

  gst_bin_add_many(GST_BIN(m_pipeline), src, depay, parse, decode, convert, sink, nullptr);

  if (!gst_element_link_many(depay, parse, decode, convert, sink, nullptr)) {
    g_printerr("Failed to link static elements\n");
    return;
  }
  g_signal_connect(src, "pad-added",
                   G_CALLBACK(+[](GstElement* src, GstPad* pad, gpointer user_data) {
                     GstElement* depay = static_cast<GstElement*>(user_data);
                     GstPad* sinkpad = gst_element_get_static_pad(depay, "sink");
                     if (!gst_pad_is_linked(sinkpad)) {
                       if (gst_pad_link(pad, sinkpad) != GST_PAD_LINK_OK) {
                         g_printerr("Failed to link rtspsrc → depay\n");
                       }
                     }
                     gst_object_unref(sinkpad);
                   }),
                   depay);
}

void RtspClient::Run() {
  if (!m_pipeline) {
    return;
  }

  gst_element_set_state(m_pipeline, GST_STATE_PLAYING);

  GstBus* bus = gst_element_get_bus(m_pipeline);
  gst_bus_poll(bus, (GstMessageType)(GST_MESSAGE_ERROR | GST_MESSAGE_EOS), -1);

  gst_object_unref(bus);

  gst_element_set_state(m_pipeline, GST_STATE_NULL);
}

void RtspClient::SetFrameCallback(FrameCB frame_cb) {
  m_frame_cb = frame_cb;
}

GstFlowReturn RtspClient::on_new_sample(GstAppSink* sink, gpointer user_data) {
  auto* self = static_cast<RtspClient*>(user_data);

  GstSample* sample = gst_app_sink_pull_sample(sink);
  if (!sample) {
    return GST_FLOW_ERROR;
  }

  if (!self) {
    gst_sample_unref(sample);
    return GST_FLOW_ERROR;
  }

  GstBuffer* buffer = gst_sample_get_buffer(sample);
  GstCaps* caps = gst_sample_get_caps(sample);
  GstStructure* s = gst_caps_get_structure(caps, 0);

  int width, height;
  gst_structure_get_int(s, "width", &width);
  gst_structure_get_int(s, "height", &height);

  GstMapInfo map;
  if (gst_buffer_map(buffer, &map, GST_MAP_READ)) {
    cv::Mat frame(height, width, CV_8UC3, (char*)map.data);
    // cv::imshow("RTSP Frame", frame);
    // cv::waitKey(1);

    if (self->m_frame_cb) {
      self->m_frame_cb(frame.clone());
    }
    gst_buffer_unmap(buffer, &map);
  }

  gst_sample_unref(sample);
  return GST_FLOW_OK;
}

}  // namespace rv
