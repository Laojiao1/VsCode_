// 树的重心
// 给定一棵树，树中包含n个结点，找到树的重心并将其删除，
// 并输出剩余各个连通块中点数的最大值
// 9
// 1 4
// 1 2
// 2 6
// 2 5
// 6 3
// 6 7
// 7 9
// 7 8

// 4
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, ans = N;
bool vis[N];
int cnt = 0, head[N];
struct edge {
    int to;
    int next;
} e[N];
void add(int x, int y) {
    e[++cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;
}
int dfs(int u) {
    vis[u] = 1; // 标记以来过防止向上遍历
    int size = 0; // 记录u的最大子树的结点数
    int sum = 1; // 记录以u为根的子树的结点数
    for(int i = head[u]; i != -1 ; i = e[i].next) {
        int j = e[i].to; // 取出邻接点
        if(vis[j]) continue; // 避免向上查找
        int s = dfs(j); // s是以j为根的子树的结点数
        size = max(size, s);
        sum += s;
    }  
    ans = min(ans, max(size, n - sum));
    return sum;
}
int main() {
   // freopen("in.in", "r", stdin);
    memset(head, -1, sizeof(head));
    cin >> n;
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}