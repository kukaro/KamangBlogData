#include <iostream>
#include <vector>
#define MAXSIZE 101
using namespace std;

int N;
int area;
vector<vector<int>> arr(MAXSIZE,vector<int>(MAXSIZE,0));

int main() {
  int tx, ty;
  cin >> N;
	int count = 0;
  for (int i = 0; i < N; i++) {
    cin >> tx >> ty;
  	for(int i=tx+1;i<=tx+10;i++){
			for(int j=ty+1;j<=ty+10;j++){
				if(arr[i][j]!=1){
					arr[i][j]=1;
					count++;
				}
			}
		}
	}
	cout<<count<<endl;
  return 0;
}
