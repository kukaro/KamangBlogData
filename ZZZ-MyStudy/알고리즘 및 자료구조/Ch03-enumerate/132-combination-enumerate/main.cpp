#include <iostream>
#include <vector>
#define MAXN 1000
using namespace std;

int N,K;

void printArr(vector<int> arr){
	for(int atom:arr){
		cout<<atom<<" ";
	}
	cout<<endl;
}

void comb(vector<int> arr,int k,int index){
	if(k==0){
		printArr(arr);
	}else if(N==index){
		return;
	}else{
		comb(arr,k,index+1);
		arr.push_back(index);
		comb(arr,k-1,index+1);
	}
}

int main(){
	cout<<"input N,K: ";
	cin>>N>>K;
	comb(vector<int>(),K,0);
	return 0;
}
