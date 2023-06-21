// https://www.luogu.com.cn/problem/P3143
// 贪心，枚举
#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int a[N], c[N] = {0}; // c[i]存储从i向左能取多少钻石
int n, k;
int r = 1; // 指针
int temp, ans = 0;
int main() {
    freopen("in.in", "r", stdin);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    a[n+1] = 999999999; // 建立哨兵，防止r跑丢
    for(int i = 1; i <= n; i++) {
        while(a[r] - a[i] <= k) r++;
        c[r] = max(c[r], r-i);
        temp = max(temp, c[i]);// 记录第i颗钻石前摆的最多的钻石
        ans = max(ans, temp + r - i);
    }
    cout << ans << endl;
    return 0;
}