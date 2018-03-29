#include <iostream>
#include <vector>
#define MAXSIZE 1000
using namespace std;

int N, K, k;

vector<int> arr;
vector<int> factbuff(MAXSIZE, 0);
int fact(int n) {
    if (n == 1) {
        return 1;
    } else if (n == 0) {
        return 0;
    }
    if (factbuff[n - 1] == 0) {
        factbuff[n - 1] = fact(n - 1);
    }
    return factbuff[n - 1] * n;
}

void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void f(int depth, int num) {
    if (depth >= N) {
        return;
    }
    int tmp = fact(N - depth);
    if ((num - 1) / tmp > 0) {
        swap(arr[depth], arr[depth + (num - 1) / tmp]);
        f(depth + 1, num % tmp);
    } else {
        f(depth + 1, num);
    }
}

int g(int depth){
    int tmp = fact(depth-1);
    if(depth==N){
        return 1;
    }
    cout<<tmp<<arr[depth]<<endl;
    return tmp*(arr[depth]-1)+g(depth+1);
}

int main() {
    cin >> N >> K;
    if (K == 1) {
        cin >> k;
        arr.push_back(0);
        for (int i = 1; i <= N; i++) {
            arr.push_back(i);
        }
        f(1, k);
        for (int i = 1; i <= N; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else if (K == 2) {
        int tmp;
        arr.push_back(0);
        for (int i = 0; i < N; i++) {
            cin >> tmp;
            arr.push_back(tmp);
        }
        cout<<g(1)<<endl;;
    }
    return 0;
}
