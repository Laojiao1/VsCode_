#include <bits/stdc++.h>
using namespace std;
int n, mp[305][305];// 陨石数量，陨石砸落的时间
bool vis[305][305];
struct point { // 人的位置
    int x;
    int y;
    int step;
};
queue<point> q;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
const int inf = 0x3f3f3f3f;//无限大
int flag = 0;
int main() {
    cin >> n;
    memset(mp, 0x3f, sizeof(mp));
    for(int i = 1; i <= n; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        mp[x][y] = min(mp[x][y], t);
        for(int j = 0; j < 4; j++) {
            int xx = x + dx[j];
            int yy = y + dy[j];
            if(xx > - 1 && yy > -1 && xx < 300 && yy < 300) {
                mp[xx][yy] = min(mp[xx][yy], t); // 拓展四周的点
            }
        }
    }
    point start;
    start.x = 0;
    start.y = 0;
    start.step = 0;
    q.push(start);
    vis[start.x][start.y] = 1; // 标记已经走过
    while(!q.empty()) {
        int tx = q.front().x;
        int ty = q.front().y;
        int tstep = q.front().step;
        // 拓展搜索周围的点
        for(int i = 0; i < 4; i++) {
            int x1 = tx + dx[i];
            int y1 = ty + dy[i];
            int step1 = tstep + 1;
            // 如果不超过边界，时间少于当前陨石坠落时间并且没有被访问过的话
            if(mp[tx][ty] == inf) {
                flag = 1;
                cout << q.front().step << endl;
                return 0;
            } // 没有陨石范围，就是安全的
            if(x1 == -1 || y1 == -1) continue;
            if(step1 < mp[x1][y1] && !vis[x1][y1]) {
                vis[x1][y1] = 1;
                point temp;
                temp.x = x1;
                temp.y = y1;
                temp.step = step1;
                q.push(temp);
            }
        }
        q.pop();
    }  
    if(flag == 0) {
        cout << -1 << endl;
    }
    return 0;
}