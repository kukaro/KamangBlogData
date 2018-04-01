#include <iostream>
#include <vector>
using namespace std;

class Point {
public:
  int x;
  int y;
  Point(int x, int y) : x(x), y(y) {}
  string info() { return to_string(x) + ":" + to_string(y); }
};

int N;
vector<Point> arr;
int area;

void pointSortX(Point &a, Point &b) {
  Point tmp = a;
  if (a.x > b.x) {
    a.x = b.x;
    b.x = tmp.x;
  }
}

void pointSortY(Point &a, Point &b) {
  Point tmp = a;
  if (a.y > b.y) {
    a.y = b.y;
    b.y = tmp.y;
  }
}

int duplicateArea(Point a, Point b) {
  int tx, ty;
  pointSortX(a, b);
  tx = a.x + 10 - b.x;
  pointSortY(a, b);
  ty = a.y + 10 - b.y;
  return tx * ty > 0 ? tx * ty : 0;
}

int main() {
  int tx, ty;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> tx >> ty;
    arr.push_back(Point(tx, ty));
  }
  area = N * 100;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      area -= duplicateArea(arr[i], arr[j]);
    }
  }
  cout << area << endl;
  return 0;
}
