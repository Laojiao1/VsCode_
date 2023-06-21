// 求从有向图每个点开始能达到的编号最大的点
// https://www.luogu.com.cn/problem/P3916
// 思路：反向建边 + dfs
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> G[100010];
int ans[100010];
void dfs(int u, int v) {
    if(ans[u]) return;
    ans[u] = v; 
    for(int i = 0; i < G[u].size(); i++) {
        dfs(G[u][i], v);
    }
}
int main() {
    int u, v;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        G[v].push_back(u); // 反向建边
    }
    for(int i = n; i >= 1; i--) {
        dfs(i, i);
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}