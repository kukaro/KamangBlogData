#include <iostream>
#include <vector>
#define MAXSIZE 105
using namespace std;

int T, N;
vector<int> arr;
vector<int> result;

int f(int n, bool sw) {
  int sum = 0;
  int a = 0, b = 0;
	cout<<arr[n]<<":"<<sw<<endl;
  if (n > N || n <= 0) {
    return 0;
  }
  if (n > N) {
    a = f(n - N + 1, false) > f(n - N + 1, true) ? f(n - N + 1, false)
                                                 : f(n - N + 1, true);
    b = f(n - N - 1, false) > f(n - N - 1, true) ? f(n - N - 1, false)
                                                 : f(n - N - 1, true);
    sum = a + b;
  } else {
    a = f(n + N + 1, false) > f(n + N + 1, true) ? f(n + N + 1, false)
                                                 : f(n + N + 1, true);
    b = f(n + N - 1, false) > f(n + N - 1, true) ? f(n + N - 1, false)
                                                 : f(n + N - 1, true);
    sum = a + b;
  }
  return sum + sw ? arr[n] : 0;
}

int main() {
  int tmp;
  int max = 0;
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;
    arr.clear();
    arr.push_back(0);
    for (int n = 1; n <= 2 * N; n++) {
      cin >> tmp;
      arr.push_back(tmp);
    }
    for (int n = 1; n <= 2 * N; n++) {
      tmp = f(n, true);
      max = max > tmp ? max : tmp;
    }
    result.push_back(max);
  }
  for (int t = 0; t < T; t++) {
    cout << result[t] << endl;
  }
  return 0;
}
