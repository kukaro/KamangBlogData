#include <iostream>
#include <vector>
using namespace std;

vector<int> arr(101, 0);

int main() {
	arr[1]=1;
	/*
		 에라토스테네스의 체에서 
		 */
  for (int i = 2; i <= 100; i++) {
    if (arr[i] == 0) {
      for (int j = 2; i * j <= 100; j++) {
        arr[i * j] = 1;
      }
    }
  }
  for (int i = 1; i <= 100; i++) {
    cout << i << ":" << arr[i] << endl;
  }
  return 0;
}
