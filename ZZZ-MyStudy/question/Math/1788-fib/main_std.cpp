#include <iostream>
#include <vector>
#include <cmath>

#define WEIGHT 1000000000
using namespace std;

int N;
int type;
int a0;
int a1;
int a2;

int main() {
    cin >> N;
    a0 = 0;
    a1 = 1;
    a2 = 1;
    if (N > 0) {
        for (int i = 2; i <= N; i++) {
            a2 = (a1 + a0) % WEIGHT;
            a0 = a1;
            a1 = a2;
        }
    } else if (N < 0) {
        for (int i = 1; i <= N * -1; i++) {
            a2 = (a1 - a0) % WEIGHT;
            a1 = a0;
            a0 = a2;
        }
    }
    if (a2 > 0) {
        type = 1;
    } else if (a2 < 0) {
        type = -1;
    }
    if (N == 0) {
        type = 0;
        a2 = 0;
    }
    cout << type << endl;
    cout << abs(a2) << endl;
    //cout << a2 << endl;
    return 0;
}
