#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXSIZE 400
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
int ans[MAXSIZE][MAXSIZE];
vector<int> res;

int bfs(){
	Point tmp;
	q.push(S);
	ans[S.x][S.y]=1;
	while(!q.empty()){
		tmp = q.front();
		q.pop();
		if(tmp.x==L.x && tmp.y==L.y){
			break;
		}
		if(tmp.x+1<N && tmp.y-2>=0 && ans[tmp.x+1][tmp.y-2]==0){
			q.push(Point(tmp.x+1,tmp.y-2));
			ans[tmp.x+1][tmp.y-2]=ans[tmp.x][tmp.y]+1;
		}
		if(tmp.x+2<N && tmp.y-1>=0 && ans[tmp.x+2][tmp.y-1]==0){
			q.push(Point(tmp.x+2,tmp.y-1));
			ans[tmp.x+2][tmp.y-1]=ans[tmp.x][tmp.y]+1;
		}
		if(tmp.x+2<N && tmp.y+1<N && ans[tmp.x+2][tmp.y+1]==0){
			q.push(Point(tmp.x+2,tmp.y+1));
			ans[tmp.x+2][tmp.y+1]=ans[tmp.x][tmp.y]+1;
		}
		if(tmp.x+1<N && tmp.y+2<N && ans[tmp.x+1][tmp.y+2]==0){
			q.push(Point(tmp.x+1,tmp.y+2));
			ans[tmp.x+1][tmp.y+2]=ans[tmp.x][tmp.y]+1;
		}
		if(tmp.x-1>=0 && tmp.y+2<N && ans[tmp.x-1][tmp.y+2]==0){
			q.push(Point(tmp.x-1,tmp.y+2));
			ans[tmp.x-1][tmp.y+2]=ans[tmp.x][tmp.y]+1;
		}
		if(tmp.x-2>=0 && tmp.y+1<N && ans[tmp.x-2][tmp.y+1]==0){
			q.push(Point(tmp.x-2,tmp.y+1));
			ans[tmp.x-2][tmp.y+1]=ans[tmp.x][tmp.y]+1;
		}
		if(tmp.x-2>=0 && tmp.y-1>=0 && ans[tmp.x-2][tmp.y-1]==0){
			q.push(Point(tmp.x-2,tmp.y-1));
			ans[tmp.x-2][tmp.y-1]=ans[tmp.x][tmp.y]+1;
		}
		if(tmp.x-1>=0 && tmp.y-2>=0 && ans[tmp.x-1][tmp.y-2]==0){
			q.push(Point(tmp.x-1,tmp.y-2));
			ans[tmp.x-1][tmp.y-2]=ans[tmp.x][tmp.y]+1;
		}
	}
	return ans[L.x][L.y]-1;
}

void resetArr(){
	for(int i=0;i<MAXSIZE;i++){
		for(int j=0;j<MAXSIZE;j++){
			ans[i][j]=0;
		}
	}
}

int main() {
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;
    cin >> S.x >> S.y >> L.x >> L.y;
		resetArr();
		queue<Point> eq;
		swap(q,eq);
		res.push_back(bfs());
  }
	for(int atom:res){
		cout<<atom<<endl;
	}
}
