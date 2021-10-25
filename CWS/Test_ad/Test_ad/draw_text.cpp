#if 0

#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(void) {

	int width = 1000;         //이미지의 가로 길이 지정
	int height = 500;        //이미지의 높이 지정

	Mat img(height, width, CV_8UC3, Scalar(0, 0, 0));   //행400,열400, 8비트unsignedCharacter3차원, BGR에 대한 값(BLACK)

	putText(img, "FONT_HERSHEY_SIMPLEX, Font scale = 1", Point(20, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 255));

	putText(img, "FONT_HERSHEY_PLAIN, Font scale = 1", Point(20, 100), FONT_HERSHEY_PLAIN, 1, Scalar(0, 255, 255));

	putText(img, "FONT_HERSHEY_DUPLEX, Font scale = 1", Point(20, 300), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 255, 255));

	putText(img, "FONT_HERSHEY_COMPLEX, Font scale = 1", Point(20, 350), FONT_HERSHEY_COMPLEX, 1, Scalar(0, 255, 255));

	putText(img, "FONT_HERSHEY_COMPLEX_SMALL, Font scale = 1", Point(20, 400), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(0, 255, 255));

	imshow("img", img);

	waitKey(0);
}

#endif