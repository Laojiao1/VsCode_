// 寻找只有一个出度为0的结点
// https://www.luogu.com.cn/problem/P2341
// 缩点
#include <bits/stdc++.h>
using namespace std;
const int N = 10050;
struct edge {
    int to;
    int next; 
} e[N*20];
int head[N], dfn[N], low[N];
int du[N], sd[N], all[N];
bool vis[N];
int cnt, tim, color, n, m;
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
            sd[y] = color; // 把强连通分量里的结点都染成一个色 
            all[color]++; // 记录强连通分量里的节点个数
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
        if(!dfn[i]) tarjan(i);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = head[i]; j; j = e[j].next) { // 遍历每个结点的边
            int u = e[j].to;
            if(sd[i] != sd[u]) { // 如果不属于同一个缩点
                du[sd[i]]++; // 出度+1
            }
        }
    }
    int id = 0;
    for(int i = 1; i <= color; i++) {
        if(!du[i]) {
            if(id) {
                cout << "0" << endl; // 如果两次以上出现出度为0，说明不存在受欢迎的牛
                return 0;
            }
            id = i; // 记录编号
        }
    }
    cout << all[id] << endl;
    return 0;
}