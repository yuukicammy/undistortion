project(interactive_calibration VERSION 0.1.0 DESCRIPTION "caliculate camera intlinsic parameters." LANGUAGES CXX)

find_package(OpenCV COMPONENTS core imgproc highgui calib3d REQUIRED)

file(GLOB source_files
            "*.hpp"
            "*.cpp"
    )
add_executable(interactive_calibration ${source_files})

target_include_directories(interactive_calibration PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(interactive_calibration ${OpenCV_LIBS} opencv_aruco)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CAMERA_CALIB_INCLUDE_DIR ${PROJECT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 17)

