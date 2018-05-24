#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<vector<int>> map;

int main(){
	int tmp;
	cin>>N>>M;
	map.resize(M+1,vector<int>(N+1,0));
	for(int n=1;n<=N;n++){
		for(int m=1;m<=M;m++){
			cin>>tmp;
			map[n][m]=tmp;
		}
	}
	for(int n=1;n<=N;n++){
		for(int m=1;m<=M;m++){
			cout<<map[n][m]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
