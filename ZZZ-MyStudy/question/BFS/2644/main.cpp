#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;          //1<=N<=100
int START, END;  //1<=START,END<=N
int V;          //1<=V<=N^2
vector<vector<int>> arr;
vector<int> res;
queue<int> q;

void print_arr() {
    cout << "**********" << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "**********" << endl;
}

void print_res_arr(){
    cout << "**********" << endl;
    for (int i = 1; i <= N; i++) {
            cout << res[i] << " ";
    }
    cout<<endl;
    cout << "**********" << endl;
}

int main() {
    int tmp;
    int ts, te;
    cin >> N >> START >> END >> V;
    arr.resize(N + 1, vector<int>(N + 1, 0));
    res.resize(N + 1, -1);
    for (int v = 1; v <= V; v++) {
        cin >> ts >> te;
        arr[ts][te] = 1;
        arr[te][ts] = 1;
    }
    q.push(START);
    res[START] = 0;
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        for (int n = 1; n <= N; n++) {
            if (arr[tmp][n] == 1 && res[n] == -1) {
                res[n] = res[tmp]+1;
                q.push(n);
            }
        }
    }
    //print_res_arr();
    cout<<res[END]<<endl;
    return 0;
}