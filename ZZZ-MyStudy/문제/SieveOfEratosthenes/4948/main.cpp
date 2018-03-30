#include <iostream>
#include <vector>
#define MAXSIZE 1000015
using namespace std;

int T;
int maxnum;
vector<int> ans;
vector<int> sieve(MAXSIZE, 1);

int countPrime(int n) {
  int result = 0;
  for (int i = n + 1; i <= 2 * n; i++) {
    result += sieve[i];
  }
  return result;
}

int main() {
  int tmp;
  while (true) {
    cin >> tmp;
    if (tmp == 0) {
      break;
    }
    maxnum = maxnum > tmp ? maxnum : tmp;
    ans.push_back(tmp);
    T++;
  }
  maxnum *= 2;
  for (int i = 2; i <= maxnum; i++) {
    if (sieve[i] == 1) {
      for (int j = 2; j * i <= maxnum; j++) {
        sieve[j * i] = 0;
        // cout<<j*i<<endl;
      }
    }
  }
  for (int t = 0; t < T; t++) {
    cout << countPrime(ans[t]) << endl;
  }
  return 0;
}
