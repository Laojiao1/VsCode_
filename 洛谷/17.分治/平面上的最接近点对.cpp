// 暴力求解
#include <bits/stdc++.h>
using namespace std;
typedef double ll;
const int N = 1e4+5;
ll n, ans = 1 << 30;
ll x[N], y[N];
ll distance(ll x1, ll y1, ll x2, ll y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int main() {
    //freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        for(int j = i-1; j >= 1; j--) {
            ans = min(ans, distance(x[j], y[j], x[i], y[i]));
        }
    }
    cout << fixed << setprecision(4) << ans << endl;
    return 0;
}