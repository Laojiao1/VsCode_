// 邻接表存图法
#include<bits/stdc++.h>
using namespace std;
int n,m;
set<int> E[100009]; // 用set默认排序
bool vis[100009];
void dfs(int x) {
    if(vis[x]) return; // 注意这里一定要有return
    vis[x] = 1; // 标记结点已经访问
    cout << x << " "; // 输出当前节点
    for(int v : E[x]) {
        dfs(v); // 开始遍历邻接点
    }
}
void bfs(int x) {
    queue<int> q;// BFS队列
    q.push(x);
    while(!q.empty()) {
        int x = q.front(); // 先把头元素拿出来
        q.pop(); // 紧跟出队
        if(vis[x]) continue; // 过滤掉已经访问过的结点
        vis[x] = 1; // 没访问的标记以访问
		cout << x << " "; // 输出结点
		for(int v : E[x]) // 遍历邻接点入队
            q.push(v);
    }
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        E[u].insert(v);
    }
    
    dfs(1);
    cout << endl;
    memset(vis, 0, sizeof(vis));
    bfs(1);
    return 0;
}