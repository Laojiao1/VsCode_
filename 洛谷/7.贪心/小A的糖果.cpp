// 水题
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, x;
ll a[100010];
ll ans = 0;
int main() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        if(a[i-1] + a[i] > x) {
            ll num = a[i-1] + a[i] - x;
            a[i] -= num;
            if(a[i] < 0) {
                a[i] = 0;
                a[i-1] -= num - a[i];
            } // 这块判断有没有都行..
            ans += num;
        }
    }
    cout << ans << endl;
    return 0;
}