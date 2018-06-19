#include <iostream>
#include <opencv/cv.hpp>

using namespace std;
using namespace cv;

string str = "/Users/kukaro/KamangBlogData/ZZZ-MyStudy/멀티미디어응용-김종남/20180620/";

int main(int argc, const char *argv[]) {
    Mat image = imread(str + "pixel_test.jpg", IMREAD_GRAYSCALE);
    if (image.empty()) {
        cout << "영상을 읽지 못 했습니다." << endl;
        exit(1);
    }
    Rect roi(135, 95, 20, 15);
    Mat roi_img = image(roi);
    cout << "[roi_img] = " << endl;

    for (int i = 0; i < roi_img.rows; i++) {
        for (int j = 0; j < roi_img.cols; j++) {
            cout.width(5);
            cout<<(int)roi_img.at<uchar>(i,j);
        }
        cout<<endl;
    }
    rectangle(image,roi,Scalar(255),1);
    imshow("image",image);
    waitKey();
    return 0;
}
