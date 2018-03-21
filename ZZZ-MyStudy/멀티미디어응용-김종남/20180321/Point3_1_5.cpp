/*
 3.1.5 Vec 클래스 사용
 75page
 */
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    Vec<int, 2> v1(5, 1);
    Vec<double, 3> v2(40, 130.7, 125.6);
    Vec2b v3(10, 10);
    Vec6f v4(40.f, 230.25f, 525.6f);
    Vec3i v5(200, 230, 250);

    Vec3d v6 = v2 + (Vec3d)v5;
    Vec2b v7 = (Vec2b)v1 + v3;
    Vec6f v8 = v4 * 20.0f;

    Point pt1 = v1 + (Vec2i)v7;
    Point3_<int> pt2 = (Point3i)v2; //책에서는 묵시적 형변환이 일어난다고 되어있음, 근데 실제로 안일어남

    cout << "[v3] = " << v3 << endl;
    cout << "[v7] = " << v7 << endl;
    cout << "[v3*v7]" << v3.mul(v7) << endl;
    cout << "v8[0] = " << v8[0] << endl;
    cout << "v8[1] = " << v8[1] << endl;
    cout << "v8[2] = " << v8[2] << endl;
    cout << "[v2] = " << v2 << endl;
    cout << "[pt2] = " << pt2 << endl;
    return 0;
}
