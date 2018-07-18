#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class St {
public:
    int num;
    int height;

    St() {}

    St(int num, int height) : num(num), height(height) {}
};

int N;
int cnt;
stack<St> s;
vector<int> res;

int main() {
    int tmp;
    cin >> N;
    for (int n = 1; n <= N; n++) {
        cin >> tmp;
        cnt++;
        while (true) {
            if (s.empty()) {
                res.push_back(0);
                s.push(St(cnt, tmp));
                break;
            } else {
                if (s.top().height > tmp) {
                    res.push_back(s.top().num);
                    s.push(St(cnt,tmp));
                    break;
                } else {
                    s.pop();
                }
            }
        }
    }
    for(int atom:res){
        cout<<atom<<" ";
    }
    cout<<endl;
    return 0;
}