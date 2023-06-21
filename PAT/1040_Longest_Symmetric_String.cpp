// 求最长回文字符串，动态规划
#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
char s[N];
int dp[N][N];
int main() {
    // freopen("in.in", "r", stdin);
    fgets(s, N+1, stdin); // fgets需要读取到换行符，所以fgets的最大长度需要比一行的字符数多1
    int len = strlen(s);
    int res = 1;
    for(int i = 0; i < len; i++) {
        dp[i][i] = 1;
        if(i < len && s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            res = 2;
        }
    }
    for(int L = 3; L <= len; L++) {
        int l = len - L + 1;
        for(int i = 0; i < l; i++) {
            int j = i + L - 1;
            if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                dp[i][j] = 1;
                res = L;
            }
        }
    }
    cout << res << endl;
    return 0;
}