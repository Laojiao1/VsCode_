// https://www.luogu.com.cn/problem/P1726
#include <bits/stdc++.h>
using namespace std;
const int N = 100050;
struct Edge {
    int to;
    int next;
} e[N*20];
int head[N], sd[N], dfn[N], low[N], all[N];
int n, m, cnt, color, tim;
bool vis[N];
stack<int> s;
inline void add(int x, int y) {
    e[++cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;
}
void tarjan(int x) {
    low[x] = dfn[x] = ++tim;
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
        int a, b, c;
        cin >> a >> b >> c;
        if(c == 1) {
            add(a, b);
        } else {
            add(a, b);
            add(b, a);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(!dfn[i]) {
            tarjan(i);
        }
    }
    int ans = 0;
    for(int i = 1; i <= color; i++) {
        ans = max(ans, all[i]);
    }
    cout << ans << endl;
    for(int i = 1; i <= n; i++) {
        if(all[sd[i]] == ans) {
            cout << i << " ";
        }
    }
    return 0;
}