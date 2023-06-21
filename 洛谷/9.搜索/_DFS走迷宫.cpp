// 经典例题
// 迷宫问题
// 给定一个迷宫n*n，入口为左上角，出口为右下角，从入口到出口有多少种路径可走
// 注意移动可以从上、下、左、右、上左、上右、下左、下右八个方向进行。
// 迷宫输入0表示可走，输入1表示墙。
// 3
// 0 0 0
// 0 1 1
// 1 0 0
#include <bits/stdc++.h>
using namespace std;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, ans;
int mp[101][101];
void dfs(int x, int y) {
    if(x == n && y == n) {
        ans++;
        return;
    } else {
        mp[x][y] = 1;
        for(int i = 0; i < 8; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(!mp[xx][yy] && xx >= 1 && xx <= n && yy >= 1 && yy <= n) {
                mp[xx][yy] = 1;
                dfs(xx, yy);
                mp[xx][yy] = 0;
            }
        }
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> mp[i][j];
        }
    }
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}
