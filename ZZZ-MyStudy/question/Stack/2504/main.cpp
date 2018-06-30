#include <iostream>
#include <stack>
#include <queue>

#define AS 0x6FFFFFFF
#define AE 0x6FFFFFFE
#define BS 0x6FFFFFFD
#define BE 0x6FFFFFFC
using namespace std;

stack<int> s;
queue<int> q;

bool isDigit(int num) {
    if (num == AS || num == AE || num == BS || num == BE) {
        return false;
    }
    return true;
}

int main() {
    int deb=1;
    int cnt;
    int ready;
    int res;
    bool output = true;
    string tmp;
    cin >> tmp;
    cnt = tmp.length();
    for (int i = 0; i < cnt; i++) {
        ready = tmp.at(0);
        if (ready == '(') {
            q.push(AS);
        } else if (ready == ')') {
            q.push(AE);
        } else if (ready == '[') {
            q.push(BS);
        } else {
            q.push(BE);
        }
        tmp = tmp.substr(1);
    }
    while (!q.empty()) {
        ready = q.front();
        q.pop();
        //cout<<deb++<<endl;
        if (s.empty()) {
            s.push(ready);
        } else {
            if (ready == AE) {
                res = 0;
                if(s.empty()){
                    output = false;
                    break;
                }
                while (isDigit(s.top())) {
                    res += s.top();
                    s.pop();
                    if(s.empty()){
                        output = false;
                        break;
                    }
                }
                if (res == 0) {
                    res = 1;
                }
                if(s.empty()){
                    output = false;
                    break;
                }
                if (s.top() == AS) {
                    s.pop();
                    res *= 2;
                    s.push(res);
                } else {
                    output = false;
                    break;
                }
            } else if (ready == BE) {
                res = 0;
                if(s.empty()){
                    output = false;
                    break;
                }
                while (isDigit(s.top())) {
                    res += s.top();
                    s.pop();
                    if(s.empty()){
                        output = false;
                        break;
                    }
                }
                if (res == 0) {
                    res = 1;
                }
                if(s.empty()){
                    output = false;
                    break;
                }
                if (s.top() == BS) {
                    s.pop();
                    res *= 3;
                    s.push(res);
                } else {
                    output = false;
                    break;
                }
            } else {
                s.push(ready);
            }
        }
    }
    res = 0;
    while(!s.empty()){
        if(!isDigit(s.top())){
            output = false;
            break;
        }
        res+=s.top();
        s.pop();
    }
    if (!output) {
        cout << 0 << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}
