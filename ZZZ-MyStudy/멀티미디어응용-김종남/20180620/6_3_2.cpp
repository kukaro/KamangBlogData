#include <iostream>
#include <opencv/cv.hpp>

using namespace std;
using namespace cv;

string str = "/Users/kukaro/KamangBlogData/ZZZ-MyStudy/멀티미디어응용-김종남/20180620/";

void calc_histo(const Mat &image, Mat &hist, int bins, int range_max = 256) {
    int histSize[] ={bins};
    float range[] = {0,(float)range_max};
    int channels[] = {0};
    const float * ranges[] = {range};
    calcHist(&image,1,channels,Mat(),hist,1,histSize,ranges);
}

int main(int argc, const char *argv[]) {
    Mat image = imread(str + "pixel_test.jpg", IMREAD_GRAYSCALE);
    CV_Assert(!image.empty());

    Mat hist;
    calc_histo(image,hist,256);
    cout<<hist.t()<<endl;

    imshow("image",image);
    waitKey();
    return 0;
}
