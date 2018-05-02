#include <iostream>
#include <opencv/cv.hpp>

using namespace std;
using namespace cv;

int main(int argc, const char *argv[]) {
    Mat image(400,600,CV_8UC3,Scalar(255,255,255));
    Point pt(100,100);
    ellipse(image,Point(100,100),Size(100,100),0,0,-180,Scalar(0,0,255),FILLED);
    ellipse(image,Point(100,100),Size(100,100),0,0,180,Scalar(255,0,0),FILLED);
    ellipse(image,Point(50,100),Size(50,50),0,0,180,Scalar(0,0,255),FILLED);
    ellipse(image,Point(150,100),Size(50,50),0,0,-180,Scalar(255,0,0),FILLED);
    imshow("result",image);
    waitKey();
    return 0;
}
