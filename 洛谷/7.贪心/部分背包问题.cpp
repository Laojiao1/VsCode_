// 没啥技巧
// 就是被别标题骗了 这就是个单纯的贪心
#include <bits/stdc++.h>
using namespace std;
int n;
double w;
double sum = 0;
struct bag {
    double m;
    double v;
    double value;
} a[105];
bool cmp(bag a1, bag a2) {
    return a1.value > a2.value;
}
int main() {
    cin >> n >> w;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].m >> a[i].v;
        a[i].value = a[i].v / a[i].m;
    }
    sort(a+1, a+1+n, cmp);
    for(int i = 1; i <= n; i++) {
        if(a[i].m <= w) {
            w -= a[i].m;
            sum += a[i].v;
        } else {
            sum += w * a[i].value;
            break;
        }
    }
    printf("%.2lf\n", sum);
    return 0;
}