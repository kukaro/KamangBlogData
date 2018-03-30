#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> arr;
int maxVal;

int f(int n){
	if(n>N){
		return 0;
	}
	if(f(n+1)>0){
		maxVal = maxVal>f(n+1)+arr[n]?maxVal:f(n+1)+arr[n];
		return f(n+1)+arr[n];
	}else{
		maxVal = maxVal>arr[n]?maxVal:arr[n];
		return arr[n];
	}
}

int main(){
	int tmp;
	cin>>N;
	arr.push_back(0);
	for(int i=1;i<=N;i++){
		cin>>tmp;
		arr.push_back(tmp);
	}
	f(1);
	cout<<maxVal<<endl;
	return 0;
}
