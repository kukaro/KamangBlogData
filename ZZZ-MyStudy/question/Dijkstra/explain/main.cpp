#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#define MAXSIZE 20001
#define INF 0x6FFFFFFF
using namespace std;

class Vertex {
public:
  int v;
  int w;

  Vertex(){};

  Vertex(int v, int w) : v(v), w(w){};
};

bool operator<(Vertex a, Vertex b) { return a.w > b.w; }

int V, E, K;
vector<Vertex> G[MAXSIZE];
vector<int> d;
priority_queue<Vertex> q;
stack<Vertex> s;

void init_queue(int num) { q.push(Vertex(num, d[num])); }

void init_distance(int num) {
  d.resize(V + 1, INF);
  d[num] = 0;
}

void print_distance() {
  for (int i = 1; i <= V; i++) {
    if (d[i] == INF) {
      cout << "INF" << endl;
    } else {
      cout << d[i] << endl;
    }
  }
}

void print_stack() {
  while (!s.empty()) {
    cout << s.top().v << " ";
    s.pop();
  }
  cout << endl;
}

int main() {
  int tu, tv, tw;
  Vertex pres;
  cin >> V >> E >> K;
  for (int i = 1; i <= E; i++) {
    cin >> tu >> tv >> tw;
    G[tu].push_back(Vertex(tv, tw));
  }
  init_distance(K);
  init_queue(K);
  while (!q.empty()) {
    // stack은 없어도 되지만 역추적 하려면 필요하다.
    s.push(q.top());
    q.pop();
    pres = s.top();
    for (Vertex next : G[pres.v]) {
      // d의 w와 pres의 w는 시작점으로 부터
      // next의 w는 pres로 부터
      if (d[next.v] > pres.w + next.w) {
        d[next.v] = pres.w + next.w;
        q.push(Vertex(next.v, d[next.v]));
      }
    }
  }
  print_stack();
  print_distance();
  return 0;
}
