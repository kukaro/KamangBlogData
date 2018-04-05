#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Point;

int M, N;
int maxVal;
vector<vector<int>> arr;
queue<Point> q;
int count;
int ex;

class Point {
public:
    int x;
    int y;

    Point() {};

    Point(int x, int y) : x(x), y(y) {}
};

void bfs() {
    Point tmp;
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        maxVal = arr[tmp.x][tmp.y] > maxVal ? arr[tmp.x][tmp.y] : maxVal;
        count++;
        if (tmp.x + 1 <= N && arr[tmp.x + 1][tmp.y] != -1 && arr[tmp.x + 1][tmp.y] == 0) {
            q.push(Point(tmp.x + 1, tmp.y));
            arr[tmp.x + 1][tmp.y] = arr[tmp.x][tmp.y] + 1;
        }
        if (tmp.x - 1 > 0 && arr[tmp.x - 1][tmp.y] != -1 && arr[tmp.x - 1][tmp.y] == 0) {
            q.push(Point(tmp.x - 1, tmp.y));
            arr[tmp.x - 1][tmp.y] = arr[tmp.x][tmp.y] + 1;
        }
        if (tmp.y + 1 <= M && arr[tmp.x][tmp.y + 1] != -1 && arr[tmp.x][tmp.y + 1] == 0) {
            q.push(Point(tmp.x, tmp.y + 1));
            arr[tmp.x][tmp.y + 1] = arr[tmp.x][tmp.y] + 1;
        }
        if (tmp.y - 1 > 0 && arr[tmp.x][tmp.y - 1] != -1 && arr[tmp.x][tmp.y - 1] == 0) {
            q.push(Point(tmp.x, tmp.y - 1));
            arr[tmp.x][tmp.y - 1] = arr[tmp.x][tmp.y] + 1;
        }
    }
}

int main() {
    int tmp;
    cin >> M >> N;
    arr.resize(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> tmp;
            arr[i][j] = tmp;
            if (tmp == 1) {
                q.push(Point(i, j));
            } else if (tmp == -1) {
                ex++;
            }
        }
    }
    bfs();
    cout << ((count + ex) == M * N ? maxVal - 1 : -1) << endl;
    return 0;
}