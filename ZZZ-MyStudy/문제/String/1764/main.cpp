#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<string> arr1;
vector<string> arr2;
vector<string> ans;

bool comp(string a, string b) {
  if (a.compare(b) < 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int i = 0, j = 0;
  string tmp;
  cin >> N >> M;
  for (int n = 0; n < N; n++) {
    cin >> tmp;
    arr1.push_back(tmp);
  }
  sort(arr1.begin(), arr1.end(), comp);
  for (int m = 0; m < M; m++) {
    cin >> tmp;
    arr2.push_back(tmp);
  }
  sort(arr2.begin(), arr2.end(), comp);
  while (true) {
    if (i == N || j == M) {
      break;
    }
    if (arr1[i].compare(arr2[j]) < 0) {
      i++;
    } else if (arr1[i].compare(arr2[j]) > 0) {
      j++;
    } else {
      ans.push_back(arr2[j]);
      i++;
    }
  }
  cout << ans.size() << endl;
  for (string atom : ans) {
    cout << atom << endl;
  }
  return 0;
}
