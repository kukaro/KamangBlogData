#include <iostream>
#include <vector>
#define ll long long

#define MAXSIZE 101
using namespace std;

int N;
vector<vector<int>> arr;
vector<vector<ll>> memo;

void print_arr() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void print_memo(bool line) {
    if (line) {
        cout << "**********" << endl;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }
    if (line) {
        cout << "**********" << endl;
    }
}

int main() {
    int tmp;
    cin >> N;
    arr.resize(N + 1, vector<int>(N + 1, 0));
    memo.resize(N + 1, vector<ll>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> tmp;
            arr[i][j] = tmp;
        }
    }
    memo[1][1] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            //cout<<i<<":"<<j<<endl;
            if (i == N && j == N) {
                break;
            }
            if (i + arr[i][j] <= N) {
                memo[i + arr[i][j]][j] += memo[i][j];
            }
            if (j + arr[i][j] <= N) {
                memo[i][j + arr[i][j]] += memo[i][j];
            }
            //print_memo(true);
        }
    }
    cout << memo[N][N] << endl;
    return 0;
}
