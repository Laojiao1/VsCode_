#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const int N = 505;
struct Node {
    int to;
    int w;
    int weight;
    int next;
} e[N*2];
int cnt = 0, head[N];
int dis[N], num[N], weight[N], w[N];
// 起点到各点的最短距离，最短路径的数量，各个点拥有的救援队，起点到各个点的最大数量救援队
bool vis[N];
int pre[N];
int n, m, s, ed;
void add(int u, int v, int w) {
    e[++cnt].to = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}
void dfs(int v) {
    if(v == s) {
        cout << s;
        return;
    }
    dfs(pre[v]);
    cout << " " << v;
} 
void dijkstra(int s) {
    fill(w, w+N, 0);
    fill(vis, vis+N, 0);
    fill(dis, dis+N, INF);
    int now = s;
    dis[now] = 0; 
    num[now] = 1;
    w[now] = weight[now];
    while(vis[now] == 0) {
        int MIN = INF;
        vis[now] = 1;
        for(int i = head[now]; i; i = e[i].next) {
            int v = e[i].to;
            if(!vis[v] && dis[v] > dis[now] + e[i].w) {
                dis[v] = dis[now] + e[i].w;
                w[v] = w[now] + weight[v];
                pre[v] = now;
                num[v] = num[now];
            } else if(!vis[v] && dis[v] == dis[now] + e[i].w) {
                if(w[v] < w[now] + weight[v]) {
                    w[v] = w[now] + weight[v];
                    pre[v] = now;
                }
                num[v] += num[now];
            }
        }
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0 && dis[i] < MIN) {
                MIN = dis[i];
                now = i;
            }
        }
    }
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> n >> m >> s >> ed;
    for(int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    dijkstra(s);
    cout << num[ed] << " " << w[ed] << endl;
    dfs(ed);
    return 0;
}