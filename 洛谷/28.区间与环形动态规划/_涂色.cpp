// https://www.luogu.com.cn/problem/P4170
// f[i][j]表示s[i]~s[j]所需染色的最小次数
// 当i == j时，子串明显只需要涂色一次，于是f[i][j ]= 1。
// 当i != j且 s[i]==s[j]时，可以想到只需要在首次涂色时多涂一格即可，于是f[i][j]=min(f[i][j-1],f[i+1][j])
// 当i != j且 s[i]!=s[j]时，我们需要考虑将子串断成两部分来涂色，
// 于是需要枚举子串的断点，设断点为k，那么f[i][j]=min(f[i][j],f[i][k]+f[k+1][j])
#include <bits/stdc++.h>
using namespace std;
const int N = 60;
char s[N];
int f[N][N];
int main() {
    cin >> s + 1; // 表示从数组a的首地址+1开始输入
    int n = strlen(s+1);
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= n; i++) {
        f[i][i] = 1;
    }
    for(int len = 2; len <= n; len++) {
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = len + l - 1;
            for(int k = l; k < r; k++) {
                if(s[l] == s[r]) {
                    f[l][r] = min(f[l+1][r], f[l][r-1]);
                } else {
                    f[l][r] = min(f[l][r], f[l][k] + f[k+1][r]);
                }
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}