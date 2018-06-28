#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> A;
vector<int> memo;
int max_val;

void print_all(vector<int> &v) {
    cout << "**********" << endl;
    for (int i = 1; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl << "**********" << endl;
}

int main() {
    int tmp;
    int pres;
    cin >> N;
    A.push_back(0);
    memo.resize(N + 1, 1);
    for (int n = 1; n <= N; n++) {
        cin >> tmp;
        A.push_back(tmp);
    }
    for (int n = N; n > 0; n--) {
        pres = A[n];
        tmp = 0;
        for (int i = n + 1; i <= N; i++) {
            if (A[i] < pres) {
                tmp = tmp > memo[i] ? tmp : memo[i];
            }
        }
        memo[n] += tmp;
        max_val = max_val > memo[n] ? max_val : memo[n];
    }
//    print_all(memo);
    cout<<max_val<<endl;
    return 0;
}
/*
6
10 30 10 20 20 10
 */
