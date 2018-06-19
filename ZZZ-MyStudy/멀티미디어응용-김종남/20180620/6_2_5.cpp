#include <iostream>
#include <opencv/cv.hpp>

using namespace std;
using namespace cv;

string str = "/Users/kukaro/KamangBlogData/ZZZ-MyStudy/멀티미디어응용-김종남/20180620/";

int main(int argc, const char *argv[]) {
    Mat image = imread(str + "contrast_test.jpg", IMREAD_GRAYSCALE);
    CV_Assert(!image.empty());

    Scalar avg = mean(image) / 2.0;
    Mat dst1 = image * 0.5;
    Mat dst2 = image * 2.0;
    Mat dst3 = image * 0.5 + avg[0];
    Mat dst4 = image * 2.0 - avg[0];

    imshow("image", image);
    imshow("dst1-decrease", dst1);
    imshow("dst2-increase", dst2);
    imshow("dst3-average decrease", dst3);
    imshow("dst4-average increase", dst4);
    waitKey();
    return 0;
}
