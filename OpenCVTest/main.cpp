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

#define BYTE unsigned char

using namespace std;
using namespace cv;

int main() {
  Mat image = imread("test.png");

  //create a window to display the image
  namedWindow("img");

  //show the image in the window
  imshow("img", image);

  //wait for the user to hit a key
  waitKey(0);
  return 0;
}

