#include <iostream>
using namespace std;

int N;
int sum = 0;

int main() {
  int tn;
  int carry = 10;
  int cnt = 1;
  cin >> N;
  tn = N;
  while (true) {
    if (tn >= carry) {
      sum += (carry - carry / 10) * cnt;
      cnt++;
      carry *= 10;
    } else {
      sum += (tn % (carry / 10) + 1) * cnt;
      break;
    }
  }
  cout << sum << endl;
  return 0;
}
