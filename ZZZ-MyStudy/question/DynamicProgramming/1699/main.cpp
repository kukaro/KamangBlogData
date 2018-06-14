#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int N;
vector<int> arr;

int main(){
	int tmp;
	cin>>N;
	arr.resize(N+1,0);
	arr[0]=0;
	arr[1]=1;
	for(int n=1;n<=N;n++){
		tmp = (int)sqrt(n);
		if(pow(tmp,2)==n){
			arr[n]=1;
		}else{
			arr[n]=arr[pow(tmp,2)]+arr[n-pow(tmp,2)];
		}
	}
	cout<<arr[N]<<endl;
	return 0;
}
