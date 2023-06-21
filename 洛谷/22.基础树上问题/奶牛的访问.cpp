// https://www.luogu.com.cn/problem/P5836
// 本题标签是LCA，但感觉并不需要
// 并查集：一共两种颜色，将颜色相同的区域合并起来，与目标进行对比，
// 当两端点属于同一个连通块且与目标颜色不同时输出0。
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int fa[N], ans[N], m, n;
char cow[N];
int find(int x) {
    if(x == fa[x]) return x;
    else return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    fa[find(x)] = find(y);
}
int main() {
    //freopen("in.in", "r", stdin);
    int cnt = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
        cin >> cow[i];
    }
    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;
        if(cow[u] == cow[v]) merge(u, v); // 如果两端点为同一个颜色，合并
    }
    for(int i = 1; i <= m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        if(find(a) == find(b) && cow[a] != c) ans[++cnt] = 0;
        // 如果两端点属于同一个连通块(同一种颜色), 且与目标颜色不一致时输出0
        else ans[++cnt] = 1; // 其余情况都满足，输出1
    }
    for(int i = 1; i <= cnt; i++) {
        cout << ans[i];
    }
    return 0;
}