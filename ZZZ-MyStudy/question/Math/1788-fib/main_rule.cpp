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
    for (int i = 2; i <= abs(N); i++) {
        a2 = (a1 + a0) % WEIGHT;
        a0 = a1;
        a1 = a2;
    }
    if (N < 0 && abs(N) % 2 == 0) {
        type = -1;
    } else if (N == 0) {
        type = 0;
        a2 = 0;
    } else {
        type = 1;
    }
    cout << type << endl;
    cout << a2 << endl;
    return 0;
}
