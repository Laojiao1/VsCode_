// https://www.luogu.com.cn/problem/P2121
// 依旧是kruskal算法
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
struct Edge {
    int u;
    int v;
    int w;
} e[N << 1];
int ans = 0, cnt = 0, f[N];
int n, m, k;
bool cmp(Edge e1, Edge e2) {
    return e1.w > e2.w;
}
int find(int x) {
    if(x == f[x]) return x;
    else return f[x] = find(f[x]); 
}
void kruskal() {
    sort(e+1, e+1+m, cmp);
    for(int i = 1; i <= m; i++) {
        int ev, eu;
        eu = find(e[i].u);
        ev = find(e[i].v);
        if(eu == ev) continue;
        f[ev] = eu;
        ans += e[i].w;
        if(++cnt == k) {
            break;
        }
    }
}
int main() {
    // freopen("in.in", "r", stdin);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for(int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    kruskal();
    cout << ans << endl;
    return 0;
}