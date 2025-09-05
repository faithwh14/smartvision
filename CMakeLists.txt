cmake_minimum_required(VERSION 3.16)

option(BUILD_VISION ON)
option(BUILD_COMM ON)
option(BUILD_APP ON)
option(BUILD_TEST ON)

if (BUILD_VISION)
    add_subdirectory(${CMAKE_SOURCE_DIR}/app)
endif()

if (BUILD_COMM)
    add_subdirectory(${CMAKE_SOURCE_DIR}/src/common)
endif()
