#include <iostream>

#define ll long long
using namespace std;

ll A, B, C;

ll pow(ll a, ll n) {
    if (n == 1) {
        return a % C;
    }
    ll pre = pow(a, n / 2);
    pre = (pre * pre) % C;
    if (n % 2 == 1) {
        pre = (pre * a) % C;
    }
    return pre % C;
}

int main() {
    cin >> A >> B >> C;
    cout << pow(A, B) << endl;
    return 0;
}