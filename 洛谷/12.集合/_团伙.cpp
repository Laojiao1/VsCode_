// 并查集+反集
// https://www.luogu.com.cn/problem/P1892
// 关于反集：
// 如果a和b是敌人，合并n+b和a，n+a和b
// 如果c和a是敌人，合并n+c和a，n+a和c
// 那么b和c就并在一起了, 满足题意
#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[5005];
int ans = 0;
int a, b;
char ch;
int find(int x) {
    if(f[x] == x) return x;
    else return f[x] = find(f[x]);
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= 2*n; i++) { // 注意这里要乘2
        f[i] = i;
    }
    for(int i = 1; i <= m; i++) {
        cin >> ch >> a >> b;
        if(ch == 'F') {
            f[find(a)] = find(b); // 是朋友直接合并
        } else {
            f[find(a+n)] = find(b);
            f[find(b+n)] = find(a); // 反集合并
        }
    }
    for(int i = 1; i <= n; i++) {
        if(f[i] == i) ans++;
    }
    cout << ans << endl;
    return 0;
}