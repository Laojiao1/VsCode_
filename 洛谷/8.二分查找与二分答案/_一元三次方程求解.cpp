// 二分逼近 https://www.luogu.com.cn/problem/P1024
#include <bits/stdc++.h>
using namespace std;
double a, b, c, d;
double func(double x) {
    return a*pow(x, 3) + b*pow(x, 2) + c*x + d;
}
int main() {
    cin >> a >> b >> c >> d;
    double l, r, mid, x1, x2;
    for(int i = -100; i < 100; i++) {
        l = i;
        r = i + 1;
        x1 = func(l);
        x2 = func(r);
        if(x1 == 0) {
            printf("%.2lf ", l);
        }
        if(x1 * x2 < 0) {
            while((r-l) >= 0.001) {
                mid = (l + r) / 2;
                if(func(mid) * func(r) <= 0) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            printf("%.2lf ", l);
        }
    }
    return 0;
}