#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Point {
public:
  int x;
  int y;
  Point(){};
  Point(int x, int y) : x(x), y(y){};
};

int T;
int N;
queue<Point> q;
Point S, L;
vector<vector<int>> ans;
vector<int> res;

int bfs(){
	Point tmp;
	q.push(S);
	while(!q.empty()){
		tmp = q.front();
		q.pop();
		cout<<tmp.x<<":"<<tmp.y<<endl;
		if(tmp.x==L.x && tmp.y==L.y){
			break;
		}
		if(tmp.x+1<=N && tmp.y-2>0 && ans[tmp.x+1][tmp.y-2]==0){
			q.push(Point(tmp.x+1,tmp.y-2));
			ans[tmp.x+1][tmp.y-2]=ans[tmp.x][tmp.y]+1;
		}
		if(tmp.x+2<=N && tmp.y-1>0 && ans[tmp.x+2][tmp.y-1]==0){
			q.push(Point(tmp.x+2,tmp.y-1));
			ans[tmp.x+2][tmp.y-1]=ans[tmp.x][tmp.y]+1;
		}
		if(tmp.x+2<=N && tmp.y+1<=N && ans[tmp.x+2][tmp.y+1]==0){
			q.push(Point(tmp.x+2,tmp.y+1));
			ans[tmp.x+2][tmp.y+1]=ans[tmp.x][tmp.y]+1;
		}
		if(tmp.x+1<=N && tmp.y+2<=N && ans[tmp.x+1][tmp.y+2]==0){
			q.push(Point(tmp.x+1,tmp.y+2));
			ans[tmp.x+1][tmp.y+2]=ans[tmp.x][tmp.y]+1;
		}
		if(tmp.x-1>0 && tmp.y+2<=N && ans[tmp.x-1][tmp.y+2]==0){
			q.push(Point(tmp.x-1,tmp.y+2));
			ans[tmp.x-1][tmp.y-2]=ans[tmp.x][tmp.y]+1;
		}
		if(tmp.x-2>0 && tmp.y+1<=N && ans[tmp.x-2][tmp.y+1]==0){
			q.push(Point(tmp.x-2,tmp.y+1));
			ans[tmp.x-2][tmp.y+1]=ans[tmp.x][tmp.y]+1;
		}
		if(tmp.x-2>0 && tmp.y-1>0 && ans[tmp.x-2][tmp.y-1]==0){
			q.push(Point(tmp.x-2,tmp.y-1));
			ans[tmp.x-2][tmp.y-1]=ans[tmp.x][tmp.y]+1;
		}
		if(tmp.x-1>0 && tmp.y-2>0 && ans[tmp.x-1][tmp.y-2]==0){
			q.push(Point(tmp.x-1,tmp.y-2));
			ans[tmp.x-1][tmp.y-2]=ans[tmp.x][tmp.y]+1;
		}
	}
	return ans[L.x][L.y];
}

int main() {
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;
    cin >> S.x >> S.y >> L.x >> L.y;
		ans.resize(N+1,vector<int>(N+1,0));
		res.push_back(bfs());
  }
	for(int atom:res){
		cout<<atom<<endl;
	}
}
