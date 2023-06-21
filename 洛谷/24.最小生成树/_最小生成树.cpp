// https://www.luogu.com.cn/problem/solution/P3366
// 最小生成树模板， Kruskal算法
// 先把边按照权值进行排序，用贪心的思想优先选取权值较小的边，
// 并依次连接，若出现环则跳过此边（用并查集来判断是否存在环）继续搜，
// 直到已经使用的边的数量比总点数少一即可
#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct Edge {
    int u, v, w;
} e[N];
int f[5005], n, m, ans = 0, cnt = 0;
bool temp = 0;
bool cmp(Edge e1, Edge e2) {
    return e1.w < e2.w;
} 
int find(int x) { 
    if(f[x] == x) return x;
    else return f[x] = find(f[x]);
}
void kruskal() {
    sort(e, e+m, cmp); // 按照权值排序
    for(int i = 0; i < m; i++) {
        int eu, ev;
        eu = find(e[i].u);
        ev = find(e[i].v);
        if(eu == ev) continue; // 成环跳过
        ans += e[i].w;
        f[ev] = eu; // 并查集合并
        if(++cnt == n-1) { 
            temp = 1;
            break;
        }
    }
}
int main() {
    //freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for(int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    kruskal();
    if(temp) cout << ans << endl;
    else cout << "orz" << endl;
    return 0;
}

