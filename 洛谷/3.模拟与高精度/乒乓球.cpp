// P1042  字符串、模拟
// WWWWWWWWWWWWWWWWWWWW
// WWLWE
#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
char str[100010];
void solve(int n) {
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 1; i <= cnt; i++) {
        if(str[i] == 'W') cnt1++;
        if(str[i] == 'L') cnt2++;
        if((cnt1 >= n || cnt2 >= n) && abs(cnt1-cnt2) >= 2) {
            cout << cnt1 << ':' << cnt2 << endl;
            cnt1 = cnt2 = 0;
        }
    }
    cout << cnt1 << ':' << cnt2 << endl;
}

int main() {
    char ch;
    while(cin >> ch && ch != 'E') {
        if(ch == 'W' || ch == 'L') {
            str[++cnt] = ch;
        }
    }
    solve(11);
    cout << endl;
    solve(21);
    return 0;
}
