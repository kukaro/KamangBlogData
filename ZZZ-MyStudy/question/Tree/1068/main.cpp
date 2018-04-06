#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cnt;
int N, K;

vector<int> child;
vector<int> tree;

int main() {
    int tmp;
    cin >> N;
    child.resize(N,0);
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        tree.push_back(tmp);
        child[tmp]=1;
    }
    cin>>K;
    for (int atom:child) {
        cout << atom << " ";
    }
    cout << endl;
    return 0;
}