set(APP_NAME app-gui)

add_executable(${APP_NAME} main.cpp)

target_include_directories(${APP_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/common
        ${PROJECT_SOURCE_DIR}/src/realvision
)

target_link_directories(${APP_NAME}
    PRIVATE
)
