#if 0

#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

int main(void) {

	using namespace cv;
	using namespace std;

	Mat src;
	src = imread("lena.jpg", IMREAD_GRAYSCALE);

	Mat neg_img(src.rows, src.cols, src.type());  //neg_img��°� �ϳ� ����

	TickMeter tm;

	tm.start();                                                   //start���� stop���� �ҷ����µ� �ɸ��� �ð��� tm�� ����.
	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			neg_img.at<uchar>(i, j) = src.at<uchar>(i, j);
		}
	}
	tm.stop();
	printf("\n\nprocessing time (for-loop-copy): %f us\n\n", tm.getTimeMicro());  //getTimeMicro : MicroSecond ������ �ð��� �����Ͷ�.
	//double�̳� float ������ %f �� ����.

	tm.reset();  //Ÿ�̸� ����

	tm.start();   //Ÿ�̸� �ٽ� ����
	neg_img = src.clone();   //Deep copy
	tm.stop();     //Ÿ�̸� ��
	//����~�� �ð� ����

	printf("\n\nprocessing time (clone()): %f us\n\n", tm.getTimeMicro());

	tm.reset();
	tm.start();
	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			neg_img.at<uchar>(i, j) = 255 - src.at<uchar>(i, j);
		}
	}

	tm.stop();
	printf("\n\nprocessing time (inverse): %f us\n\n", tm.getTimeMicro());

	imshow("src", src);
	imshow("neg_img", neg_img);

	waitKey(0);
	return 0;
}

#endif