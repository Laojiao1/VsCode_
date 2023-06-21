// https://www.luogu.com.cn/problem/P1119
// 非常好的基于floyed算法题
// 理解floyed算法的本质: 用其他的点进行中转，从而达到求出最短路的目的。
#include <bits/stdc++.h>
using namespace std;
const int N = 205, inf = 1e9;
int n, m, a[N], Q;
int mp[N][N];
void init() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            mp[i][j] = inf; // 全部初始化最大
        }
    }
    for(int i = 0; i < n; i++) {
        mp[i][i] = 0; // 自己到自己的路径为0
    }
}
inline void floyed(int k) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mp[i][j] > mp[i][k] + mp[k][j]) {
                mp[j][i] =  mp[i][j] = mp[i][k] + mp[k][j];
            }
        }
    }
    return;
}   
int main() {
    freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i]; // 注意这里是从0开始的
    }
    init();
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mp[u][v] = mp[v][u] = w;
    }
    cin >> Q;
    int now = 0;
    for(int i = 1; i <= Q; i++) {
        int s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        while(now < n && a[now] <= s3) {
            floyed(now); // 将该时间点之前的结点都用上
            now++;
        }
        if(a[s1] > s3 || a[s2] > s3) cout << -1 << endl;
        else {
            if(mp[s1][s2] == inf) cout << -1 << endl;
            else cout << mp[s1][s2] << endl;
        }
    }
    return 0;
}
