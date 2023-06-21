#include <bits/stdc++.h>
using namespace std;
const int N = 101;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
const char dir[4] = {'R', 'L', 'D', 'U'};
int mp[N][N], vis[N][N];
struct Node {
    int x, y;
    string ans;
    Node (int a, int b, string s) {
        a = x;
        b = y;
        ans = s;
    }
};
queue<Node> q;
// 方法一：BFS
void BFS() {
    Node start(1, 1, "");
    q.push(start);
    vis[1][1] = 1;
    while(!q.empty()) {
        Node top = q.front();
        q.pop();
        int x = top.x;
        int y = top.y;
        if(x == 30 && y == 50) {
            cout << top.ans << endl;
            return;
        }
        for(int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx > 0 && tx <= 30 && ty > 0 && ty <= 50 && !vis[tx][ty] && !mp[tx][ty]) {
                vis[tx][ty] = 1;
                q.push(Node(tx, ty, top.ans + dir[i]));
            }
        }
    }
}
int main() {
    for(int i = 1; i <= 30; i++) {
        for(int j = 1; j <= 50; j++) {
            char t;
            cin >> t;
            mp[i][j] = t - '0';
        }
    }
    BFS();
    return 0;
}