#include <iostream>
#include <opencv/cv.hpp>
using namespace std;
using namespace cv;

int main(int argc, const char *argv[]) {
    string filename = "/Users/kukaro/KamangBlogData/ZZZ-MyStudy/멀티미디어응용-김종남/20180430/ex_color.jpg";
    Mat toGray = imread(filename,IMREAD_GRAYSCALE);
    CV_Assert(toGray.data);
    vector<int> params_jpg,params_png;
    params_jpg.push_back(IMWRITE_JPEG_QUALITY);
    params_jpg.push_back(100);
    params_png.push_back(IMWRITE_PNG_COMPRESSION);
    params_png.push_back(9);
    
    imwrite("/Users/kukaro/Desktop/test.jpg",toGray,params_jpg);
    imwrite("/Users/kukaro/Desktop/test.png",toGray,params_png);
    imshow("result",toGray);
    waitKey();
    return 0;
}
