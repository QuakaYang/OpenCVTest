//
//  border_detection_canny.h
//  OpenCVTest
//
//  Created by 杨驭帆 on 2021/8/4.
//

#ifndef BORDERDETECTION_H
#define BORDERDETECTION_H

using namespace cv;
using namespace std;

class CannyBorderDetection {
 private:
  static void CannyThreshold(int, void*);

 public:
  int canny_process();
};

#endif /* BORDERDETECTION_H */
