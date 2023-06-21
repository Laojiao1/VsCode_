#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, s1;
    getline(cin, s1);
    getline(cin, s);
    int cnt = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'V' && s[i+1] == 'K') {
            cnt++;
            s[i] = s[i+1] = 'T';
        }
    }
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != 'T' && s[i] == s[i+1]) {
            cnt++;
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}