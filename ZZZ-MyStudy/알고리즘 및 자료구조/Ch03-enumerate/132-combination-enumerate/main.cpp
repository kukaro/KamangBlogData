#include <iostream>
#define MAXN 1000
using namespace std;

void print_arr(int set[], int set_size) {
	for (int i = 0; i < set_size; i++) {
    cout << set[i] << " ";
  }
  cout << endl;
}

void subset(int set[], int set_size, int n, int index) {
  if (index == n) {
    print_arr(set, set_size);
    return;
  }
  set[set_size] = index;
  subset(set, set_size + 1, n, index + 1);
  subset(set, set_size, n, index + 1);
}

int main() {
  int set[MAXN], n;
  cout << "input n: ";
  cin >> n;
  subset(set, 0, n, 0);
  return 0;
}
