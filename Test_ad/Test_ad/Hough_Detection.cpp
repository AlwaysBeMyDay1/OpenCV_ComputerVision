#if 0
#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <iostream>

int main(void) {
	using namespace cv;
	using namespace std;

	Mat src = imread("src/building.jpg", IMREAD_GRAYSCALE);

	Mat src_edge;
	Canny(src, src_edge, 50, 150);

	//eg1 - HoughLines
	/*vector<Vec2f> lines;
	HoughLines(src_edge, lines, 1, CV_PI / 180, 250);

	Mat dst;
	cvtColor(src_edge, dst, COLOR_GRAY2BGR);

	for (size_t i = 0; i < lines.size(); i++) {
		float r = lines[i][0], t = lines[i][1];
		double cos_t = cos(t), sin_t = sin(t);
		double x0 = r * cos_t, y0 = r * sin_t;
		double alpha = 1000;
		Point pt1(cvRound(x0 + alpha * (-sin_t)), cvRound(y0 + alpha * cos_t));
		Point pt2(cvRound(x0 - alpha * (-sin_t)), cvRound(y0 - alpha * cos_t));
		line(dst, pt1, pt2, Scalar(0, 0, 255), 2, LINE_AA);
	}

	imshow("src", src);
	imshow("dst", dst);
	*/

	//eg2 - HoughLines-P
	vector<Vec4i> lines;
	HoughLinesP(src_edge, lines, 1, CV_PI / 180, 160, 50, 5);

	Mat dst;
	cvtColor(src_edge, dst, COLOR_GRAY2BGR);

	for (int i = 0; i < lines.size(); i++) {
		Vec4i temp_lines = lines[i];
		line(dst, Point(temp_lines[0], temp_lines[1]), Point(temp_lines[2], temp_lines[3]), Scalar(0, 0, 255), 3, 8);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}
#endif