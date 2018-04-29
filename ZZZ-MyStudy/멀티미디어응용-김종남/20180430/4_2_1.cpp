/*
	이벤트 리스너인데 구시대적인 방법임
*/
#include <iostream>
#include <opencv/cv.hpp>
#define CUSTOM_ESC 27
using namespace std;
using namespace cv;

int main() {
	Mat image(200, 300, CV_8U, Scalar(255));
	namedWindow("키보드 이벤트", WINDOW_AUTOSIZE);
	imshow("키보드 이벤트", image);
	while (true) {
		int key = cvWaitKey(100);
		/*
			waitKey는 위아래등의 방향키를 받지 못하더라
		*/
		if (key == CUSTOM_ESC) break;
		switch (key) {
		case 'a': cout << "a키 입력" << endl;
			break;
		case 'b': cout << "b키 입력" << endl;
			break;
		case 'A': cout << "A키 입력" << endl;
			break;
		case 'B': cout << "B키 입력" << endl;
			break;

		case 0x250000: cout << "왼쪽 화살표 키 입력" << endl;
			break;
		case 0x260000: cout << "윗쪽 화살표 키 입력" << endl;
			break;
		case 0x270000: cout << "오른쪽 화살표 키 입력" << endl;
			break;
		case 0x280000: cout << "아래쪽 화살표 키 입력" << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}
