// https://www.luogu.com.cn/problem/P1115
// 前缀和
// 方法一：DP
#include <bits/stdc++.h>
using namespace std;
int n;
int dp[10001]; // 表示从1到i之间(且必须包括i)的最大子段和
int temp, ans = -99999999;
int main() {
    freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        dp[i] = max(dp[i-1] + temp, temp);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
// 方法二：(其实也是DP)
// #include <bits/stdc++.h>
// using namespace std;
// const int maxn = 200005;
// int n, a[maxn], b[maxn], sum[maxn]; 
// int ans = -99999999;
// // sum[i]为从1到i的和，b[i]为从头到i的最大子段和 
// // b[i]等于sum[i] - min(sum[i], minn) (DP公式)
// int main() {
//     //freopen("in.in", "r", stdin);
//     cin >> n;
//     for(int i = 1; i <= n; i++) {
//         cin >> a[i];
//         sum[i] = a[i] + sum[i-1];// 计算前缀和
//     }
//     b[1] = a[1];
//     int minn = min(0, sum[1]);
//     for(int i = 2; i <= n; i++) {
//         b[i] = sum[i] - min(minn, sum[i]);
//     }
//     for(int i = 1; i <= n; i++) {
//         ans = max(ans, b[i]);
//     }
//     cout << ans << endl;
//     return 0;   
// }
