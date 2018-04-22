#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> arr;
vector<int> DP(10001, 0);

int main() {
  int tmp;
  cin >> N >> K;
  arr.push_back(0);
  for (int n = 1; n <= N; n++) {
    cin >> tmp;
    arr.push_back(tmp);
  }
  DP[0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= K; j += arr[i]) {
      if (j >= arr[i]) {
        DP[j] += DP[j - arr[i]];
      }
    }
  }
  cout << DP[K] << endl;
  return 0;
}
