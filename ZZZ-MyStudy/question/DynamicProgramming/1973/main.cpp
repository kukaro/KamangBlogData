#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#define ll long long
using namespace std;

class Point {
public:
    int x;
    int y;
    int v;

    Point() {}

    Point(int x, int y, int v) : x(x), y(y), v(v) {}
};

bool operator<(Point a, Point b) {
    return a.v < b.v;
}

bool operator>(Point a, Point b) {
    return a.v > b.v;
}

int N;
vector<Point> ARR;
vector<vector<ll>> memo;
vector<vector<int>> MAP;
ll max_val;
int last_v;

void print_memo() {
    cout << "**********" << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << memo[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "**********" << endl;
}

int main() {
    ll tmp;
    ll weight;
    cin >> N;
    memo.resize(N + 1, vector<ll>(N + 1, 0));
    MAP.resize(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> tmp;
            ARR.push_back(Point(i, j, tmp));
            MAP[i][j] = tmp;
        }
    }
    sort(ARR.begin(), ARR.end());
    for (Point atom:ARR) {
        weight = 0;
        if (atom.x + 1 <= N && MAP[atom.x + 1][atom.y] != atom.v) {
            tmp = memo[atom.x + 1][atom.y];
            weight = weight > tmp ? weight : tmp;
        }
        if (atom.x - 1 >= 1 && MAP[atom.x - 1][atom.y] != atom.v) {
            tmp = memo[atom.x - 1][atom.y];
            weight = weight > tmp ? weight : tmp;
        }
        if (atom.y + 1 <= N && MAP[atom.x][atom.y + 1] != atom.v) {
            tmp = memo[atom.x][atom.y + 1];
            weight = weight > tmp ? weight : tmp;
        }
        if (atom.y - 1 >= 1 && MAP[atom.x][atom.y - 1] != atom.v) {
            tmp = memo[atom.x][atom.y - 1];
            weight = weight > tmp ? weight : tmp;
        }
        memo[atom.x][atom.y] += weight;
        memo[atom.x][atom.y]++;
        max_val = max_val > memo[atom.x][atom.y] ? max_val : memo[atom.x][atom.y];
        //print_memo();
    }
    cout << max_val << endl;
    return 0;
}