// https://www.luogu.com.cn/problem/P2574
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
struct Node {
    int l, r;
    int pre;
    int lazy;
} tree[4*N];
int a[N];
int n, m, x, y, z;
void Build_Tree(int index, int l, int r) {
    tree[index].l = l;
    tree[index].r = r;
    if(l == r) {
        tree[index].pre = a[l];
        return;
    }
    int mid = (l+r)/2;
    Build_Tree(index << 1, l, mid);
    Build_Tree(index << 1 | 1, mid+1, r);
    tree[index].pre = tree[index << 1].pre + tree[index << 1 | 1].pre;
}
void pushdown(int index) { // 回溯
    if(tree[index].lazy) {
		tree[index << 1].pre = tree[index << 1].r - tree[index << 1].l + 1 - tree[index << 1].pre;//如上所说修改
		tree[index << 1 | 1].pre = tree[index << 1 | 1].r - tree[index << 1 | 1].l + 1 - tree[index << 1 | 1].pre;
		tree[index << 1].lazy ^= 1;
		tree[index << 1 | 1].lazy ^= 1;
		tree[index].lazy = 0;//别忘记清空！！
	}
}
int Query(int index, int l, int r) { 
    if(l <= tree[index].l && r >= tree[index].r) {
        return tree[index].pre;
    }
    int mid = (tree[index].l + tree[index].r) / 2;
    int temp = 0;
    pushdown(index);
    if(l <= mid) temp += Query(index << 1, l, r);
    if(mid < r) temp += Query(index << 1 | 1, l, r);
    return temp;
}
void Change(int index, int l, int r) {
    if(l <= tree[index].l && r >= tree[index].r) {
        tree[index].pre = tree[index].r - tree[index].l + 1 - tree[index].pre;
        tree[index].lazy ^= 1;
        return;
    }
    int mid = (tree[index].l + tree[index].r)/2;
    pushdown(index);
    if(l <= mid) Change(index << 1, l, r);
    if(mid < r) Change(index << 1 | 1, l, r);
    tree[index].pre = tree[index << 1].pre + tree[index << 1 | 1].pre;
}
int main() {
    freopen("in.in", "r", stdin);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		scanf("%1d", &a[i]);
	Build_Tree(1, 1, n);
	for(int i = 1; i <= m; i++) {
		cin >> z;
		if(z == 0) {
			cin >> x >> y;
			Change(1, x, y);	
		}
		else {
			cin >> x >> y;
			cout << Query(1, x, y) << endl;	
		}
	}
	return 0;
}
