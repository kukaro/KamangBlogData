#include <iostream>
using namespace std;

int X;
int cnt;
int res = 0;
int dest = 64;

int main() {
  cin >> X;
  cnt = 0;
  while (res != X) {
    if (X == 64) {
      cnt++;
      break;
    }
    dest = dest / 2;
    if (res + dest <= X) {
      res += dest;
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
