#include <iostream>
#include <opencv/cv.hpp>

using namespace std;
using namespace cv;

string str = "/Users/kukaro/KamangBlogData/ZZZ-MyStudy/멀티미디어응용-김종남/20180620/";

int main(int argc, const char *argv[]) {
    Mat image = imread(str + "bright.jpg", IMREAD_GRAYSCALE);
    CV_Assert(!image.empty());

    Mat dst1 = image + 100;
    Mat dst2 = image - 100;
    Mat dst3 = 255 - image;
    Mat dst4(image.size(), image.type());
    Mat dst5(image.size(), image.type());
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            dst4.at<uchar>(i, j) = image.at<uchar>(i, j) + 100;
            dst5.at<uchar>(i, j) = 255 - image.at<uchar>(i, j);
        }
    }

    imshow("원 영상", image);
    imshow("dst1 - 밝게", dst1);
    imshow("dst2 - 어둡게", dst2);
    imshow("dst3 - 반전", dst3);
    imshow("dst4 - 밝게", dst4);
    imshow("dst5 - 반전", dst5);
    waitKey();
    return 0;
}
