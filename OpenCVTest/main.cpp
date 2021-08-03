/* ********************************************* *
 * @Project: OpenCVTest
 * @File:    main.cpp
 *
 * @Author:  yangyufan
 * @Data:    2021/8/2.
 * ********************************************* */

#include <iostream>
#include <vector>

#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>

constexpr auto path0 = "match1.jpeg";
constexpr auto path1 = "match2.jpeg";

using namespace cv;

int main() {
  Mat image0 = imread(path0, 1);
  Mat image1 = imread(path1, 1);

  // imshow("image0", image0);
  // imshow("image1", image1);

  /*
  step1:特征检测器
  */

  // SURF can not use
  // Ptr<xfeatures2d::SURF> detector;
  // detector = xfeatures2d::SURF::create(800); // 800为海塞矩阵阈值，越大越精准

  // SIFT
  // Ptr<xfeatures2d::SIFT> detector;
  // detector = xfeatures2d::SIFT::create(800); // 800为保留的点数

  // ORB
  Ptr<ORB> detector;
  detector = ORB::create(1200); // 保留点数

  // STAR
  // Ptr<xfeatures2d::StarDetector> detector;
  // detector = xfeatures2d::StarDetector::create();

  // MSD
  // Ptr<xfeatures2d::MSDDetector> detector;
  // detector = xfeatures2d::MSDDetector::create();

  std::vector <KeyPoint> key0;
  std::vector <KeyPoint> key1;

  detector->detect(image0, key0, noArray());
  detector->detect(image1, key1, noArray());

  /*
  step2:描述子提取器
  常见的提取器：SURF，SIFT，LUCID，BriefDescriptorExtractor，VGG，BoostDesc
  */
  Ptr<xfeatures2d::BriefDescriptorExtractor> Extractor;
  // 参数表示字节数, 采用长度为64×8=512的向量表示
  Extractor = xfeatures2d::BriefDescriptorExtractor::create(64, true);

  // Ptr<xfeatures2d::SURF> Extractor;
  // Extractor = xfeatures2d::SURF::create();

  Mat descriptor0, descriptor1;
  Extractor->compute(image0, key0, descriptor0);
  Extractor->compute(image1, key1, descriptor1);

  /*
  step3:匹配器
  */
  BFMatcher matcher(NORM_HAMMING); // 匹配器 汉明距离匹配特征点
  std::vector<DMatch> matches; // 存放匹配结果
  std::vector<DMatch> good_matches; // 存放好的匹配结果

  matcher.match(descriptor0, descriptor1, matches);

  // 筛选匹配点，根据match里面特征对的距离从小到大排序
  std::sort(matches.begin(), matches.end());

  int ptsPairs = std::min(200, (int)(matches.size()));
  std::cout << "匹配点数为" << ptsPairs << std::endl;
  for (int i = 0; i < ptsPairs; i++) {
    // 距离最小的50个压入新的DMatch
    good_matches.push_back(matches[i]);
  }

  Mat result;
  drawMatches(image0, key0, image1, key1,
              good_matches, result, Scalar::all(-1),
              Scalar::all(-1), std::vector<char>(),
              DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS); //绘制匹配点
  imshow("result", result);
  waitKey(0);
}
