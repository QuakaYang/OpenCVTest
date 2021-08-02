//
//  main.cpp
//  OpenCVTest
//
//  Created by 杨驭帆 on 2021/8/2.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <fstream>
using namespace std;
using namespace cv;
 
#define BYTE unsigned char
 
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

