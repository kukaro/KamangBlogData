#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define VERTEX_SIZE 1001
#define INF 0x6FFFFFFF
using namespace std;

class Vertex {
public:
  int v;
  int w;
  Vertex() {}
  Vertex(int v, int w) : v(v), w(w) {}
};

bool operator<(Vertex a, Vertex b) { return a.w < b.w; }

int N;
int M;
int START_VERTEX, END_VERTEX;
vector<Vertex> G[VERTEX_SIZE];
stack<Vertex> s;
priority_queue<Vertex> heap;
vector<int> d;

void init_distance(int START_VERTEX) {
  d.resize(N + 1, INF);
  d[START_VERTEX] = 0;
}

void init_heap(int START_VERTEX) {
  heap.push(Vertex(START_VERTEX, d[START_VERTEX]));
}

void print_distance() {
  for (int n = 1; n <= N; n++) {
    cout << d[n] << " ";
  }
  cout << endl;
}

int main() {
  Vertex pres;
  int tu, tv, tw;
  cin >> N >> M;
  for (int m = 1; m <= M; m++) {
    cin >> tu >> tv >> tw;
    G[tu].push_back(Vertex(tv, tw));
  }
  cin >> START_VERTEX >> END_VERTEX;
  init_distance(START_VERTEX);
  init_heap(START_VERTEX);
  while (!heap.empty()) {
    pres = heap.top();
    s.push(heap.top());
    heap.pop();
    for (Vertex next : G[pres.v]) {
      if (d[next.v] > pres.w + next.w) {
        d[next.v] = pres.w + next.w;
        heap.push(Vertex(next.v, d[next.v]));
      }
    }
  }
  // print_distance();
  cout << d[END_VERTEX] << endl;
  return 0;
}
