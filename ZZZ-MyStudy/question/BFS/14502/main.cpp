#include <iostream>
#include <queue>
#include <vector>
#define MAXSIZE 9
using namespace std;

class Point {
public:
  int x;
  int y;
  Point() {}
  Point(int x, int y) : x(x), y(y) {}
};

int N, M;
vector<vector<int>> G(MAXSIZE, vector<int>(MAXSIZE, 0));
queue<Point> q;
int max_val;

void printArr() {
  cout << "**********" << endl;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cout << G[i][j] << " ";
    }
    cout << endl;
  }
  cout << "**********" << endl;
}

void clearGraph() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (G[i][j] == 3) {
        G[i][j] = 0;
      }
    }
  }
}

void bfs() {
  Point tmp;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (G[i][j] == 2) {
        q.push(Point(i, j));
        while (!q.empty()) {
          tmp = q.front();
          q.pop();
          if (tmp.x - 1 > 0 && G[tmp.x - 1][tmp.y] == 0) {
            G[tmp.x - 1][tmp.y] = 3;
            q.push(Point(tmp.x - 1, tmp.y));
          }
          if (tmp.y + 1 <= M && G[tmp.x][tmp.y + 1] == 0) {
            G[tmp.x][tmp.y + 1] = 3;
            q.push(Point(tmp.x, tmp.y + 1));
          }
          if (tmp.x + 1 <= N && G[tmp.x + 1][tmp.y] == 0) {
            G[tmp.x + 1][tmp.y] = 3;
            q.push(Point(tmp.x + 1, tmp.y));
          }
          if (tmp.y - 1 > 0 && G[tmp.x][tmp.y - 1] == 0) {
            G[tmp.x][tmp.y - 1] = 3;
            q.push(Point(tmp.x, tmp.y - 1));
          }
        }
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (G[i][j] == 0) {
        res++;
      }
    }
  }
  max_val = max_val > res ? max_val : res;
}

int main() {
  int tmp;
  int bar_cnt;
  int a, b, c;
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> tmp;
      G[i][j] = tmp;
    }
  }
  for (int i = 0; i < N * M; i++) {
    if (G[i / M + 1][i % M + 1] == 0) {
      G[i / M + 1][i % M + 1] = 1;
      for (int j = i + 1; j < N * M; j++) {
        if (G[j / M + 1][j % M + 1] == 0) {
          G[j / M + 1][j % M + 1] = 1;
          for (int k = j + 1; k < N * M; k++) {
            if (G[k / M + 1][k % M + 1] == 0) {
              G[k / M + 1][k % M + 1] = 1;
              bfs();
              // printArr();
              clearGraph();
              G[k / M + 1][k % M + 1] = 0;
            }
          }
          G[j / M + 1][j % M + 1] = 0;
        }
      }
      G[i / M + 1][i % M + 1] = 0;
    }
  }
  cout << max_val << endl;
  //  for (int i = 1; i <= N; i++) {
  //    for (int j = 1; j <= M; j++) {
  //      cout << G[i][j] << " ";
  //    }
  //    cout << endl;
  //  }
  return 0;
}
