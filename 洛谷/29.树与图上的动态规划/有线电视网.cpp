// https://www.luogu.com.cn/problem/P1273
// 树形背包dp
#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
struct Node {
    int to;
    int w;
    int next;
} e[N];
int head[N], cnt;
int n, m, f[N][N], sizee[N], val[N];
// f[i][j]表示从第i个结点选j个用户所能得到的最大利润
void add(int x, int y, int w) {
    e[++cnt].to = y;
    e[cnt].w = w;
    e[cnt].next = head[x];
    head[x] = cnt;
}
int dfs(int u) {
    if(u > n-m) {
        f[u][1] = val[u];
        return 1;
    }
    int sum = 0, temp;
    for(int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        temp = dfs(v);
        sum += temp;
        for(int j = sum; j; j--) {
            for(int k = 1; k <= j; k++) {
                f[u][j] = max(f[u][j], f[u][j-k] + f[v][k] - e[i].w);
            }
        }
    }
    return sum;
}
int main() {
    freopen("in.in", "r", stdin);
    memset(f, ~0x3f, sizeof(f));
    cin >> n >> m;
    for(int i = 1; i <= n-m; i++) {
        int num;
        cin >> num;
        while(num--) {
            int a, b;
            cin >> a >> b;
            add(i, a, b);
        }
    }
    for(int i = n-m+1; i <= n; i++) {
        cin >> val[i];
    }
    for(int i = 1; i <= n; i++) {
        f[i][0] = 0;
    }
    dfs(1);
    for(int i = m; i >= 1; i--) {
        if(f[1][i] >= 0) {
            cout << i;
            break;
        }
    }
    return 0;
}