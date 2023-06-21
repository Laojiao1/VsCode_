// https://www.luogu.com.cn/problem/P2015
// 这其实是一道树形背包题，感觉比没有上司的舞会更经典
#include <bits/stdc++.h>
using namespace std;
const int N = 105;
struct Node {
    int to;
    int next;
    int w;
} e[N*2];
int cnt, head[N];
int n, m, f[N][N], sizee[N];
// 设f[u][i]表示u的子树上保留i条边，至多保留的苹果数目
// sizee[u]表示u的子树上的边数，q就是题目中要求的最多保留边数
// f[u][i] = max(f[u][i], f[u][i−j−1] + f[v][j] + e[i].w) ( 1 ≤ i ≤ min(q,sz[u]), 0 ≤ j ≤ min(sz[v],i−1) )
void add(int x, int y, int w) {
    e[++cnt].to = y;
    e[cnt].w = w;
    e[cnt].next = head[x];
    head[x] = cnt;
}
void dfs(int u) {
    for(int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        dfs(v);
        sizee[u] += sizee[v] + 1;
        for(int j = min(sizee[u], m); j > 0; j--) { // u结点所取得边，注意不能取0条边
            for(int k = min(sizee[v], j-1); k >= 0; k--) { // 遍历u的邻接点v所取得边，可以选择不取
                f[u][j] = max(f[u][j], f[u][j-k-1] + f[v][k] + e[i].w);
            }
        }
    }
}
int main() {
    // freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    dfs(1);
    cout << f[1][m] << endl;
    return 0;
}