#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
    int x;
    int y;
    int v;

    Point() {};

    Point(int x, int y, int v) : x(x), y(y), v(v) {};

    string get() {
        return to_string(x) + ":" + to_string(y) + ":" + to_string(v);
    }
};

bool operator<(Point a, Point b) {
    return a.v > b.v;
}

int N, M;
vector<vector<int>> arr;
vector<vector<int>> memo;
vector<Point> q;

void p(){
    cout<<"**********"<<endl;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"**********"<<endl;
}

int main() {
    int tmp;
    cin >> N >> M;
    arr.resize(N + 1, vector<int>(M + 1, 0));
    memo.resize(N + 1, vector<int>(M + 1, 0));
    for (int n = 1; n <= N; n++) {
        for (int m = 1; m <= M; m++) {
            cin >> tmp;
            arr[n][m] = tmp;
            q.push_back(Point(n, m, tmp));
        }
    }
    sort(q.begin(), q.end());
    int max_val;
    for (Point atom:q) {
        if (atom.x == 1 && atom.y == 1) {
            memo[atom.x][atom.y] = 1;
            continue;
        }
        max_val = 0;
        if (atom.x - 1 > 0 && arr[atom.x - 1][atom.y] > arr[atom.x][atom.y]) {
            max_val += memo[atom.x - 1][atom.y];
        }
        if (atom.x + 1 <= N && arr[atom.x + 1][atom.y] > arr[atom.x][atom.y]) {
            max_val += memo[atom.x + 1][atom.y];
        }
        if (atom.y - 1 > 0 && arr[atom.x][atom.y - 1] > arr[atom.x][atom.y]) {
            max_val += memo[atom.x][atom.y - 1];
        }
        if (atom.y + 1 <= M && arr[atom.x][atom.y + 1] > arr[atom.x][atom.y]) {
            max_val += memo[atom.x][atom.y + 1];
        }
        memo[atom.x][atom.y] = max_val;
    }
    cout<<memo[N][M]<<endl;
    return 0;
}
