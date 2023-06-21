// https://www.luogu.com.cn/problem/P1122
// 找树中以某个结点为根的最大权值和的子树
#include <bits/stdc++.h>
using namespace std;
const int N = 16005;
struct Node {
    int to;
    int next;
} e[N<<1]; // 无向图别忘记开2倍
int head[N], cnt;
int n, f[N], a[N]; // f[i]表示以i为结点所形成的权值最大的子树
void add(int x, int y) {
    e[++cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;
}
void dfs(int u, int father) {
    for(int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if(v != father) {
            dfs(v, u);
            f[u] = f[u] + (f[v] > 0 ? f[v] : 0);
        }
    }
}
int main() {
   // freopen("in.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        f[i] = a[i];
    }
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    int ans = -2147483647;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, f[i]);
    }
    printf("%d", ans);
    return 0;
}