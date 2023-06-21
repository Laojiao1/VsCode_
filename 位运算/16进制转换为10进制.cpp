#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    long long ans = 0;
    for(int i = 0, j = s.length()-1; i < s.length(); i++, j--) {
        if(s[i] >= '0' && s[i] <= '9') {
            ans += (s[i] - '0') * pow(16, j);
        }
        if(s[i] >= 'A' && s[i] <= 'F') {
            ans += (s[i] - 'A' + 10) * pow(16, j); 
        }
    }
    cout << ans << endl;
    return 0;
}