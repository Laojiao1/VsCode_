#include <bits/stdc++.h>
using namespace std;
const int N = 25001;
char str[N];
int cnt = 0;
void solve(int n) {
    int a = 0, b = 0;
    for(int i = 0; i < cnt; i++) {
        if(str[i] == 'W') a ++;
        if(str[i] == 'L') b ++;
        if((a >= n || b >= n) && abs(a-b) >= 2) {
            cout << a << ":" << b << endl;
            a = b = 0;
        }
    }
    cout << a << ":" << b << endl;
}
int main() {
    char c;
    while(cin >> c && c != 'E') {
        if(c == 'W' || c == 'L') {
            str[cnt++] = c;
        }
    }
    solve(11);
    cout << endl;
    solve(21);
    return 0;
}