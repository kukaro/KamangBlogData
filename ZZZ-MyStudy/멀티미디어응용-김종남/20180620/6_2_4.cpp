#include <iostream>
#include <opencv/cv.hpp>

using namespace std;
using namespace cv;

string str = "/Users/kukaro/KamangBlogData/ZZZ-MyStudy/멀티미디어응용-김종남/20180620/";

int main(int argc, const char *argv[]) {
    Mat image1 = imread(str + "add1.jpg", IMREAD_GRAYSCALE);
    Mat image2 = imread(str + "add2.jpg", IMREAD_GRAYSCALE);
    CV_Assert(!(image1.empty() || image2.empty()));
    double alpha = 0.6, beta = 0.7;
    Mat add_img1 = image1 + image2;
    Mat add_img2 = image1 * 0.5 + image2 * 0.5;
    Mat add_img3 = image1 * alpha + image2 * (1 - alpha);
    Mat add_img4;
    addWeighted(image1, alpha, image2, beta, 0, add_img4);
    imshow("image1", image1);
    imshow("image2", image2);
    imshow("add_img1", add_img1);
    imshow("add_img2", add_img2);
    imshow("add_img3", add_img3);
    imshow("add_img4", add_img4);
    waitKey();
    return 0;
}
