// 二维版本的求最大子段和
// https://www.luogu.com.cn/problem/P1719
#include <bits/stdc++.h>
using namespace std;
int n, mp[200][200];
int ans = 0;
int main() {
    //freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> mp[i][j];
            mp[i][j] += mp[i-1][j]; // 压缩求和
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int k = 1; k <= i; k++) {
            // 开始dp
            int f[200] = {0}; // f[j]表示第j列压缩矩阵的值  
            int dp[200] = {0}; // dp[j]表示从第i列到第j列压缩矩阵值的和
            for(int j = 1; j <= n; j++) {
                f[j] = mp[i][j] - mp[i-k][j];
                dp[j] = max(dp[j-1] + f[j], f[j]);
                ans = max(ans, dp[j]); // 更新最大值
            }
        }
    }
    cout << ans << endl;
    return 0;
}