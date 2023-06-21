// https://www.luogu.com.cn/problem/P1439
// 方法一：该方法会被luogu的毒瘤数据卡死
#include <bits/stdc++.h>
using namespace std;
const int N = 2001;
int n, nums1[N], nums2[N];
int dp[1001][1001]; // nums1以i结束，nums2以j结束，所有的最长公共子序列dp[i][j]
int main() {
   // freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums1[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }
    for(int i = 1; i <= n; i++) {   
        for(int j = 1; j <= n; j++) {
            if(nums1[i] == nums2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}