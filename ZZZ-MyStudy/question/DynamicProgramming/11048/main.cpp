#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> ans;

int main() {
  int tmp;
  int max_val;
  cin >> N >> M;
  map.resize(N + 1, vector<int>(M + 1, 0));
  ans.resize(N + 1, vector<int>(M + 1, 0));

  for (int n = 1; n <= N; n++) {
    for (int m = 1; m <= M; m++) {
      cin >> tmp;
      map[n][m] = tmp;
    }
  }

  for (int n = 1; n <= N; n++) {
    for (int m = 1; m <= M; m++) {
      max_val = 0;
      if (n - 1 > 0) {
        max_val = max_val > ans[n - 1][m] ? max_val : ans[n - 1][m];
      }
      if (m - 1 > 0) {
        max_val = max_val > ans[n][m - 1] ? max_val : ans[n][m - 1];
      }
      ans[n][m] += max_val + map[n][m];
    }
  }
  cout << ans[N][M] << endl;
  //	for(int n=1;n<=N;n++){
  //		for(int m=1;m<=M;m++){
  //			cout<<map[n][m]<<" ";
  //		}
  //		cout<<endl;
  //	}
  return 0;
}
