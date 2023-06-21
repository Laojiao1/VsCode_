#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5; 
struct Node {
	int val; // 树的权值 
	int key; // 堆的随机值 
	int size; // 子树大小 
	int l, r; // 左右儿子 
} t[N];
int n, idx, root;
void push_up(int p) {
    t[p].size = t[t[p].l].size + t[t[p].r].size + 1;
}
int newnode(int v) {
    t[++idx].val = v;
    t[idx].key = rand();
    t[idx].size = 1;
    return idx;
}
void split(int p, int v, int& x, int& y) {
    if(!p) {
        x = y = 0;
        return;
    }
    if(t[p].val <= v) {
        x = p;
        split(t[x].r, v, t[x].r, y);
    } else {
        y = p;
        split(t[y].l, v, x, t[y].l);
    }
    push_up(p);
}
int merge(int x, int y) {
    if(!x || !y) return x + y;
    if(t[x].key < t[y].key) {
        t[x].r = merge(t[x].r, y);
        push_up(x);
        return x;
    } else {
        t[y].l = merge(x, t[y].l);
        push_up(y);
        return y;
    }
}
void insert(int v) {
    int x, y, z;
    split(root, v, x, y);
    z = newnode(v);
    root = merge(merge(x, z), y);
}
void del(int v) {
    int x, y, z;
    split(root, v, x, z);
    split(x, v-1, x, y);
    y = merge(t[y].l, t[y].r);
    root = merge(merge(x, y), z);
}
int get_k(int p, int k) {
    if(k <= t[t[p].l].size) {
        return get_k(t[p].l, k);
    }
    if(k == t[t[p].l].size + 1) {
        return p;
    }
    return get_k(t[p].r, k - t[t[p].l].size - 1);
}
void get_pre(int v) {
    int x, y;
    split(root, v-1, x, y);
    int p = get_k(x, t[x].size);
    cout << t[p].val << endl;
    root = merge(x, y);
}
void get_suc(int v) {
    int x, y;
    split(root, v, x, y);
    int p = get_k(y, 1);
    cout << t[p].val << endl;
    root = merge(x, y);
}
void get_rank(int v) {
    int x, y;
    split(root, v-1, x, y);
    cout << t[x].size+1 << endl;
    root = merge(x, y);
}
void get_val(int k) {
    int p = get_k(root, k);
    cout << t[p].val << endl;
}
int main() {
	scanf("%d", &n);
    while(n--) {
        int op, x;
        scanf("%d %d", &op, &x);
        if(op == 1) insert(x);
        if(op == 2) del(x);
        if(op == 3) get_rank(x);
        if(op == 4) get_val(x);
        if(op == 5) get_pre(x);
        if(op == 6) get_suc(x);
    }
	return 0;
} 