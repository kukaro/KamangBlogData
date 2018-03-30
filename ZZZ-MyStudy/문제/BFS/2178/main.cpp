#include<iostream>
#include<vector>
#include<queue>
#define MAXSIZE 105
using namespace std;

int N,M;
vector<vector<int>> G(MAXSIZE,vector<int>(MAXSIZE,0));
vector<vector<bool>> visit(MAXSIZE,vector<bool>(MAXSIZE,false));

class Point{
public:
	int n;
	int m;
	Point(int n,int m):n(n),m(m){}
	Point(){}
};

void f(){
	Point tmp;
	queue<Point> q;
	q.push(Point(1,1));
	while(!q.empty()){
		tmp = q.front();
		q.pop();
		if(tmp.n-1 >0 && G[tmp.n-1][tmp.m]==1 && !visit[tmp.n-1][tmp.m]){
			G[tmp.n-1][tmp.m]+=G[tmp.n][tmp.m];
			q.push(Point(tmp.n-1,tmp.m));
		}
		if(tmp.n+1 <=N && G[tmp.n+1][tmp.m]==1 && !visit[tmp.n+1][tmp.m]){
			G[tmp.n+1][tmp.m]+=G[tmp.n][tmp.m];
			q.push(Point(tmp.n+1,tmp.m));
		}
		if(tmp.m-1>0 && G[tmp.n][tmp.m-1]==1 && !visit[tmp.n][tmp.m-1]){
			G[tmp.n][tmp.m-1]+=G[tmp.n][tmp.m];
			q.push(Point(tmp.n,tmp.m-1));
		}
		if(tmp.m+1<=M && G[tmp.n][tmp.m+1]==1 && !visit[tmp.n][tmp.m+1]){
			G[tmp.n][tmp.m+1]+=G[tmp.n][tmp.m];
			q.push(Point(tmp.n,tmp.m+1));
		}
	}
}

int main(){
	char tmp;
	cin>>N>>M;
	for(int n=1;n<=N;n++){
		for(int m=1;m<=M;m++){
			cin>>tmp;
			G[n][m]=tmp-'0';
		}
	}
//	for(int n=1;n<=N;n++){
//		for(int m=1;m<=M;m++){
//			cout<<G[n][m];
//		}
//		cout<<endl;
//	}
	f();
	cout<<G[N][M]<<endl;
	return 0;
}
