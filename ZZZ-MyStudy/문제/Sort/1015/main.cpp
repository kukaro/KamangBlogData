#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> P;
vector<int> A;
vector<bool> Ac;
vector<int> B;

int main() {
    int tmp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        A.push_back(tmp);
    }
    B.resize(N,0);
    P.resize(N,0);
    Ac.resize(N,false);
    copy(A.begin(),A.end(),B.begin());
    sort(B.begin(),B.end());
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(B[i]==A[j] &&Ac[j]==false) {
                P[j] = i;
                Ac[j] = true;
                break;
            }
        }
    }
    for(int atom:P){
        cout<<atom<<" ";
    }
    cout<<endl;
    return 0;
}