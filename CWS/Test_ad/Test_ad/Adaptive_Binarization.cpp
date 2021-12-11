#if 0
#include "opencv2/opencv.hpp";
#include <stdio.h>;
#include <iostream>;
using namespace cv;
using namespace std;

void on_threshold(int pos, void* userdata);
void on_trackbar(int pos, void* userdata);

int main(void) {

	Mat src = imread("sudoku.jpg", IMREAD_GRAYSCALE);

	Mat  dst_binary;
	threshold(src, dst_binary, 200, 255, THRESH_BINARY);

	imshow("src", src);
	imshow("dst_binary", dst_binary);

	namedWindow("dst_origin");
	createTrackbar("Threshold", "dst_origin", 0, 255, on_threshold, (void*)&src);
	setTrackbarPos("Threshold", "dst_origin", 128);

	namedWindow("adaptive_dst");
	createTrackbar("Adaptive_Threshold", "adaptive_dst", 0, 200, on_trackbar, (void*)&src);
	setTrackbarPos("Adaptive_Threshold", "adaptive_dst", 11);

	imshow("src", src);

	waitKey(0);
	return 0;
}

void on_threshold(int pos, void* userdata) {
	Mat src = *(Mat*)userdata;
	Mat ori_dst;

	threshold(src, ori_dst, pos, 255, THRESH_BINARY);
	imshow("dst_origin", ori_dst);
}

void on_trackbar(int pos, void* userdata) {
	Mat src = *(Mat*)userdata;
	int bsize = pos;
	if (bsize % 2 == 0)bsize--;
	if (bsize < 3)bsize = 3;

	Mat dst;
	adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, bsize, 5);
	imshow("adaptive_dst", dst);
}

#endif