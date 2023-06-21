// dfs 记忆化优先搜索
// https://www.luogu.com.cn/problem/P1434
#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
int n, m;
int ans = 0;
int a[maxn][maxn], s[maxn][maxn];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int x, int y) {
    if(s[x][y]) return s[x][y]; // 如果之前已经计算过了就直接返回
    s[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        int xx = dx[i] + x;
        int yy = dy[i] + y;
        if(xx > 0 && yy > 0 && xx <= n && yy <= m && a[x][y] > a[xx][yy]) {
            dfs(xx, yy);
            s[x][y] = max(s[x][y], s[xx][yy]+1);
        }
    }
    return s[x][y];
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    // 遍历每一个点
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << endl;
    return 0;
}