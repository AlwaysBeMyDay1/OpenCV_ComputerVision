#if 0
#include "opencv2/opencv.hpp"
#include <iostream>

int main(void) {
	using namespace cv;
	using namespace std;
	
	Mat airplane = imread("airplane.bmp");
	Mat field = imread("field.bmp");
	Mat mask_plane = imread("mask_plane.bmp");
	Mat airplane_masked,field_masked, mask_plane_reverse, airplane_with_field;

	bitwise_not(mask_plane, mask_plane_reverse);
	bitwise_and(mask_plane, airplane, airplane_masked);
	bitwise_and(mask_plane_reverse, field,field_masked);
	bitwise_or(field_masked, airplane_masked, airplane_with_field);
	imshow("airplane_with_field", airplane_with_field);

	waitKey();
	return 0;
}
#endif