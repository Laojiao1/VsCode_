// https://www.luogu.com.cn/problem/P3834
// 主席树 —— 求区间第k大，或者历史信息
#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
#define lc(x) t[x].l
#define rc(x) t[x].r
int n, m, a[N];
vector<int> v; // 离散化存储容器 
struct Node {
	int l, r;
	int s; // 节点值域中有多少结点 
} t[N*23];
int idx, root[N];
int getid(int x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
} 
void build(int &x, int l, int r) {
	x = ++idx;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(lc(x), l, mid);
	build(rc(x), mid+1, r);
}
void insert(int x, int& y, int l, int r, int v) {
	y = ++idx;
	t[y] = t[x];
	t[y].s++;
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(v <= mid) insert(lc(x), lc(y), l, mid, v);
	else insert(rc(x), rc(y), mid+1, r, v);
}
int query(int x, int y, int l, int r, int k) {
	if(l == r) return l;
	int mid = (l + r) >> 1;
	int s = t[lc(y)].s - t[lc(x)].s;
	if(k <= s) {
		return query(lc(x), lc(y), l, mid, k);
	} else {
		return query(rc(x), rc(y), mid+1, r, k-s);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		v.push_back(a[i]);
	}
    // 离散化：排序、去重、编号
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int vn = v.size();
	build(root[0], 1, n);
	for(int i = 1; i <= n; i++) {
		insert(root[i-1], root[i], 1, vn, getid(a[i]));
	}
	while(m--) {
		int l, r, k;
    	scanf("%d %d %d", &l, &r, &k);
    	int id = query(root[l-1], root[r], 1, vn, k)-1;
    	printf("%d\n", v[id]);
	}
	return 0;
}