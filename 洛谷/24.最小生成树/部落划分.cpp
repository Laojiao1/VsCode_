// https://www.luogu.com.cn/problem/P4047
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
struct Edge {
    int u, v;
    double w;
} e[1000001];
struct Node {
    int x, y;
} E[N];
int n, k, cnt = 0, tot = 0, id;
int f[N];
bool cmp(Edge e1, Edge e2) {
    return e1.w < e2.w;
}
void add(int x, int y, double w) {
    e[++cnt].u = x;
    e[cnt].v = y;
    e[cnt].w = w;
}
int find(int x) {
    if(x == f[x]) return x;
    else return f[x] = find(f[x]);
}
double distance(int a, int b) {
    return (double)(sqrt((double)(E[a].x - E[b].x) * (E[a].x - E[b].x) +
            (double)(E[a].y - E[b].y) * (E[a].y - E[b].y)));
}
void kruskal() {
    sort(e+1, e+1+cnt, cmp);
    for(int i = 1; i <= cnt; i++) {
        int eu, ev;
        eu = find(e[i].u);
        ev = find(e[i].v);
        if(eu == ev) continue;
        f[ev] = eu;
        if(++tot == n-k+1) {
            id = i;
            break;
        }
    }
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for(int i = 1; i <= n; i++) {
        cin >> E[i].x >> E[i].y;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            double dis = distance(i, j);
            add(i, j, dis);
        }
    }
    kruskal();
    printf("%.2lf\n", e[id].w);
    return 0;
}