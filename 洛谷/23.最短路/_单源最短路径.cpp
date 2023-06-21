// https://www.luogu.com.cn/problem/P3371
// Dijkstra算法, 不用堆优化
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
// long long inf = 2147483647;
#define inf 2147483647
int head[N], cnt = 0;
long long ans[N];
bool vis[N];
int m, n, s; // 点的个数、有向边的个数、出发点的编号。
struct Node {
    int to;
    int w;
    int next;
} e[N];
void add(int x, int y, int z) {
    e[++cnt].to = y;
    e[cnt].w = z;
    e[cnt].next = head[x];
    head[x] = cnt;
}
int main() {
   // freopen("in.in", "r", stdin);
    cin >> m >> n >> s;
    for(int i = 1; i <= m; i++) {
        ans[i] = inf;
    } // 初始化为无穷大
    ans[s] = 0;
    for(int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int now = s; // 从s点开始
    while(vis[now] == 0) {
        long long minn = inf;
        vis[now] = 1; // 标记访问
        for(int i = head[now]; i; i = e[i].next) { // 取出邻接点
            if(!vis[e[i].to] && ans[e[i].to] > ans[now] + e[i].w) {
                ans[e[i].to] = ans[now] + e[i].w;
            }
        }
        for(int i = 1; i <= m; i++) {
            if(ans[i] < minn && !vis[i]) { // 收录最短路径
                minn = ans[i];
                now = i;
            }
        }
    }
    for(int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}