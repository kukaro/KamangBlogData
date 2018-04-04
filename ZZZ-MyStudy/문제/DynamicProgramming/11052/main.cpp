#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> arr;

int f(int n) {
  int max = 0;
	if (n == 0) {
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (n - i >= 0) {
      if (max < f(n - i) + arr[i]) {
        max = f(n - i) + arr[i];
      }
    }
  }
  return max;
}

int main() {
  int tmp;
  cin >> N;
  arr.push_back(0);
  for (int i = 1; i <= N; i++) {
    cin >> tmp;
    arr.push_back(tmp);
  }
  cout << f(N) << endl;
  return 0;
}
