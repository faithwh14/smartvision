set(DETECT_MODULE rv_detection)

set(DETECT_SRC
)

add_library(${DETECT_MODULE}
    STATIC
        ${DETECT_SRC}    
)

target_include_directories(${DETECT_MODULE}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/common
        ${PROJECT_SOURCE_DIR}/src/realvision
)

target_link_libraries(${DETECT_MODULE}
    PRIVATE
        ${ONNXRUNTIME_LIBS}
        ${OpenCV_LIBS}
)
