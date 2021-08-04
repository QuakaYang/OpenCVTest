/* ********************************************* *
 * @Project: OpenCVTest
 * @File:    border_detection_canny.cpp
 *
 * @Author:  yangyufan
 * @Data:    2021/8/4.
 * ********************************************* */

#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "border_detection_canny.h"

Mat src, src_gray;
Mat dst, detected_edges;
int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int rat = 3;
int kernel_size = 3;

int CannyBorderDetection::canny_process() {
  // 装载图像
  src = imread("test.png");

  // imshow("Edge Map1", src);
  if( !src.data ) {
    return -1;
  }

  // 创建与src同类型和大小的矩阵(dst)
  dst.create(src.size(), src.type());

  // 原图像转换为灰度图像
  cvtColor(src, src_gray, COLOR_BGR2GRAY);

  // 创建显示窗口
  namedWindow("Edge Map", WINDOW_AUTOSIZE);

  // 创建trackbar
  createTrackbar("Min Threshold:", "Edge Map", &lowThreshold, max_lowThreshold, CannyThreshold);

  // 显示图像
  CannyThreshold(0, 0);

  // 等待用户反应
  waitKey(0);
  return 0;
}

/**
 * @函数：CannyThreshold
 * @简介：trackbar 交互回调 - Canny阈值输入比例1:3
 */
void CannyBorderDetection::CannyThreshold(int, void*){
  // 使用 3x3内核降噪
//  blur( src_gray, detected_edges, Size(3,3) );

  // 使用高斯平滑处理
  GaussianBlur(src_gray, detected_edges, Size(7, 7), 1.0);

  // 运行Canny算子
  Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * rat, kernel_size);

  // 使用 Canny算子输出边缘作为掩码显示原图像
  dst = Scalar::all(0);

  src.copyTo( dst, detected_edges);
  imshow( "Edge Map", detected_edges );
}
