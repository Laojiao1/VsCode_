// 加强版板子题
// https://www.luogu.com.cn/problem/P3373
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
struct Tree {
    int l, r;
    ll sum, add, mul;
} t[N*4];
int n, m, mod;
int a[N];
inline void update(int u) {
    t[u].sum = (t[u << 1].sum + t[u << 1 | 1].sum) % mod;
    return;
}
inline void pushdown(int u) {
    t[u << 1].sum = (t[u << 1].sum * t[u].mul + t[u].add * (t[u << 1].r - t[u << 1].l + 1)) % mod;
	t[u << 1 | 1].sum = (t[u << 1 | 1].sum * t[u].mul + t[u].add * (t[u << 1 | 1].r - t[u << 1 | 1].l + 1)) % mod;
	
	t[u << 1].mul = (t[u << 1].mul * t[u].mul) % mod;
	t[u << 1 | 1].mul = (t[u << 1 | 1].mul * t[u].mul) % mod;
	
	t[u << 1].add = (t[u << 1].add * t[u].mul + t[u].add) % mod;
	t[u << 1 | 1].add = (t[u << 1 | 1].add * t[u].mul + t[u].add) % mod;

    t[u].add = 0;
    t[u].mul = 1;

    return;
}
void buildTree(int u, int l, int r) { // 建树
    t[u].l = l;
    t[u].r = r;
    t[u].mul = 1;
    if(l == r) {
        t[u].sum = a[l] % mod;
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(u << 1, l, mid);
    buildTree(u << 1 | 1, mid + 1, r);
    update(u);
    return;
}
void ChangeMul(int u, int x, int y, int k) { //区间乘法
    if(x <= t[u].l && y >= t[u].r) {
        t[u].add = (t[u].add * k) % mod;
        t[u].mul = (t[u].mul * k) % mod;
        t[u].sum = (t[u].sum * k) % mod;
        return;
    }
    pushdown(u);
    int mid = (t[u].l + t[u].r) >> 1;
    if(x <= mid) ChangeMul(u << 1, x, y, k);
    if(mid < y) ChangeMul(u << 1 | 1, x, y, k);
    update(u);
    return;
}
void ChangeAdd(int u, int x, int y, int k) { //区间加法
    if(x <= t[u].l && y >= t[u].r) {
        t[u].add = (t[u].add + k) % mod;
        t[u].sum = (t[u].sum + k * (t[u].r - t[u].l + 1)) % mod;
        return;
    }
    pushdown(u);
    int mid = (t[u].l + t[u].r) >> 1;
    if(x <= mid) ChangeAdd(u << 1, x, y, k);
    if(mid < y) ChangeAdd(u << 1 | 1, x, y, k);
    update(u);
    return;
}
ll query(int u, int x, int y) {
    if(x <= t[u].l && y >= t[u].r) {
        return t[u].sum;
    }
    pushdown(u);
    ll temp = 0;
    int mid = (t[u].l + t[u].r) >> 1;
    if(x <= mid) temp = (temp + query(u << 1, x, y)) % mod;
    if(y > mid) temp = (temp + query(u << 1 | 1, x, y)) % mod;
    return temp;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> mod;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	buildTree(1, 1, n);
	for (int i = 1; i <= m; i++) {
		int q, x, y;
		cin >> q >> x >> y;
		if (q == 1) {
			int k;
			cin >> k;
			ChangeMul(1, x, y, k);
		}
		if (q == 2) {
			int k;
			cin >> k;
			ChangeAdd(1, x, y, k);
		}
		if (q == 3) {
			printf("%lld\n", query(1, x, y));
		}
	}
    return 0;
}