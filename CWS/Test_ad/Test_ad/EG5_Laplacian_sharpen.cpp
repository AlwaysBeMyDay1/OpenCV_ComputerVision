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
						 0.0, 1.0, 0.0 };   //�� ���ϸ� 0 =>���͸� ��� ��ο���

	float data2_3x3[] = { 0.0, -1.0, 0.0,
						 -1.0, 4.0, -1.0,
						 0.0, -1.0, 0.0 };  //�� ��ġ�� 0 => ���͸� ��� ��ξ���

	Mat laplacian1_3x3(3, 3, CV_32FC1, data1_3x3);
	filter2D(src, src_laplacian1, -1, laplacian1_3x3, Point(-1, -1), 0);

	Mat laplacian2_3x3(3, 3, CV_32FC1, data2_3x3);
	filter2D(src, src_laplacian2, -1, laplacian2_3x3, Point(-1, -1), 0);

	dst = src - src_laplacian1; //�����̹���(src)�� ���͸��� ���� ����
	dst2 = src + src_laplacian2;  //�����̹���(src)�� ���͸��� ���� ���Ѱ�

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