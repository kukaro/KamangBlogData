#include <iostream>
#include <vector>
using namespace std;

int M;
vector<int> arr;

void initVec() {
  arr.push_back(500);
  arr.push_back(100);
  arr.push_back(50);
  arr.push_back(10);
  arr.push_back(5);
  arr.push_back(1);
}

int main() {
  int count = 0;
  cin >> M;
  M = 1000 - M;
  initVec();
  for (int i = 0; i < arr.size(); i++) {
    if (M >= arr[i]) {
      count += M / arr[i];
      M -= M / arr[i] * arr[i];
    }
  }
  cout << count << endl;
  return 0;
}
