#include <iostream>
#include <stack>
#include <vector>
using namespace std;

string str1;
string str2;
vector<char> s;
stack<char> ts;

int main() {
    bool sw;
    cin >> str1 >> str2;
    for (char atom:str1) {
        s.push_back(atom);
        if (atom == str2[str2.length() - 1]) {
            sw = true;
            for (int i = str2.length() - 1; i >= 0; i--) {
                if (s[s.size()-1] == str2[i]) {
                    ts.push(s[s.size()-1]);
                    s.pop_back();
                } else {
                    sw = false;
                }
            }
            if(!sw){
                while(!ts.empty()){
                    s.push_back(ts.top());
                    ts.pop();
                }
            }else{
                while(!ts.empty()){
                    ts.pop();
                }
            }
        }
    }
    if(s.empty()){
        cout<<"FRULA";
    }else{
        for (char atom:s){
            cout<<atom;
        }
    }
    cout<<endl;
    return 0;
}