#if 0

#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <iostream>

int main(void) {

	using namespace cv;
	using namespace std;

	Mat src, src_laplacian1, src_laplacian2, dst, dst2;

	src = imread("moon.jpg", IMREAD_GRAYSCALE);

	float data1_3x3[] = { 0.0, 1.0, 0.0,
						 1.0, -4.0, -1.0,
						 0.0, 1.0, 0.0 };   //다 합하면 0 =>필터링 결과 어두워짐

	float data2_3x3[] = { 0.0, -1.0, 0.0,
						 -1.0, 4.0, -1.0,
						 0.0, -1.0, 0.0 };  //다 합치면 0 => 필터링 결과 어두어짐

	Mat laplacian1_3x3(3, 3, CV_32FC1, data1_3x3);
	filter2D(src, src_laplacian1, -1, laplacian1_3x3, Point(-1, -1), 0);

	Mat laplacian2_3x3(3, 3, CV_32FC1, data2_3x3);
	filter2D(src, src_laplacian2, -1, laplacian2_3x3, Point(-1, -1), 0);

	dst = src - src_laplacian1; //원본이미지(src)에 필터링한 것을 뺀거
	dst2 = src + src_laplacian2;  //원본이미지(src)에 핕터링한 것을 더한거

	imshow("src", src);
	imshow("src_laplacian", src_laplacian1);
	imshow("src_laplacian2", src_laplacian2);

	imshow("dst", dst);
	imshow("dst2", dst2);

	waitKey(0);
	destroyAllWindows();

	return 0;
}

#endif