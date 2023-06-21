#include <bits/stdc++.h>
using namespace std;
int a, b;
int cnt;
int ans = 0;
int x, y;
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        if(a >= b) {
            cout << a - b << endl;
            continue;
        }
        ans = 2147483647;
        cnt = 0;
        x = a;
        y = b;
        while((x | y) != y) {
            x++;
            cnt++;
        }
        if(x != y) cnt ++;
        ans = min(ans, cnt);

        cnt = 0;
        x = a;
        y = b;
        while((x | y) != y) {
            y++;
            cnt++;
        }
        if(x != y) cnt ++;
        ans = min(ans, cnt);

        cout << ans << endl;
    }
    return 0;
}