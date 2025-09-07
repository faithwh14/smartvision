set(GSTREAM_MODULE rv_gstream)

set(GSTREAM_SRC
    Orchestrator.h
    Orchestrator.cpp
)

set(GSTREAM_RTSP_CLIENT_SRC
    rtsp/client/RtspClient.h
    rtsp/client/RtspClient.cpp
)

set(GSTREAM_RTSP_SERVER_SRC
    rtsp/server/RtspServer.h
    rtsp/server/RtspServer.cpp
)

add_library(${GSTREAM_MODULE}
    STATIC
        ${GSTREAM_SRC}
        ${GSTREAM_RTSP_CLIENT_SRC}
        ${GSTREAM_RTSP_SERVER_SRC}
)

target_include_directories(${GSTREAM_MODULE}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/common
        ${PROJECT_SOURCE_DIR}/src/realvision
        ${GST_INCLUDE_DIRS}
        ${GST_BASE_INCLUDE_DIRS}
        ${GST_VIDEO_INCLUDE_DIRS}
        ${GST_APP_INCLUDE_DIRS}
        ${GST_RTSP_SERVER_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(${GSTREAM_MODULE}
    PRIVATE
        ${GST_LIBRARIES}
        ${GST_BASE_LIBRARIES}
        ${GST_VIDEO_LIBRARIES}
        ${GST_RTSP_SERVER_LIBRARIES}
        ${GST_APP_LIBRARIES}
        ${OpenCV_LIBS}
)
