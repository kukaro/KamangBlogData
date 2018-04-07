#include <iostream>
#include <vector>
using namespace std;

int N,K;
vector<int> arr;

int f(int k,int m){
	int result=0;
	if(k<0){
		return 0;
	}else if(k==0){
		return 1;
	}
	for(int n=1;n<=N;n++){
		result+=f(k-arr[n],arr[n]);
	}
	return result;
}

int main() {
	int tmp;
	cin>>N>>K;
	arr.push_back(0);
	for(int n=1;n<=N;n++){
		cin>>tmp;
		arr.push_back(tmp);
	}
	cout<<f(10,0);
  return 0;
}
