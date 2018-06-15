#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A;
vector<int> memo;
int max_val;

void print_memo() {
  for (int n = 1; n <= N; n++) {
    cout << memo[n] << " ";
  }
  cout << endl;
}

int main() {
  int tmp;
  int tm;
  cin >> N;
  A.push_back(0);
  memo.resize(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> tmp;
    A.push_back(tmp);
  }
  for (int n = 1; n <= N; n++) {
    memo[n] = tmp = A[n];
    tm = 0;
    for (int i = n - 1; i > 0; i--) {
      if (A[i] < tmp && tm < memo[i]) {
        tm = memo[i];
      }
    }
    memo[n] += tm;
    max_val = max_val > memo[n] ? max_val : memo[n];
  }
  // print_memo();
  cout << max_val << endl;
  return 0;
}
