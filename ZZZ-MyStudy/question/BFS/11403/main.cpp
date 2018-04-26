#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> G;
vector<vector<int>> ans;

void f(int s,int x){
	for(int i=1;i<=N;i++){
		if(G[x][i]==1 && ans[s][i]==0){
			ans[s][i]=1;
			f(s,i);
		}
	}
}

int main() {
  int tmp;
	int cur;

  cin >> N;
  G.resize(N + 1, vector<int>(N + 1, 0));
  ans.resize(N + 1, vector<int>(N + 1, 0));
  
	for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> tmp;
      G[i][j] = tmp;
    }
  }
	
	for (int i=1;i<=N;i++){
		f(i,i);
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
  return 0;
}
