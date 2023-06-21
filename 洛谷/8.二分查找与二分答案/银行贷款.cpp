// 依旧是二分枚举答案
// 需要点财政知识emmm其实就是数学知识
// https://www.luogu.com.cn/problem/P1163
#include <bits/stdc++.h>
using namespace std;
double n, m, k;
double l, r, mid;
double ans = 0;
bool pd(double x) {
    return pow(1.0/(1.0 + x), k) >= 1 - x/m * n;
}
int main() {
    cin >> n >> m >> k;
    l = 0, r = 10;
    while(r - l >= 0.0001) { // 注意精度
        mid = (l + r) / 2;
        if(pd(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%.1lf\n", l*100);
    return 0;
}