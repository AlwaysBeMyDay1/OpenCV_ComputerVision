#if 0

#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <iostream>

int main(void) {

	using namespace cv;
	using namespace std;

	Mat src;

	src = imread("lena.jpg", IMREAD_GRAYSCALE);

	imshow("src", src);

	int num = (int)(src.total() * 0.1);  //get the total pixels and multiple 0.1

	for (int i = 0; i < num; i++) {
		int x = rand() % src.rows;
		int y = rand() % src.cols;
		src.at<uchar>(x, y) = (i % 2) * 255;
	}

	Mat dst1, dst2;
	GaussianBlur(src, dst1, Size(), 1);
	medianBlur(src, dst2, 3);

	imshow("src", src);
	imshow("dst1", dst1);
	imshow("dst2", dst2);

	waitKey(0);

	destroyAllWindows();

	return 0;
}

#endif