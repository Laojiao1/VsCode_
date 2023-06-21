// https://www.luogu.com.cn/problem/P3146
#include <bits/stdc++.h>
using namespace std;
const int N = 303;
int n, f[N][N], a[N], ans = -1;
int main() {
    freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i][i] = a[i]; // 不要忘记预处理
    }
    for(int len = 2; len <= n; len++) {
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for(int k = l; k < r; k++) {
                if(f[l][k] == f[k+1][r] && f[l][k] != 0 && f[k+1][r] != 0) {
                // 注意如果两个区间的值都为0的话，合并后是什么也没有的
                    f[l][r] = max(f[l][r], f[l][k] + 1);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}