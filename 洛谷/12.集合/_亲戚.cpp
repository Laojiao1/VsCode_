// 并查集板子题
// https://www.luogu.com.cn/problem/P1551
#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int f[5005];
int find_(int x) { // 
    if(f[x] == x) return x;
    else return f[x] = find_(f[x]);
}
int main() {
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        f[find_(x)] = find_(y); // 合并x子集和y子集
        // 即找到他们的根节点然后合并成一个子集
    }
    for(int i = 1; i <= q; i++) {
        int c, d;
        cin >> c >> d;
        if(find_(c) == find_(d)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}