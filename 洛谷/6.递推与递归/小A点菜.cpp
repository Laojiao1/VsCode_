// P1164 https://www.luogu.com.cn/problem/P1164
// 动态规划
// 思路不难，可以拿来练手
#include <bits/stdc++.h>
using namespace std;
int a[1001];
int f[101][10001];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin>> a[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if(j == a[i]) f[i][j] = f[i-1][j] + 1;
            if(j > a[i]) f[i][j] = f[i-1][j] + f[i-1][j- a[i]];
            if(j < a[i]) f[i][j] = f[i-1][j];
        }
    cout << f[n][m] << endl;
    return 0;
}
// 滚动数组优化
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 10001;
// int n, m, dp[N], a[N];
// int main() {
// 	cin >> n >> m;
// 	for(int i = 1; i <= n; i++) {
// 		cin >> a[i];
// 	}
// 	dp[0] = 1;
// 	for(int i = 1; i <= n; i++) {
// 		for(int j = m; j >= a[i]; j--) {
// 			dp[j] += dp[j - a[i]];
// 		}
// 	}
// 	cout << dp[m] << endl;
// 	return 0;
// }