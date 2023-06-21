#include <bits/stdc++.h>
using namespace std;
bool solve(int num) {
    if(num == 2) {
        return 1;
    }
    if(num == 0 || num == 1) {
        return 0;
    }
    int flag = 1;
    for(int i = 2; i < num; i++) {
        if(num % i == 0) {
            flag = 0;
        }
    }
    if(flag == 1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    string s;
    cin >> s;
    int len = s.length();
    int cnt = 0;
    int minn = 100000001, maxx = 0;
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            if(s[i] == s[j]) {
                cnt ++;
            }
        }
        minn = min(minn, cnt);
        maxx = max(maxx, cnt);
        cnt = 0;
    }
    int num = maxx - minn;
    // cout << maxx << " " << minn << endl;
    bool flag = solve(num);
    if(flag == 1) {
        cout << "Lucky Word" << endl;
        cout << num << endl;
    } else {
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }
    return 0;
}