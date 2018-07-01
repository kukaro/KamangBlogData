#include <iostream>
#include <vector>

using namespace std;

int K;
vector<int> arr;
vector<int> res;

void print_arr(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void comb(int cur, int remain) {
    //cout<<cur<<":"<<remain<<endl;
    if (cur > K) {
        return;
    }
    if (remain == 0) {
        print_arr(res);
        return;
    }
    res.push_back(arr[cur+1]);
    comb(cur + 1, remain - 1);
    res.pop_back();
    //print_arr(res);
    comb(cur + 1, remain);
}

int main() {
    int tmp;
    while (true) {
        cin >> K;
        if (K == 0) {
            break;
        }
        arr.clear();
        arr.resize(K + 1, 0);
        for (int k = 1; k <= K; k++) {
            cin >> tmp;
            arr[k] = tmp;
        }
        //print_arr(arr);
        comb(0, 6);
        cout<<endl;
    }
    return 0;
}
