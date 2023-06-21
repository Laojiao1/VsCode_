#include <bits/stdc++.h>
using namespace std;
const int maxn = 100050;
bool dp[105][maxn]; // 注意这里要设置为bool类型
// dp数组定义：dp[i][j] 表示前i个砝码能否称出重量j
int n, w[105], sum;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
        sum += w[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(j == w[i]) {
                dp[i][j] = dp[i-1][j] + 1;
            } else {
                dp[i][j] = dp[i-1][j] + dp[i-1][abs(j - w[i])];
            }
            // f[i][j] = f[i-1][j]||f[i-1][abs(j-w[i])];	//一种情况为true就为true
        }
    }
    long long ans = 0;
    for(int i = 1; i <= sum; i++) {
        if(dp[n][i] != 0)
            ans += dp[n][i]; 
    }
    cout << ans << endl;
    return 0;
}