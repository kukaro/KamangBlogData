#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Point {
public:
  int x;
  int y;

	Point(){}
  Point(int x, int y) : x(x), y(y) {}
};

int N;
vector<vector<int>> G;
vector<vector<int>> ans;
queue<Point> q;

int main() {
  int tmp;
	int cur;
	Point p;

  cin >> N;
  G.resize(N + 1, vector<int>(N + 1, 0));
  ans.resize(N + 1, vector<int>(N + 1, 0));
  
	for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> tmp;
      G[i][j] = tmp;
      if (tmp == 1) {
        q.push(Point(i, j));
      }
    }
  }
	
	while(!q.empty()){
		p = q.front();
		q.pop();
		cur = p.x;
		
	}
  //	for(int i=1;i<=N;i++){
  //		for(int j=1;j<=N;j++){
  //			cout<<G[i][j]<<" ";
  //		}
  //		cout<<endl;
  //	}
  return 0;
}
