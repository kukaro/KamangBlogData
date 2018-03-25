#include <iostream>
#include <vector>
#define ll long long
#define MAXSIZE 10000

using namespace std;

vector<vector<ll>> memo;
int N, R;

ll c(int n, int r) {

  if (r == 0 || n == r) {
    return memo[n][r] = 1;
  }
  return c(n - 1, r - 1) + c(n - 1, r);
}

int main() {
  cout << " input n, r : ";
  cin >> N >> R;
  cout << c(N, R);
  return 0;
}
