#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long n, m, d[1001][1001], sum, tot;
long long k, ans = 1;
char mp[1001][1001];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
long long quickpow(long long n, long long k) {
    long long res = 1;
    while(k) {
        if(k & 1) res = res * n % mod;
        k >>= 1;
        n = n*n % mod;
    }
    return res;
}
int find(int x, int y) { // 寻找周围的坐椅数
    int js = 0;
    for(int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && mp[tx][ty] != 'X') {
            js++;
        }
    }
    return js;
}
void dfs(int x, int y) {
    if(find(x, y) == 1) tot++; // 记录周围只有一个座椅的座椅数
    mp[x][y] = 'W'; // 不要忘记标记一下，防止重复查找而超时
    sum++; // 座椅数加一
    for(int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx >= 1 && ty >= 1 && tx <= n && ty <= m && mp[tx][ty] == 'O') {
            dfs(tx, ty);
        }
    }
}
int main() {
    freopen("in.in", "r", stdin);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(mp[i][j] == 'O') {
                sum = tot = 0;
                dfs(i, j);
                if(tot < 2 && sum > 1) {
                    cout << "0" << endl;
                    return 0;
                }
                ans = ans * k % mod * quickpow(k-1, sum-1) % mod;
            }
        }
    }
    cout << ans << endl;
    return 0;
}