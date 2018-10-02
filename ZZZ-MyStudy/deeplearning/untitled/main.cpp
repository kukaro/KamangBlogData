#include <iostream>
#include <algorithm>
#include <vector>

#define ARR_SIZE 5

using namespace std;

vector<vector<int>> arr1;
vector<vector<int>> arr2;

void set_arr(vector<vector<int>> &v) {
    for (int i = 0; i < ARR_SIZE; i++) {
        v.push_back(vector<int>());
        for (int j = 0; j < ARR_SIZE; j++) {
            v[i].push_back(i * j + i + j);
        }
    }
}

void print_arr(vector<vector<int>> arr) {
    for (int i = 0; i < ARR_SIZE; i++) {
        for (int j = 0; j < ARR_SIZE; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    set_arr(arr1);
    arr2.resize(ARR_SIZE, vector<int>(ARR_SIZE));
    copy(arr1.begin(), arr1.end(), arr2.begin());

    print_arr(arr2);
    return 0;
}