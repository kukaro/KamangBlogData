#include <iostream>
#include <opencv/cv.hpp>
using namespace std;
using namespace cv;

string title="result";
Mat image;

void onMouse(int event,int x,int y,int flags,void*param){
    Scalar color(0,0,0);
    if(flags & EVENT_FLAG_CTRLKEY){
        color=Scalar(0,0,255);
    }
    if(flags & EVENT_FLAG_SHIFTKEY){
        color=Scalar(255,0,0);
    }
    if(event==EVENT_RBUTTONUP){
        circle(image,Point(x,y),20,color,2);
        imshow(title,image);
    }else if(event==EVENT_LBUTTONUP){
        rectangle(image, Point(x-15,y-15), Point(x+15,y+15), color,2);
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
