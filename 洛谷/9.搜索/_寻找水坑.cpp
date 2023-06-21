// https://www.luogu.com.cn/problem/P1596
// 搜索连通块
#include <bits/stdc++.h>
using namespace std;
char mp[101][101];
bool vis[101][101];
const int dx[8]={-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8]={-1, 0, 1, -1, 1, -1, 0, 1};
int ans = 0;
int n, m;
void dfs(int x, int y) {
    // 搜过的地方标记为1
    vis[x][y] = 1;
    for(int i = 0; i < 8; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(mp[xx][yy] == 'W' && !vis[xx][yy]) {
            dfs(xx, yy);
        }
    }
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(mp[i][j] == 'W' && !vis[i][j]) {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}