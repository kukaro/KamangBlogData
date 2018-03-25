#include <iostream>
#include <vector>
#define MAXSIZE 1000
using namespace std;

int N,M;

int f(int n,int m){
	int result=0;
	if(n-m<0){
		return 0;
	}else if(n-m==0){
		return 1;
	}
	for(int i=1;i<=m;i++){
		result += f(n-m,i);
	}
	return result;
};

int main(){
	cout<<"input N, M : ";
	cin>>N>>M;
	cout<<"total : "<<f(N+M,M)<<endl;;
	return 0;
}
