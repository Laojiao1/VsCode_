#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int v[maxn];
struct L {
    int x;
    int y1, y2;
    int state;
    bool operator<(L oth) { return x < oth.x; }
} line[maxn]; // 扫描线结构体
struct Node {
    int l, r, cover;
    long long len;
} sgt[maxn << 3]; // 线段树维护区间
inline int ls(int k) { return k << 1; }
inline int rs(int k) { return k << 1 | 1;}
inline void pushup(int k) {
    if(sgt[k].cover) sgt[k].len = sgt[k].r - sgt[k].l;
    else sgt[k].len = sgt[ls(k)].len + sgt[rs(k)].len;
}
void build_Tree(int l, int r, int k = 1) {
    sgt[k].l = v[l];
    sgt[k].r = v[r];
    if(r - l <= 1) return;
    int mid = (l + r) >> 1;
    build_Tree(l, mid, ls(k));
    build_Tree(mid, r, rs(k));
}
void modify(int x, int y, int z, int k = 1) {
    int l = sgt[k].l, r = sgt[k].r;
    if(x <= l && y >= r) {
        sgt[k].cover += z;
        pushup(k);
        return;
    }
    if(x < sgt[ls(k)].r) modify(x, y, z, ls(k));
    if(y > sgt[rs(k)].l) modify(x, y, z, rs(k));
    pushup(k);
}
int main() {
    freopen("in.in", "r", stdin);
    int n;
    cin >> n;
    int a, b, c, d;
    for(int i = 1; i <= n; i++) {
        cin >> a >> b >> c >> d;
        v[i] = b;
        v[n + i] = d;
        line[i] = (L){a, b, d, 1};
        line[n+i] = (L){c, b, d, -1};
    }
    sort(v+1, v + 1 + (n << 1));
    sort(line + 1, line + 1 + (n << 1));
    build_Tree(1, n << 1);
    unsigned long long ans = 0;
    for(int i = 1; i <= n << 1; i++) {
        ans += sgt[1].len*(line[i].x - line[i-1].x);
        modify(line[i].y1, line[i].y2, line[i].state);
    } 
    cout << ans << endl;
    return 0;
}