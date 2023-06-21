// https://www.luogu.com.cn/problem/P4057
// gcd 和 lcm 的关系
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, d;
ll ans;
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a*b / gcd(a, b);
}
int main() {
    cin >> a >> b >> c;
    d = lcm(a, b);
    ans = lcm(d, c);
    cout << ans << endl;
    return 0;
}