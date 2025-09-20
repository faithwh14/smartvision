set(app test-thread)

add_executable(${app} main-thread.cpp)

target_include_directories(${app}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/common    
)

target_link_libraries(${app}
    PRIVATE
        sv_common
)
