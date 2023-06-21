// 普普通通的tarjan缩点
// https://www.luogu.com.cn/problem/P2863
#include <bits/stdc++.h>
using namespace std;
const int N = 10050;
struct Edge {
    int to;
    int next;
} e[N*20];
int n, m, cnt, tim, color, ans;
int head[N], dfn[N], low[N], sd[N], all[N];
bool vis[N];
stack<int> s;
inline void add(int x, int y) {
    e[++cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;
}
void tarjan(int x) {
    dfn[x] = low[x] = ++tim;
    s.push(x);
    vis[x] = 1;
    for(int i = head[x]; i; i = e[i].next) {
        int to = e[i].to;
        if(!dfn[to]) {
            tarjan(to);
            low[x] = min(low[x], low[to]);
        } else if(vis[to]) {
            low[x] = min(low[x], low[to]);
        }
    }
    if(low[x] == dfn[x]) {
        int y;
        ++color;
        do {
            y = s.top();
            s.pop();
            vis[y] = 0;
            sd[y] = color;
            all[color]++;
        } while(x != y);
    }
}
int main() {
    //freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    for(int i = 1; i <= n; i++) {
        if(!dfn[i]) {
            tarjan(i);
        }
    }
    for(int i = 1; i <= color; i++) {
        if(all[i] > 1) ans++;
    }
    cout << ans << endl;
    return 0;
}