// This program calculates camera intrinsic parameters.
// References:
// https://docs.opencv.org/master/d4/d94/tutorial_camera_calibration.html
// https://raw.githubusercontent.com/opencv/opencv/114848d313cfc5c5af656d5dfc90391da1a2401c/samples/cpp/tutorial_code/calib3d/camera_calibration/camera_calibration.cpp

#include <cstdio>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>

#include <opencv2/calib3d.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

int main(int argc, char *argv[]) {
  double camerap[] = {3.3258497317336787e+03,
                      0.,
                      1.5115000000000000e+03,
                      0.,
                      3.3258497317336787e+03,
                      2.0155000000000000e+03,
                      0.,
                      0.,
                      1.};
  cv::Mat cameraMatrix = cv::Mat(3, 3, CV_64F, camerap);
  double distp[] = {2.4196229931873073e-01, -1.4702994851442519e+00, 0., 0.,
                    2.8427794537368820e+00};
  cv::Mat distCoeffs = cv::Mat(5, 1, CV_64F, distp);

  std::string base_path =
      "/Users/ytra/Documents/Code/undistortion/camera_calib/"
      "docs/iPhoneX/IMG_";
  constexpr int start = 2280;
  constexpr int end = 2284;
  constexpr int n = end - start + 1;
  for (int i = 0; i < n; i++) {
    std::string im_path = base_path + std::to_string(start + i) + ".JPG";
    std::cout << im_path << std::endl;

    cv::Mat src = cv::imread(im_path);
    cv::Mat dst(src.size(), src.type());
    if (src.empty()) {
      continue;
    }
    cv::undistort(src, dst, cameraMatrix, distCoeffs);
    cv::imshow("Image View", dst);
    char key = (char)cv::waitKey(50);
    if (!dst.empty()) {
      cv::imwrite(base_path + std::to_string(start + i) + "_undistorted.jpeg",
                  dst);
    }
  }

  return 0;
}
