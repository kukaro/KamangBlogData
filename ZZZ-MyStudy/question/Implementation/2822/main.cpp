#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Point {
public:
  int index;
  int data;
  Point(int index, int data) : index(index), data(data) {}
  void info() { cout << index << ":" << data << endl; }
};

vector<Point> arr;
vector<int> ans;

bool comp(Point a, Point b) {
  if (a.data < b.data) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int tmp;
	int count=0;
  for (int i = 0; i < 8; i++) {
    cin >> tmp;
    arr.push_back(Point(i + 1, tmp));
  }
  sort(arr.begin(), arr.end(), comp);
  for(int i=arr.size()-1;i>arr.size()-6;i--){
		count+=arr[i].data;
		ans.push_back(arr[i].index);
	}
	sort(ans.begin(),ans.end());
	cout<<count<<endl;
	for(int atom:ans){
		cout<<atom<<" ";
	}
	cout<<endl;
	return 0;
}
