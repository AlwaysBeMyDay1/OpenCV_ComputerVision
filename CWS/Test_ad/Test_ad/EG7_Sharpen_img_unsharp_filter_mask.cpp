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
		//sigma=표준편차, 시그마 커지면 필터가 완만해진다(blur가 더 심해진다_

		Mat blurred;

		GaussianBlur(src, blurred, Size(), sigma);

		float alpha = 1.f;


		Mat dst = (1 + alpha) * src - alpha * blurred;
		//h(x,y) = f(x,y)+a(f(x,y)-favg(f,x))=(1+a)f(x,y)-a(favg(x,y));
		//(1+a)에다가 소스이미지를 더하고, 알파에다가 블러 된 값을 뺀다.

		String desc = format("sigma %d", sigma);

		putText(dst, desc, Point(10, 30), FONT_HERSHEY_COMPLEX, 1.0, Scalar(255), 1, 8);

		imshow("dst", dst);

		waitKey(0);
	}
	destroyAllWindows();

	return 0;
}

#endif