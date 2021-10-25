#if 0

#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

int main(void) {

	using namespace cv;
	using namespace std;

	Mat src, La_input, La_abs;

	src = imread("lena.jpg", IMREAD_GRAYSCALE);

	imshow("src", src);

	for (int stddev = 10; stddev <= 30; stddev+= 10) {
	//stddev=ǥ������(=sigma)
		Mat noise(src.size(), CV_32SC1);

		randn(noise, 0, stddev);
		//random noise�� ����� �Լ�
		//(noise, ����þȺ��������, ǥ������)

		Mat dst;

		add(src, noise, dst, Mat(), CV_8U);
		// add : src�� noise�� ���ؼ� dst�� �־��ִ� �Լ�

		String desc = format("sigma %d", stddev);
		
		putText(dst, desc, Point(10, 30), FONT_HERSHEY_COMPLEX, 1.0, Scalar(255), 1, 8);

		imshow("dst", dst);

		waitKey(0);
	}

	destroyAllWindows();

	return 0;
}

#endif