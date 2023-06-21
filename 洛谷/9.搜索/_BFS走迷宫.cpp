// 给出一个n*m迷宫, 0代表能通过，1代表不能通过
// 给出一个起点和终点
// 求由起点到终点需要走的步数最少是多少步，如果走不到，输出No answer!
// Input:
// 5 4
// 0 0 1 0
// 0 0 0 0 
// 0 0 1 0
// 0 1 0 0
// 0 0 0 1
// 1 1 4 3
// Output:
// 7
#include <bits/stdc++.h>
using namespace std;
int startx, starty, endx, endy; // 起点，终点
int n, m; 
int mp[101][101], vis[101][101];
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
struct point {
    int x; // 横坐标
    int y; // 纵坐标
    int step; // 走的步数
};
int flag = 0;
queue<point> q;
int main() {
    cin >> n >> m; // n * m
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }// 迷宫地图输入
    cin >> startx >> starty >> endx >> endy; // 起点和终点
    point start;
    start.x = startx;
    start.y = starty;
    start.step = 0;
    q.push(start); // 把起点入队
    vis[startx][starty] = 1; // 标记已访问
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        if(x == endx && y == endy) { // 如果到终点了就直接输出
            flag = 1;
            cout << q.front().step << endl;
            break;
        }
        for(int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(!mp[tx][ty] && !vis[tx][ty] && tx <= n && tx > 0 && ty <= m && ty > 0) {
                vis[tx][ty] = 1; // 标记为访问
                point temp;
                temp.x = tx;
                temp.y = ty;
                temp.step = q.front().step + 1;
                q.push(temp); // 入队
            }
        }
        q.pop(); // 拓展完了之后把队首元素出队
    }
    if(flag == 0) {
        cout << "No answer!" << endl;
    }
    return 0;
}