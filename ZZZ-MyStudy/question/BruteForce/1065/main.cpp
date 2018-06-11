#include <iostream>
using namespace std;

int N;
int cnt;

int main() {
  int tmp;
  int num1;
  int num2;
  int def;
  bool sw;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    if (i < 100) {
      cnt++;
      continue;
    }
    tmp = i;
    sw = true;
    num1 = tmp % 10;
    tmp = tmp / 10;
    num2 = tmp % 10;
    tmp = tmp / 10;
    def = num1 - num2;
    while (tmp != 0) {
      num1 = num2;
      num2 = tmp % 10;
      tmp = tmp / 10;
      if (def != num1 - num2) {
        sw = false;
      }
    }
    if (sw) {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
