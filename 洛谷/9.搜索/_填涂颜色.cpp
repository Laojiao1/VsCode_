// https://www.luogu.com.cn/problem/P1162
// 染色问题
#include <bits/stdc++.h>
using namespace std;
int a[32][32], b[32][32]; // 一个用于记录原始图，一个用来进行搜索操作
const int dx[5] = {0, -1, 1, 0, 0};
const int dy[5] = {0, 0, 0, 1, -1};
int n;
void dfs(int x, int y) {
    if(x < 0 || y < 0 || x > n + 1 || y > n + 1 || a[x][y] != 0) {
        // 如果超出边界，或者已经搜过的话就停止搜索直接返回
        // 因此只会搜索到围墙外面的点
        return;
    } else {
        a[x][y] = 1; // 对围墙外面的点进行染色标记
        for(int i = 1; i <= 4; i++) {
            dfs(x + dx[i], y + dy[i]); // 拓展方向
        }
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> b[i][j]; // 记录原始图
            if(b[i][j] == 0) a[i][j] = 0; 
            else a[i][j] = 2; // 标记围墙
        }
    }
    // 一定要从从（0 0）开始搜索，否则会搜索不完全
    dfs(0, 0);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            // a[i][j] == 0 说明这是围墙之内的点
            if(a[i][j] == 0) cout << 2 << " ";
            // 否则就输出原始图
            else cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}