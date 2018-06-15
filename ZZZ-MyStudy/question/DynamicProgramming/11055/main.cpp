#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> A;
vector<int> memo;
int max_val;

void print_memo(){
	for(int n=1;n<=N;n++){
		cout<<memo[n]<<" ";
	}
	cout<<endl;
}

int main(){
	int tmp;
	cin>>N;
	A.push_back(0);
	memo.resize(N+1,0);
	for(int n=1;n<=N;n++){
		cin>>tmp;
		A.push_back(tmp);
	}
	for(int n=1;n<=N;n++){
		memo[n] = tmp = A[n];
		for(int i=n-1;i>0;i--){
			if(A[i]<tmp){
				memo[n]+=A[i];
				tmp = A[i];
			}
		}
		max_val = max_val>memo[n]?max_val:memo[n];
	}
	cout<<max_val<<endl;
	return 0;
}
