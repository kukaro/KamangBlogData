#include<iostream>
#include<vector>
using namespace std;

int N,M;
vector<string> arr;
vector<string> ans;

int main(){
	string tmp;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>tmp;
		arr.push_back(tmp);		
	}
	for(int i=0;i<M;i++){
		cin>>tmp;
		for(string atom :arr){
			if(atom.compare(tmp)==0){
				ans.push_back(tmp);
				break;
			}
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
