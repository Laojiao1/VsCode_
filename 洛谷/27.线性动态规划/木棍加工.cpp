// https://www.luogu.com.cn/problem/P1233
// 问题转化为求最长上升子序列
// 根据dilworth定理：最少分割为多少个不上升子序列 = 最长上升子序列
#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
struct Node {
    int l, w;
} a[N];
int n, dp[N]; // dp[i] 表示前i个数中最长上升子序列
int ans = -1;
bool cmp(Node a1, Node a2) {
    if(a1.l != a2.l) {
        return a1.l > a2.l;
    } else {
        return a1.w > a2.w;
    }
}
int main() {
    //freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].w;
    }
    sort(a, a+n, cmp);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i].w > a[j].w) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans+1 << endl;
    return 0;
}