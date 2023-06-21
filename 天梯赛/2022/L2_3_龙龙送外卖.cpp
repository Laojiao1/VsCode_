#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int n, m, root;
int vis[N], depth[N], b[N], cnt[N];
struct Node {
    int to;
    int next;
} e[2 * N];
int head[N], tot;
void add(int x, int y) {
    e[++tot].to = y;
    e[tot].next = head[x];
    head[x] = tot;
}
void dfs(int x) {
    for(int i = head[x]; i; i = e[i].next) {
        int v = e[i].to;
        depth[v] = depth[x] + 1;
        dfs(v);
        vis[x] = min(vis[x], vis[v]);
        // 回溯的时候更新出现的时间点，如果有之前走过的就更新 
    }
    if(x != root) cnt[vis[x]]++; // 统计走过的时间点
}
int main() {
    freopen("in.in","r", stdin);
    cin >> n >> m;
    int a;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        vis[i] = 2147483647;
        if(a == -1) {
            root = i; // 找到根节点
        }
        add(a, i);
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        vis[b[i]] = min(vis[b[i]], i); // 记录每个送外卖点出现的时间
    }
    dfs(root);
    int sum = 0;
    int maxx = 0;
    for(int i = 1; i <= n; i++) {
        cout << cnt[i] << " ";
    }
    for(int i = 1; i <= m; i++) {
        sum += cnt[i];
        maxx = max(maxx, depth[b[i]]);
        //cout << sum * 2 - maxx << endl;
    }
    return 0;
}