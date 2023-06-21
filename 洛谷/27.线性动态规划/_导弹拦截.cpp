// https://www.luogu.com.cn/problem/P1020
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int dp[N], nums[N], vis[N]; // dp[i] 表示前i个数字中递减序列的最大长度
int ans1 = 0, ans2 = 0;
int main() {
    freopen("in.in", "r", stdin);
    int cnt = 0;
    while(cin >> nums[++cnt]);
    cnt--;
    // for(int i = 1; i <= cnt; i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    // 第一问
    for(int i = 1; i <= cnt; i++) dp[i] = 1;
    for(int i = 1; i <= cnt; i++) {
        for(int j = 1; j < i; j++) {
            if(nums[i] <= nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if(ans1 < dp[i]) ans1 = dp[i];
    }
    // for(int i = 1; i <= cnt; i++) {
    //     cout << dp[i] << " ";
    // }
    cout << ans1 << endl;
    int s = 0;
    while(s < cnt) {
        int maxx = 9999999;
        for(int i = 1; i <= cnt; i++) {
            if(nums[i] <= maxx && !vis[i]) {
                s++;
                maxx = nums[i];
                vis[i] = 1;
            }
        }
        ans2++;
    }
    cout << ans2 << endl;
    return 0;
}