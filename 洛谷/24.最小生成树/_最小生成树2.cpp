// prim算法（跟Dijkstra）有点像
#include <bits/stdc++.h>
using namespace std;
int cnt_, head[5005], dis[5005], vis[5005];
int n, m, cnt, sum;
struct Edge {
    int to;
    int w;
    int next;
} e[400005];
typedef pair <int,int> p;
priority_queue <p,vector<p>,greater<p> > q;
void add(int x, int y, int w) {
    e[++cnt_].to = y;
    e[cnt_].w = w;
    e[cnt_].next = head[x];
    head[x] = cnt_;
}
void prim() {
    dis[1] = 0;
    q.push(make_pair(0, 1)); // 收录距离和结点信息
    while(!q.empty() && cnt < n) {
        int d = q.top().first;
        int now = q.top().second;
        q.pop();
        if(vis[now]) continue;
        cnt++;
        sum += d;
        vis[now] = 1;
        for(int i = head[now]; i; i = e[i].next) {
            if(dis[e[i].to] > e[i].w) {
                dis[e[i].to] = e[i].w;
                q.push(make_pair(dis[e[i].to], e[i].to));
            }
        }
    }
}
int main() {
   // freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        dis[i] = 9999999;
    }
    for(int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    prim();
    if (cnt == n) cout << sum << endl;
    else cout << "orz" << endl;
}