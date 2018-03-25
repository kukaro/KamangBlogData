#include <iostream>
#include <vector>
#define MAXSIZE 1000
using namespace std;

int cacheCount;
vector<int> arr;
vector<vector<int>> memo;

int f(int m, int n) {
  int result = 0;
  int bigCache = arr[n - 1];
  int iter = m / bigCache;
  if (n == 1) {
    if (m % bigCache == 0) {
      return 1;
    } else {
      return 0;
    }
  }
	if(memo[m][n]>0){
		return memo[m][n];
	}
  for (int i = 0; i <= iter; i++) {
    result += memo[m - bigCache * i][ n - 1] = f(m - bigCache * i, n - 1);
  }
  return result;
}

int main() {
  int tmp;
  int money;
  cout << "input number of bills : ";
  cin >> cacheCount;
  cout << "input biils : ";
  for (int i = 0; i < cacheCount; i++) {
    cin >> tmp;
    arr.push_back(tmp);
  }
  cout << "input money : ";
  cin >> money;
  memo.resize(money + 1, vector<int>(money+1,0));
  cout << f(money, cacheCount)<<endl;
  return 0;
}
