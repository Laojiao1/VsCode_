// https://www.luogu.com.cn/problem/P1077
// 定义状态：f(i, j) 表示前 i 个数总和为 j 的方案数。
#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int MOD = 1e6+7;
int dp[N][N], num[N];
int n, m;
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) { // 遍历种类 
		for(int j = 0; j <= m; j++) { // 遍历总共的花盆数 
			for(int k = 0; k <= min(j, num[i]); k++) {
				dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
			} 
		}
	}
	cout << dp[n][m] << endl;
	return 0;
} 