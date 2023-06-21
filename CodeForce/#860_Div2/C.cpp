// 贪心
// cost % bi * di == 0 ——> cost % lcm(b1, b2, ..., bi) == 0
// ai % di == 0 ——> ai*bi % bi*di == 0 
//              ——> ai*bi % cost == 0
//              ——> gcd(a1*a2 ... ai*bi) % cost == 0
// lcm(b1, b2, ..., bi) % gcd(a1*a2 ... ai*bi) == 0

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 200005;
ll a[N];
ll b[N];
int n;
ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}
inline void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    ll g = 0;
    ll l = 1;
    ll ans = 1;
    for(int i = 1; i <= n; i++) {
        // 遍历前i种类型的糖果
        g = __gcd(g, a[i] * b[i]);
        l = lcm(l, b[i]);
        if(g % l) {
            // 不能整除了，ans+=1
            ans += 1;
            // 更新当前的g,l 继续遍历直到数组结束
            g = a[i] * b[i];
            l = b[i];
        }
    }
    cout << ans << endl;
    return;
}
int main() {
    //freopen("in.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}