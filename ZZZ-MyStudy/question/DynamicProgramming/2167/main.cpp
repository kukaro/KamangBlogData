#include <iostream>
#include <vector>
#define MAXSIZE 305
using namespace std;

int N, M, K;
int i, j, x, y;
vector<vector<int>> map(MAXSIZE, vector<int>(MAXSIZE, 0));
vector<int> result;

int main() {
  int tmp;
  cin >> N >> M;
  for (int n = 1; n <= N; n++) {
    for (int m = 1; m <= M; m++) {
      cin >> tmp;
      map[n][m] += -map[n - 1][m - 1] + map[n - 1][m] + map[n][m - 1] + tmp;
    }
  }
  //  for (int n = 1; n <= N; n++) {
  //    for (int m = 1; m <= M; m++) {
  //      cout << map[n][m] << " ";
  //    }
  //    cout << endl;
  //  }
  cin >> K;
  for (int k = 0; k < K; k++) {
    cin >> i >> j >> x >> y;
    result.push_back(map[x][y] - map[i - 1][y] - map[x][j - 1] +
                     map[i - 1][j - 1]);
  }

  for (int atom : result) {
    cout << atom << endl;
  }
  return 0;
}
