#if 0

#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <iostream>

int main(void) {

	using namespace cv;
	using namespace std;

	Mat src, blur, La_input, La_abs;

	src = imread("moon.jpg", IMREAD_GRAYSCALE);

	GaussianBlur(src, blur, Size(5, 5), 0, 0, 4);
	//원래 이미지(src)를 가우시안블러 한다. 사이즈는 5x5로

	Laplacian(blur, La_input, CV_16S, 1, 1, 0);
	//블러된 이미지를 입력받아서 라플라시안 처리해서 La_input에 넣는다.
	//1,1,0은 라플라시안 디폴트니까 그냥 써라

	convertScaleAbs(La_input, La_abs);
	//라플라시안 결과를 절대값으로 바꿔서 La_abs로 바꾼다.
	Mat dst;
	dst = src + La_abs;
	//원래 이미지(src)에 더한다.

	imshow("src", src);
	imshow("blur", blur);
	imshow("La_src", La_input);

	imshow("La_src_abs",La_abs);
	imshow("dst", dst);

	waitKey(0);
	destroyAllWindows();

	return 0;
}

#endif