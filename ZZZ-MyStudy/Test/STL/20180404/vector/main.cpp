#include <iostream>
#include <vector>
using namespace std;

int main() { 
	vector<int> v;
	v<<1;
	for(int atom:v){
		cout<<atom<<" ";
	}
	cout<<endl;
	return 0; 
}
