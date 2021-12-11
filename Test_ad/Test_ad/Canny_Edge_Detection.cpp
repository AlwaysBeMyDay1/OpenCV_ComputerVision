#if 1
#include <opencv2/opencv.hpp>;
#include <stdio.h>;
#include <iostream>;

int main(void) {
	using namespace cv;
	using namespace std;

	Mat src = imread("src/lena.jpg", IMREAD_GRAYSCALE);
	
	Mat src_canny;
	Canny(src, src_canny, 100, 200, 3);

	imshow("src", src);
	imshow("src_canny", src_canny);

	Mat building = imread("src/castle.jpg", IMREAD_GRAYSCALE);
	GaussianBlur(building, building, Size(5, 5), 5, 5, BORDER_DEFAULT);

	Mat building_canny;
	Canny(building, building_canny, 100, 200, 3);

	imshow("building", building);
	imshow("building_canny", building_canny);

	waitKey(0);
	return 0;
}
#endif