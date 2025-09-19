cmake_minimum_required(VERSION 3.16)

project(smartvision LANGUAGES C CXX)

# check if it is wrong
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Threads REQUIRED)
find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core Quick QuickControls2 Gui Widgets Multimedia)
find_package(PkgConfig REQUIRED)

pkg_check_modules(GST REQUIRED gstreamer-1.0>=1.14)
pkg_check_modules(GST_BASE REQUIRED gstreamer-base-1.0)
pkg_check_modules(GST_APP REQUIRED gstreamer-app-1.0)
pkg_check_modules(GST_RTSP_SERVER REQUIRED gstreamer-rtsp-server-1.0)

option(BUILD_VISION "Build vision" ON)
option(BUILD_COMM "Build common" ON)
option(BUILD_APP "Build app" ON)
option(BUILD_TEST "Build test" ON)

if (BUILD_VISION)
    add_subdirectory(${CMAKE_SOURCE_DIR}/src/realvision)
endif()

if (BUILD_COMM)
    add_subdirectory(${CMAKE_SOURCE_DIR}/src/common)
endif()

if (BUILD_APP)
    add_subdirectory(${CMAKE_SOURCE_DIR}/app)
endif()
