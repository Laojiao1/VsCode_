// https://www.luogu.com.cn/problem/P4933
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int MOD = 998244353;
int dp[N][4010], a[N], n;
// dp[i][j] 表示前i个数以公差为j所能组成的等差数列的个数
int ans = 0;
int main() {
    // freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int t = 20000;
    for(int i = 1; i <= n; i++) {
        ans = (ans + i) % MOD;
        for(int j = i-1; j >= 1; j--) {
            ans = (ans + dp[j][a[i] - a[j] + t]) % MOD;
            dp[i][a[i] - a[j] + t] = (dp[i][a[i] - a[j] + t] + dp[j][a[i] - a[j] + t] + 1) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}