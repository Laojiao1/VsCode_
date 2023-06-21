// https://www.luogu.com.cn/problem/P1195
// 最小生成树
#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct Edge {
    int u, v, w;
} e[N << 1];
int f[5005], n, m, k, ans = 0, cnt = 0;
bool temp = 0;
bool cmp(Edge e1, Edge e2) {
    return e1.w < e2.w;
}
int find(int x) { 
    if(f[x] == x) return x;
    else return f[x] = find(f[x]);
}
void kruskal() {
    sort(e+1, e+m+1, cmp); // 按照权值排序
    for(int i = 1; i <= m; i++) {
        int eu, ev;
        eu = find(e[i].u);
        ev = find(e[i].v);
        if(eu == ev) continue; // 成环跳过
        ans += e[i].w;
        f[ev] = eu; // 并查集合并
        if(++cnt == n-k) { 
            temp = 1;
            break;
        }
    }
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for(int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    kruskal();
    if(temp) cout << ans << endl;
    else cout << "No Answer" << endl;
    return 0;
}