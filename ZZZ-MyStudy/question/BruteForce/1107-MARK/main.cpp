/*
5457
3
6 7 8
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define INF 0x6FFFFFF

using namespace std;

int N, M;
vector<int> ARR;

int main() {
    int tn;
    int max_val = 0;
    int min_val = 100;
    int res1;
    int res2 = 0;
    int tmp;
    int cur;
    int tnum;
    int cnt = 1;
    cin >> N >> M;
    tn = N;
    while (cnt <= N) {
        cnt *= 10;
        res2++;
    }
    cnt /= 10;
    ARR.resize(10, 1);
    for (int m = 1; m <= M; m++) {
        cin >> tmp;
        ARR[tmp] = 0;
    }
    for (int i = 0; i < 10; i++) {
        if (ARR[i] == 1) {
            max_val = max_val > i ? max_val : i;
        }
    }
    for (int i = 9; i >= 0; i--) {
        if (ARR[i] == 1) {
            min_val = min_val < i ? min_val : i;
        }
    }
    res1 = abs(N - 100);
    tnum = 0;
    while (cnt != 0) {
        tmp = N / cnt;
        cur = -100;
        for (int i = 0; i < 10; i++) {
            if (ARR[i] == 1) {
                cur = abs(cur - tmp) < abs(i - tmp) ? cur : i;
            }
        }
        if (cur == -100) {
            res2 = INF;
            tnum = 0;
            tn = 0;
            break;
        }
        //cout<<cur<<endl;
        tnum += cur;
        if(cnt==1){
            break;
        }
        if (cur > tmp) {
            while (cnt != 1) {
                tnum = tnum * 10 + min_val;
                cnt /= 10;
            }
            cnt /= 10;
        } else if (cur < tmp) {
            while (cnt != 1) {
                tnum = tnum * 10 + max_val;
                cnt /= 10;
            }
            cnt /= 10;
        } else {
            tnum = tnum * 10;
            N -= cur * cnt;
            cnt /= 10;
        }
    }
    //cout<<max_val<<min_val<<endl;
    cout<<tnum<<endl;
    res2 += abs(tnum - tn);
    cout << res1 << ":" << res2 << endl;
    cout << (res1 < res2 ? res1 : res2) << endl;
    return 0;
}