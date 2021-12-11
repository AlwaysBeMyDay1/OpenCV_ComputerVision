#if 0
#include <opencv2/opencv.hpp>;
#include <stdio.h>;
#include <iostream>;

int main(void) {
	using namespace cv;
	using namespace std;

	Mat src = imread("src/lena.jpg", IMREAD_GRAYSCALE);

	Mat f_src_dx, f_src_dy;

	Mat grad_x, grad_y;
	Scharr(src, grad_x, CV_16S, 1, 0);
	Scharr(src, grad_y, CV_16S, 0, 1);

	Mat abs_grad_x, abs_grad_y, gard_mag;
	convertScaleAbs(grad_x, abs_grad_x);
	convertScaleAbs(grad_y, abs_grad_y);

	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, gard_mag);

	Mat src_edge_th = gard_mag > 250;

	imshow("src", src);
	imshow("src_dx", abs_grad_x);
	imshow("src_dy", abs_grad_y);
	imshow("src_mag", gard_mag);
	imshow("src_edge_th", src_edge_th);

	waitKey(0);
	return 0;
}
#endif