#include <iostream>
#include <vector>
using namespace std;

int N;
int K;
int count=0;
vector<int> arr;

int main() {
    int tmp;
    int j;
    cin>>N>>K;
    for(int i=0;i<N;i++) {
        cin>>tmp;
        arr.push_back(tmp);
    }
    for(int i=N-1;i>=0;i--) {
        if(K!=0) {
            if (arr[i] <= K) {
                j = 1;
                while (arr[i] * j <= K) {
                    j++;
                }
                j--;
                count += j;
                K -= arr[i] * j;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}