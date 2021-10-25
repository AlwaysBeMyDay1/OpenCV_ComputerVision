#if 1

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	//A
	Mat lenna_gray = imread("lenna_test.bmp", IMREAD_GRAYSCALE);
	imshow("Ma-A_gray_image", lenna_gray);

	//B
	Mat lenna_color = imread("lenna_test.bmp", IMREAD_COLOR);
	imshow("Ma-B_color_image", lenna_color);

	//C
	Mat lenna_colorB;
	split(lenna_color, lenna_colorB);
	imshow("M1-C_Bchannel", lenna_colorB);
	Mat lenna_colorG;
	split(lenna_color, lenna_colorG);
	imshow("M1-C_Gchannel", lenna_colorG);
	Mat lenna_colorR;
	split(lenna_color, lenna_colorR);
	imshow("M1-C_Rchannel", lenna_colorR);

	//D
	Mat add50_gray(lenna_gray.rows, lenna_gray.cols, lenna_gray.type());
	for (int i = 0; i < lenna_gray.rows; i++) {
		for (int j = 0; j < lenna_gray.cols; j++) {
			add50_gray.at<uchar>(i, j) = saturate_cast<uchar>(lenna_gray.at<uchar>(i, j) + 50);
		}
	}
	imshow("Ma-D_gray+50_image", add50_gray);

	//E
	Mat neg_gray;
	bitwise_not(lenna_gray, neg_gray);
	imshow("neg_image", neg_gray);

	waitKey();
	return 0;
}
#endif