#if 0

#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(void) {

	int width = 800;         //�̹����� ���� ���� ����
	int height = 400;        //�̹����� ���� ����

	Mat img(height, width, CV_8UC3, Scalar(255, 255, 255));   //��400,��400, 8��ƮunsignedCharacter3����, BGR�� ���� ��(���)

	line(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255)); //img, ��ŸƮ����Ʈ, ��������Ʈ, ������

	line(img, Point(50, 100), Point(250, 100), Scalar(255, 0, 0),3); 
	//�������� 3�� �� �β� �߰�(������ ����Ʈ 1)(�����ڷ� 3�ʿ� (, , ,) ���� Ȯ���غ���)

	arrowedLine(img, Point(25, 150), Point(300, 150), Scalar(0, 255, 0), 1);  //�̰͵� ������ 1�� Line�β�

	arrowedLine(img, Point(25, 250), Point(300, 250), Scalar(0, 255, 0), 2,8,0,0.05); //������� �� �� �ֱ� (�����ڷ� 3�� �ڵ� �������)

	imshow("img", img);

	waitKey(0);
}

#endif