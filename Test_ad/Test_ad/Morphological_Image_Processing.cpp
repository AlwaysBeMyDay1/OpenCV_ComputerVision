#if 0
#include "opencv2/opencv.hpp";
#include <stdio.h>;
#include <iostream>;

int main(void) {
	using namespace cv;
	using namespace std;

	Mat src= imread("src/neutrophils.png", IMREAD_GRAYSCALE);

	src = 255 - src; //make inv img

	Mat dst;
	threshold(src, dst, 50, 255, THRESH_BINARY);
	imshow("src", src);
	imshow("dst", dst);

	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(10, 10));
	Mat dst_erode, dst_dilate;

	erode(dst, dst_erode, element);
	erode(dst, dst_dilate, element);

	imshow("dst_erode", dst_erode);
	imshow("dst_dilate", dst_dilate);

	Mat dst_opening, dst_closing;

	morphologyEx(dst, dst_opening, MORPH_OPEN, element);
	morphologyEx(dst, dst_closing, MORPH_CLOSE, element);

	imshow("dst_opening", dst_opening);
	imshow("dst_closing", dst_closing);
	waitKey(0);
	return 0;
}
#endif