#include <iostream>
#include <vector>
#define INF 0x7FFFFFFF
using namespace std;

int N, K;
vector<int> arr;
vector<int> memo;

int main() {
  int tmp;
  int min;
  cin >> N >> K;
  arr.push_back(0);
  memo.resize(K + 1, 0);
  memo.push_back(0);
  for (int n = 1; n <= N; n++) {
    cin >> tmp;
    arr.push_back(tmp);
  }
  for (int k = 1; k <= K; k++) {
    min = INF;
    for (int n = 1; n <= N; n++) {
      if (k - arr[n] >= 0 && memo[k - arr[n]] != -1) {
        min = min >= memo[k - arr[n]] ? memo[k - arr[n]] : min;
      }
    }
    if (min == INF) {
      memo[k] = -1;
    } else {
      memo[k] = min + 1;
    }
  }
  cout << memo[K] << endl; 
	return 0;
}
