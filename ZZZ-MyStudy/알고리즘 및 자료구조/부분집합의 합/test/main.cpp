#include <iostream>
#include <vector>
using namespace std;

int M,N;
vector<int> arr;

bool f(int n,int m){
	if(n==1){
		if(m==0){
			return true;
		}
		else{
			return false;
		}
	}
	return f(n-1,m-arr[n])-f(n-1,m);
}

int main() {
	int tmp;
  cout<<"input m, n: ";
	cin>>M>>N;
	arr.push_back(0);
	for(int i=0;i<N;i++){
		cin>>tmp;
		arr.push_back(tmp);
	}
	cout<<f(N,M);
	return 0;
}
