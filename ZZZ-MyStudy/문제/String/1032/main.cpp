#include <iostream>
#include <vector>

using namespace std;

int T;
vector<string> arr;
string result = "";

int main() {
    int i;
    string tmp;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> tmp;
        arr.push_back(tmp);
    }
    for (i = 0; i < arr[0].length(); i++) {
        bool sw = false;
        for (int t = 1; t < T; t++) {
            if (arr[t - 1][i] != arr[t][i]) {
                sw = true;
                break;
            }
        }
        if (sw == false) {
            result += arr[0][i];
        } else {
            result += '?';
        }
    }
    cout << result << endl;
    return 0;
}