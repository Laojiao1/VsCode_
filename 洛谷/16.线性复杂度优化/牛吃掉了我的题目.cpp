// https://www.luogu.com.cn/problem/P4086
// 前缀和思想（前缀和倒着用）
#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n;
double a[N], avr[N], sum[N], mn[N], mx;
int main() {
    // freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
       scanf("%lf", &a[i]);
    }
    for(int i = 1; i <= n+1; i++) {
        mn[i] = 99999; // 初始化最小值数组
    }
    // 预处理各各数组
    for(int i = n; i >= 2; i--) {
        mn[i] = min(mn[i+1], a[i]); // 求出从i到n内的最小值
        sum[i] = sum[i+1] + a[i]; // 求出从i到n的和
        if(i != n) { // 求出从i到n的平均值
            avr[i] = (sum[i] - mn[i]) / (double)(n - i);
        }
    }
    // 求出平均值最高的
    for(int i = 2; i <= n-1; i++) {
        mx = max(mx, avr[i]);
    }
    for(int i = 2; i <= n-1; i++) {
        if(mx == avr[i]) {
            cout << i-1 << endl;
        }
    }
    return 0;
}