// https://www.luogu.com.cn/problem/P1433
#include <bits/stdc++.h>
using namespace std;
double x[16], y[16], f[16][100000]; // f[i][st]表示从i点开始，在状态st下的最短路径
int n;
double dis(int a, int b) {
    return sqrt( (x[a] - x[b]) * (x[a]-x[b]) + (y[a] - y[b]) * (y[a] - y[b]) );
}
void DP() {
    for(int i = 1; i <= n; i++) f[i][1<<(i-1)] = 0; //点到自身的距离为0
    for(int i = 1; i <= (1<<n)-1; i++) { // n个奶酪的所有状态
        for(int now = 1; now <= n; now++) {
            if((i & (1 << (now-1))) == 0) continue; // 跳过未访问的点
            for(int pre = 1; pre <= n; pre++) {
                if((i & (1 << (pre-1))) != 0) { // 保证i状态中pre那一位是1，即上个点有走过
                    f[now][i] = min(f[now][i], f[pre][i - (1 << (now-1))] + dis(pre, now));
                }
            }
        }
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    memset(f, 127, sizeof(f)); // 初始化点在各种状况下的距离
    DP();
    double minn = 0x3f3f3f3f; // 初始化为很大的数
    for(int i = 1; i <= n; i++) {
        if(f[i][(1 << n)-1] + dis(0, i) < minn) {
            minn = f[i][(1 << n)-1] + dis(0, i);
        }
    }
    printf("%.2lf", minn);
    return 0;
}