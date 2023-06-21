#include <bits/stdc++.h>
using namespace std;
struct Node {
    int x, y, s; // 坐标和步数
    string move[100]; // 存储每一步的方案
};
queue<Node> q;
const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, 1, -1, 1, 1, 1, -1};
string st[8] = {"L", "R", "U", "D", "LU", "LD", "RU", "RD"};
bool vis[10][10];
int main() {
    //freopen("in.in", "r", stdin);
    string s1, s2;
    cin >> s1 >> s2;
    int startx = s1[0] - 'a' + 1;
    int starty = s1[1] - '0';
    q.push({startx, starty, 0, ""});
    vis[startx][starty] = 1;
    int endx = s2[0] - 'a' + 1;
    int endy = s2[1] - '0';
    if(vis[endx][endy]) {
        cout << 0 << endl;
        return 0;
    }
    while(!q.empty()) {
        Node top = q.front();
        q.pop();
        for(int i = 0; i < 8; i++) {
            Node t;
            t.x = top.x + dx[i];
            t.y = top.y + dy[i];
            t.s = top.s + 1;
            for(int j = 1; j <= top.s; j++) {
                t.move[j] = top.move[j];
            }
            t.move[t.s] = st[i];
            if(t.x < 1 || t.y > 8 || t.y < 1 || t.y > 8 || vis[t.x][t.y])
                continue;
            vis[t.x][t.y] = 1;
            if(t.x == endx && t.y == endy) {
                cout << t.s << endl;
                for(int k = 1; k <= t.s; k++) {
                    cout << t.move[k] << endl;
                }
                return 0;
            }
            q.push(t);
        }
    }
    return 0;
}