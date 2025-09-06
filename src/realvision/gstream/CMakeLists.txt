set(GSTREAM_MODULE rv_gstream)

set(GSTREAM_SRC
)

set(GSTREAM_RTSP_CLIENT_SRC
)

set(GSTREAM_RTSP_SERVER_SRC
)

add_library(${GSTREAM_MODULE}
    STATIC
        ${GSTREAM_SRC}
        ${GRPC_CLIENT_SRC}
        ${GRPC_SERVER_SRC}
)

target_include_directories(${GSTREAM_MODULE}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/common
        ${PROJECT_SOURCE_DIR}/src/realvision
)

target_link_libraries(${GSTREAM_MODULE}
    PRIVATE
        ${GST_LDFLAGS_OTHER}
        ${GST_BASE_LDFLAGS_OTHER}
        ${GST_VIDEO_LDFLAGS_OTHER}
        ${GST_APP_LDFLAGS_OTHER}
        ${GST_RTSP_SERVER_LDFLAGS_OTHER}
)
