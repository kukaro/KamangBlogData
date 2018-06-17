#include<iostream>
#include<vector>
#define INF 0xFFFFFFF
#define MAXSIZE 1001
using namespace std;

vector<vector<int>> d;
int V,W,START_VERTEX;
int max_val;

void print_d(){
	cout<<"**********\n";
	for(int i=1;i<=V;i++){
		for(int j=1;j<=V;j++){
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"**********\n";
}

int main(){
	int tmp;
	int tu,tv,tw;
	cin>>V>>W>>START_VERTEX;
	d.resize(V+1,vector<int>(V+1,INF));
	for(int w=1;w<=W;w++){
		cin>>tu>>tv>>tw;
		d[tu][tv]=tw;
	}
	//print_d();
	for(int m=1;m<=V;m++){
		for(int s=1;s<=V;s++){
			for(int e=1;e<=V;e++){
				tmp = d[s][m]+d[m][e];
				d[s][e]=d[s][e]>tmp?tmp:d[s][e];
			}
		}
	}
	for(int v=1;v<=V;v++){
		if(v==START_VERTEX){
			continue;
		}
		tmp = d[v][START_VERTEX]+d[START_VERTEX][v];
		max_val=max_val>tmp?max_val:tmp;
	}
	cout<<max_val<<endl;
	//print_d();
	return 0;
}
