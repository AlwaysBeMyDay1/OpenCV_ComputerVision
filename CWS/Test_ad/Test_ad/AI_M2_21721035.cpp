#if 0

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {

	TickMeter tm;
	tm.start();
	//A
	Mat moon_gray = imread("moon_test.jpg", IMREAD_GRAYSCALE);
	imshow("M2-A_input_image", moon_gray);

	//B
	

	//E
	Mat sharpen_moon(moon_gray.rows, moon_gray.cols, moon_gray.type());
	GaussianBlur(moon_gray, sharpen_moon, Size(), 5);
	imshow("M2-E_sharpening_image", sharpen_moon);

	//F
	putText(moon_gray, "21721035", Point(30, 40), 1, 1, Scalar(255));
	imshow("M2-G", moon_gray);

	//G
	tm.stop();
	cout << "Total processing time is "<< tm.getTimeMicro() << "us";

	waitKey();
	return 0;
}
#endif