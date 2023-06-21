// https://www.luogu.com.cn/problem/P1352
// 入门树形dp，很不错的一道题
#include <bits/stdc++.h>
using namespace std;
const int N = 6005;
struct Node {
    int to;
    int next;
} e[N];
int cnt, head[N];
int n, happy[N], vis[N];
int f[N][2]; 
// f[x][0]表示以x为根的子树,且x不参加舞会的最大快乐值
// f[x][1]表示以x为根的子树，且x参加了舞会的最大快乐值
void add(int x, int y) {
    e[++cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;
}
void dfs(int u) {
    f[u][1] = happy[u];
    f[u][0] = 0;
    for(int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        dfs(v);
        f[u][0] += max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
}
int main() {
    // freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> happy[i];
    }
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        add(b, a);
        vis[a] = 1;
    }
    int root;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            root = i;
            break;
        }
    } // 找到根节点，从根节点开始dfs
    dfs(root);
    cout << max(f[root][0], f[root][1]) << endl;
    return 0;
}