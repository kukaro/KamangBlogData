#include <iostream>
#include <vector>
#define ll long long
#define MAXSIZE 1000

using namespace std;

vector<vector<ll>> memo(MAXSIZE, vector<ll>(MAXSIZE, 0));
int N, R;

ll c(int n, int r) {
  cout << n << ":" << r << endl;
  if (memo[n][r] > 0) {
    return memo[n][r];
  }
  if (r == 0 || n == r) {
    return memo[n][r] = 1;
  }
  return memo[n][r] = c(n - 1, r - 1) + c(n - 1, r);
}

int main() {
  cout << "input n, r : ";
  cin >> N >> R;
  cout << c(N, R);
  return 0;
}
