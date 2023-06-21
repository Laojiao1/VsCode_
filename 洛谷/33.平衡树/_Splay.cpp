// https://www.luogu.com.cn/problem/P3369
// Splay
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
struct Node {
	int s[2]; // 左右儿子 
	int p; // 父节点 
	int v; // 当前节点的值 
	int cnt; // 当前节点出现的数量 
	int size; // 子树大小 
	void init(int p1, int v1) {
		p = p1, v = v1;
		cnt = size = 1;
	}
} t[N];
int root; // 根结点编号 
int idx; // 节点个数 
int n;
void pushup(int x) {
	t[x].size = t[t[x].s[0]].size + t[t[x].s[1]].size + t[x].cnt;
} // 左子树大小 + 右子树大小 + 当前根的大小 
void rotate(int x) { // 旋转, 保序且信息正确 
	int y = t[x].p; // 取出父亲 
	int z = t[y].p; // 取出爷爷
	int k = t[y].s[1] == x;
	
	// 以下代码根据图像理解 
	t[y].s[k] = t[x].s[k^1]; 
	t[t[x].s[k^1]].p = y;
	
	t[x].s[k^1] = y;
	t[y].p = x;
	
	t[z].s[t[z].s[1] == y] = x;
	t[x].p = z;
	
	pushup(y);
	pushup(x);
}
void Splay(int x, int k) {
    while(t[x].p != k) {
        int y = t[x].p, z = t[y].p;
        if(z != k) { // 折转底，直转中
            (t[y].s[0] == x) ^ (t[z].s[0] == y) ? rotate(x): rotate(y);
        }
        rotate(x);
    }
    if(k == 0) root = x;
}
void find(int v) {
    int x = root;
    while(t[x].s[v > t[x].v] && v != t[x].v) {
        x = t[x].s[v > t[x].v];
    }
    Splay(x, 0);
}
int get_pre(int v) {
    find(v);
    int x = root;
    if(t[x].v < v) return x;
    x = t[x].s[0];
    while(t[x].s[1] != 0) {
        x = t[x].s[1];
    }
    return x;
}
int get_suc(int v) {
    find(v);
    int x = root;
    if(t[x].v > v) return x;
    x = t[x].s[1];
    while(t[x].s[0] != 0) {
        x = t[x].s[0];
    }
    return x;
}
void del(int v) {
    int pre = get_pre(v);
    int suc = get_suc(v);
    Splay(pre, 0), Splay(suc, pre);
    int del = t[suc].s[0];
    if(t[del].cnt > 1) {
        t[del].cnt--;
        Splay(del, 0); // 更新受影响的子树
    } else {
        t[suc].s[0] = 0;
        Splay(suc, 0); // 更新受影响的子树
    }
}
int get_val(int k) {
    int x = root;
    while(1) {
        int y = t[x].s[0];
        if(t[y].size + t[x].cnt < k) {
            k -= t[y].size + t[x].cnt;
            x = t[x].s[1];
        } else {
            if(t[y].size >= k) {
                x = t[x].s[0];
            } else {
                break;
            }
        }
	}
    Splay(x, 0);
    return t[x].v;
}
int get_rank(int v) {
    find(v);
    return t[t[root].s[0]].size; // 不用加1，因为之前插入了哨兵
}
void insert(int v) {
    int x = root, p = 0; // p记录当前节点的父节点
    while(x && t[x].v != v) {
        p = x;
        x = t[x].s[v > t[x].v];
    }
    if(x) t[x].cnt++;
    else {
        x = ++idx;
        t[p].s[v > t[p].v] = x;
        t[x].init(p, v);
    }
    Splay(x, 0);
}
int main() {
	insert(-2147483647); insert(2147483647);
    scanf("%d", &n);
    while(n--) {
        int op, x;
        scanf("%d %d", &op, &x);
        if(op == 1) insert(x);
        if(op == 2) del(x);
        if(op == 3) printf("%d\n", get_rank(x));
        if(op == 4) printf("%d\n", get_val(x+1));
        if(op == 5) printf("%d\n", t[get_pre(x)].v);
        if(op == 6) printf("%d\n", t[get_suc(x)].v);
    }
	return 0;
}