#include <iostream>
#include <vector>
#define MAXSIZE 100005
using namespace std;

int T, N;
vector<int> arr;
vector<int> result;
vector<vector<vector<int>>> memo(MAXSIZE,
                                 vector<vector<int>>(2, vector<int>(2, 0)));

int f(int n, bool isChoice, bool isTop) {
  int add = 0;
  int next = 0;
  int cnt = 0;
  if (n > N) {
    return 0;
  }
  if (isTop) {
    cnt = n;
  } else {
    cnt = n + N;
  }
  if (memo[n + 1][true][!isTop] == 0) {
    memo[n + 1][true][!isTop] = f(n + 1, true, !isTop);
  }
  if (memo[n + 1][false][!isTop] == 0) {
    memo[n + 1][false][!isTop] = f(n + 1, false, !isTop);
  }
  next = memo[n + 1][true][!isTop] > memo[n + 1][false][!isTop]
             ? memo[n + 1][true][!isTop]
             : memo[n + 1][false][!isTop];
  if (isChoice) {
    add = arr[cnt];
  } else {
    if (memo[n + 1][true][isTop] == 0) {
      memo[n + 1][true][isTop] = f(n + 1, true, isTop);
    }
    if (memo[n + 1][false][isTop] == 0) {
      memo[n + 1][false][isTop] = f(n + 1, false, isTop);
    }
    next = next > memo[n + 1][true][isTop] ? next : memo[n + 1][true][isTop];
    next = next > memo[n + 1][false][isTop] ? next : memo[n + 1][false][isTop];
  }
  return next + add;
}

int main() {
  int tmp;
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;
    arr.clear();
    arr.push_back(0);
    memo.clear();
    memo.resize(MAXSIZE, vector<vector<int>>(2, vector<int>(2, 0)));
    for (int n = 1; n <= 2 * N; n++) {
      cin >> tmp;
      arr.push_back(tmp);
    }
    result.push_back(f(0, false, false));
  }
  for (int t = 0; t < T; t++) {
    cout << result[t] << endl;
  }
  return 0;
}
