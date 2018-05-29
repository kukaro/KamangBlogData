#include <iostream>
#include <vector>
#define MAXSIZE 9
using namespace std;

int N, M;
vector<vector<int>> G(MAXSIZE, vector<int>(MAXSIZE, 0));

int main() {
  int tmp;
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> tmp;
      G[i][j] = tmp;
    }
  }
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(G[i][j]==0){
				f(i,j);
			}
		}
	}
//  for (int i = 1; i <= N; i++) {
//    for (int j = 1; j <= M; j++) {
//      cout << G[i][j] << " ";
//    }
//    cout << endl;
//  }
  return 0;
}
