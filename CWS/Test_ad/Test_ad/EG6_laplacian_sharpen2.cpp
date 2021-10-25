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
	//���� �̹���(src)�� ����þȺ� �Ѵ�. ������� 5x5��

	Laplacian(blur, La_input, CV_16S, 1, 1, 0);
	//���� �̹����� �Է¹޾Ƽ� ���ö�þ� ó���ؼ� La_input�� �ִ´�.
	//1,1,0�� ���ö�þ� ����Ʈ�ϱ� �׳� ���

	convertScaleAbs(La_input, La_abs);
	//���ö�þ� ����� ���밪���� �ٲ㼭 La_abs�� �ٲ۴�.
	Mat dst;
	dst = src + La_abs;
	//���� �̹���(src)�� ���Ѵ�.

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