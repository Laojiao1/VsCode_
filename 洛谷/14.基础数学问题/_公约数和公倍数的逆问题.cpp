// https://www.luogu.com.cn/problem/P1072
// 根据一系列推导的得出结论：gcd(x/a1, a/a1) = 1; gcd(b1/b, b1/x) = 1;
// 思路：枚举x, 使x为a1的倍数并且满足上述两个式子(其中以x为b1的因子作为限制条件)
#include <bits/stdc++.h>
using namespace std;
int n, a, a1, b, b1;
int gcd(int x, int y) {
    if(y == 0) return x;
    else return gcd(y, x % y);
}
int main() {
   // freopen("in.in", "r", stdin);
    cin >> n;
    while(n--) {
        int ans = 0;
        cin >> a >> a1 >> b >> b1;
        int p = a/a1;
        int q = b1/b;
        for(int x = 1; x <= sqrt(b1); x++) {
            if(b1 % x == 0) {
                if(x % a1 == 0 && gcd(x/a1, p) == 1 && gcd(q, b1/x) == 1) {
                    ans++;
                }
                int y = b1/x; // 找出另外一个因子
                if(x == y) continue;
                if(y % a1 == 0 && gcd(y/a1, p) == 1 && gcd(q, b1/y) == 1) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}