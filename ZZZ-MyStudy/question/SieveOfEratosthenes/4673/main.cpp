#include <iostream>
#include <vector>
#define MAXSIZE 10000
using namespace std;

vector<int> arr(MAXSIZE + 5, 0);

int d(int num) {
  int sum = num;
  while (num != 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

int main() {
  int tmp;
  for (int i = 1; i <= MAXSIZE; i++) {
    if (arr[i] == 0) {
      tmp = d(i);
      while (tmp <= MAXSIZE) {
        arr[tmp] = 1;
        tmp = d(tmp);
      }
    }
  }
  for (int i = 1; i <= MAXSIZE; i++) {
    if (arr[i] == 0) {
      cout << i << endl;
    }
  }
  return 0;
}
