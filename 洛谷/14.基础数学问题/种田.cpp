// 简简单单的数学题
// https://www.luogu.com.cn/problem/P2660
#include <bits/stdc++.h>
using namespace std;
long long a, b, c, ans;
int main() {
    cin >> a >> b;
    while(a && b) {
        c = min(a, b);
        if(a == c) {
            ans += 4 * c * (b / a);
            b %= a;
        } else {
            ans += 4 * c * (a / b);
            a %= b;
        }
    }
    cout << ans << endl;
    return 0;
}
