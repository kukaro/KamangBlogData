#include <iostream>
#include <vector>

using namespace std;

int N;
int res_val;
vector<int> memo;


int main() {
    cin >> N;
    memo.resize(N + 1, 0);
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;
    for (int i = 3; i <= N; i++) {
        memo[i] = (memo[i - 1] + memo[i - 2]) % 15746;
    }
    cout << memo[N] << endl;
}
