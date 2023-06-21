// https://www.luogu.com.cn/problem/P1194
// kruskal法无敌
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
struct Edge {
    int u;
    int v;
    int w;
} e[N << 1];
int A, B, f[N], cnt = 0, tot = 0, ans = 0;
bool cmp(Edge e1, Edge e2) {
    return e1.w < e2.w;
}
int find(int x) {
    if(x == f[x]) return x;
    else return f[x] = find(f[x]);
}
void add(int x, int y, int z) {
    e[++cnt].u = x;
    e[cnt].v = y;
    e[cnt].w = z;
}
void kruskal() {
    sort(e+1, e+1+cnt, cmp);
    for(int i = 1; i <= cnt; i++) {
        int eu, ev;
        eu = find(e[i].u);
        ev = find(e[i].v);
        if(eu == ev) continue;
        f[ev] = eu;
        ans += e[i].w;
        if(++tot == B) {
            break;
        }
    }
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> A >> B;
    for(int i = 0; i <= B; i++) {
        f[i] = i;
    }
    for(int i = 1; i <= B; i++) {
        add(0, i, A);
        for(int j = 1; j <= B; j++) {
            int x;
            cin >> x;
            if(i < j && x != 0) add(i, j, x); // 注意0不建边
        }
    }
    kruskal();
    cout << ans << endl;
    return 0;
}