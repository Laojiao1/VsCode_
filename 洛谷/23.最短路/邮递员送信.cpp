// https://www.luogu.com.cn/problem/P1629
// 裸的dijkstra算法
// 正着走过去的时候用一便dijkstra
// 返回时就建个返图跑一遍dijkstra
// 反图可以把所有结点的编号+n+n建在原图的体系中
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p> > q;
int inf = 2147483647;
int cnt = 0;
bool vis[N];
int head[N];
long long dis[N], ans = 0;
struct Node {
    int to;
    int w;
    int next;
} e[N];
int n, m;
void add(int x, int y, int z) {
    e[++cnt].to = y;
    e[cnt].w = z;
    e[cnt].next = head[x];
    head[x] = cnt;
}
void dijkstra(int now) {
    for(int i = 1; i <= n*2; i++) {
        dis[i] = inf;
    }
    dis[now] = 0;
    q.push(make_pair(0, now));
    while(!q.empty()) {
        int x = q.top().second;
        q.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        for(int i = head[x]; i; i = e[i].next) {
            if(dis[e[i].to] > dis[x] + e[i].w) {
                dis[e[i].to] = dis[x] + e[i].w;
                q.push(make_pair(dis[e[i].to], e[i].to));
            }
        }
    }
}
int main() {
    // freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v + n, u + n, w);
    }
    dijkstra(1);
    for(int i = 2; i <= n; i++) ans += dis[i];
    dijkstra(1 + n);
    for(int i = 2+n; i <= n*2; i++) ans += dis[i];
    cout << ans << endl;
    return 0;
}