#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> arr;

int main() {
  int tmp;
  int buf;
  cin >> N;
  arr.resize(N + 1, 0);
  arr[0] = 0;
  arr[1] = 1;
  for (int n = 1; n <= N; n++) {
    tmp = (int)sqrt(n);
    if (pow(tmp, 2) == n) {
      arr[n] = 1;
    } else {
				arr[n]=arr[pow(tmp,2)]+arr[n-pow(tmp,2)];
      for (int i = tmp-1; i >= 1; i--) {
        arr[n]=arr[n] < arr[pow(i, 2)] + arr[n - pow(i, 2)]
            ? arr[n]
            : arr[pow(i, 2)] + arr[n - pow(i, 2)];
      }
    }
  }
  for (int n = 1; n <= N; n++) {
    cout << n << ":" << arr[n] << endl;
  }
  cout << arr[N] << endl;
  return 0;
}
