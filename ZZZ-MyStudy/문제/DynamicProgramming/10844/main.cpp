#include <iostream>
#include <vector>
#define MAXSIZE 105
using namespace std;

int N;
vector<vector<int>> memo(MAXSIZE, vector<int>(MAXSIZE, 0));

int f(int n, int p) {
  if (n == 0 || p < 0 || p >= 10) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  if (memo[n - 1][ p - 1] == 0) {
    memo[n - 1][ p - 1] = f(n - 1, p - 1);
  }
  if (memo[n - 1][ p + 1] == 0) {
    memo[n - 1][ p + 1] = f(n - 1, p + 1);
  }
  return memo[n - 1][p - 1] + memo[n - 1][p + 1] % 1000000000;
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
