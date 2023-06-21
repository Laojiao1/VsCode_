// 用spfa算法求出每个结点的最长路径，最后输出dis[n]即可
// https://www.luogu.com.cn/problem/P1807
#include <bits/stdc++.h>
using namespace std;
queue<int> q;
const int maxn = 1505;
int dis[maxn], mp[maxn][maxn];
int n, m;
void bfs() {
    memset(dis, -1, sizeof(dis));
    dis[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        for(int i = 1; i <= n; i++) { // 搜索队列头部结点的边权
            if(mp[t][i] && dis[i] < dis[t] + mp[t][i]) {
                dis[i] = dis[t] + mp[t][i];
                q.push(i); // 入队继续搜索下一个结点
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mp[u][v] = max(w, mp[u][v]);
    }
    bfs();
    cout << dis[n] << endl;
    return 0;
}