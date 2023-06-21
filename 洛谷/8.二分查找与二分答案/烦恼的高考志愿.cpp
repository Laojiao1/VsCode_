// 水题
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
typedef long long ll;
ll s1[N], s2[N];  
ll m, n;
ll ans = 0;
int main() {
    cin >> m >> n;
    for(int i = 1; i <= m; i++) cin >> s1[i];
    for(int i = 1; i <= n; i++) cin >> s2[i];
    sort(s1+1, s1+1+m);
    s1[0] = s1[1];
    for(int i = 1; i <= n; i++) {
        ll pos = upper_bound(s1+1, s1+1+m, s2[i]) - s1;
        ans += min(abs(s2[i] - s1[pos]), abs(s2[i] - s1[pos-1]));
    }
    cout << ans << endl;
    return 0;
}