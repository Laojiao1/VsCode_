#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int n;
    cin >> n >> s;
    int len = s.length();
    for(int i = 0; i < len; i++) {
            s[i] = 'a' + (s[i] - 'a' + n) % 26;
    }
    cout << s << endl;
    return 0;
}