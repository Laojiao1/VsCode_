// https://www.luogu.com.cn/problem/P2651
#include <bits/stdc++.h>
using namespace std;
int a[10010], n, t;
int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}
int main() {
    // freopen("in.in", "r", stdin);
    cin >> t;
    while(t--) {
        cin >> n >> a[1] >> a[2];
        a[2] /= gcd(a[1], a[2]);
        for(int i = 3; i <= n; i++) {
            cin >> a[i];
            a[2] /= gcd(a[2], a[i]);
        }
        if(a[2] == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}