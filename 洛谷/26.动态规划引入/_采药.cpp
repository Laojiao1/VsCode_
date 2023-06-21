// 经典01背包DP
// https://www.luogu.com.cn/problem/P1048
// 方法一：二维dp五部曲
#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int t, m;
int tim[N], value[N];
// 1. 确定dp数组及其下标含义
int dp[N][N]; // dp[i][j] 表示在前i个草药中所能摘取的最大总价值，且该总价值不大于j
int main() {
    //freopen("in.in", "r", stdin);
    cin >> t >> m;
    for(int i = 1; i <= m; i++) {
        cin >> tim[i] >> value[i];
    }
    // 3. dp数组初始化
    for(int j = tim[1]; j <= t; j++) {
        dp[1][j] = value[1]; 
    }
    // 4. 确定遍历顺序
    for(int i = 2; i <= m; i++) { // 遍历物品
        for(int j = 1; j <= t; j++) { // 遍历时间
            if(j < tim[i]) dp[i][j] = dp[i-1][j]; // 如果当前遍历的所需时间小于实际采摘物品需要的时间，就不摘这个物品
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-tim[i]] + value[i]); // 2.确定dp表达式
        }
    }
    cout << dp[m][t] << endl; // 5. 推导输出
    return 0;
}
// 方法二：一维滚动数组优化
// #include <bits/stdc++.h>
// using namespace std;
// int T, M;
// const int maxn = 1001;
// int t[maxn], m[maxn];
// int f[maxn];
// int main() {
//     cin >> T >> M;
//     for(int i = 1; i <= M; i++) {
//         cin >> t[i] >> m[i];
//     }
//     for(int i = 1; i <= M; i++) {
//         for(int l = T; l >= t[i]; l--) {
//             if(f[l - t[i]] + m[i] > f[l])
//             f[l] = f[l - t[i]] + m[i];
//         }
//     }
//     cout << f[T];
//     return 0;
// }