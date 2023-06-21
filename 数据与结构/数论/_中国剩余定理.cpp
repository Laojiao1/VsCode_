// https://www.luogu.com.cn/problem/P1495
// 中国剩余定理（CRT）构造法：
// 1. 计算所有模数的乘积M
// 2. 计算第i个方程的Ci = M / mi
// 3. 计算ci在mi意义下的逆元Ci^-1
// 4. x = 求和ri*Ci*Ci^-1(mod M)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class solution {
    public:
    ll exgcd(ll a, ll b, ll &x, ll& y) { // 欧几里得算法求乘法逆元
        if(b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        ll d, x1, y1;
        d = exgcd(b, a%b, x1, y1);
        x = y1, y = x1 - a / b * y1;
        return d;
    }
    ll CRT(ll m[], ll r[]) {
        ll M = 1, ans = 0;
        int n;
        for(int i = 1; i <= n; i++) {
            M *= m[i];
        }
        for(int i = 1; i <= n; i++) {
            ll c = M / m[i], x, y;
            exgcd(c, m[i], x, y);
            ans = (ans + r[i] * c * x % M) % M;
        }
        return (ans % M + M) % M;
    }
};
int main() {

    return 0;
}
