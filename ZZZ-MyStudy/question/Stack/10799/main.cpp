#include <iostream>
#include <stack>

using namespace std;

stack<char> S;
int cnt;
int res;

int main() {
    string str;
    cin >> str;
    for (char ch : str) {
        if (ch == '(') {
            cnt++;
            S.push(ch);
        } else if (S.empty() == false and S.top() == '(' and ch == ')') {
            cnt--;
            res += cnt;
            S.push(ch);
        } else if (S.empty() == false and S.top() == ')' and ch == ')') {
            cnt--;
            res += 1;
            S.push(ch);
        }
    }
    cout << res;
    return 0;
}