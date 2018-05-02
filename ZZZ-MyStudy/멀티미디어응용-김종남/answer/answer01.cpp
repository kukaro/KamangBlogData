#include <iostream>
#include <opencv/cv.hpp>

using namespace std;
using namespace cv;

int main(int argc, const char *argv[]) {
    Mat image(400,600,CV_8UC3,Scalar(255,255,255));
    Point pt(100,100);
    circle(image,pt,100,Scalar(255,0,0),1);
    ellipse(image,Point(50,100),Size(50,50),0,0,180,Scalar(255,0,0));
    ellipse(image,Point(150,100),Size(50,50),0,0,-180,Scalar(255,0,0));
    imshow("result",image);
    waitKey();
    return 0;
}
