cmake_minimum_required(VERSION 3.1)
project(camera_calib VERSION 0.1.0 DESCRIPTION "caliculate camera intlinsic parameters." LANGUAGES CXX)


find_package(OpenCV REQUIRED)
add_executable(camera_calib ./src/main.cpp)

target_include_directories (camera_calib PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries (camera_calib ${OpenCV_LIBS})

include(CTest)
enable_testing()

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CAMERA_CALIB_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(CMAKE_CXX_STANDARD 17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
