#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> G;

int f(int n, int m) {
	if(G[n][m]==0){
		return 0;
	}
  if(n==1 && m==1){
		return 1;
	}
	return (n - 1 > 0 ? f(n - 1, m) : 0) + (m - 1 > 0 ? f(n, m - 1) : 0);
}

int main() {
  cin >> N >> M;
  G.resize(N + 1, vector<int>(M + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> G[i][j];
    }
  }
  cout << f(N, M);
  return 0;
}
