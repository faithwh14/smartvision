set(app test-efd)

add_executable(${app} main-efd.cpp)

target_include_directories(${app}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/common
)

target_link_libraries(${app}
    PRIVATE
        sv_common
)