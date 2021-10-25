#if 0

#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(void) {

	int width = 1000;         //이미지의 가로 길이 지정
	int height = 500;        //이미지의 높이 지정

	Mat img(height, width, CV_8UC3, Scalar(255, 255, 255));   //행400,열400, 8비트unsignedCharacter3차원, BGR에 대한 값(흰색)

	rectangle(img, Rect(50, 50,100,50), Scalar(0, 0, 255),1); //Rect(start x, starty, width, height)

	rectangle(img, Rect(50, 150, 100, 50), Scalar(0, 0, 255), -1);  //Rect(start x, starty, width, height)

	circle(img, Point(300, 120), 30, Scalar(255, 0, 0), -1,8);

	circle(img, Point(300, 180), 30, Scalar(0, 0, 255), 1, 8);

	Point trapezoid[1][4];        
	trapezoid[0][0] = Point(width / 4, height / 4);    //vertex of polygon (clock wise direction)
	trapezoid[0][1] = Point(width * 3/4, height / 4);
	trapezoid[0][2] = Point(width * 7/8, height / 2);
	trapezoid[0][3] = Point(width * 1/8, height / 2);

	const Point* ptr_trapezoid[1] = { trapezoid[0] };
	int number_of_points[] = { 4 };

	fillPoly(img, ptr_trapezoid, number_of_points, 1, Scalar(0, 0, 0), 0);  //애초에 이름이 follpoly라서 채워서(fill) 나온다.

	imshow("img", img);

	waitKey(0);
}

#endif