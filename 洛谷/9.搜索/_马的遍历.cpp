// BFS 最短路径
// 板子题
// Input:
// 3 3 1 1
// Output: 
// 0    3    2    
// 3    -1   1
// 2    1    4
#include <bits/stdc++.h>
using namespace std;
int f[405][405], vis[405][405]; // 存步数，是否访问
int n, m, x, y;
const int dx[8]={-1, -2, -2, -1, 1, 2, 2, 1};
const int dy[8]={2, 1, -1, -2, 2, 1, -1, -2};//8个方向
struct point {
    int x;
    int y;
};
queue<point> q;
int main() {
    memset(f, -1, sizeof(f));
    cin >> n >> m >> x >> y;
    point start;
    start.x = x;
    start.y = y;
    q.push(start);
    vis[x][y] = 1;
    f[x][y] = 0;
    while(!q.empty()) {
        int xx = q.front().x;
        int yy = q.front().y;
        for(int i = 0; i < 8; i++) {
            int tx = xx + dx[i];
            int ty = yy + dy[i];
            if(tx <= n && tx > 0 && ty <= m && ty > 0 && !vis[tx][ty]) {
                point temp;
                temp.x = tx;
                temp.y = ty;
                f[tx][ty] = f[xx][yy] + 1;
                vis[tx][ty] = 1;
                q.push(temp);
            }
        }
        q.pop();
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            printf("%-5d",f[i][j]); // 这里的意思事场宽为5
        }
        cout << endl;
    }
    return 0;
}