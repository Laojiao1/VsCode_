#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.length();
    for(int i = 0; i < len; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32;
        }
    }
    cout << s << endl;
    return 0;
}