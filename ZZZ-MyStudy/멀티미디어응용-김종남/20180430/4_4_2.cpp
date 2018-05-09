/*
  이미지 저장하기
*/
#include <iostream>
#include <opencv/cv.hpp>

using namespace std;
using namespace cv;

int main(int argc, const char *argv[]) {
    Mat img8 = imread("/Users/kukaro/KamangBlogData/ZZZ-MyStudy/멀티미디어응용-김종남/20180430/ex_color.jpg", IMREAD_COLOR);
    CV_Assert(img8.data);

    vector<int> params_jpg, params_png;
    params_jpg.push_back(IMWRITE_JPEG_QUALITY);
    params_jpg.push_back(50);
    params_png.push_back(IMWRITE_PNG_COMPRESSION);
    params_png.push_back(9);

    imwrite("/Users/kukaro/Desktop/write_test1.jpg", img8);
    imwrite("/Users/kukaro/Desktop/write_test2.jpg", img8, params_jpg);
    imwrite("/Users/kukaro/Desktop/write_test.png", img8, params_png);
    imwrite("/Users/kukaro/Desktop/write_test.bmp", img8);
    waitKey();
    return 0;
}
