#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int N;
vector<int> arr;
int maxVal;

int main() {
    int tmp;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end(),greater<int>());
    for(int i=0;i<N;i++){
        maxVal = maxVal>arr[i]*(i+1)?maxVal:arr[i]*(i+1);
    }
    cout<<maxVal<<endl;
    return 0;
}