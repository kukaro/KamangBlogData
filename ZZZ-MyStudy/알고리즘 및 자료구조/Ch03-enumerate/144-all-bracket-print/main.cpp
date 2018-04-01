#include <iostream>
#include <vector>
using namespace std;

int N;

void printArr(vector<char> arr) {
	for (char atom : arr) {
    cout << atom << " ";
  }
  cout << endl;
}

void f(vector<char> arr, int op, int cl) {
	bool sw = false;
	if (op == 0 && cl == 0) {
    printArr(arr);
    return;
  }
  if (op > 0) {
    arr.push_back('(');
		sw = true;
    f(arr, op - 1, cl + 1);
  }
  if (cl > 0) {
		if(sw==true){
			arr.pop_back();
		}
    arr.push_back(')');
    f(arr, op, cl - 1);
  }
}

int main() {
  cout << "input n : ";
  cin >> N;
  f(vector<char>(), N, 0);
	return 0;
}
