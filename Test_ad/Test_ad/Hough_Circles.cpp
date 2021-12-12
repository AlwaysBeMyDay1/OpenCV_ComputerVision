#if 1
#include <opencv2/opencv.hpp>;
#include <stdio.h>;
#include <iostream>;

int main(void) {
	using namespace cv;
	using namespace std;

	Mat src = imread("src/coins.png", IMREAD_GRAYSCALE);

	Mat src_blur;
	blur(src, src_blur, Size(3,3));

	vector<Vec3f> circles;
	HoughCircles(src_blur, circles, HOUGH_GRADIENT, 1, 50, 150, 30);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	for (int i = 0; i < circles.size(); i++) {
		Vec3f temp_circles = circles[i];
		Point center(cvRound(temp_circles[0]), cvRound(temp_circles[1]));
		int radius = cvRound(temp_circles[2]);
		circle(dst, center, radius, Scalar(0, 0, 255), 2, LINE_AA);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}
#endif