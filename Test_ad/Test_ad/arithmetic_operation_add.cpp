#if 0

#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(void) {

	using namespace cv;
	using namespace std;

	Mat src1, src2, dst;
	src1 = imread("airplane.bmp", IMREAD_GRAYSCALE);
	src2 = imread("field.bmp", IMREAD_GRAYSCALE);

	imshow("src1", src1);
	imshow("src2", src2);

	dst = src2 + src1;

	
	for (int i = 0; i < src1.rows; i++) {
	   for (int j = 0; j < src1.cols; j++) {
		 dst.at<uchar>(i,j) = saturate_cast<uchar>(0.5*src1.at<uchar>(i,j) + 0.5*src2.at<uchar>(i,j));
	   }
	 }
	 

	 //add(src1, src2, dst);

	imshow("src1+src2", dst);

	waitKey(0);
	return 0;
}
#endif