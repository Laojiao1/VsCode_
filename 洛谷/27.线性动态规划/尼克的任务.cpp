// https://www.luogu.com.cn/problem/P1280
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+1;
int n, k, num = 1;
int dp[N]; // i~n时间内尼克能获得的最大空暇时间
// 两种情况：1. 本时刻无任务: dp[i] = dp[i+1] + 1; （倒着遍历）
// 2. 本时刻有任务: dp[i] = max(dp[i], dp[i+tim[i]]);
struct Node {
    int p, t;
} a[N];
int cnt[N]; // 记录每个时间点的任务数量
bool cmp(Node a1, Node a2) {
    return a1.p > a2.p;
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> n >> k;
    for(int i = 1; i <= k; i++) {
        cin >> a[i].p >> a[i].t;
        cnt[a[i].p]++;
    }
    sort(a+1, a+1+k, cmp);
    for(int i = n; i >= 1; i--) {
        if(cnt[i] == 0) { // 如果当前时间没有任务
            dp[i] = dp[i+1] + 1; 
        } else {
            for(int j = 1; j <= cnt[i]; j++) { // 遍历重复的任务，选出花费时间最小的
                if(dp[i + a[num].t] > dp[i]) {
                    dp[i] = dp[i + a[num].t];
                }
                num++; // 记录已经扫过的任务数
            }
        }
    }
    cout << dp[1] << endl;
    return 0;
}