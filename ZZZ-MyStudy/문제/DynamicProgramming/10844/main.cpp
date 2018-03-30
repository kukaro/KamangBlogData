#include <iostream>
#include <vector>
using namespace std;

int N;

int f(int n, int p) {
  if (n == 0 || p < 0 || p >= 10) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return f(n - 1, p - 1) + f(n - 1, p + 1);
}

int main() {
  int result = 0;
  cin >> N;
  for (int i = 1; i < 10; i++) {
    result += f(N, i);
  }
  cout << result << endl;
  return 0;
}
