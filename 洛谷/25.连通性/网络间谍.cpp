// https://www.luogu.com.cn/problem/P1262
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int inf = 1e9+7;
struct Edge {
    int to;
    int next;
} e[N*20];
int head[N], dfn[N], low[N], sd[N], color, tim, cnt, ans;
int in[N], n, p, r, money[N], sum[N], all[N];
bool vis[N];
stack<int> s;
inline void add(int x, int y) {
    e[++cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;
}
void tarjan(int x) {
    dfn[x] = low[x] = ++tim;
    vis[x] = 1;
    s.push(x);
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
            sum[color] = min(sum[color], money[y]);
        } while(x != y);
    }
}
int main() {
    //freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) money[i] = inf;
    for(int i = 1; i <= n; i++) sum[i] = inf; // 记得初始化
    cin >> p;
    for(int i = 1; i <= p; i++) {
        int people, mony;
        cin >> people >> mony;
        money[people] = mony;
    }
    cin >> r;
    for(int i = 1; i <= r; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    for(int i = 1; i <= n; i++) {
        if(!dfn[i] && money[i] != inf) {
            tarjan(i);
        }
    }
    // 情况一：如果有人没被访问说明无解
    for(int i = 1; i <= n; i++) {
        if(!dfn[i]) {
            cout << "NO" << endl;
            cout << i << endl; 
            return 0;
        }
    }
    // 情况二:
    for(int i = 1; i <= n; i++) {
        for(int j = head[i]; j; j = e[j].next) {
            int u = e[j].to;
            if(sd[i] != sd[u]) {
                in[sd[u]]++;   
            }
        }
    }
    cout << "YES" << endl;
    for(int i = 1; i <= color; i++) {
        if(in[i] == 0) ans += sum[i];
    }
    cout << ans << endl;
    return 0;
}