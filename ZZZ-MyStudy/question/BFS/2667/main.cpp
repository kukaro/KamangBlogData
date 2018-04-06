#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
    int x;
    int y;

    Point() {};

    Point(int x, int y) : x(x), y(y) {}
};

int N;
int countVal;
vector<vector<int>> arr;
queue<Point> q;
vector<int> result;

void bfs() {
    Point tmp;
    int res;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] == 1) {
                q.push(Point(i, j));
                countVal++;
                res = 0;
                arr[i][j] = 0;
                while (!q.empty()) {
                    tmp = q.front();
                    q.pop();
                    res++;
                    if (tmp.x + 1 <= N && arr[tmp.x + 1][tmp.y] != 0) {
                        q.push(Point(tmp.x + 1, tmp.y));
                        arr[tmp.x + 1][tmp.y] = 0;
                    }
                    if (tmp.x - 1 > 0 && arr[tmp.x - 1][tmp.y] != 0) {
                        q.push(Point(tmp.x - 1, tmp.y));
                        arr[tmp.x - 1][tmp.y] = 0;
                    }
                    if (tmp.y + 1 <= N && arr[tmp.x][tmp.y + 1] != 0) {
                        q.push(Point(tmp.x, tmp.y + 1));
                        arr[tmp.x][tmp.y + 1] = 0;
                    }
                    if (tmp.x - 1 <= N && arr[tmp.x][tmp.y - 1] != 0) {
                        q.push(Point(tmp.x, tmp.y - 1));
                        arr[tmp.x][tmp.y - 1] = 0;
                    }
                }
                result.push_back(res);
            }
        }
    }
}

int main() {
    char tmp;
    cin >> N;
    arr.resize(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> tmp;
            arr[i][j] = tmp - '0';
        }
    }
    bfs();
    cout<<countVal<<endl;
    sort(result.begin(),result.end());
    for (int res : result) {
        cout << res << endl;
    }
    return 0;
}