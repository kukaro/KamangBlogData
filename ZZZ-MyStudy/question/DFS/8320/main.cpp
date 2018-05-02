#include <iostream>
#include <vector>

using namespace std;

int N;
int maxVal = 0;

void f(int row, int col) {
    if (row * col <= N) {
        maxVal++;
        f(row + 1, col);
        if (row == col + 1) {
            f(row, col + 1);
        }
    }
}

int main() {
    cin >> N;
    f(1, 1);
    cout << maxVal << endl;
    return 0;
}