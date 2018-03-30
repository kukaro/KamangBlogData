#include <iostream>
#include <vector>
#define MAXSIZE 100005
using namespace std;

int N;
vector<int> arr;
int maxVal=0x80000000;
vector<int> memo(MAXSIZE, 0);

int f(int n) {
  int tmp = 0;
  if (n > N) {
    return 0;
  }
  if (memo[n + 1] == 0) {
    memo[n + 1] = f(n + 1);
  }
  tmp = memo[n + 1];
  if (tmp > 0) {
    maxVal = maxVal > tmp + arr[n] ? maxVal : tmp + arr[n];
    return tmp + arr[n];
  } else {
    maxVal = maxVal > arr[n] ? maxVal : arr[n];
    return arr[n];
  }
}

int main() {
  int tmp;
  cin >> N;
  arr.push_back(0);
  for (int i = 1; i <= N; i++) {
    cin >> tmp;
    arr.push_back(tmp);
  }
  f(1);
  cout << maxVal << endl;
  return 0;
}
