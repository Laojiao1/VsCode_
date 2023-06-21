// 跟修路那道题一样的思路
#include <bits/stdc++.h>
using namespace std;
const int N = 5000100;
int n, m;
// 存坐标
struct Edge {
    int x;
    int y;
} E[N];
// 存边
struct edge {
    double u;
    double v;
    double w;
} e[N];
int cnt1 = 0, cnt2 = 0, f[N];
double sum = 0.0;
bool cmp(edge e1, edge e2) {
    return e1.w < e2.w;
}
double distance(int a, int b) {
    return (double)(sqrt((double)(E[a].x - E[b].x) * (E[a].x - E[b].x) +
            (double)(E[a].y - E[b].y) * (E[a].y - E[b].y)));
}
void add(int x, int y, double z) {
    e[++cnt1].u = x;
    e[cnt1].v = y;
    e[cnt1].w = z;
}
int find(int x) {
    if(x == f[x]) return x;
    else return f[x] = find(f[x]);
}
void kruskal() {
    sort(e + 1, e + 1 + cnt1, cmp);
    for(int i = 1; i <= cnt1; i++) {
        int eu, ev;
        eu = find(e[i].u);
        ev = find(e[i].v);
        if(eu == ev) continue;
        f[ev] = eu;
        sum = e[i].w;
        if(++cnt2 == n - m) {
            break;
        }
    }
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> m >> n;
    for(int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for(int i = 1; i <= n; i++) {
        cin >> E[i].x >> E[i].y;
    }
    // 求每个点之间的距离并存入边中
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            double z = distance(i, j);
            add(i, j, z);
        }
    }  
    kruskal();
    printf("%.2lf\n", sum);
    return 0;
}