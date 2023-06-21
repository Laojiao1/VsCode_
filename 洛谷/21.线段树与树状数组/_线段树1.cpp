// 线段树模板题 https://www.luogu.com.cn/problem/P3372
// 线段树一般用于区间更新和查询，更新会需要用到lazy标记
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
struct Tree {
    int l;
    int r;
    long long pre = 0; // 当前初始值
    long long lazy = 0; // lazy值(其实就是区间每个数要加的值)
} t[N*4+2]; // 最好开4倍
int a[N+2]; // 存储每一个区间的初始值
int n, m;
void buildTree(int u, int l, int r) {
    t[u].l = l;
    t[u].r = r;
    if(l == r) {
        t[u].pre = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(u << 1, l, mid); //建立左子树
    buildTree(u << 1 | 1, mid + 1, r); //建立右子树
    t[u].pre = t[u << 1].pre + t[u << 1 | 1].pre;
}
inline void pushdown(int u) { // 回溯
    if(t[u].lazy) {
        t[u << 1].pre += t[u].lazy * (t[u << 1].r - t[u << 1].l + 1);
        t[u << 1 | 1].pre += t[u].lazy * (t[u << 1 | 1].r - t[u << 1 | 1].l + 1);

        t[u << 1].lazy += t[u].lazy; // 标记新的lazy值
        t[u << 1 | 1].lazy += t[u].lazy; // 标记新的lazy值
        
        t[u].lazy = 0; // 注意最后一定要把当前节点的add清零
    }
}
void changeAdd(int u, int x, int y, int value) { // 操作1
    if(x <= t[u].l && y >= t[u].r) { //递归出口, 目标操作
        t[u].pre += (ll)value * (t[u].r - t[u].l + 1);
        t[u].lazy += value;// 更新lazy值
        return;
    }
    pushdown(u);//回溯往下更新
    int mid = (t[u].l + t[u].r) >> 1;
    if(x <= mid) {
        changeAdd(u << 1, x, y, value);
    }
    if(mid < y) {
        changeAdd(u << 1 | 1, x, y, value);
    }
    t[u].pre = t[u << 1].pre + t[u << 1 | 1].pre;
}
ll qurey(int u, int l, int r) { //操作2，返回区间内所有值的和
    if(l <= t[u].l && r >= t[u].r) {
        return t[u].pre;
    }
    pushdown(u); 
    ll temp = 0;
    int mid = (t[u].l + t[u].r) >> 1;
    if(l <= mid) {
        temp += qurey(u << 1, l, r);
    }
    if(mid < r) {
        temp += qurey(u << 1 | 1, l, r);
    }
    return temp;
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    buildTree(1, 1, n);
    for(int i = 1; i <= m; i++) {
        int q, x, y, z;
        cin >> q;
        if(q == 1) {
            cin >> x >> y >> z;
            changeAdd(1, x, y, z);
        } else {
            cin >> x >> y;
            cout << qurey(1, x, y) << endl;
        }
    }
    return 0;
}