#include <iostream>
#include <vector>

#define CHIPHER 10000000000000000
#define MAXSIZE 105
#define ll long long
using namespace std;

class BigInt {
public:
    ll high;
    ll low;

    BigInt() : low(0), high(0) {}

    BigInt(ll low) : low(low), high(0) {}

    BigInt(ll high, ll low) : high(high), low(low) {}
};

BigInt operator+(BigInt a, BigInt b) {
    ll tlow = a.low % CHIPHER + b.low % CHIPHER;
    ll thigh = 0;
    if (tlow % CHIPHER != tlow) {
        thigh = 1;
    }
    thigh += a.high + b.high;
    return BigInt(thigh, tlow % CHIPHER);
}

ostream &operator<<(ostream &os, BigInt a) {
    if (a.high == 0) {
        os << a.low;
    } else {
        os << a.high << a.low;
    }
    return os;
}

bool operator==(BigInt a, BigInt b) {
    if (a.high == b.high && a.low == b.low) {
        return true;
    }
    return false;
}

ll N, M;
vector<vector<BigInt>> memo(MAXSIZE, vector<BigInt>(MAXSIZE, BigInt(-1)));

BigInt comb(int n, int k) {
    if (k == 0 || n == k) {
        return BigInt(1);
    }
    if (memo[n - 1][k - 1] == BigInt(-1)) {
        memo[n - 1][k - 1] = comb(n - 1, k - 1);
    }
    if (memo[n - 1][k] == BigInt(-1)) {
        memo[n - 1][k] = comb(n - 1, k);
    }
    return memo[n - 1][k - 1] + memo[n - 1][k];
}

int main() {
    cin >> N >> M;
    BigInt res = comb(N,M);
    if(res.high!=0){
        printf("%ld%016ld\n",res.high,res.low);
    }else{
        printf("%ld\n",res.low);
    }
    return 0;
}