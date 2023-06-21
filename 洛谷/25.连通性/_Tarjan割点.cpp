// https://www.luogu.com.cn/problem/P3388
// 关于tarjan算法，一直有一个很大的争议，
// 就是low[u]=min(low[u],dfn[v]);
// 这句话，如果改成low[u]=min(low[u],low[v])
// 就会wa掉，但是在求强连通分量时却没有问题
// 在求强连通分量时，如果v已经在栈中，那么说明u，v一定在同一个强连通分量中，
// 所以到最后low[u]=low[v]是必然的，提前更新也不会有问题，
// 但是在求割点时，low的定义有了小小的变化，
// 不再是最早能追溯到的祖先，（因为是个无向图）没有意义，
// 应该是最早能绕到的割点，为什么用绕到，是因为是无向边，
// 所以有另一条路可以走，如果把dfn[v]改掉就会上翻过头，可能翻进另一个环中，所以wa掉
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct Edge {
    int to;
    int next;
} e[N << 1];
int head[N], dfn[N], low[N];
int n, m, tim, cnt, tot;
bool cut[N];
void add(int x, int y) {
    e[++cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;
}
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++tim; // 初始化时间戳
    int child = 0; // 记录儿子的个数
    for(int i = head[u]; i; i = e[i].next) { // 遍历邻接点
        int to = e[i].to; // 把邻接点拿出来
        if(!dfn[to]) {
            tarjan(to, fa); // dfs更新信息
            if(low[to] >= dfn[u] && u != fa) { // 割点判断条件
                cut[u] = 1; // 标记为割点
            }
            if(u == fa) child++; // 如果是根节点，就child++
            low[u] = min(low[u], low[to]);
        }
        low[u] = min(low[u], dfn[to]); // 注意这句话
    }
    if(child >= 2 && u == fa) {
        cut[u] = 1;
    }
}
int main() {
    //freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    for(int i = 1; i <= n; i++) {
        if(!dfn[i]) {
            tarjan(i, i);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(cut[i]) tot++;
    }
    cout << tot << endl;
    for(int i = 1; i <= n; i++) {
        if(cut[i]) {
            cout << i << " ";
        }
    }
    return 0;
}