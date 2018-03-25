#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int N, M;
vector<vector<ll>> G;
vector<vector<ll>> buff;

void f() {
  int i, j;
  buff[1][1] = G[1][1];
  for (int i = 2; i <= N; i++) {
    if (G[i][1] == 0) {
      buff[i][1] = 0;
    } else {
      buff[i][1] = buff[i - 1][1];
    }
  }
  for (int i = 2; i <= N; i++) {
    if (G[1][i] == 0) {
      buff[1][i] = 0;
    } else {
      buff[1][i] = buff[1][i - 1];
    }
  }
  for (int i = 2; i <= N; i++) {
    for (int j = 2; j <= N; j++) {
      if (G[i][j] == 0) {
        buff[i][j] = 0;
      } else {
        buff[i][j] = buff[i][j - 1] + buff[i - 1][j];
      }
    }
  }
}

int main() {
  cin >> N >> M;
  G.resize(N + 1, vector<int>(M + 1, 0));
  buff.resize(N + 1, vector<int>(M + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> G[i][j];
    }
  }
  cout << buff[N][M];
  return 0;
}
