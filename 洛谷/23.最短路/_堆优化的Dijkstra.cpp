// https://www.luogu.com.cn/problem/P3371
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p> > q;
const int N = 1e6+5;
long long inf = 2147483647;
int head[N], cnt = 0;
long long ans[N];
bool vis[N];
int m, n, s; // 点的个数、有向边的个数、出发点的编号。
struct Node {
    int to;
    int w;
    int next;
} e[N];
long long ret = 0;
void add(int x, int y, int z) {
    e[++cnt].to = y;
    e[cnt].w = z;
    e[cnt].next = head[x];
    head[x] = cnt;
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++) {
        ans[i] = inf;
    }
    for(int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    ans[s] = 0;
    q.push(make_pair(0, s));
    while(!q.empty()) {
        int now = q.top().second; // 把堆顶元素取出来
        q.pop();
        if(vis[now]) continue; // 如果曾经使用过，就跳过
        vis[now] = 1; // 标记使用
        for(int i = head[now]; i; i = e[i].next) {
            if(ans[e[i].to] > ans[now] + e[i].w) {
                ans[e[i].to] = ans[now] + e[i].w;
                q.push(make_pair(ans[e[i].to], e[i].to));
                // 记录信息
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}