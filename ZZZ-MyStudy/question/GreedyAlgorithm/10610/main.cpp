#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<char> arr;

int main() {
    char tmp;
    int pSum = 0;
    bool isDec = false;
    while (true) {
        tmp = getchar();
        if (tmp == '\n') {
            break;
        }
        arr.push_back(tmp - '0');
    }
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0 && !isDec) {
            isDec = true;
            arr.erase(arr.begin() + i);
        }
        pSum += arr[i];
    }
    if (pSum % 3 == 0 && isDec) {
        sort(arr.begin(), arr.end(), greater<int>());
        for (int atom:arr) {
            cout << atom;
        }
        cout << 0 << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}