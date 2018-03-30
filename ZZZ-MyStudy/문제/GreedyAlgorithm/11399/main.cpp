#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;

int main() {
    int tmp;
    int result = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < N; i++) {
        result += arr[i] * (N - i);
    }
    cout << result << endl;
    return 0;
}