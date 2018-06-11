#include <iostream>
using namespace std;

int N, F;

int main() {
  int num;
  int tmp;
  int res;
  cin >> N >> F;
  tmp = N / 100 * 100;
  if (tmp % F == 0) {
    res = tmp;
  } else {
    res = tmp + F - tmp % F;
  }
  if (res%100 < 10) {
    cout << "0" << res % 100 << endl;
  } else {
    cout << res % 100 << endl;
  }
  return 0;
}
