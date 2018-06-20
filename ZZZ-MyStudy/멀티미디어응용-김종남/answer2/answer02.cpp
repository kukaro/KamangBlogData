#include <iostream>
#include <opencv/cv.hpp>

using namespace std;
using namespace cv;

string str = "/Users/kukaro/KamangBlogData/ZZZ-MyStudy/멀티미디어응용-김종남/20180620/equalize_test.jpg";
string title = "title";
Mat image;

void calc_histo(const Mat &image, Mat &hist, int bins, int range_max = 256) {
    int histSize[] = {bins};
    float range[] = {0, (float) range_max};
    int channels[] = {0};
    const float *ranges[] = {range};
    calcHist(&image, 1, channels, Mat(), hist, 1, histSize, ranges);
}

void draw_histo(Mat hist, Mat &hist_img, Size size = Size(256, 200)) {
    hist_img = Mat(size, CV_8U, Scalar(255));
    float bin = (float) hist_img.cols / hist.rows;
    normalize(hist, hist, 0, hist_img.rows, NORM_MINMAX);
    for (int i = 0; i < hist.rows; i++) {
        float start_x = i * bin;
        float end_x = (i + 1) * bin;
        Point2f pt1(start_x, 0);
        Point2f pt2(end_x, hist.at<float>(i));
        if (pt2.y > 0) {
            rectangle(hist_img, pt1, pt2, Scalar(0), -1);
        }
    }
    flip(hist_img, hist_img, 0);
}

void create_hist(Mat img, Mat &hist, Mat &hist_img) {
    int histsize = 256;
    int range = 256;
    calc_histo(img, hist, histsize, range);
    draw_histo(hist, hist_img);
}

void onMouse(int event,int x,int y,int flags,void*param){
    if(event==EVENT_LBUTTONUP){
        Rect roi(x,y,100,100);
        Mat roi_img = image(roi);
        cout<<roi_img<<endl;
        Mat hist, hist_img,dst;
        create_hist(roi_img, hist, hist_img);
        equalizeHist(roi_img,dst);
        imshow("roi",dst);
        imshow("roi_hist",hist_img);
    }
}

int main(int argc, const char *argv[]) {
    image = imread(str, IMREAD_GRAYSCALE);
    CV_Assert(!image.empty());
    imshow("title",image);
    setMouseCallback(title, onMouse,0);
    waitKey();
    return 0;
}
