// https://www.luogu.com.cn/problem/P2014
// 和二叉苹果树类似，也是一个树形背包题
#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
struct Node {
    int to;
    int next;
} e[N];
int head[N], cnt;
int n, m, f[N][N], sizee[N], w[N];
void add(int x, int y) {
    e[++cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;
}
void dfs(int u) {
    for(int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        dfs(v);
        sizee[u] += sizee[v] + 1;
        for(int j = min(sizee[u], m); j > 0; j--) {
            for(int k = min(sizee[v], j-1); k >= 0; k--) {
                f[u][j] = max(f[u][j], f[u][j-k-1] + f[v][k] + w[i]);
            }
        }
    }
}
int main() {
    // freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int father;
        cin >> father >> w[i];
        add(father, i);
    }
    dfs(0);
    cout << f[0][m] << endl;
    return 0;
}