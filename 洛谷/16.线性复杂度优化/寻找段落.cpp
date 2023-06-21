// 二分答案
// 我们将a全部减去mid，问题转化为:
// 判断是否存在一个长度在s~t范围内的区间它的和为正，
// 如果有说明还有更大的平均值。
// 用前缀和和单调队列维护。
// https://www.luogu.com.cn/problem/P1419
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, s, t;
double l, r, mid;
double a[maxn], sum[maxn];
double b[maxn];
int q[maxn];// 队列数组
bool check(double x) {
    int l = 1, r = 0;
    for(int i = 1; i <= n; i++) {
        b[i] = (double)a[i] - x;
    }
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + b[i]; // 预处理出来前缀和
    } 
    sum[0] = 0;
    for(int i = 1; i <= n; i++) {
        if(i - s >= 0) {
            while(l <= r && sum[i-s] < sum[q[r]]) r--; // 维护单调性
            q[++r] = i - s; // 把区间长度入队
        }
        if(l <= r && q[l] < i - t) l++;
        if(l <= r && sum[i] - sum[q[l]] >= 0) return true;
    }
    return false;
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> n >> s >> t;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    l = -10000; r = 10000;
    while(r - l > 1e-5) {
        mid = (l + r) / 2;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%.3lf\n", l);
    return 0;
}