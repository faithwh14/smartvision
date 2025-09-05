cmake_minimum_required(VERSION 3.16)

# check if it is wrong
CXX_STANDARD_REQUIRED(2.0)
C_STANDARD_REQUIRED(1.16)

find_package(OpenCV REQUIRED)
find_package(gRPC REQUIRED)
find_package(Eigen REQURIED)

add_proto_config(gstreamer)

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
