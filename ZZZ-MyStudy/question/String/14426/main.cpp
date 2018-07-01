#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> arr1;
vector<string> arr2;
int N, M;
int result;

int main() {
    string tmp;
    cin >> N >> M;
    for (int n = 0; n < N; n++) {
        cin >> tmp;
        arr1.push_back(tmp);
    }
    for (int m = 0; m < M; m++) {
        cin >> tmp;
        arr2.push_back(tmp);
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int n = 0;
    int m = 0;
    int cmp;
    while (n < N && m < M) {
        cmp = arr1[n].compare(arr2[m]);
        if (cmp < 0) {
            if(arr1[n].find(arr2[m])==0){
                m++;
                result++;
                continue;
            }
            n++;
        } else if (cmp > 0) {
            if(arr1[n].find(arr2[m])==0){
                m++;
                result++;
                continue;
            }
            m++;
        } else {
            n++;
            m++;
            result++;
        }
    }
    cout<<result<<endl;
    return 0;
}
