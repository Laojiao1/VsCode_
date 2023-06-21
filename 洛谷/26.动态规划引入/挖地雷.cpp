// https://www.luogu.com.cn/problem/P2196
#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int mp[N][N], a[N], pre[N];
int dp[N]; // 在i结点进行挖地雷，能最多挖到dp[i]个地雷 
// dp[i] = max(dp[i], dp[j] + a[i]) (mp[j][i] == 1)
int n, ans, pos;
void dfs(int x) {
    if(pre[x]) dfs(pre[x]);
    cout << x << " ";
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = a[i]; // 初始化
    }
    for(int i = 1; i < n; i++) {
        for(int j = i+1; j <= n; j++) {
            cin >> mp[i][j];
            mp[j][i] = mp[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i-1; j >= 1; j--) { // 倒着遍历
            if(mp[j][i] && dp[i] < dp[j] + a[i]) {
                dp[i] = dp[j] + a[i];
                pre[i] = j; // 记录i的前驱结点为j
            }
        }
        // 更新答案
        if(ans < dp[i]) {
            ans = dp[i];
            pos = i; // 记录最后到达的点，以便输出路径
        }
    }
    dfs(pos); // dfs输出路径
    cout << endl << ans << endl;
    return 0;
}