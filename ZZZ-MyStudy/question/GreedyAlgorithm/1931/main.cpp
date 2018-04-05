#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}
};

int N;
vector<Point> arr;
vector<int> h(24, 0);
int result;

bool cmp(Point &a, Point &b) {
    if (a.y < b.y) {
        return true;
    } else if (a.y > b.y) {
        return false;
    } else {
        if (a.x < b.x) {
            return true;
        } else {
            return false;
        }
    }
}

int main() {
    int pre = 0;
    int tx, ty;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tx >> ty;
        arr.push_back(Point(tx, ty));
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < N; i++) {
        if (arr[i].x >= pre) {
            result++;
            pre = arr[i].y;
        }
    }
    cout << result << endl;
    return 0;
}