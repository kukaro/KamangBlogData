#include <iostream>
#include <vector>

#define MAXSIZE 1005
using namespace std;

int N;
vector<int> arr;
vector<vector<int>> memo;

int f(int n, int last) {
    int a = 0;
    int b = 0;
    if (n > N) {
        return 0;
    }
    if (last < arr[n]) {
        if (memo[n + 1][arr[n]] == 0) {
            memo[n + 1][arr[n]] = f(n + 1, arr[n]);
        }
        a = memo[n + 1][arr[n]]+1;
    }
    if (memo[n + 1][last] == 0) {
        memo[n + 1][last] = f(n + 1, last);
    }
    b = memo[n + 1][last];

    return a > b ? a : b;
}

int main() {
    int tmp;
    cin >> N;
    arr.push_back(0);
    memo.resize(MAXSIZE, vector<int>(MAXSIZE, 0));
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }
    cout << f(1, 0);
    return 0;
}