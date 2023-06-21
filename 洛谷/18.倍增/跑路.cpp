// 倍增floyed算法
// https://www.luogu.com.cn/problem/P1613
#include <bits/stdc++.h>
using namespace std;
bool G[60][60][65];// G[i][j][k]表示从i到j可以通过走2^k距离直接到达
int dis[60][60], n, m;
void init() {
    for(int k = 1; k <= 64; k++) { //2^64次方足够了
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                for(int t = 1; t <= n; t++) {
                // 如果i到j存在一条2^k-1长度的路径
                // 并且j到t存在一条2^k-1长度的路径
                // 就说明i到j，j到t都可以一秒到达，
                // 因此i到t之间距离刚好是2^k，也可以一秒到达
                // 所以将i到t连通成1
                    if(G[i][j][k-1] && G[j][t][k-1]) {
                        G[i][t][k] = true;
                        dis[i][t] = 1;
                    }
                }
            }
        }
    }
}
void floyed() { // 经典弗洛伊德算法
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
            }
        }
    }
}
int main() {
   // freopen("in.in", "r", stdin);
    memset(dis, 20, sizeof(dis));
    memset(G, false, sizeof(G));
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        dis[x][y] = 1;
        G[x][y][0] = true;
    }
    init();
    floyed();
    printf("%d\n", dis[1][n]);
    return 0;
}