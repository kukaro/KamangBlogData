#include <iostream>
#include <vector>

using namespace std;

int N, F, K;
vector<int> A;
vector<int> arr;

void print_arr() {
    for (int n = 1; n <= N; n++) {
        cout << arr[n] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void rotate_right(int s, int e) {
    int end = arr[e];
    for (int i = e; i > s; i--) {
        arr[i] = arr[i - 1];
    }
    arr[s] = end;
}

void rotate_left(int s, int e) {
    int start = arr[s];
    for (int i = s; i < e; i++) {
        arr[i] = arr[i + 1];
    }
    arr[e] = start;
}

void permutation(int n) {
    if (n == N) {
        print_arr();
        return;
    }
    for (int i = n; i <= N; i++) {
        rotate_right(n, i);
        permutation(n + 1);
        rotate_left(n, i);
    }
}

int main() {
    int tmp;
    cin >> N >> F;
    A.push_back(0);
    if (F == 1) {
        cin >> K;
    } else {
        for (int n = 1; n <= N; n++) {
            cin >> tmp;
            A.push_back(tmp);
        }
    }
    arr.push_back(0);
    for (int n = 1; n <= N; n++) {
        arr.push_back(n);
    }
    permutation(1);
    return 0;
}
