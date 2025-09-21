set(app test-rtsp)

add_executable(${app} main-rtsp.cpp)

target_include_directories(${app}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/common
        ${PROJECT_SOURCE_DIR}/src/realvision
        ${GST_INCLUDE_DIRS}
        ${GST_BASE_INCLUDE_DIRS}
        ${GST_VIDEO_INCLUDE_DIRS}
        ${GST_RTSP_SERVER_INCLUDE_DIRS}
        ${GST_APP_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(${app}
    PRIVATE
        sv_common
        rv_gstream
        ${GST_LIBRARIES}
        ${GST_BASE_LIBRARIES}
        ${GST_APP_LIBRARIES}
        ${GST_RTSP_SERVER_LIBRARIES}
        ${OpenCV_LIBS}
)
