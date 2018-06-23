#include <iostream>
#include <vector>

#define MAXSIZE 1001
using namespace std;

vector<vector<int>> memo;
string a, b;

int f(int na, int nb) {
    if (na == a.length() || nb == b.length()) {
        return 0;
    }
    int w = a.at(na) == b.at(nb);
    int max_val = 0;
    int tmp;
    if (memo[na + 1][nb + 1] == -1) {
        memo[na + 1][nb + 1] = f(na + 1, nb + 1);
    }
    tmp = memo[na + 1][nb + 1] + w;
    max_val = max_val > tmp ? max_val : tmp;
    if (memo[na + 1][nb] == -1) {
        memo[na + 1][nb] = f(na + 1, nb);
    }
    tmp = memo[na + 1][nb];
    max_val = max_val > tmp ? max_val : tmp;
    if (memo[na][nb + 1] == -1) {
        memo[na][nb + 1] = f(na, nb + 1);
    }
    tmp = memo[na][nb + 1];
    max_val = max_val > tmp ? max_val : tmp;
    return max_val;
}

int main() {
    cin >> a >> b;
    memo.resize(MAXSIZE, vector<int>(MAXSIZE, -1));
    int res_val = f(0, 0);
    cout << res_val << endl;
    return 0;
}