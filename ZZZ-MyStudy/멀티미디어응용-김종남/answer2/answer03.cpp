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

int main(int argc, const char *argv[]) {
    image = imread(str, IMREAD_COLOR);
    CV_Assert(!image.empty());
    Mat mat_arr[3],roi_img[3];
    split(image,mat_arr);
    Rect roi[3];
    int res[3]={0,};
    int all=0;
    for(int i=0;i<3;i++){
        roi[i] = Rect(50,50,100,100);
        roi_img[i]=mat_arr[i](roi[i]);
//        cout<<roi_img[i]<<endl;
    }
    for(int n=0;n<3;n++){
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                res[n]+=roi_img[n].at<uchar>(i,j);
            }
        }
        res[n]/=100*100;
    }
    for(int n=0;n<3;n++){
        cout<<n<<":"<<res[n]<<endl;
    }
    for(int i=0;i<image.rows;i++){
        for(int j=0;j<image.cols;j++){
            all+=(mat_arr[0].at<uchar>(i,j)+mat_arr[1].at<uchar>(i,j)+mat_arr[2].at<uchar>(i,j))/3;
        }
    }
    all/=image.rows*image.cols;
    cout<<"all:"<<all<<endl;
    return 0;
}
