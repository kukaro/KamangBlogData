#include <iostream>
#include <opencv/cv.hpp>
using namespace std;
using namespace cv;

int main(int argc, const char *argv[]) {
    FileStorage fs("/Users/kukaro/Desktop/test.xml",FileStorage::WRITE);
    string filename = "/Users/kukaro/KamangBlogData/ZZZ-MyStudy/멀티미디어응용-김종남/20180430/ex_color.jpg";
    Mat img8 = imread(filename,IMREAD_COLOR);
    CV_Assert(img8.data);
    fs<<"image_size"<<img8.size();
    fs<<"depth"<<img8.depth();
    fs<<"image_Data"<<img8;
    fs.release();
    return 0;
}
