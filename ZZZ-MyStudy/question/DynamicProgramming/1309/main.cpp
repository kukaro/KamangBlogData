#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<vector<int>>> memo;

int f(int num, bool isLeft, bool isRight) {
    int return_val = 0;
    if (num == N) {
        return 1;
    }
    if (isLeft && !isRight) {
        if (memo[num + 1][0][1] == -1) {
            memo[num + 1][0][1] = f(num + 1, false, true) % 9901;
        }
        if (memo[num + 1][0][0] == -1) {
            memo[num + 1][0][0] = f(num + 1, false, false) % 9901;
        }
        return_val += memo[num + 1][0][1];
        return_val += memo[num + 1][0][0];
    } else if (!isLeft && isRight) {
        if (memo[num + 1][1][0] == -1) {
            memo[num + 1][1][0] = f(num + 1, true, false) % 9901;
        }
        if (memo[num + 1][0][0] == -1) {
            memo[num + 1][0][0] = f(num + 1, false, false) % 9901;
        }
        return_val += memo[num + 1][1][0];
        return_val += memo[num + 1][0][0];
    } else if (isLeft && isRight) {
        if (memo[num + 1][0][0] == -1) {
            memo[num + 1][0][0] = f(num + 1, false, false) % 9901;
        }
        return_val += memo[num + 1][0][0];
    } else if (!isLeft && !isRight) {
        if (memo[num + 1][0][0] == -1) {
            memo[num + 1][0][0] = f(num + 1, false, false) % 9901;
        }
        if (memo[num + 1][1][0] == -1) {
            memo[num + 1][1][0] = f(num + 1, true, false) % 9901;
        }
        if (memo[num + 1][0][1] == -1) {
            memo[num + 1][0][1] = f(num + 1, false, true) % 9901;
        }
        return_val += memo[num + 1][0][0];
        return_val += memo[num + 1][1][0];
        return_val += memo[num + 1][0][1];
    }
    return return_val % 9901;
}

int main() {
    cin >> N;
    memo.resize(N + 1, vector<vector<int>>(2, vector<int>(2, -1)));
    cout << (f(1, true, false) + f(1, false, true) + f(1, false, false)) % 9901 << endl;
    return 0;
}