#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int N;

int main() {
  bool sw;
  char pre;
  string str;
  cin >> N;
  int result = 0;
  for (int n = 0; n < N; n++) {
    cin >> str;
		arr.clear();
    arr.resize(26, 0);
    pre = '\0';
    sw = true;
    for (char ch : str) {
      if (pre == ch) {
        continue;
      } else if (arr[ch - 'a'] >= 1) {
        sw = false;
        break;
      } else {
        pre = ch;
        arr[ch - 'a']++;
      }
    }
    if (sw) {
      result++;
    }
  }
  cout << result << endl;
  return 0;
}
