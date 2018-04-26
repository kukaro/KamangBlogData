#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Point {
public:
  int x;
  int y;
  Point() {}
  Point(int x, int y) : x(x), y(y) {}
};

int N, M;
vector<vector<int>> G;
queue<Point> q;

int main() {
  Point p;
  int u, v;
  int cnt = 0;

  cin >> N >> M;
  G.resize(N + 1, vector<int>(N + 1, 0));
  for (int m = 1; m <= M; m++) {
    cin >> u >> v;
    G[u][v] = 1;
    G[v][u] = 1;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (G[i][j] == 1) {
        cnt++;
        q.push(Point(i, j));
        while (!q.empty()) {
          p = q.front();
          q.pop();
          G[p.x][p.y] = 0;
          G[p.y][p.x] = 0;
          for (int k = 1; k <= N; k++) {
            if (G[p.x][k] == 1) {
              q.push(Point(p.x, k));
            }
            if (G[p.y][k] == 1) {
              q.push(Point(p.y, k));
            }
          }
        }
//        for (int i = 1; i <= N; i++) {
//          for (int j = 1; j <= N; j++) {
//            cout << G[i][j] << " ";
//          }
//          cout << endl;
//        }
      }
    }
  }
  cout << cnt << endl;
  //	for(int i=1;i<=N;i++){
  //		for(int j=1;j<=N;j++){
  //			cout<<G[i][j]<<" ";
  //		}
  //		cout<<endl;
  //	}
  return 0;
}
