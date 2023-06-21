// 8
// qyizhong
// gydthkjy
// nwidghji
// orbzsfgz
// hhgrhwth
// zzzzzozo
// iwdfrgng
// yyyygggg
// https://www.luogu.com.cn/problem/P1101
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
char mp[maxn][maxn];
string s = "yizhong";
bool vis[maxn][maxn]; // 标记位置
// 以这种方式存储路径有助于往一个方向查找
const int dir[][2] = {{0, 0}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
struct point {
    int x;
    int y;
}c[maxn];
int n;
void dfs(int x, int y, point c[], int k, int num) {
    // x, y:坐标，c[]:记录坐标的结构体，k:当前搜索方向，num:匹配的字符数
    if(num == 7) {
        for(int i = 0; i < 7; i++) {
            // 保存路径
            vis[c[i].x][c[i].y] = 1;
        }
    } else {
        int xx = x + dir[k][0];
        int yy = y + dir[k][1];
        if(num == 6 || mp[xx][yy] == s[num+1]) { // 如果该位置与目标字符对应的话
            // 记录位置
            c[num].x = x;
            c[num].y = y;
            // 继续搜索
            dfs(xx, yy, c, k, num+1);
        }
    }
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> mp[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            // 找到y,i相连的方向，以该方向进行搜索
            if(mp[i][j] == 'y') {
                for(int k = 0; k <= 8; k++) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if(mp[x][y] == 'i') {
                        dfs(i, j, c, k, 0);
                    }
                }
            }
        }
    }
    // 输出
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(vis[i][j]) cout << mp[i][j];
            else cout << "*";
        }
        cout << endl;
    }
    return 0;
}