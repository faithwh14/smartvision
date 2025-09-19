set(APP_TEST_COMMON test-log)

add_executable(${APP_TEST_COMMON} test-log-main.cpp)

target_include_directories(${APP_TEST_COMMON}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/common
)

target_link_libraries(${APP_TEST_COMMON}
    PRIVATE
        sv_common
)
