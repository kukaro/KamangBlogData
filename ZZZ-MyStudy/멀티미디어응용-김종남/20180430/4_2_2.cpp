/*
	콜백으로 만든 이벤트 리스너
*/
#include <iostream>
#include <opencv/cv.hpp>
using namespace std;
using namespace cv;

void onMouse(int event, int x, int y, int flags, void*param);

int main() {
	Mat image(200, 300, CV_8U);
	image.setTo(255);
	imshow("마우스 이벤트1", image);
	imshow("마우스 이벤트2", image);
	setMouseCallback("마우스 이벤트1", onMouse, 0);
	waitKey();
	return 0;
}

void onMouse(int event, int x, int y, int flags, void*para) {
	switch (event) {
	case EVENT_LBUTTONDOWN:
		cout << "마우스 왼쪽버튼 누르기" << endl;
		break;
	case EVENT_RBUTTONDOWN:
		cout << "마우스 오른쪽버튼 누르기" << endl;
		break;
	case EVENT_RBUTTONUP:
		cout << "마우스 오른족버튼 떼기" << endl;
		break;
	case EVENT_LBUTTONDBLCLK:
		cout << "마우스 왼쪽버튼 더블클릭" << endl;
		break;
	default:
		break;
	}
}
