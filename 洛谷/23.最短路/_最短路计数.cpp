// BFS 走一遍统计最短路的条数
// https://www.luogu.com.cn/problem/P1144
#include <bits/stdc++.h>
using namespace std;
const int MOD = 100003;
const int N = 2e6+5;
int n, m, cnt[N], dis[N];
vector<int> G[N];
queue<int> q;
bool vis[N];
int main() {
    //freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cnt[1] = 1;
    q.push(1);
    vis[1] = 1;
    dis[N] = 0;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = 0; i < G[x].size(); i++) { // 遍历邻接点
            int t = G[x][i];
            if(!vis[t]) {
                vis[t] = 1;
                dis[t] = dis[x] + 1;
                q.push(t);
            }
            if(dis[t] == dis[x] + 1) { // 计数
                cnt[t] = (cnt[t] + cnt[x]) % MOD;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << cnt[i] << endl;
    }
    return 0;
}