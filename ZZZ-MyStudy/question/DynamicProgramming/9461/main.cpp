#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<ll> result;
vector<ll> memo;
int T;

ll P(ll x) {
  if (x == 1) {
    return 1;
  } else if (x == 2) {
    return 1;
  } else if (x == 3) {
    return 1;
  }
  if (memo[x - 3] == 0) {
    memo[x - 3] = P(x - 3);
  }
  if (memo[x - 2] == 0) {
    memo[x - 2] = P(x - 2);
  }
  return memo[x - 3] + memo[x - 2];
}

int main() {
  ll tmp;
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> tmp;
    memo.clear();
    memo.resize(tmp + 1, 0);
    memo[1] = memo[2] = memo[3] = 1;
    result.push_back(P(tmp));
  }
  for (ll atom : result) {
    cout << atom << endl;
  }
}
