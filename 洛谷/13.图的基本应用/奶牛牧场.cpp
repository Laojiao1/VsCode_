// https://www.luogu.com.cn/problem/P2853
// 从k个奶牛分别dfs，用mk[i]表示第i个牧场被遍历过多少次，
// 最后只有mk[i]==k的牧场满足条件。用邻接表存储。
#include <bits/stdc++.h>
using namespace std;
bool vis[1001];
int k, n, m, ans;
int mark[1010]; // 记录每个节点遍历次数
int a[1010]; // 记录奶牛所在的牧场编号
vector<int> v[1010];
void dfs(int x) {
    if(vis[x]) return;
    vis[x] = 1;
    mark[x]++;
    for(int i = 0; i < v[x].size(); i++) {
        if(!vis[v[x][i]]) { // 如果当前邻接点没有被访问
            dfs(v[x][i]); // 继续dfs
        }
    }
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> k >> n >> m;
    for(int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y); // 建边
    }
    for(int i = 1; i <= k; i++) {
        memset(vis, 0, sizeof(vis));
        dfs(a[i]); // 从每个奶牛所在农场开始遍历 
    }
    for(int i = 1; i <= n; i++) {
        if(mark[i] == k) ans++;
    }
    cout << ans << endl;
    return 0;
}