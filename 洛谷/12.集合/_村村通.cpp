// https://www.luogu.com.cn/problem/P1536
// 查找没有被合并的元素
#include <bits/stdc++.h>
using namespace std;
int n, m; // 城镇数目，道路数目
int f[1001];
int find_(int x) {
    if(f[x] == x) return x;
    else return f[x] = find_(f[x]);
}

int main() {
    while(1) {
        int ans = 0;
        cin >> n >> m;
        if(n == 0) {
            return 0;
        }
        for(int i = 1; i <= n; i++) {
            f[i] = i;
        }
        for(int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            f[find_(x)] = find_(y);
        }
        for(int i = 1; i <= n; i++) {
            if(f[i] == i) ans++;
        } 
        cout << ans-1 << endl;
    }
    return 0;
}