#include <iostream>
#include <vector>

#define MAXSIZE 1005
using namespace std;

int N;
vector<vector<int>> memo(MAXSIZE, vector<int>(10, -1));

int f(int n, int start) {
    int sum_val = 0;
    if (n == 1) {
        return 1;
    }
    for (int i = start; i < 10; i++) {
        if (memo[n - 1][i] == -1) {
            memo[n - 1][i] = f(n - 1, i) % 10007;
        }
        sum_val += memo[n - 1][i] % 10007;
    }
    return sum_val;
}

int main() {
    int sum_val = 0;
    cin >> N;
    for (int i = 0; i < 10; i++) {
        if (memo[N][i] == -1) {
            memo[N][i] = f(N, i) % 10007;
        }
        sum_val += memo[N][i] % 10007;
    }
    cout << sum_val%10007 << endl;
    return 0;
}
