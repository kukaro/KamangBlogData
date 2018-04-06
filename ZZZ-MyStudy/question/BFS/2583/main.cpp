#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Point {
public:
    int x;
    int y;

    Point() {};

    Point(int x, int y) : x(x), y(y) {};
};

int M, N, K;
vector<vector<int>> map;
queue<Point> q;
vector<int> result;

void bfs() {
    Point tmp;
    int res;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (map[i][j] == 0) {
                res = 1;
                map[i][j] = 1;
                q.push(Point(i, j));
                while (!q.empty()) {
                    tmp = q.front();
                    q.pop();
                    if (tmp.x + 1 <= N && map[tmp.x + 1][tmp.y] == 0) {
                        q.push(Point(tmp.x + 1, tmp.y));
                        map[tmp.x + 1][tmp.y] = 1;
                        res++;
                    }
                    if (tmp.x - 1 > 0 && map[tmp.x - 1][tmp.y] == 0) {
                        q.push(Point(tmp.x - 1, tmp.y));
                        map[tmp.x - 1][tmp.y] = 1;
                        res++;
                    }
                    if (tmp.y + 1 <= M && map[tmp.x][tmp.y + 1] == 0) {
                        q.push(Point(tmp.x, tmp.y + 1));
                        map[tmp.x][tmp.y + 1] = 1;
                        res++;
                    }
                    if (tmp.y - 1 > 0 && map[tmp.x][tmp.y - 1] == 0) {
                        q.push(Point(tmp.x, tmp.y - 1));
                        map[tmp.x][tmp.y - 1] = 1;
                        res++;
                    }
                }
                result.push_back(res);
            }
        }
    }
}

int main() {
    int ax, ay, bx, by;
    cin >> M >> N >> K;
    map.resize(N + 1, vector<int>(M + 1, 0));
    for (int k = 1; k <= K; k++) {
        cin >> ax >> ay >> bx >> by;
        for (int i = ax + 1; i <= bx; i++) {
            for (int j = ay + 1; j <= by; j++) {
                map[i][j] = 1;
            }
        }
    }
//    for(int i=1;i<=N;i++){
//        for(int j=1;j<=M;j++){
//            cout<<map[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    bfs();
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (int res : result) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}