#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int cnt = 1;
    getline(cin, s);
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == s[i+1] && s[i+1] != ' ') {
            cnt++;
        } else {
            if(s[i] != ' ') {
                cout << cnt << s[i];
                cnt = 1;
            }
        }
        if(s[i] == ' ' && s[i+1] != '\0') {
            cout << '-';
        }
    }
    return 0;
}