#include <iostream>
#include <queue>
#include <vector>
#define MAXSIZE 100005
using namespace std;

int N, K;
vector<int> arr(MAXSIZE, -1);
queue<int> q;

void bfs() {
  int tmp;
  arr[N] = 0;
 	q.push(N);
  while (!q.empty()) {
    tmp = q.front();
    q.pop();
		cout<<tmp<<":"<<arr[tmp]<<endl;
		if (tmp == K) {
      break;
    }
		if(tmp-1>0 && arr[tmp-1]==-1){
    	q.push(tmp - 1);
			arr[tmp-1]=arr[tmp]+1;
		}
		if(tmp+1<=MAXSIZE && arr[tmp+1]==-1){
    	q.push(tmp + 1);
			arr[tmp+1]=arr[tmp]+1;
		}
		if(2*tmp>N && arr[2*tmp]==-1){
    	q.push(2 * tmp);
			arr[2*tmp]=arr[tmp]+1;
		}
  }
}

int main() {
  cin >> N >> K;
  bfs();
  cout << arr[K] << endl;
  return 0;
}
