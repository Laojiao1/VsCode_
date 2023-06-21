// 一道很好的综合大题
// https://www.luogu.com.cn/problem/P1967
#include <bits/stdc++.h>
#define INF 999999999
using namespace std;
const int N = 1e4+5;
struct  Edge {
    int x, y, dis;
} e[50005];
struct edge {
    int to, next, w;
} E[100005];
int cnt, n, m, deep[N], d[N], head[N], w[N][21], fa[N][21], f[N];
bool vis[N];
void add(int x, int y, int w) {
    E[++cnt].next = head[x];
    E[cnt].to = y;
    E[cnt].w = w;
    head[x] = cnt;
    return;
}
bool cmp(Edge e1, Edge e2) {
    return e1.dis > e2.dis;
}
int find(int x) {
    if(x == f[x]) return x;
    else return f[x] = find(f[x]);
}
void kruskal() {
    sort(e+1, e+1+m, cmp);
    for(int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for(int i = 1; i <= m; i++) {
        if(find(e[i].x) != find(e[i].y)) {
            f[find(e[i].y)] = find(e[i].x);
            add(e[i].x, e[i].y, e[i].dis);
            add(e[i].y, e[i].x, e[i].dis);
        }
    }
    return;
}
void dfs(int node) {
    vis[node] = 1;
    for(int i = head[node]; i; i = E[i].next) {
        int to = E[i].to;
        if(vis[to]) continue;
        deep[to] = deep[node] + 1;
        fa[to][0] = node;
        w[to][0] = E[i].w;
        dfs(to);
    }
    return;
}
int lca(int x, int y) {
    if(find(x) != find(y)) return -1; // 如果不连通返回-1
    int ans = INF;
    if(deep[x] > deep[y]) swap(x, y); // 让y结点更深
    for(int i = 20; i >= 0; i--) {
        if(deep[fa[y][i]] >= deep[x]) {
            ans = min(ans, w[y][i]);
            y = fa[y][i];
        }
    }
    if(x == y) return ans;
    for(int i = 20; i >= 0; i--) {
        if(fa[x][i] != fa[y][i]) {
            ans = min(ans, min(w[x][i], w[y][i]));
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    ans = min(ans, min(w[x][0], w[y][0]));
    return ans;
}
int main() {
    freopen("in.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        e[i].x = x;
        e[i].y = y;
        e[i].dis = z;
    }
    kruskal();
    // DFS收集信息
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            deep[i] = 1;
            dfs(i);
            fa[i][0] = i;
            w[i][0] = INF;
        }
    }
    // LCA初始化
    for(int i = 1; i <= 20; i++) {
        for(int j = 1; j <= n; j++) {
            fa[j][i] = fa[fa[j][i-1]][i-1];
            w[j][i] = min(w[j][i-1], w[fa[j][i-1]][i-1]);
        }
    }
    int q;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", lca(x, y));
    }
    return 0;
}