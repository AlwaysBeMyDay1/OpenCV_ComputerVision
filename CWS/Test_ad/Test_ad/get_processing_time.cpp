#if 0

#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

int main(void) {

	using namespace cv;
	using namespace std;

	Mat src;
	src = imread("lena.jpg", IMREAD_GRAYSCALE);

	Mat neg_img(src.rows, src.cols, src.type());  //neg_img라는걸 하나 만듬

	TickMeter tm;

	tm.start();                                                   //start부터 stop까지 불러오는데 걸리는 시간이 tm에 들어간다.
	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			neg_img.at<uchar>(i, j) = src.at<uchar>(i, j);
		}
	}
	tm.stop();
	printf("\n\nprocessing time (for-loop-copy): %f us\n\n", tm.getTimeMicro());  //getTimeMicro : MicroSecond 단위로 시간을 가져와라.
	//double이나 float 변수는 %f 를 쓴다.

	tm.reset();  //타이머 리셋

	tm.start();   //타이머 다시 시작
	neg_img = src.clone();   //Deep copy
	tm.stop();     //타이머 끝
	//시작~끝 시간 측정

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