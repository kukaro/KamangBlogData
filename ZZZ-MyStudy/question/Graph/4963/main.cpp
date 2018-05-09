#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> G;
vector<int> result;
int W, H;

void f(int h, int w) {
  if (h == 0 || h > H || w == 0 || w > W) {
    return;
  }
  if (G[h][w] == 1) {
    G[h][w] = 0;
    f(h - 1, w);
    f(h + 1, w);
    f(h, w - 1);
    f(h, w + 1);
    f(h + 1, w + 1);
    f(h + 1, w - 1);
    f(h - 1, w + 1);
    f(h - 1, w - 1);
  }
}

int main() {
  int tmp;
  int tresult;
  while (true) {
    cin >> W >> H;
    if (H == 0 && W == 0) {
      break;
    }
    tresult = 0;
    G.clear();
    G.resize(W + 1, vector<int>(H + 1, 0));
    for (int h = 1; h <= H; h++) {
      for (int w = 1; w <= W; w++) {
        cin >> tmp;
        G[h][w] = tmp;
      }
    }
    for (int h = 1; h <= H; h++) {
      for (int w = 1; w <= W; w++) {
        if (G[h][w] == 1) {
          tresult++;
          f(h, w);
        }
      }
    }
    result.push_back(tresult);
    //    for (int h = 1; h <= H; h++) {
    //      for (int w = 1; w <= W; w++) {
    //      	cout<<G[h][w]<<" ";
    //			}
    //			cout<<endl;
    //    }
  }
  for (int atom : result) {
    cout << atom << endl;
  }
  return 0;
}
