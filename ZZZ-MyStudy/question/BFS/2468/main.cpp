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

int N;
int cnt;
vector<vector<int>> arr;
vector<vector<int>> ans;
int max_val;
queue<Point> q;

int bfs(int n) {
  Point tmp;
  int result_val = 0;
  // submerged
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (ans[i][j] == 0 && arr[i][j] > n) {
        q.push(Point(i, j));
        ans[i][j] = 1;
        result_val++;
        while (!q.empty()) {
          tmp = q.front();
          q.pop();
          if (tmp.x + 1 <= N && ans[tmp.x + 1][tmp.y] == 0 &&
              arr[tmp.x + 1][tmp.y] > n) {
            ans[tmp.x + 1][tmp.y] = 1;
            q.push(Point(tmp.x + 1, tmp.y));
          }
          if (tmp.y + 1 <= N && ans[tmp.x][tmp.y + 1] == 0 &&
              arr[tmp.x][tmp.y + 1] > n) {
            ans[tmp.x][tmp.y + 1] = 1;
            q.push(Point(tmp.x, tmp.y + 1));
          }
          if (tmp.x - 1 > 0 && ans[tmp.x - 1][tmp.y] == 0 &&
              arr[tmp.x - 1][tmp.y] > n) {
            ans[tmp.x - 1][tmp.y] = 1;
            q.push(Point(tmp.x - 1, tmp.y));
          }
          if (tmp.y - 1 > 0 && ans[tmp.x][tmp.y - 1] == 0 &&
              arr[tmp.x][tmp.y - 1] > n) {
            ans[tmp.x][tmp.y - 1] = 1;
            q.push(Point(tmp.x, tmp.y - 1));
          }
        }
      }
    }
  }
//  cout << "**********" << endl;
//  for (int i = 1; i <= N; i++) {
//    for (int j = 1; j <= N; j++) {
//      cout << ans[i][j] << " ";
//    }
//    cout << endl;
//  }
//  cout << "**********" << endl;
//  cout << result_val << endl;
//  cout << "**********" << endl;
  return result_val;
}

int main() {
  int tmp;
  cin >> N;
  arr.resize(N + 1, vector<int>(N + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> tmp;
      cnt = cnt > tmp ? cnt : tmp;
      arr[i][j] = tmp;
    }
  }
  for (int n = 0; n <= cnt; n++) {
    ans.clear();
    ans.resize(N + 1, vector<int>(N + 1, 0));
    tmp = bfs(n);
    //		cout<<tmp<<"*"<<endl;
    max_val = max_val > tmp ? max_val : tmp;
  }
  cout << max_val << endl;
  //  for (int i = 1; i <= N; i++) {
  //    for (int j = 1; j <= N; j++) {
  //			cout<<arr[i][j]<<" ";
  //    }
  //		cout<<endl;
  //  }
  return 0;
}
