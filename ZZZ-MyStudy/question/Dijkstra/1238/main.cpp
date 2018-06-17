#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define INF 0x6FFFFFFF
#define VERTEX_SIZE 10001
using namespace std;

class Vertex {
public:
  int v;
  int w;
  Vertex() {}
  Vertex(int v, int w) : v(v), w(w) {}
};

bool operator<(Vertex a, Vertex b) { return a.w < b.w; }

int V, E, START_VERTEX;
vector<Vertex> G[VERTEX_SIZE];
vector<int> d[VERTEX_SIZE];
priority_queue<Vertex> heap;
int max_val;

void init_distance() {
  for (int v = 1; v <= V; v++) {
    d[v].resize(V + 1, INF);
    d[v][v] = 0;
  }
}

void init_queue(int num, int start_vertex) {
  heap.push(Vertex(start_vertex, d[num][start_vertex]));
}

void print_distance(int num) {
  for (int v = 1; v <= V; v++) {
    cout << d[num][v] << " ";
  }
  cout << endl;
}

int main() {
  Vertex pres;
  int tu, tv, tw;
  cin >> V >> E >> START_VERTEX;
  for (int e = 1; e <= E; e++) {
    cin >> tu >> tv >> tw;
    G[tu].push_back(Vertex(tv, tw));
  }
  init_distance();
  for (int v = 1; v <= V; v++) {
    init_queue(v, v);
    while (!heap.empty()) {
      pres = heap.top();
      heap.pop();
      for (Vertex next : G[pres.v]) {
        if (d[v][next.v] > next.w + pres.w) {
          d[v][next.v] = next.w + pres.w;
          heap.push(Vertex(next.v, d[v][next.v]));
        }
      }
    }
  }
  //	for(int v=1;v<=V;v++){
  //		int res = d[v][START_VERTEX]+d[START_VERTEX][v];
  //		max_val=max_val>res?max_val:res;
  //		print_distance(v);
  //	}
  cout << max_val << endl;
  return 0;
}
