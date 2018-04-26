#include <iostream>
#include <vector>

using namespace std;

int N, M, K;

int main() {
    cin >> N >> M >> K;
    while (K > 0) {
        if (N > M * 2) {
            N--;
            K--;
        } else {
            M--;
            K--;
        }
    }
    cout << (M * 2 < N ? M : N / 2) << endl;
    return 0;
}