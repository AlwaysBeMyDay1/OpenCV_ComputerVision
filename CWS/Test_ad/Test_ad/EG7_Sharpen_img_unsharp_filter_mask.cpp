#if 0

#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <iostream>

int main(void) {

	using namespace cv;
	using namespace std;

	Mat src, blur, La_input, La_abs;

	src = imread("rose.bmp", IMREAD_GRAYSCALE);

	imshow("src", src);

	for (int sigma = 1; sigma <= 5; sigma++) {
		//sigma=ǥ������, �ñ׸� Ŀ���� ���Ͱ� �ϸ�������(blur�� �� ��������_

		Mat blurred;

		GaussianBlur(src, blurred, Size(), sigma);

		float alpha = 1.f;


		Mat dst = (1 + alpha) * src - alpha * blurred;
		//h(x,y) = f(x,y)+a(f(x,y)-favg(f,x))=(1+a)f(x,y)-a(favg(x,y));
		//(1+a)���ٰ� �ҽ��̹����� ���ϰ�, ���Ŀ��ٰ� �� �� ���� ����.

		String desc = format("sigma %d", sigma);

		putText(dst, desc, Point(10, 30), FONT_HERSHEY_COMPLEX, 1.0, Scalar(255), 1, 8);

		imshow("dst", dst);

		waitKey(0);
	}
	destroyAllWindows();

	return 0;
}

#endif