// 数论 + 快速幂
// https://www.luogu.com.cn/problem/P3197
// ans = m^n - m*(m-1)^n-1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 100003;
ll func(ll base, ll power) {
    ll ans = 1;
    while(power) {
        if(power & 1) {
            ans = (ans * base) % mod;
        }
        power >>= 1;
        base = (base * base) % mod;
    }
    return ans;
}
int main() {
    ll m, n;
    scanf("%lld %lld",&m,&n);
    ll ans = func(m, n) - m*func(m-1, n-1)%mod;
    ans += mod; // 注意这里要加一个mod，因为减法可能会导致负数，这样的话再取模就不对了
    printf("%lld", ans % mod);
    return 0;
}