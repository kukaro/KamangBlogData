#include <iostream>
#include <opencv/cv.hpp>

using namespace std;
using namespace cv;

string str = "/Users/kukaro/KamangBlogData/ZZZ-MyStudy/멀티미디어응용-김종남/20180620/";

int main(int argc, const char *argv[]) {
    Mat BGR_img = imread(str + "color_model.jpg", IMREAD_COLOR);
    CV_Assert(BGR_img.data);

    Scalar white(255, 255, 255);
    Mat CMY_img = white - BGR_img;
    Mat CMY_arr[3];
    split(CMY_img, CMY_arr);

    imshow("BGR_img",BGR_img);
    imshow("CMY_img",CMY_img);
    imshow("Yellow",CMY_arr[0]);
    imshow("Magenta",CMY_arr[1]);
    imshow("Cyan",CMY_arr[2]);
    waitKey();
    return 0;
}
