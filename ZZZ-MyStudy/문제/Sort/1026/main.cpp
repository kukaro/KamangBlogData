#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int N;
vector<int> A,B;

void swap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int tmp;
    int result=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        A.push_back(tmp);
    }
    for(int i=0;i<N;i++){
        cin>>tmp;
        B.push_back(tmp);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<int>());
    for(int i=0;i<N;i++){
        result+=A[i]*B[i];
    }
    cout<<result<<endl;
    return 0;
}