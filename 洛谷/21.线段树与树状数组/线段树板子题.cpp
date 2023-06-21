// 线段树 —— 单点修改，区间查询
// 题目描述：
// 给定一个数列，有两种操作：1 表示修改某个元素，2 表示求区间连续和
// 输入数据第一行包含两个整数n, m (n <= 100000, m <= 500000), 以
// 下是m行， 每行有三个正整数k, a, b (k = 0 或 1, a, b <= n).
// k = 0 表示将a处数字加上b; k = 1 表示询问[a, b]内所有数字的和。
// 对于每个询问输出对应的答案.
// INPUT：
// 10 10
// 0 1 9
// 0 7 4
// 0 2 3
// 0 2 4
// 0 4 2
// 0 5 1
// 0 9 1
// 0 6 2
// 1 4 4
// 1 1 10
// OUTPUT:
// 2
// 26
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
int n, m;
struct Tree {
    int l, r;
    int sum;
} t[N*4];
void buildTree(int u, int l, int r) {
    t[u].l = l;
    t[u].r = r;
    if(l == r) return;
    int mid = (l + r) >> 1;
    buildTree(u << 1, l, mid); // 左儿子
    buildTree(u << 1 | 1, mid+1, r); // 右儿子
    t[u].sum = t[u << 1].sum + t[u << 1 | 1].sum;
}
// 由于pushup函数需要频繁调用，为了提高效率，加上inline
inline void pushup(int u) { // 回溯
    t[u].sum = t[u << 1].sum + t[u << 1 | 1].sum;
}
void change(int u, int index, int value) { // 操作0，修改区间值
    if(t[u].l == index && t[u].r == index) {
        t[u].sum += value;
        return;
    }
    pushup(u); // 回溯更新父节点
    int mid = (t[u].l + t[u].r) >> 1;
    if(index <= mid) change(u << 1, index, value); // 小于mid往左儿子找
    else change(u << 1 | 1, index, value); //反之往右儿子找
    t[u].sum = t[u << 1].sum + t[u << 1 | 1].sum;
}
ll qurey(int u, int l, int r) { // 操作1，区间查询
    if(l <= t[u].l && r >= t[u].r) return t[u].sum; // 如果目的区间包含该节点区间，直接返回sum
    pushup(u); // 回溯更新父节点
    ll temp = 0;
    int mid = (t[u].l + t[u].r) >> 1;
    if(l <= mid) temp += qurey(u << 1, l, r);// 如果目的区间左值比当前结点区间中点小的话，往左边找
    if(r > mid) temp += qurey(u << 1 | 1, l, r); // 如果目的区间右值比当前结点区间中点大的话，往右边找
    return temp;
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> n >> m;
    buildTree(1, 1, n);
    while(m--) {
        char op;
        cin >> op;
        if(op == '0') {
            int index, value;
            cin >> index >> value;
            change(1, index, value);
        } else {
            int L, R;
            cin >> L >> R;
            ll ans = qurey(1, L, R);
            cout << ans << endl;
        }
    }
    return 0;
}