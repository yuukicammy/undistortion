cmake_minimum_required(VERSION 3.1)
project(demo VERSION 0.1.0 DESCRIPTION "caliculate camera intlinsic parameters." LANGUAGES CXX)


find_package(OpenCV REQUIRED)
add_executable(demo ./main.cpp)

target_include_directories (demo PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries (demo ${OpenCV_LIBS})

include(CTest)
enable_testing()

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CAMERA_CALIB_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(CMAKE_CXX_STANDARD 17)