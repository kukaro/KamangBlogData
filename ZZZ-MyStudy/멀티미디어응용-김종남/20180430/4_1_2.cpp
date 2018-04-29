/*
	윈도우 이동, 이름짓기
*/
#include <iostream>
#include <opencv/cv.hpp>
using namespace std;
using namespace cv;

int main() {
	Mat image(200, 300, CV_8U, Scalar(255));
	string title1 = "창 크기변경1 - AUTOSIZE";
	string title2 = "창 크기변경2 - NORMAL";

	namedWindow(title1, WINDOW_AUTOSIZE);
	namedWindow(title2, WINDOW_NORMAL);
	moveWindow(title1, 500, 200);
	moveWindow(title2, 500, 200);

	imshow(title1, image);
	imshow(title2, image);
	waitKey();
	destroyAllWindows();
	return 0;
}
