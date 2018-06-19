#include <iostream>
#include <opencv/cv.hpp>

using namespace std;
using namespace cv;

string str = "/Users/kukaro/KamangBlogData/ZZZ-MyStudy/멀티미디어응용-김종남/20180620/";

void calc_histo(Mat image, Mat &hist, int bins, int range_max = 256) {
    hist = Mat(bins, 1, CV_32F, Scalar(0));
    float gap = range_max / (float) bins;

    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            int idx = int(image.at<uchar>(i, j) / gap);
            hist.at<float>(idx)++;
        }
    }
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
