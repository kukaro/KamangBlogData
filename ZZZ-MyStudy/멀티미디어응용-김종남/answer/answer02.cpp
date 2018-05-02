#include <iostream>
#include <opencv/cv.hpp>
using namespace std;
using namespace cv;

string title="result";
Mat image;

void onMouse(int event,int x,int y,int flags,void*param){
    if(event==EVENT_RBUTTONUP){
        circle(image,Point(x,y),20,Scalar(255,0,0),2);
        imshow(title,image);
    }else if(event==EVENT_LBUTTONUP){
        rectangle(image, Point(x-15,y-15), Point(x+15,y+15), Scalar(255,0,0),2);
        imshow(title,image);
    }
}

int main(int argc, const char *argv[]) {
    image = Mat(400,600,CV_8UC3,Scalar(255,255,255));
    imshow(title,image);
    setMouseCallback(title, onMouse,0);
    waitKey();
    return 0;
}
