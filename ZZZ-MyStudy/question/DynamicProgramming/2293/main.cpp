#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> arr;
int memo[101][10001];

int f(int n, int k) {
  int i = 0;
  int sum = 0;
  if (k == 0) {
    //    cout << n << ":" << k << endl;
    return 1;
  }
  if (n <= 0 || n > N || k < 0) {
    return 0;
  }
  while (i * arr[n] <= K) {
    if (memo[n + 1][k - i * arr[n]] == 0) {
      memo[n + 1][k - i * arr[n]] = f(n + 1, k - i * arr[n]);
    }
    sum += memo[n + 1][k - i * arr[n]];
		//sum+=f(n + 1, k - i * arr[n]);
    i++;
  }
		//cout<<n<<":"<<i<<":"<<sum<<endl;
  return sum;
}

int main() {
  int tmp;
  cin >> N >> K;
  arr.push_back(0);
  for (int n = 1; n <= N; n++) {
    cin >> tmp;
    arr.push_back(tmp);
  }
  cout << f(1, K);
  return 0;
}
