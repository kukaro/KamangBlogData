#include <iostream>
#include <vector>
/*
8
1 6 2 5 7 3 5 6
 */
using namespace std;

int N;
vector<int> ARR;
vector<int> memo;
int max_val = 0;

void print_arr() {
    for (int n = 1; n <= N; n++) {
        cout << memo[n] << " ";
    }
    cout << endl;
}

int main() {
    int tmp;
    cin >> N;
    ARR.push_back(0);
    memo.resize(N + 1, 1);
    for (int n = 1; n <= N; n++) {
        cin >> tmp;
        ARR.push_back(tmp);
    }
    memo[1] = 1;
    max_val = memo[1];
    for (int n = 2; n <= N; n++) {
        for (int i = 1; i < n; i++) {
            if (ARR[i] < ARR[n]) {
                memo[n] = memo[n] > memo[i] + 1 ? memo[n] : memo[i] + 1;
                max_val = max_val > memo[n] ? max_val : memo[n];
            }
        }
    }
    //print_arr();
    cout << max_val << endl;
    return 0;
}