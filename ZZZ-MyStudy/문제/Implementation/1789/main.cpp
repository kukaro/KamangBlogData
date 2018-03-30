#include <iostream>
#define ll long long
using namespace std;

ll S;
int count;

int main() {
  ll i = 0;
  cin >> S;
  while (S > i) {
    S -= i;
    i++;
  }
  cout << i - 1 << endl;
  return 0;
}
