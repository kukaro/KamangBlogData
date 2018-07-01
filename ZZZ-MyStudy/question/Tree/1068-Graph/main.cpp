#include <iostream>
#include <vector>
#include <queue>

#define MAXSIZE 51
using namespace std;

int N, D;
vector<int> G[MAXSIZE]; //무가중치 그래프
int result;
queue<int> q;

int main() {
    int tmp;
    cin >> N;
    int root;
    for (int n = 0; n < N; n++) {
        cin >> tmp;
        if (tmp == -1) {
            root = n;
        } else {
            G[tmp].push_back(n);
        }
    }
    cin >> D;
    if (D == root) {
        cout << 0 << endl;
        exit(0);
    }
    q.push(root);
    int w;
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        w = 0;
        for (int atom:G[tmp]) {
            if (atom != D) {
                w++;
                q.push(atom);
            }
        }
        if (w == 0) {
            result++;
        }
    }
    cout << result << endl;
    return 0;
}
