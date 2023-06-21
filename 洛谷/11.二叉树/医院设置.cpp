// 需要用到floyd多元最短路径算法
// https://www.luogu.com.cn/problem/P1364
#include <bits/stdc++.h>
using namespace std;
const int maxn = 0x7fffffff;
int people[101];
int mp[101][101];
int n, ans = maxn;
int main() {
    memset(mp, 0x7f/3, sizeof(mp));
    cin >> n;
    for(int i = 1; i <= n; i++) {
        mp[i][i] = 0;
        int x, y;
        cin >> people[i] >> x >> y;
        if(x) {
            mp[i][x] = mp[x][i] = 1;
        }
        if(y) {
            mp[i][y] = mp[y][i] = 1;
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i != k && i != j && k != j && mp[i][j] > mp[i][k] + mp[k][j]) {
                    mp[i][j] = mp[i][k] + mp[k][j];
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        int total = 0;
        for(int j = 1; j <= n; j++) {
            total += mp[i][j] * people[j];
        }
        ans = min(ans, total);
    }  
    cout << ans << endl;
    return 0;
}