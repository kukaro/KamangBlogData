#include <iostream>
#include <opencv/cv.hpp>

using namespace std;
using namespace cv;

int main(int argc, const char *argv[]) {
    Scalar blue(255, 0, 0), red(0, 0, 255), green(0, 255, 0), white(255, 255, 255), yellow(0, 255, 255);
    Mat image(400, 600, CV_8UC3, white);
    Point pt1(50, 130), pt2(200, 300), pt3(300, 150), pt4(400, 50);
    Rect rect(pt3, Size(200, 150));

    line(image, pt1, pt2, red);
    line(image, pt3, pt4, green, 2, LINE_AA);
    line(image, pt3, pt4, green, 3, LINE_8, 1);


    rectangle(image, rect, blue, 2);
    rectangle(image, rect, blue, FILLED, LINE_4, 1);
    rectangle(image, pt1, pt2, red, 3);
    imshow("직선 & 사각형", image);
    waitKey();
    return 0;
}
