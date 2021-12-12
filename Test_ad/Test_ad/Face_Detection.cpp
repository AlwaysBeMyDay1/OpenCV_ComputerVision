#if 1
#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <iostream>

int main(void) {
	using namespace cv;
	using namespace std;

	Mat ori_src;

	Mat src = imread("src/lena.jpg", IMREAD_COLOR);

	CascadeClassifier classifier("haarcascades/haarcascade_frontalface_default.xml");

	if (classifier.empty()) {
		cout << "XML Load Failed" << endl;
			return 0;
	}

	vector<Rect> faces;
	classifier.detectMultiScale(src, faces);

	for (int i = 0; i < faces.size(); i++) {
		Point left_bottom(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
		Point top_right(faces[i].x, faces[i].y);
		rectangle(src, left_bottom, top_right, Scalar(0, 255, 0), 2);
	}

	imshow("src", src);

	waitKey(0);
	return 0;
}
#endif