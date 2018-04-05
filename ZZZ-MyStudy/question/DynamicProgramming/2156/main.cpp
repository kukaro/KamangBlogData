#include<iostream>
#include<vector>
#define MAXSIZE 10005
using namespace std;

int N;
vector<int> arr;
vector<vector<int>> memo(MAXSIZE,vector<int>(3,0));

int f(int n,int fl){
	int result=0;
	if(n>N){
		return 0;
	}
	if(fl==0){
		if(memo[n+1][1]==0){
			memo[n+1][1]=f(n+1,1);
		}
		if(memo[n+1][0]==0){
			memo[n+1][0]=f(n+1,0);
		}
		result=memo[n+1][1]+arr[n]>memo[n+1][0]?memo[n+1][1]+arr[n]:memo[n+1][0];
	}else if(fl==1){
		if(memo[n+1][2]==0){
			memo[n+1][2]=f(n+1,2);
		}
		if(memo[n+1][0]==0){
			memo[n+1][0]=f(n+1,0);
		}
		result=memo[n+1][2]+arr[n]>memo[n+1][0]?memo[n+1][2]+arr[n]:memo[n+1][0];
	}else{
		if(memo[n+1][0]==0){
			memo[n+1][0]=f(n+1,0);
		}
		result=memo[n+1][0];
	}
	return result;
}

int main(){
	int tmp;
	cin>>N;
	arr.push_back(0);
	for(int i=0;i<N;i++){
		cin>>tmp;
		arr.push_back(tmp);
	}
	cout<<f(1,0)<<endl;
	return 0;
}
