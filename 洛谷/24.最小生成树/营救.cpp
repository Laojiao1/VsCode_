// https://www.luogu.com.cn/problem/P1396
// 依旧是裸的最小生成树
#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct Edge {
    int u, v, w;
} e[N];
int f[50005], n, m, s, t, cnt = 0;
bool temp = 0;
bool cmp(Edge e1, Edge e2) {
    return e1.w < e2.w;
}
int find(int x) { 
    if(f[x] == x) return x;
    else return f[x] = find(f[x]);
}
void kruskal() {
    sort(e, e+m, cmp); // 按照权值排序
    for(int i = 0; i < m; i++) {
        int eu, ev;
        eu = find(e[i].u);
        ev = find(e[i].v);
        if(eu == ev) continue; // 成环跳过
        f[ev] = eu; // 并查集合并
        if(find(s) == find(t)) { // 如果联通直接输出
            cout << e[i].w << endl;
            break;
        }
    }
}
int main() {
    //freopen("in.in", "r", stdin);
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for(int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    kruskal();
    return 0;
}