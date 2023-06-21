// https://www.luogu.com.cn/problem/P1572
// 直接模拟即可
#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
    if(y == 0) return x;
    else return gcd(y, x % y);
}
int main() {
    //freopen("in.in", "r", stdin);
    int a, b, c, d;
    scanf("%d/%d", &a, &b);
    while(scanf("%d/%d", &c, &d) != EOF) {
        int m = gcd(b, d);
        a *= d / m;
        c *= b / m;
        a += c;
        b *= d / m;
        int n = gcd(a, b); // 约分
        a /= n;
        b /= n;
    }
    if(b < 0) {
        b = -b;
        a = -a;
    }
    if(b == 1) cout << a;
    else cout << a << "/" << b << endl;
    return 0;
}