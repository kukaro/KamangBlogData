#include <iostream>
#include <opencv/cv.hpp>

using namespace std;
using namespace cv;

string str = "/Users/kukaro/KamangBlogData/ZZZ-MyStudy/멀티미디어응용-김종남/20180620/equalize_test.jpg";
string title = "title";
string var_title ="var";
Mat image,t_image;
int line_val;

void onChange(int value,void*userdata){
    line_val = value-1;
    for(int i=0;i<image.rows;i++){
        for(int j=0;j<image.cols;j++){
            t_image.at<uchar>(i,j) = image.at<uchar>(i,j)>=value?255:0;
        }
    }
    imshow(title,t_image);
}

int main(int argc, const char *argv[]) {
    int value=0;
    image = imread(str, IMREAD_GRAYSCALE);
    t_image= Mat(image.size(),image.type());
    CV_Assert(!image.empty());
    imshow(title,image);
    createTrackbar(var_title, title, &value, 256,onChange);
    waitKey();
    return 0;
}
