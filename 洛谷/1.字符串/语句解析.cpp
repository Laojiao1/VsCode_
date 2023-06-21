#include <bits/stdc++.h>
using namespace std;
map<char, char> mp;
int cnt = 0;
int main() {
    mp['a'] = '0';
    mp['b'] = '0';
    mp['c'] = '0';
    string s;
    getline(cin, s);
    for(int i = 0; i < s.length(); i+=5) {
        if(s[i+3] >= '0' && s[i+3] <= '9') {
            // mp.insert(pair<char, char>(s[i], s[i+3]));
            mp[s[i]] = s[i+3];
        } else {
            mp[s[i]] = mp[s[i+3]];
        }
        cnt++;
    }
    cout << mp['a'] << " " << mp['b'] << " " << mp['c'] << endl;
    return 0;
}