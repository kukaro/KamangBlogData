#include <iostream>
#include <vector>

#define INF 0xFFFFFFF
using namespace std;

int N, V;
vector<vector<int>> arr;

void print_arr() {

    //cout << "**********" << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << (arr[i][j] != INF ? arr[i][j] : 0) << " ";
        }
        cout << endl;
    }
    //cout << "**********" << endl;
}

int main() {
    int tu, tv, tw;
    cin >> N >> V;
    arr.resize(N + 1, vector<int>(N + 1, INF));
    for (int v = 1; v <= V; v++) {
        cin >> tu >> tv >> tw;
        tw = tw < arr[tu][tv] ? tw : arr[tu][tv];
        arr[tu][tv] = tw;
    }
    //print_arr();
    for (int i = 1; i <= N; i++) {
        arr[i][i] = 0;
    }
    int tmp;
    for (int m = 1; m <= N; m++) {
        for (int s = 1; s <= N; s++) {
            for (int e = 1; e <= N; e++) {
                tmp = arr[s][m] + arr[m][e];
                arr[s][e] = tmp < arr[s][e] ? tmp : arr[s][e];
            }
        }
    }
    print_arr();
    return 0;
}
