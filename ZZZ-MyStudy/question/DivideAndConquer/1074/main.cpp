#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, R, C;
int result;

void select_num(int n, int tr, int tc) {
    bool cr = false;
    bool cc = false;
    if (n == 0) {
        return;
    }
    if (tr+pow(2, n) / 2 <= R) {
        tr += pow(2, n - 1);
        cr = true;
    }
    if (tc+pow(2, n) / 2 <= C) {
        tc += pow(2, n - 1);
        cc = true;
    }
    if (!cr && !cc) {
        result += pow(4, n-1) * 0;
    }
    if (!cr && cc) {
        result += pow(4, n-1) * 1;
    }
    if (cr && !cc) {
        result += pow(4, n-1) * 2;
    }
    if (cr && cc) {
        result += pow(4, n-1) * 3;
    }
    select_num(n - 1, tr, tc);
}

int main() {
    cin >> N >> R >> C;
    select_num(N, 0, 0);
    cout << result << endl;
    return 0;
}
