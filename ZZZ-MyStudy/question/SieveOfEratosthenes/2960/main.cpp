#include <iostream>
#include <vector>
#define MAXSIZE 10005
using namespace std;

int N, K;
vector<int> arr(MAXSIZE, 0);
int ans;

int main() {
  cin >> N >> K;
  for (int i = 2; i <= N; i++) {
    if (arr[i] == 0) {
      for (int j = 1; j * i <= N; j++) {
        if (arr[i * j] != 1) {
          arr[i * j] = 1;
          K--;
          if (K == 0) {
            ans = i * j;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
