// https://www.luogu.com.cn/problem/P3387
// Tarjan + 缩点 + 拓扑排序
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+15;
int n, m, cnt, tim, top, cnt2;
int p[N], head[N], sd[N], dfn[N], low[N];
int stac[N], vis[N];
int head2[N], in[N], dis[N];
struct Edge {
    int to, next, from;
} e1[N*10], e2[N*10];
void add(int x, int y) {
    e1[++cnt].next = head[x];
    e1[cnt].to = y;
    e1[cnt].from = x;
    head[x] = cnt;
}
void tarjan(int x) {
    low[x] = dfn[x] = ++tim; // 初始化时间戳
    stac[++top] = x; // 入栈
    vis[x] = 1; // 标记以访问
    for(int i = head[x]; i; i = e1[i].next) { // 访问邻接点
        int v = e1[i].to;
        if(!dfn[v]) {
            tarjan(v); // 如果已经有前置时间戳就继续dfs
            low[x] = min(low[x], low[v]); // 更新时间戳
        } else if(vis[v]) { // 如果已经被访问过了
            low[x] = min(low[x], low[v]); // 仍然更新时间戳
        }
    }
    if(dfn[x] == low[x]) { // 把环缩成点
        int y;
        while(y = stac[top--]) {
            sd[y] = x;
            vis[y] = 0;
            if(x == y) break; // 回到了这个点就代表缩点完毕，退出
            p[x] += p[y]; // 把该强连通分量的所有权值都加起来保存起来
        }
    }
}
int Topsort() {
    queue<int> q; // 拓扑排序必备队列
    int tot = 0;
    for(int i = 1; i <= n; i++) {
        if(sd[i] == i && !in[i]) { // 入度为0的入队
            q.push(i);
            dis[i] = p[i];
        }
    }
    while(!q.empty()) {
        int temp = q.front(); q.pop();
        for(int i = head2[temp]; i; i = e2[i].next) { // 遍历邻接点
            int v = e2[i].to;
            dis[v] = max(dis[v], dis[temp] + p[v]); // DP一下
            in[v]--;// 当前结点入度-1
            if(in[v] == 0) q.push(v); // 入度为0了就继续入队
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dis[i]); // 找到最大的权值
    }
    return ans;
}
int main() {
    // freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> p[i]; // 读入权重
    }
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v); // 加边
    }
    for(int i = 1; i <= n; i++) {
        if(!dfn[i]) tarjan(i); // dfs更新信息
    }
    for(int i = 1; i <= m; i++) {
        int x = sd[e1[i].from], y = sd[e1[i].to];
        if(x != y) { // 如果不是同一个缩点
            e2[++cnt2].next = head2[x]; // 加边
            e2[cnt2].from = x;
            e2[cnt2].to = y;
            head2[x] = cnt2;
            in[y]++; // y的入度+1
        }
    }
    cout << Topsort() << endl;
    return 0;
}