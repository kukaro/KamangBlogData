#include <iostream>
#include <vector>
#include <queue>
#define MAXSIZE 1005
using namespace std;

int cnt;
int N, K;

int child[MAXSIZE];
int parent[MAXSIZE];

int main() {
    int tmp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        parent[i]=tmp;
        child[tmp]++;
    }
    cin >> K;
    child[K] = -1;
    child[parent[K]]--;
    for (int i = 0; i < N; i++) {
        cout<<child[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < N; i++) {
        if(child[parent[i]]==-1){
            child[i]=-1;
        }
    }
    for (int i = 0; i < N; i++) {
        cout<<child[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<N;i++){
        if(child[i]==0){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}