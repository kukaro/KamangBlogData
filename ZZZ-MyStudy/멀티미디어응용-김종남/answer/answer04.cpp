#include <iostream>
#include <opencv/cv.hpp>
using namespace std;
using namespace cv;

string title="result";
string bar_title_line="line";
string bar_title_rad="rad";
int line_val;
int rad_val;
Mat image;

void onChangeLine(int value,void*userdata){
    line_val = value;
}

void onChangeRad(int value,void*userdata){
    rad_val = value;
}

void onMouse(int event,int x,int y,int flags,void*param){
    Scalar color(0,0,0);
    if(flags & EVENT_FLAG_CTRLKEY){
        color=Scalar(0,0,255);
    }
    if(flags & EVENT_FLAG_SHIFTKEY){
        color=Scalar(255,0,0);
    }
    if(event==EVENT_RBUTTONUP){
        circle(image,Point(x,y),rad_val,color,line_val);
        imshow(title,image);
    }else if(event==EVENT_LBUTTONUP){
        rectangle(image, Point(x-15,y-15), Point(x+15,y+15), color,line_val);
        imshow(title,image);
    }

}

int main(int argc, const char *argv[]) {
    int value=0;
    image = Mat(400,600,CV_8UC3,Scalar(255,255,255));
    imshow(title,image);
    createTrackbar(bar_title_line, title, &value, 10, onChangeLine);
    createTrackbar(bar_title_rad, title, &value, 50, onChangeRad);
    setMouseCallback(title, onMouse,0);
    waitKey();
    return 0;
}
