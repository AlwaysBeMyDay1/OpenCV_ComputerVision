#if 0

#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(void) {

	int width = 800;         //이미지의 가로 길이 지정
	int height = 400;        //이미지의 높이 지정

	Mat img(height, width, CV_8UC3, Scalar(255, 255, 255));   //행400,열400, 8비트unsignedCharacter3차원, BGR에 대한 값(흰색)

	line(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255)); //img, 스타트포인트, 엔드포인트, 빨간색

	line(img, Point(50, 100), Point(250, 100), Scalar(255, 0, 0),3); 
	//마지막에 3은 선 두께 추가(없으면 디폴트 1)(강의자료 3쪽에 (, , ,) 순서 확인해보기)

	arrowedLine(img, Point(25, 150), Point(300, 150), Scalar(0, 255, 0), 1);  //이것도 마지막 1은 Line두께

	arrowedLine(img, Point(25, 250), Point(300, 250), Scalar(0, 255, 0), 2,8,0,0.05); //순서대로 각 값 넣기 (강의자료 3쪽 코드 순서대로)

	imshow("img", img);

	waitKey(0);
}

#endif