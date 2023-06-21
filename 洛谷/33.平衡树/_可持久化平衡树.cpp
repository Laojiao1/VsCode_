// 可持久化平衡树(套的Treap)
#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
struct Node {
	int l, r;
	int val;
	int rnd;
	int size;
} t[N*50]; 
int root[N], idx;
void newnode(int& x, int v) {
	x = ++idx;
	t[idx].val = v;
	t[idx].rnd = rand();
	t[idx].size = 1;
}
void push_up(int p) {
	t[p].size = t[t[p].l].size + t[t[p].r].size + 1;
}
void split(int p, int v, int& x, int& y) {
	if(!p) {
		x = y = 0;
		return;
	}
	if(t[p].val <= v) {
		x = ++idx;
		t[x] = t[p];
		split(t[x].r, v, t[x].r, y);
		push_up(x);
	} else {
		y = ++idx;
		t[y] = t[p];
		split(t[y].l, v, x, t[y].l);
		push_up(y);
	}
}
int merge(int x, int y) {
	if(!x || !y) return x + y;
	if(t[x].rnd < t[y].rnd) {
		t[x].r = merge(t[x].r, y);
		push_up(x);
		return x;
	} else {
		t[y].l = merge(x, t[y].l);
		push_up(y);
		return y;
	}
}
void insert(int& root, int v) {
	int x, y, z;
	split(root, v, x, y);
	newnode(z, v);
	root = merge(merge(x, z), y);
}
void del(int& root, int v) {
	int x, y, z;
	split(root, v, x, z);
	split(x, v-1, x, y);
	y = merge(t[y].l, t[y].r);
	root = merge(merge(x, y), z);
}
int get_rank(int& root, int v) {
	int x, y;
	split(root, v-1, x, y);
	int ans = t[x].size + 1;
	root = merge(x, y);
	return ans;
}
int get_val(int root, int k) {
	if(k == t[t[root].l].size + 1) return t[root].val;
	else if(k <= t[t[root].l].size) {
		return get_val(t[root].l, k);
	} else {
		return get_val(t[root].r, k - t[t[root].l].size - 1);
	}
}
int get_pre(int &root, int v){
	int x, y, s, ans;
	split(root, v-1, x, y);
	if(!x) return -2147483647;
	s = t[x].size;
	ans = get_val(x, s);
	root = merge(x, y);
	return ans;
}
int get_suc(int& root, int v) {
	int x, y, ans;
	split(root, v, x, y);
	if(!y) return 2147483647;
	ans = get_val(y, 1);
	root = merge(x, y);
	return ans;
}
int main() {
  	int n, ver, op, v;
  	scanf("%d", &n);
  	for(int i = 1; i <= n; ++i) {
    	scanf("%d %d %d", &ver, &op, &v);
    	root[i] = root[ver];
    	if(op == 1) insert(root[i], v);
    	else if(op == 2) del(root[i], v);
    	else if(op == 3) printf("%d\n", get_rank(root[i], v));
    	else if(op == 4) printf("%d\n", get_val(root[i], v));
    	else if(op == 5) printf("%d\n", get_pre(root[i], v));
    	else printf("%d\n", get_suc(root[i], v));
  	}
  	return 0;
}