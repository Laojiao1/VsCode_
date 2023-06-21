// 快速幂板子题
// 求a^b mod n = ?
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll base, power, mod, ans = 1;
int main() {
    cin >> base >> power >> mod;
    ll a = base, b = power;
    while(power > 0) {
        if(power & 1) { // 如果为奇数
            ans = ans * base % mod;
        }
        power >>= 1;
        base = (base * base) % mod;
    }
    printf("%lld^%lld mod %lld=%lld\n", a, b, mod, ans);
    return 0;
}