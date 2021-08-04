/* ********************************************* *
 * @Project: OpenCVTest
 * @File:    main.cpp
 *
 * @Author:  yangyufan
 * @Data:    2021/8/2.
 * ********************************************* */

#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "border_detection_canny.h"

using namespace std;
using namespace cv;

int main() {

  // Canny
  CannyBorderDetection detection;
  detection.canny_process();

  return 0;
}

