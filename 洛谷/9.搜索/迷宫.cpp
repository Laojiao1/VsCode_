// DFS走迷宫，版子题
// https://www.luogu.com.cn/problem/P1605
#include <bits/stdc++.h>
using namespace std;
int n, m, num; // 行列以及障碍物数
bool mp[10][10];
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int startx, starty, endx, endy;
int ans = 0;
void dfs(int x, int y) {
    if(x == endx && y == endy) {
        ans++;
        return;
    } else {
        mp[x][y] = 1;
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx > 0 && yy > 0 && xx <= n && yy <= m && !mp[xx][yy]) {
                mp[xx][yy] = 1; // 标记以访问
                dfs(xx, yy);
                mp[xx][yy] = 0; // 回溯
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> num;
    cin >> startx >> starty >> endx >> endy;
    for(int i = 1; i <= num; i++) {
        int x, y;
        cin >> x >> y;
        mp[x][y] = 1;
    }
    mp[startx][starty] = 1;
    dfs(startx, starty);
    cout << ans << endl;
    return 0;
}