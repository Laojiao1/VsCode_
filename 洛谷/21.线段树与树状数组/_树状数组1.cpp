// https://www.luogu.com.cn/problem/P3374
// 树状数组板子题
// 树状数组适合于在多次求和，多次修改，数据量大的时候使用
// 1 x k 含义：将第 x 个数加上 k
// 2 x y 含义：输出区间 [x,y] 内每个数的和
#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int n, m;
int Tree[N], input[N]; // Tree[]为树状数组
int lowbit(int x) { // Tree[i]的区间长度 
    return x & -x;
}
void add(int i, int k) { // 点更新，a[i] 加上 k 
    for(; i <= n; i += lowbit(i)) { // 更新所有的后继
        Tree[i] += k;
    }
}
int sum(int i) { // 求前缀和，a[1] …… a[i]
    int sum = 0;
    for(; i > 0; i -= lowbit(i)) { // 累加所有前驱 
        sum += Tree[i];
    }
    return sum;
}
int sum_interval(int i, int j) { // 求区间和，a[i] …… a[j] 
	return sum(j) - sum(i-1);
}
int main() {
    // freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> input[i];
        add(i, input[i]);
    }
    for(int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) add(b, c);
        if(a == 2) cout << sum_interval(b, c) << endl;
    }
    return 0;
}