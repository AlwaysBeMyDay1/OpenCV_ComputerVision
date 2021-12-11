#if 0

#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

int main(void) {

	using namespace cv;
	using namespace std;

	Mat src1, src2, dst1, dst2, dst3;
	src1 = imread("surveillance_road.jpg", IMREAD_GRAYSCALE);
	src2 = imread("surveillance_car.jpg", IMREAD_GRAYSCALE);

	imshow("src1", src1);
	imshow("src2", src2);

	subtract(src1, src2, dst1);   //src1 - src2 를 dst1에 넣어라    
	imshow("subtract", dst1);

	dst2 = Mat(src1.rows, src1.cols, src1.type());

	for (int i = 0; i < src1.rows; i++) {
		for (int j = 0; j < src1.cols; j++) {
			dst2.at<uchar>(i, j) = saturate_cast<uchar>(src1.at<uchar>(i, j) - src2.at<uchar>(i, j));
		}
	}

	imshow("manually", dst2);

	absdiff(src1, src2, dst3);
	imshow("dst3", dst3);

	waitKey(0);
	return 0;
}

#endif